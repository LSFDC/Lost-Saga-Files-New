import { BillingController } from "@/controller/billing.controller";
import { billingMiddleware } from "@/middleware/billing-middleware";
import express from "express";

const privateRouter = express.Router();

///////////////////////////////
// middleware
///////////////////////////////

privateRouter.use(billingMiddleware);

///////////////////////////////
// routes
///////////////////////////////

privateRouter.post("/billing", BillingController.index);

export { privateRouter };
