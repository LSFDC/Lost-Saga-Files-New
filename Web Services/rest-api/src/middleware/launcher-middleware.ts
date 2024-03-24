import { LauncherModel } from "@/model/launcher.model";
import { Request, Response, NextFunction } from "express";

export const launcherMiddleware = async (
  req: Request,
  res: Response,
  next: NextFunction
) => {
  if (req.url !== "/launcher") {
    next();
    return;
  }

  const authorization = req.headers.authorization;
  const brandName = authorization?.split(" ")[0];
  const spesificKey = authorization?.split(" ")[1];

  const launcherkey = await LauncherModel.getLauncherInfo();

  if (!launcherkey)
    return res.status(401).json({
      error:
        "Failed to get launcher info. Please try again later or contact admin on Discord",
    });

  if (!authorization) return res.status(403).json({ error: "Unauthorized" });

  if (brandName !== launcherkey.launcherKey)
    return res.status(401).json({ error: "Unauthorized" });

  if (spesificKey !== process.env.API_KEY)
    return res.status(401).json({ error: "Unauthorized" });

  next();
};
