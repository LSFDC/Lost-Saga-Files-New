import { BillingModel } from "@/model/billing.model";
import {
  BillingGetCashEmbed,
  BillingGetCashRequest,
  BillingGetCashValidation,
  BillingPaymentEmbed,
  BillingPaymentRequest,
  BillingPaymentValidation,
  BillingPresentEmbed,
  BillingPresentRequest,
  BillingPresentValidation,
  GetCashResponse,
  PaymentResponse,
} from "./billing.utils";
import { BillingError } from "@/middleware/response/billing-error";
import { BillingWebhook } from "@/lib/webhook.lib";

export class BillingService {
  static cashprocess = async (
    req: BillingGetCashRequest
  ): Promise<GetCashResponse> => {
    const ValidRequest = await BillingGetCashValidation.parseAsync(req).catch(
      () => {
        throw new BillingError(422, "Invalid Request");
      }
    );

    const { makeCodeNo, userId, userNo } = ValidRequest;

    if (makeCodeNo !== process.env.BILLING_SECRET) {
      throw new BillingError(401, "Invalid makeCodeNo");
    }

    const isUserLogin = await BillingModel.checkUserLogin(Number(userNo));

    if (!isUserLogin) {
      throw new BillingError(401, "User not logged in.");
    }

    const usercash = await BillingModel.userCashInfo(Number(userNo));

    if (!usercash) {
      throw new BillingError(500, "Failed to get user cash information.");
    }

    BillingWebhook.send(
      BillingGetCashEmbed(ValidRequest, isUserLogin.userIP as string)
    );

    return {
      result: "success",
      message: "",
      userNo: Number(userNo),
      realCash: Number(usercash.amtCash),
      bonusCash: Number(usercash.amtBonus),
    };
  };

  static paymentProcess = async (
    req: BillingPaymentRequest
  ): Promise<PaymentResponse> => {
    const ValidRequest = BillingPaymentValidation.parse(req);

    if (!ValidRequest) {
      throw new BillingError(422, "Invalid Request");
    }

    const {
      makeCodeNo,
      userId,
      userNo,
      charId,
      clientIp,
      clientPort,
      gameServerNo,
      itemCnt,
      itemId,
      itemUnitPrice,
      location,
      worldNo,
    } = ValidRequest;

    const TempCash = {
      realCash: 0,
      bonusCash: 0,
    };

    const isUserLogin = await BillingModel.checkUserLogin(Number(userNo));

    if (!isUserLogin) {
      throw new BillingError(401, "User not logged in.");
    }

    const usercash = await BillingModel.userCashInfo(Number(userNo));

    if (!usercash) {
      throw new BillingError(500, "Failed to get user cash information.");
    }

    TempCash.realCash = Number(usercash.amtCash);
    TempCash.bonusCash = Number(usercash.amtBonus);

    if (TempCash.bonusCash > 0) {
      TempCash.bonusCash -= Number(itemUnitPrice) * Number(itemCnt);
      if (TempCash.bonusCash < 0) {
        TempCash.realCash -= -TempCash.bonusCash;
        TempCash.bonusCash = 0;
      }
    } else {
      TempCash.realCash -= Number(itemUnitPrice) * Number(itemCnt);
    }

    //handle check if user has enough cash
    if (TempCash.realCash < 0 && TempCash.bonusCash < 0) {
      throw new BillingError(500, "Cash not enough");
    }

    const updatecashuser = await BillingModel.updateUserCash(
      Number(userNo),
      TempCash.realCash,
      TempCash.bonusCash
    );

    if (!updatecashuser) {
      throw new BillingError(500, "Failed to update user cash!");
    }

    BillingWebhook.send(
      BillingPaymentEmbed(ValidRequest, isUserLogin.userIP as string, {
        result: "",
        userNo: updatecashuser.accountIDX,
        realCash: updatecashuser.amtCash,
        bonusCash: updatecashuser.amtBonus,
        chargedCashAmt: Number(itemUnitPrice) * Number(itemCnt),
        itemInfos: { chargeNo: "test123" },
      })
    );

    return {
      result: "success",
      userNo: updatecashuser.accountIDX,
      realCash: updatecashuser.amtCash,
      bonusCash: updatecashuser.amtBonus,
      chargedCashAmt: Number(itemUnitPrice) * Number(itemCnt),
      itemInfos: { chargeNo: "test123" },
    };
  };

  static presentProcess = async (
    req: BillingPresentRequest
  ): Promise<PaymentResponse> => {
    const ValidRequest = BillingPresentValidation.parse(req);

    if (!ValidRequest) {
      throw new BillingError(422, "Invalid Request");
    }

    const {
      makeCodeNo,
      userId,
      userNo,
      charId,
      receiveCharId,
      receiveUserId,
      receiveUserNo,
      clientIp,
      clientPort,
      gameServerNo,
      itemCnt,
      itemId,
      itemUnitPrice,
      location,
      worldNo,
    } = ValidRequest;

    const TempCash = {
      realCash: 0,
      bonusCash: 0,
    };

    const isUserLogin = await BillingModel.checkUserLogin(Number(userNo));

    if (!isUserLogin) {
      throw new BillingError(401, "User not logged in.");
    }

    const usercash = await BillingModel.userCashInfo(Number(userNo));

    if (!usercash) {
      throw new BillingError(500, "Failed to get user cash information.");
    }

    TempCash.realCash = Number(usercash.amtCash);
    TempCash.bonusCash = Number(usercash.amtBonus);

    const calculate =
      TempCash.realCash - Number(itemUnitPrice) * Number(itemCnt);

    if (calculate < 0) {
      throw new BillingError(500, "Cash not enough");
    }

    const updatecashuser = await BillingModel.updateUserCash(
      Number(userNo),
      calculate,
      TempCash.bonusCash
    );

    if (!updatecashuser) {
      throw new BillingError(500, "Failed to update user cash!");
    }

    BillingWebhook.send(
      BillingPresentEmbed(ValidRequest, isUserLogin.userIP as string, {
        result: "",
        userNo: updatecashuser.accountIDX,
        realCash: updatecashuser.amtCash,
        bonusCash: updatecashuser.amtBonus,
        chargedCashAmt: Number(itemUnitPrice) * Number(itemCnt),
        itemInfos: { chargeNo: "test123" },
      })
    );

    return {
      result: "success",
      userNo: updatecashuser.accountIDX,
      realCash: updatecashuser.amtCash,
      bonusCash: updatecashuser.amtBonus,
      chargedCashAmt: Number(itemUnitPrice) * Number(itemCnt),
      itemInfos: { chargeNo: "test123" },
    };
  };
}
