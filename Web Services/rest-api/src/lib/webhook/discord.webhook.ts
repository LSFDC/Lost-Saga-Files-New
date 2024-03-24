import { sendWebhook } from "./api";
import { MessageBuilder } from "./discord.utils";

interface WebhookOptions {
  url: string;
  throwErrors?: boolean;
  retryOnLimit?: boolean;
}

export interface Payload {
  username?: string;
  avatar_url?: string;
  content?: string;
  [key: string]: any; // Allow any other properties
}

export class DiscordWebhook {
  hookURL: string;
  throwErrors: boolean;
  retryOnLimit: boolean;
  payload: Payload;

  constructor(options: string | WebhookOptions) {
    this.payload = {};

    if (typeof options === "string") {
      this.hookURL = options;
      this.throwErrors = true;
      this.retryOnLimit = true;
    } else {
      this.hookURL = options.url;
      this.throwErrors = options.throwErrors ?? true;
      this.retryOnLimit = options.retryOnLimit ?? true;
    }
  }

  setUsername(username: string): this {
    this.payload.username = username;
    return this;
  }

  setAvatar(avatarURL: string): this {
    this.payload.avatar_url = avatarURL;
    return this;
  }

  //   async sendFile(filePath: string): Promise<void> {
  //     try {
  //       const res = await sendFile(this.hookURL, filePath, this.payload);

  //       if (res.statusCode !== 200) {
  //         throw new Error(
  //           `Error sending webhook: ${res.statusCode} status code.`
  //         );
  //       }
  //     } catch (err) {
  //       if (this.throwErrors) throw new Error(err.message);
  //     }
  //   }

  async send(payload: string | { getJSON(): object }): Promise<void> {
    let endPayload: Payload = { ...this.payload };

    if (typeof payload === "string") {
      endPayload.content = payload;
    } else {
      endPayload = {
        ...endPayload,
        ...payload.getJSON(),
      };
    }

    try {
      const res = await sendWebhook(this.hookURL, endPayload);

      if (res.status === 429 && this.retryOnLimit) {
        const body = await res.json();
        const waitUntil = body["retry_after"];

        setTimeout(() => sendWebhook(this.hookURL, endPayload), waitUntil);
      } else if (res.status !== 204) {
        throw new Error(
          `Error sending webhook: ${
            res.status
          } status code. Response: ${await res.text()}`
        );
      }
    } catch (err) {
      if (this.throwErrors) throw new Error((err as any).message);
    }
  }

  async info(
    title: string,
    fieldName?: string,
    fieldValue?: string,
    inline?: boolean
  ): Promise<void> {
    const embed = new MessageBuilder()
      .setTitle(title)
      .setTimestamp()
      .setColor(4037805);

    if (fieldName !== undefined && fieldValue !== undefined) {
      embed.addField(fieldName, fieldValue, inline);
    }

    await this.send(embed);
  }

  async success(
    title: string,
    fieldName?: string,
    fieldValue?: string,
    inline?: boolean
  ): Promise<void> {
    const embed = new MessageBuilder()
      .setTitle(title)
      .setTimestamp()
      .setColor(65340);

    if (fieldName !== undefined && fieldValue !== undefined) {
      embed.addField(fieldName, fieldValue, inline);
    }

    await this.send(embed);
  }

  async warning(
    title: string,
    fieldName?: string,
    fieldValue?: string,
    inline?: boolean
  ): Promise<void> {
    const embed = new MessageBuilder()
      .setTitle(title)
      .setTimestamp()
      .setColor(16763904);

    if (fieldName !== undefined && fieldValue !== undefined) {
      embed.addField(fieldName, fieldValue, inline);
    }

    await this.send(embed);
  }

  async error(
    title: string,
    fieldName?: string,
    fieldValue?: string,
    inline?: boolean
  ): Promise<void> {
    const embed = new MessageBuilder()
      .setTitle(title)
      .setTimestamp()
      .setColor(16729149);

    if (fieldName !== undefined && fieldValue !== undefined) {
      embed.addField(fieldName, fieldValue, inline);
    }

    await this.send(embed);
  }
}
