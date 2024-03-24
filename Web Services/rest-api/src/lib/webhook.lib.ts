import { DiscordWebhook } from "./webhook/discord.webhook";

const discordWebhook = new DiscordWebhook(process.env.DISCORD_WEBHOOK_MAIN!);

discordWebhook.setUsername("Lost Saga RESTfull API");
discordWebhook.setAvatar(process.env.DISCORD_WEBHOOK_MAIN_AVATAR!);

const LauncherWebhook = new DiscordWebhook(
  process.env.DISCORD_WEBHOOK_LAUNCHER!
);

LauncherWebhook.setUsername("Lost Saga RESTfull API");
LauncherWebhook.setAvatar(process.env.DISCORD_WEBHOOK_LAUNCHER_AVATAR!);

const BillingWebhook = new DiscordWebhook(process.env.DISCORD_WEBHOOK_BILLING!);

BillingWebhook.setUsername("Lost Saga RESTfull API");
BillingWebhook.setAvatar(process.env.DISCORD_WEBHOOK_BILLING_AVATAR!);

export { discordWebhook, LauncherWebhook, BillingWebhook };
