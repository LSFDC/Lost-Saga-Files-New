import { LauncherController } from "@/controller/launcher.controller";
import { launcherMiddleware } from "@/middleware/launcher-middleware";
import express from "express";

const publicRouter = express.Router();

/////////////////////////////////
// middleware
/////////////////////////////////
publicRouter.use(launcherMiddleware);

/////////////////////////////////
// routes
/////////////////////////////////

publicRouter.post("/launcher", LauncherController.index);

export { publicRouter };
