import { NextFunction, Request, Response } from "express";
import { ResponseError } from "./response/response-error";
import { BillingError } from "./response/billing-error";
import { ZodError } from "zod";

const errorMiddleware = async (
  err: Error,
  req: Request,
  res: Response,
  next: NextFunction
) => {
  if (!err) {
    next();
    return;
  }

  if (err instanceof ZodError) {
    res
      .status(400)
      .json({
        error: `Validation Error : ${err.errors
          .map((e) => e.message)
          .join(", ")}`,
      })
      .end();
  } else if (err instanceof ResponseError) {
    res
      .status(err.status)
      .json({
        error: err.message,
      })
      .end();
  } else if (err instanceof BillingError) {
    res
      .status(err.status)
      .json({
        result: "error",
      })
      .end();
  } else {
    return res
      .status(500)
      .json({
        error: err.message,
      })
      .end();
  }
};

export { errorMiddleware };
