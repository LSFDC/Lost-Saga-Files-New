import dotenv from "dotenv";
import { app } from "./config/app";

import { discordWebhook } from "./lib/webhook.lib";

dotenv.config();

app
  .listen(process.env.APP_PORT, () => {
    console.log(
      "\x1b[33m",
      `${process.env.APP_NAME} has been running on ${process.env.APP_HOST}:${process.env.APP_PORT}/`,
      "\x1b[0m"
    );
  })
  .on("listening", async () => {
    process.env.TZ = "UTC";

    discordWebhook.success(
      `${process.env.APP_NAME} has been running on ${process.env.APP_HOST}:${process.env.APP_PORT}/`
    );
  });
