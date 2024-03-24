import { Payload } from "./discord.webhook";

export const sendWebhook = (
  hookURL: string,
  payload: Payload
): Promise<Response> =>
  new Promise((resolve, reject) => {
    fetch(hookURL, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(payload),
    })
      .then((res: Response) => resolve(res))
      .catch((err: Error) => reject(err));
  });
