import { LauncherWebhook } from "@/lib/webhook.lib";
import { ResponseError } from "@/middleware/response/response-error";
import { LauncherService } from "@/service/launcher/launcher.service";
import {
  LauncherFailedEmbed,
  LoginRequest,
} from "@/service/launcher/launcher.utils";
import { NextFunction, Request, Response } from "express";

export class LauncherController {
  static async index(req: Request, res: Response, next: NextFunction) {
    try {
      const request: LoginRequest = req.body as LoginRequest;
      const response = await LauncherService.login(request);

      res.status(200).json(response).end();
    } catch (error) {
      const request: LoginRequest = req.body as LoginRequest;
      if (error instanceof ResponseError) {
        LauncherWebhook.send(
          LauncherFailedEmbed(
            request.username,
            request.publicIP,
            request.privateIP,
            request.HWID,
            error?.message
          )
        );
      }
      next(error);
    }
  }
}
