import { MessageBuilder } from "@/lib/webhook/discord.utils";
import { z } from "zod";

export type BillingType = "getcash" | "payment" | "present";

export const BillingGetCashValidation = z.object({
  makeCodeNo: z.string().regex(/^[0-9]{1,10}$/),
  userNo: z.string().regex(/^[0-9]{1,10}$/),
  userId: z
    .string()
    .min(4)
    .trim()
    .regex(/^[a-zA-Z0-9]+$/), //username
});

export type BillingGetCashRequest = z.infer<typeof BillingGetCashValidation>;

//decided to use regex for correct typesafe validation
export const BillingPaymentValidation = z.object({
  makeCodeNo: z.string().regex(/^[0-9]{1,10}$/),
  userNo: z.string().regex(/^[0-9]{1,10}$/),
  userId: z
    .string()
    .min(4)
    .trim()
    .regex(/^[a-zA-Z0-9]+$/), //username
  charId: z
    .string()
    .min(4)
    .trim()
    .regex(/^[a-zA-Z0-9]+$/), //nickname
  clientIp: z.string(),
  clientPort: z.string(),
  itemId: z.string().regex(/^[0-9]{1,10}$/),
  itemCnt: z.string().regex(/^[0-9]{1,10}$/),
  itemUnitPrice: z.string().regex(/^[0-9]{1,10}$/),
  gameServerNo: z.string().regex(/^[0-9]{1,10}$/),
  worldNo: z.string().regex(/^[0-9]{1,10}$/),
  statProperty1: z.optional(z.string()),
  statProperty2: z.optional(z.string()),
  statProperty3: z.optional(z.string()),
  location: z.literal("GAME"),
});

export type BillingPaymentRequest = z.infer<typeof BillingPaymentValidation>;

//decided to use regex for correct typesafe validation

export const BillingPresentValidation = z.object({
  makeCodeNo: z.string().regex(/^[0-9]{1,10}$/),
  userNo: z.string().regex(/^[0-9]{1,10}$/),
  userId: z
    .string()
    .min(4)
    .trim()
    .regex(/^[a-zA-Z0-9]+$/), //username
  charId: z
    .string()
    .min(4)
    .trim()
    .regex(/^[a-zA-Z0-9]+$/), //nickname
  receiveUserNo: z.string().regex(/^[0-9]{1,10}$/),
  receiveUserId: z
    .string()
    .trim()
    .regex(/^[a-zA-Z0-9]+$/),
  receiveCharId: z
    .string()
    .trim()
    .regex(/^[a-zA-Z0-9]+$/),
  clientIp: z.string(),
  clientPort: z.string(),
  itemId: z.string().regex(/^[0-9]{1,10}$/),
  itemCnt: z.string().regex(/^[0-9]{1,10}$/),
  itemUnitPrice: z.string().regex(/^[0-9]{1,10}$/),
  gameServerNo: z.string().regex(/^[0-9]{1,10}$/),
  worldNo: z.string().regex(/^[0-9]{1,10}$/),
  statProperty1: z.optional(z.string()),
  statProperty2: z.optional(z.string()),
  statProperty3: z.optional(z.string()),
  location: z.literal("GAME"),
});

export type BillingPresentRequest = z.infer<typeof BillingPresentValidation>;

///////////////////////////////
// Types for Response
///////////////////////////////

export type GetCashResponse = {
  result: string;
  message: string;
  userNo: number;
  realCash: number;
  bonusCash: number;
};

export type PaymentResponse = {
  result: string;
  userNo: number;
  realCash: number;
  bonusCash: number;
  chargedCashAmt: number;
  itemInfos: { chargeNo: "test123" };
};

///////////////////////////////
// Webhook Message
///////////////////////////////

export const BillingGetCashEmbed = (
  req: BillingGetCashRequest,
  ipaddress: string
) => {
  const embedbuilder = new MessageBuilder()
    .setAuthor(
      "Billing logger",
      "https://styles.redditmedia.com/t5_2tjkp/styles/communityIcon_j1vhjmngovq21.png",
      ""
    )
    .setTitle("Billing GetCash")
    .setDescription(`${req.userId} has requested to get cash.`)
    .addField("Username", `\`\`\`${req.userId}\`\`\``)
    .addField("UserNo", `\`\`\`${req.userNo}\`\`\``)
    .addField("MakeCodeNo", `\`\`\`${req.makeCodeNo}\`\`\``)
    .addField("IP Address", `\`\`\`${ipaddress}\`\`\``)
    .setColor(0x00ff00)
    .setFooter(
      "Lost Saga RESTfull API",
      "https://styles.redditmedia.com/t5_2tjkp/styles/communityIcon_j1vhjmngovq21.png"
    )
    .setTimestamp();

  return embedbuilder;
};

