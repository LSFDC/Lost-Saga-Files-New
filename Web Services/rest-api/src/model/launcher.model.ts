import { LosaGameDB } from "@/lib/prisma.lib";

export class LauncherModel {
  static async getLauncherInfo() {
    try {
      const launcherInfo = await LosaGameDB.define_launcher_info.findUnique({
        where: {
          launcherKey: process.env.LAUNCHER_KEY,
        },
      });
      return launcherInfo;
    } catch (error) {
      return null;
    }
  }

  static async getWhitelistAccess(username: string) {
    try {
      const whitelistIP = await LosaGameDB.define_launcher_whitelist.findUnique(
        {
          where: {
            username,
          },
        }
      );
      return whitelistIP;
    } catch (error) {
      return null;
    }
  }

  static async getServerInfo() {
    try {
      const serverInfo = await LosaGameDB.define_game_server.findUnique({
        where: {
          serverID: Number(process.env.SERVER_ID),
        },
      });

      return serverInfo;
    } catch (error) {
      return null;
    }
  }

  static async getServerEncodeKey() {
    try {
      const serverKey = await LosaGameDB.define_encode_key.findFirst({
        orderBy: {
          regDate: "desc",
        },
      });

      return serverKey;
    } catch (error) {
      return null;
    }
  }

  static async getUserInfo(username: string) {
    try {
      const userInfo = await LosaGameDB.userMemberDB.findUnique({
        where: {
          userID: username,
        },
      });

      if (!userInfo || !/^[a-zA-Z0-9-]+$/.test(userInfo.nickName)) {
        return null;
      }

      return userInfo;
    } catch (error) {
      return null;
    }
  }

  static async updateLoginInfo(userIDX: number, ip: string) {
    try {
      const updateLogin = await LosaGameDB.userLoginDB.update({
        data: {
          userIP: ip,
          connDate: new Date(),
        },
        where: {
          accountIDX: userIDX,
        },
      });

      return updateLogin;
    } catch (error) {
      return null;
    }
  }

  static async updateGameInfo(userIDX: number) {
    try {
      const updateGame = await LosaGameDB.userGameDB.update({
        data: {
          userState: -1,
        },
        where: {
          accountIDX: userIDX,
        },
      });

      return updateGame;
    } catch (error) {
      return null;
    }
  }

  //TODO: Add HWID check
  static async checkHWID(hwid: string) {
    try {
      const checkifHWIDBlocked =
        await LosaGameDB.define_hwid_blocklist.findUnique({
          where: {
            hwid: hwid,
          },
        });

      return checkifHWIDBlocked ? true : false;
    } catch (error) {
      return null;
    }
  }

  static async banUserAccount(username: string) {
    try {
      const banUser = await LosaGameDB.userMemberDB.update({
        data: {
          limitType: 100,
          limitDate: new Date(new Date().getTime() + 90 * 24 * 60 * 60 * 1000), // 90 days ban
        },
        where: {
          userID: username,
        },
      });

      return banUser;
    } catch (error) {
      return null;
    }
  }
}
