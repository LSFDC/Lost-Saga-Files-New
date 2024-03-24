import { UAParser } from "ua-parser-js";
import { errorMiddleware } from "@/middleware/error-middleware";
import express from "express";
import { privateRouter } from "./routes/private.router";
import { publicRouter } from "./routes/public.router";

export const app = express();

app.use(express.json());
app.use(
  express.urlencoded({
    extended: true,
  })
);

app.use("/v2", publicRouter);
app.use("/v2", privateRouter);

app.use(function (req, res, next) {
  const UA = new UAParser(req.headers["user-agent"]);

  const prefixLink = "/v2";
  const routePaths = [
    {
      BILLING: [
        {
          route: prefixLink + "/billing?type=getcash",
          method: "POST",
          description: "Get User Cash Information",
          isNeedKey: true,
        },
        {
          route: prefixLink + "/billing?type=payment",
          method: "POST",
          description: "Payment User Cash Information",
          isNeedKey: true,
        },
        {
          route: prefixLink + "/billing?type=present",
          method: "POST",
          description: "Present/Gift(InGame) User Cash Information",
          isNeedKey: true,
        },
      ],
      LAUNCHER: [
        {
          route: prefixLink + "/launcher",
          method: "POST",
          description: "Launcher Login",
          isNeedKey: true,
        },
      ],
    },
  ];

  return res.status(200).json({
    Service: "Lost Saga REST API",
    Version: "2.0.0",
    Author: "LSFD a.k.a Lost Saga For Developers",
    Messages: "This is free and prohibited for sale!!",
    RequestDetails: {
      IP: req.headers["x-real-ip"] || req.ip,
      UserAgent: UA.getResult(),
    },
    RoutePaths: routePaths,
  });
});

app.use(errorMiddleware);