export const BillingPaymentEmbed = (
  req: BillingPaymentRequest,
  ipaddress: string,
  res: PaymentResponse
) => {
  const embedbuilder = new MessageBuilder()
    .setAuthor(
      "Billing logger",
      "https://styles.redditmedia.com/t5_2tjkp/styles/communityIcon_j1vhjmngovq21.png",
      ""
    )
    .setTitle("Billing Payment")
    .setDescription(`${req.userId} has requested to make a payment.`)
    .addField("UserNo", `\`\`\`${req.userNo}\`\`\``)
    .addField("Username", `\`\`\`${req.userId}\`\`\``)
    .addField("Nickname", `\`\`\`${req.charId}\`\`\``, true)
    .addField("Client IP", `\`\`\`${req.clientIp}\`\`\``, true)
    .addField("Client Port", `\`\`\`${req.clientPort}\`\`\``, true)
    .addField("Item ID", `\`\`\`${req.itemId}\`\`\``, true)
    .addField("Item Count", `\`\`\`${req.itemCnt}\`\`\``, true)
    .addField("Item Unit Price", `\`\`\`${req.itemUnitPrice}\`\`\``, true)
    .addField("Game Server No", `\`\`\`${req.gameServerNo}\`\`\``, true)
    .addField("World No", `\`\`\`${req.worldNo}\`\`\``, true)

    .addField("Real Cash", `\`\`\`${res.realCash}\`\`\``, true)
    .addField("Bonus Cash", `\`\`\`${res.bonusCash}\`\`\``, true)
    .addField("Charged Cash Amount", `\`\`\`${res.chargedCashAmt}\`\`\``)
    .addField("Charge No", `\`\`\`${res.itemInfos.chargeNo}\`\`\``)
    .addField("Location", `\`\`\`${req.location}\`\`\``)
    .addField("MakeCodeNo", `\`\`\`${req.makeCodeNo}\`\`\``)
    .addField("IP Address", `\`\`\`${ipaddress}\`\`\``)
    .setColor(0x00ff00)
    .setFooter(
      "Lost Saga RESTfull API",
      "https://styles.redditmedia.com/t5_2tjkp/styles/communityIcon_j1vhjmngovq21.png"
    )
    .setTimestamp();

  return embedbuilder;
};

export const BillingPresentEmbed = (
  req: BillingPresentRequest,
  ipaddress: string,
  res: PaymentResponse
) => {
  const embedbuilder = new MessageBuilder()
    .setAuthor(
      "Billing logger",
      "https://styles.redditmedia.com/t5_2tjkp/styles/communityIcon_j1vhjmngovq21.png",
      ""
    )
    .setTitle("Billing Payment")
    .setDescription(`${req.userId} has requested to make a payment.`)
    .addField("UserNo", `\`\`\`${req.userNo}\`\`\``)
    .addField("Username", `\`\`\`${req.userId}\`\`\``)
    .addField("Nickname", `\`\`\`${req.charId}\`\`\``, true)
    .addField("Client IP", `\`\`\`${req.clientIp}\`\`\``, true)
    .addField("Client Port", `\`\`\`${req.clientPort}\`\`\``, true)
    .addField("Receive UserNo", `\`\`\`${req.receiveUserNo}\`\`\``, true)
    .addField("Receive Username", `\`\`\`${req.receiveUserId}\`\`\``, true)
    .addField("Receive Nickname", `\`\`\`${req.receiveCharId}\`\`\``, true)
    .addField("Item ID", `\`\`\`${req.itemId}\`\`\``, true)
    .addField("Item Count", `\`\`\`${req.itemCnt}\`\`\``, true)
    .addField("Item Unit Price", `\`\`\`${req.itemUnitPrice}\`\`\``, true)
    .addField("Game Server No", `\`\`\`${req.gameServerNo}\`\`\``, true)
    .addField("World No", `\`\`\`${req.worldNo}\`\`\``, true)

    .addField("Real Cash", `\`\`\`${res.realCash}\`\`\``)
    .addField("Bonus Cash", `\`\`\`${res.bonusCash}\`\`\``, true)
    .addField("Charged Cash Amount", `\`\`\`${res.chargedCashAmt}\`\`\``)
    .addField("Charge No", `\`\`\`${res.itemInfos.chargeNo}\`\`\``)
    .addField("Location", `\`\`\`${req.location}\`\`\``)
    .addField("MakeCodeNo", `\`\`\`${req.makeCodeNo}\`\`\``)
    .addField("IP Address", `\`\`\`${ipaddress}\`\`\``)
    .setColor(0x00ff00)
    .setFooter(
      "Lost Saga RESTfull API",
      "https://styles.redditmedia.com/t5_2tjkp/styles/communityIcon_j1vhjmngovq21.png"
    )
    .setTimestamp();

  return embedbuilder;
};
