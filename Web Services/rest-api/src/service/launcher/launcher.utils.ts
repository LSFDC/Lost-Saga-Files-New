import { MessageBuilder } from "@/lib/webhook/discord.utils";
import { z } from "zod";

///////////////////////////////
// Validate Request
///////////////////////////////

export const LoginRequestValidation = z.object({
  username: z
    .string()
    .min(4)
    .max(12)
    .trim()
    .regex(/^[a-zA-Z0-9]+$/),
  password: z.string().trim().min(4).max(16, {
    message: "Password must be between 4 and 16 characters.",
  }),
  privateIP: z.string(),
  publicIP: z.string(),
  HWID: z.string(),
});

///////////////////////////////
// Types for Request & Response
///////////////////////////////

export type LoginRequest = z.infer<typeof LoginRequestValidation>;
export type LoginResponse = {
  status: boolean;
  message: string;
  AppName: string;
  userID: string;
  encodeKey: string;
  serverID: string;
  userIP: string;
};

///////////////////////////////
// Webhook Message
///////////////////////////////

export const LauncherSuccesEmbed = (
  username: string,
  nickname: string,
  publicIP: string,
  privateIP: string,
  HWID: string,
  serverID: string
) => {
  const embedbuilder = new MessageBuilder()
    .setAuthor(
      "Launcher logger",
      "https://styles.redditmedia.com/t5_2tjkp/styles/communityIcon_j1vhjmngovq21.png",
      ""
    )
    .setTitle("Launcher Info")
    .setDescription(`${username} has successfully logged in.`)
    .addField("Username", `\`\`\`${username}\`\`\``, true)
    .addField("Nickname", `\`\`\`${nickname}\`\`\``, true)
    .addField("Private IP", `\`\`\`${privateIP}\`\`\``, false)
    .addField("Public IP", `\`\`\`${publicIP}\`\`\``, true)
    .addField("HWID", `\`\`\`${HWID}\`\`\``, false)
    .addField("Server ID", `\`\`\`${serverID}\`\`\``, false)
    .setColor(0x00ff00)
    .setFooter(
      "Lost Saga RESTfull API",
      "https://styles.redditmedia.com/t5_2tjkp/styles/communityIcon_j1vhjmngovq21.png"
    )
    .setTimestamp();

  return embedbuilder;
};

export const LauncherFailedEmbed = (
  username: string,
  publicIP: string,
  privateIP: string,
  HWID: string,
  error: string
) => {
  const embedbuilder = new MessageBuilder()
    .setAuthor(
      "Launcher logger",
      "https://styles.redditmedia.com/t5_2tjkp/styles/communityIcon_j1vhjmngovq21.png",
      ""
    )
    .setTitle("Launcher Info")
    .setDescription(`${username} failed to logged in.`)
    .addField("Username", `\`\`\`${username}\`\`\``, true)
    .addField("Private IP", `\`\`\`${privateIP}\`\`\``, false)
    .addField("Public IP", `\`\`\`${publicIP}\`\`\``, true)
    .addField("HWID", `\`\`\`${HWID}\`\`\``, false)
    .addField("Error", `\`\`\`${error}\`\`\``, false)
    .setColor(0xff0000)
    .setFooter(
      "Lost Saga RESTfull API",
      "https://styles.redditmedia.com/t5_2tjkp/styles/communityIcon_j1vhjmngovq21.png"
    )
    .setTimestamp();

  return embedbuilder;
};
