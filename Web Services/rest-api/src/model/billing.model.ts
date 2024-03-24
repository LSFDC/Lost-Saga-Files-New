import { LosaGameDB } from "@/lib/prisma.lib";

export class BillingModel {
  static async checkUserLogin(userIDX: number) {
    try {
      const checkLogin = await LosaGameDB.userLoginDB.findFirst({
        where: {
          accountIDX: userIDX,
          AND: {
            gameServerID: {
              not: 0,
            },
          },
        },
      });

      return checkLogin;
    } catch (error) {
      return null;
    }
  }

  static async userCashInfo(userIDX: number) {
    try {
      const userCash = await LosaGameDB.userCashDB.findFirst({
        where: {
          accountIDX: userIDX,
        },
      });

      return userCash;
    } catch (error) {
      return null;
    }
  }

  static async updateUserCash(
    userIDX: number,
    realcash: number,
    bonuscash: number
  ) {
    try {
      const updatecash = await LosaGameDB.userCashDB.update({
        where: {
          accountIDX: userIDX,
        },
        data: {
          amtCash: realcash,
          amtBonus: bonuscash,
          amtSum: realcash + bonuscash,
          chgDate: new Date(),
        },
      });

      return updatecash;
    } catch (error) {
      return null;
    }
  }
}
