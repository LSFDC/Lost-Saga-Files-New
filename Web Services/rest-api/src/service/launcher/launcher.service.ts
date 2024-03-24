import { ResponseError } from "@/middleware/response/response-error";
import {
  LauncherSuccesEmbed,
  LoginRequest,
  LoginRequestValidation,
  LoginResponse,
} from "./launcher.utils";
import { LauncherModel } from "@/model/launcher.model";
import bcrypt from "bcrypt";
import { LauncherWebhook } from "@/lib/webhook.lib";

export class LauncherService {
  /////////////////////////////////
  // login function
  /////////////////////////////////
  static async login(req: LoginRequest): Promise<LoginResponse> {
    const ValidRequest = LoginRequestValidation.parse(req);

    if (!ValidRequest) {
      throw new ResponseError(422, "Invalid Request");
    }

    const { username, password, privateIP, publicIP, HWID } = ValidRequest;

    const launcherinfo = await LauncherModel.getLauncherInfo();

    if (!launcherinfo) {
      throw new ResponseError(
        500,
        "Failed to get launcher information. Please try again later or contact support on Discord."
      );
    }

    if (launcherinfo.status !== 1) {
      const isWhitelist = await LauncherModel.getWhitelistAccess(username);

      if (!isWhitelist) {
        throw new ResponseError(
          401,
          "Server currently under maintenance. Please try again later or contact support on Discord."
        );
      }
    }

    const serverinfo = await LauncherModel.getServerInfo();
    const serverkey = await LauncherModel.getServerEncodeKey();

    const isHWIDBlocked = await LauncherModel.checkHWID(HWID);

    if (isHWIDBlocked) {
      await LauncherModel.banUserAccount(username);
      throw new ResponseError(401, "Account is blocked or banned.");
    }

    if (!serverinfo || !serverkey) {
      throw new ResponseError(
        500,
        "Failed to get server information. Please try again later or contact support on Discord."
      );
    }

    const existUser = await LauncherModel.getUserInfo(username);
    if (!existUser) {
      throw new ResponseError(401, "Account does not exist.");
    }

    if (existUser.limitType === 100) {
      throw new ResponseError(
        401,
        `Account is blocked or banned until: ${existUser.limitDate}`
      );
    }

    if (existUser.userID === password) {
      throw new ResponseError(401, "Account not available to play!");
    }

    const checkPassword = await bcrypt.compare(password, existUser?.userPWD);

    if (!checkPassword) {
      throw new ResponseError(401, "Invalid password.");
    }

    const updateLogin = await LauncherModel.updateLoginInfo(
      existUser.accountIDX,
      privateIP
    );

    if (!updateLogin) {
      throw new ResponseError(
        500,
        "Failed to update login information. Please try again later or contact support on Discord."
      );
    }

    const updateGame = await LauncherModel.updateGameInfo(existUser.accountIDX);

    if (!updateGame) {
      throw new ResponseError(
        500,
        "Failed to update game information. Please try again later or contact support on Discord."
      );
    }

    LauncherWebhook.send(
      LauncherSuccesEmbed(
        username,
        existUser.nickName,
        publicIP,
        privateIP,
        HWID,
        serverinfo.serverID.toString()
      )
    );

    return {
      status: true,
      message: "success",
      AppName: "lostsaga.exe",
      userID: existUser.userID,
      encodeKey: serverkey.encodeKey,
      serverID: serverinfo.serverID.toString(),
      userIP: publicIP,
    };
  }
}
