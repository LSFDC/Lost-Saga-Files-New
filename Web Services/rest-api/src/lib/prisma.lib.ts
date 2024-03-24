import { PrismaClient } from "@prisma/client";

declare global {
  var LosaGame: PrismaClient | undefined;
}

const LosaGameDB =
  globalThis.LosaGame ||
  new PrismaClient({
    log: ["query", "info", "warn", "error"],
    errorFormat: "pretty",
    transactionOptions: {
      maxWait: 1000,
      timeout: 1000,
    },
  });

export { LosaGameDB };

if (process.env.NODE_ENV !== "production") {
  globalThis.LosaGame = LosaGameDB;
}
