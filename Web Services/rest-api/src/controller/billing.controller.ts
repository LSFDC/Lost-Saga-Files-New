import { BillingService } from "@/service/billing/billing.service";
import {
  BillingGetCashRequest,
  BillingPaymentRequest,
  BillingPresentRequest,
  BillingType,
} from "@/service/billing/billing.utils";
import { Request, Response, NextFunction } from "express";

export class BillingController {
  static index = async (req: Request, res: Response, next: NextFunction) => {
    try {
      let result = {};
      const billingType: BillingType = req.query?.type as BillingType;

      switch (billingType) {
        case "getcash":
          const cashrequest: BillingGetCashRequest =
            req.body as BillingGetCashRequest;

          result = await BillingService.cashprocess(cashrequest);

          break;
        case "payment":
          const paymentrequest: BillingPaymentRequest =
            req.body as BillingPaymentRequest;

          result = await BillingService.paymentProcess(paymentrequest);
          break;
        case "present":
          const presentrequest: BillingPresentRequest =
            req.body as BillingPresentRequest;
          result = await BillingService.presentProcess(presentrequest);
          break;
      }

      res.status(200).json(result);
    } catch (error) {
      next(error);
    }
  };
}
