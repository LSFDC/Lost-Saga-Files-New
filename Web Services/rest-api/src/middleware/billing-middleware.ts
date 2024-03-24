import { NextFunction, Request, Response } from "express";

const whitelistIP = [""]; // IP whitelist for billing

const billingMiddleware = async (
  req: Request,
  res: Response,
  next: NextFunction
) => {
  if (
    req.url !== "/billing?type=getcash" &&
    req.url !== "/billing?type=payment" &&
    req.url !== "/billing?type=present"
  ) {
    next();
    return;
  }

  const authorization = req.headers.authorization;
  const brandName = authorization?.split(" ")[0];
  const spesificKey = authorization?.split(" ")[1];

  if (!whitelistIP.includes(req.headers["x-real-ip"] as string))
    return res.sendStatus(403);

  if (!authorization) return res.sendStatus(403);

  if (
    brandName !== process.env.BILLING_NAME &&
    spesificKey !== process.env.BILLING_API_KEY
  ) {
    return res.status(401).json({ error: "Unauthorized" }).end();
  }

  next();
};

export { billingMiddleware };
