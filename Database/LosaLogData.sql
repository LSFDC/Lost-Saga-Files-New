/*
 Navicat Premium Data Transfer

 Source Server         : [LSFD] LS
 Source Server Type    : SQL Server
 Source Server Version : 16004105 (16.00.4105)
 Source Host           : 172.17.191.44:1433
 Source Catalog        : LosaLogData
 Source Schema         : dbo

 Target Server Type    : SQL Server
 Target Server Version : 16004105 (16.00.4105)
 File Encoding         : 65001

 Date: 24/03/2024 14:29:25
*/


-- ----------------------------
-- Table structure for GAME_LOG
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[GAME_LOG]') AND type IN ('U'))
	DROP TABLE [dbo].[GAME_LOG]
GO

CREATE TABLE [dbo].[GAME_LOG] (
  [RegDate] datetime  NOT NULL,
  [LogIDX] bigint  IDENTITY(1,1) NOT NULL,
  [LogType] int  NOT NULL,
  [AccountIDX] int  NOT NULL,
  [UserID] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserLevel] int  NOT NULL,
  [UserExp] int  NOT NULL,
  [CpType] int  NOT NULL,
  [TBLIDX] int  NOT NULL,
  [ObjCode] int  NOT NULL,
  [EventType] tinyint  NOT NULL,
  [Param1] int  NOT NULL,
  [Param2] int  NOT NULL,
  [Param3] int  NOT NULL,
  [Param4] int  NOT NULL,
  [Param5] varchar(50) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL
)
GO

ALTER TABLE [dbo].[GAME_LOG] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for Log_buy_gold_item
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[Log_buy_gold_item]') AND type IN ('U'))
	DROP TABLE [dbo].[Log_buy_gold_item]
GO

CREATE TABLE [dbo].[Log_buy_gold_item] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickname] varchar(12) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [itemType] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] varchar(200) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[Log_buy_gold_item] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for Log_buy_item
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[Log_buy_item]') AND type IN ('U'))
	DROP TABLE [dbo].[Log_buy_item]
GO

CREATE TABLE [dbo].[Log_buy_item] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [userID] varchar(12) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [applyType] char(2) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [playType] int DEFAULT 0 NOT NULL,
  [modeType] int DEFAULT 0 NOT NULL,
  [sub1Type] int DEFAULT 0 NOT NULL,
  [sub2Type] int DEFAULT 0 NOT NULL,
  [buyplace] int DEFAULT 0 NULL,
  [classType] int DEFAULT 0 NOT NULL,
  [kindred] int DEFAULT -1 NOT NULL,
  [decoType] int DEFAULT -1 NOT NULL,
  [decoCode] int DEFAULT -1 NOT NULL,
  [itemType] int DEFAULT 0 NOT NULL,
  [buyType] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [note] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[Log_buy_item] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_buy_item_accessory
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_buy_item_accessory]') AND type IN ('U'))
	DROP TABLE [dbo].[log_buy_item_accessory]
GO

CREATE TABLE [dbo].[log_buy_item_accessory] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [eventType] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_buy_item_accessory] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_buy_item_class
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_buy_item_class]') AND type IN ('U'))
	DROP TABLE [dbo].[log_buy_item_class]
GO

CREATE TABLE [dbo].[log_buy_item_class] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [classType] int DEFAULT 0 NOT NULL,
  [limitType] int DEFAULT 0 NOT NULL,
  [eventType] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_buy_item_class] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_buy_item_costume
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_buy_item_costume]') AND type IN ('U'))
	DROP TABLE [dbo].[log_buy_item_costume]
GO

CREATE TABLE [dbo].[log_buy_item_costume] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [eventType] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_buy_item_costume] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_buy_item_decoration
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_buy_item_decoration]') AND type IN ('U'))
	DROP TABLE [dbo].[log_buy_item_decoration]
GO

CREATE TABLE [dbo].[log_buy_item_decoration] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [classType] int DEFAULT 0 NOT NULL,
  [kindred] int DEFAULT 0 NOT NULL,
  [itemType] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [eventType] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_buy_item_decoration] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_buy_item_equip
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_buy_item_equip]') AND type IN ('U'))
	DROP TABLE [dbo].[log_buy_item_equip]
GO

CREATE TABLE [dbo].[log_buy_item_equip] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [itemType] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [reinforce] int DEFAULT 0 NOT NULL,
  [machineType] int DEFAULT 0 NOT NULL,
  [limitDate] int DEFAULT 0 NOT NULL,
  [eventType] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_buy_item_equip] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_buy_item_gold
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_buy_item_gold]') AND type IN ('U'))
	DROP TABLE [dbo].[log_buy_item_gold]
GO

CREATE TABLE [dbo].[log_buy_item_gold] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [itemType] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [itemValue] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [cpType] smallint DEFAULT 0 NOT NULL,
  [billingID] varchar(64) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [buyType] tinyint DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_buy_item_gold] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_buy_item_sbox
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_buy_item_sbox]') AND type IN ('U'))
	DROP TABLE [dbo].[log_buy_item_sbox]
GO

CREATE TABLE [dbo].[log_buy_item_sbox] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [presentType] smallint DEFAULT 0 NOT NULL,
  [value1] int DEFAULT 0 NOT NULL,
  [value2] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [cpType] smallint DEFAULT 0 NOT NULL,
  [billingID] varchar(64) COLLATE SQL_Latin1_General_CP1_CI_AS DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] nvarchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [limitDate] int  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_buy_item_sbox] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_buy_item_special
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_buy_item_special]') AND type IN ('U'))
	DROP TABLE [dbo].[log_buy_item_special]
GO

CREATE TABLE [dbo].[log_buy_item_special] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [itemType] int DEFAULT 0 NOT NULL,
  [itemValue] int DEFAULT 0 NOT NULL,
  [eventType] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_buy_item_special] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_accessory_upgrade
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_accessory_upgrade]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_accessory_upgrade]
GO

CREATE TABLE [dbo].[log_data_accessory_upgrade] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [nowUpgradeValue] int DEFAULT 0 NOT NULL,
  [resultUpgradeValue] int DEFAULT 0 NOT NULL,
  [pieceCode] int DEFAULT 0 NOT NULL,
  [logType] tinyint DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_accessory_upgrade] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_awake
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_awake]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_awake]
GO

CREATE TABLE [dbo].[log_data_awake] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [classType] int DEFAULT 0 NOT NULL,
  [pieceCode] int DEFAULT 0 NOT NULL,
  [pieceUseCount] smallint DEFAULT 0 NOT NULL,
  [awakeType] tinyint DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_awake] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_cardmatching
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_cardmatching]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_cardmatching]
GO

CREATE TABLE [dbo].[log_data_cardmatching] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [NickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserLevel] int  NOT NULL,
  [LogType] int DEFAULT 0 NOT NULL,
  [MissionType] int DEFAULT 0 NOT NULL,
  [MissionMark1] int DEFAULT 0 NOT NULL,
  [MissionMark2] int DEFAULT 0 NOT NULL,
  [UserMark1] int DEFAULT 0 NOT NULL,
  [UserMark2] int DEFAULT 0 NOT NULL,
  [RewardStep] int DEFAULT 0 NOT NULL,
  [ItemType] int DEFAULT 0 NOT NULL,
  [ItemCode] int DEFAULT 0 NOT NULL,
  [ItemValue] int DEFAULT 0 NOT NULL,
  [RegDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_cardmatching] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_character
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_character]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_character]
GO

CREATE TABLE [dbo].[log_data_character] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [playType] int DEFAULT 0 NOT NULL,
  [modeType] int DEFAULT 0 NOT NULL,
  [subType1] int DEFAULT 0 NOT NULL,
  [subType2] int DEFAULT 0 NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL,
  [characterType] int DEFAULT 0 NOT NULL,
  [kill] int DEFAULT 0 NOT NULL,
  [death] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT 0 NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_character] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_cheating
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_cheating]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_cheating]
GO

CREATE TABLE [dbo].[log_data_cheating] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [userID] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [userIP] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [mainIDX] int DEFAULT 0 NOT NULL,
  [subIDX] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_cheating] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_clover
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_clover]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_clover]
GO

CREATE TABLE [dbo].[log_data_clover] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [friendIDX] int DEFAULT 0 NOT NULL,
  [eventType] smallint DEFAULT 0 NOT NULL,
  [CloverCount] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_clover] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_custom_medal
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_custom_medal]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_custom_medal]
GO

CREATE TABLE [dbo].[log_data_custom_medal] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int DEFAULT 0 NOT NULL,
  [MedalIDX] int DEFAULT 0 NOT NULL,
  [MedalCode] int DEFAULT 0 NOT NULL,
  [BasicGrowth1] int DEFAULT 0 NOT NULL,
  [BasicGrowth2] int DEFAULT 0 NOT NULL,
  [BasicGrowth3] int DEFAULT 0 NOT NULL,
  [BasicGrowth4] int DEFAULT 0 NOT NULL,
  [SkillGrowth1] int DEFAULT 0 NOT NULL,
  [SkillGrowth2] int DEFAULT 0 NOT NULL,
  [SkillGrowth3] int DEFAULT 0 NOT NULL,
  [SkillGrowth4] int DEFAULT 0 NOT NULL,
  [LimitType] int DEFAULT 0 NOT NULL,
  [LimitDate] datetime  NOT NULL,
  [LogType] tinyint DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_custom_medal] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_DiceGame
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_DiceGame]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_DiceGame]
GO

CREATE TABLE [dbo].[log_data_DiceGame] (
  [AccountIDX] int  NOT NULL,
  [GameState] int  NOT NULL,
  [DiceCountUsed] int  NOT NULL,
  [BoardCountUsed] int  NOT NULL,
  [RewardCountUsed] int  NOT NULL,
  [Position] int  NOT NULL,
  [Trace01] int  NOT NULL,
  [Trace02] int  NOT NULL,
  [Trace03] int  NOT NULL,
  [Trace04] int  NOT NULL,
  [Trace05] int  NOT NULL,
  [Trace06] int  NOT NULL,
  [Board] tinyint  NOT NULL,
  [RewardStep01] int  NOT NULL,
  [RewardStep02] int  NOT NULL,
  [RewardStep03] int  NOT NULL,
  [RewardStep04] int  NOT NULL,
  [RewardStep05] int  NOT NULL,
  [RewardStep06] int  NOT NULL,
  [RewardStep07] int  NOT NULL,
  [RewardStep08] int  NOT NULL,
  [RewardStep09] int  NOT NULL,
  [RewardStep10] int  NOT NULL,
  [StartTime] datetime  NULL,
  [EndTime] datetime  NULL
)
GO

ALTER TABLE [dbo].[log_data_DiceGame] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_excavating_new
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_excavating_new]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_excavating_new]
GO

CREATE TABLE [dbo].[log_data_excavating_new] (
  [RegDate] datetime  NOT NULL,
  [LogIDX] bigint  IDENTITY(1,1) NOT NULL,
  [LogType] int  NOT NULL,
  [AccountIDX] int  NOT NULL,
  [UserID] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [ExLevel] int  NOT NULL,
  [ExEXP] int  NOT NULL,
  [CType] int  NOT NULL,
  [CLevel] int  NOT NULL,
  [CExpert] int  NOT NULL,
  [RCount] tinyint  NOT NULL,
  [MapID] int  NOT NULL,
  [X] int  NOT NULL,
  [Y] int  NOT NULL,
  [Z] int  NOT NULL,
  [RewardType] int  NOT NULL,
  [Index] int  NOT NULL,
  [Price] int  NOT NULL,
  [Mutiple] int  NOT NULL,
  [ResultMoney] int  NOT NULL,
  [UserIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_excavating_new] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_gear_upgrade
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_gear_upgrade]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_gear_upgrade]
GO

CREATE TABLE [dbo].[log_data_gear_upgrade] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [gearCode] int DEFAULT 0 NOT NULL,
  [nowUpgradeValue] tinyint DEFAULT 0 NOT NULL,
  [resultUpgradeValue] tinyint DEFAULT 0 NOT NULL,
  [pieceCode] int DEFAULT 0 NOT NULL,
  [logType] tinyint DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_gear_upgrade] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_league_present
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_league_present]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_league_present]
GO

CREATE TABLE [dbo].[log_data_league_present] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [leagueIDX] int DEFAULT 0 NOT NULL,
  [currentRound] tinyint  NOT NULL,
  [presentCode1] int DEFAULT 0 NOT NULL,
  [presentCode2] int DEFAULT 0 NOT NULL,
  [presentCode3] int DEFAULT 0 NOT NULL,
  [presentCode4] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_league_present] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_localinfo
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_localinfo]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_localinfo]
GO

CREATE TABLE [dbo].[log_data_localinfo] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [os] nvarchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [ie] nvarchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [directx] nvarchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [cpu] nvarchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [gpu] nvarchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [memory] nvarchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [systemResolution] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS DEFAULT 0 NOT NULL,
  [losaResolution] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS DEFAULT 0 NOT NULL,
  [screenType] tinyint DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL,
  [hdd_serial] nvarchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS DEFAULT NULL NULL
)
GO

ALTER TABLE [dbo].[log_data_localinfo] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_matchmode
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_matchmode]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_matchmode]
GO

CREATE TABLE [dbo].[log_data_matchmode] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int  NOT NULL,
  [Tier1] int  NOT NULL,
  [Tier2] int  NOT NULL,
  [MatchTime] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL,
  [RoomNumber] int DEFAULT 0 NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_matchmode] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_matchmode2
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_matchmode2]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_matchmode2]
GO

CREATE TABLE [dbo].[log_data_matchmode2] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int  NOT NULL,
  [Tier1] int  NOT NULL,
  [Tier2] int  NOT NULL,
  [MatchTime] int DEFAULT 0 NOT NULL,
  [MatchPoint] int DEFAULT 0 NOT NULL,
  [WinningStreakCount] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [MatchType] int DEFAULT 0 NOT NULL,
  [RoomNumber] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_matchmode2] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_medal
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_medal]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_medal]
GO

CREATE TABLE [dbo].[log_data_medal] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [medalType] int  NOT NULL,
  [limitType] int  NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_medal] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_medal_extend
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_medal_extend]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_medal_extend]
GO

CREATE TABLE [dbo].[log_data_medal_extend] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [classType] int DEFAULT 0 NOT NULL,
  [slotNum] tinyint DEFAULT 0 NOT NULL,
  [period] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_medal_extend] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_oakbarrel
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_oakbarrel]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_oakbarrel]
GO

CREATE TABLE [dbo].[log_data_oakbarrel] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [NickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserLevel] int  NOT NULL,
  [ItemType] int DEFAULT 0 NOT NULL,
  [ItemCode] int DEFAULT 0 NOT NULL,
  [ItemValue] int DEFAULT 0 NOT NULL,
  [SwordCount] int DEFAULT 0 NOT NULL,
  [LogType] int DEFAULT 0 NOT NULL,
  [RegDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_oakbarrel] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_pcroom
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_pcroom]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_pcroom]
GO

CREATE TABLE [dbo].[log_data_pcroom] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [pcnum] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [pcrType] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_pcroom] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_peso
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_peso]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_peso]
GO

CREATE TABLE [dbo].[log_data_peso] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [peso] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_peso] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_pet
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_pet]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_pet]
GO

CREATE TABLE [dbo].[log_data_pet] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [petIDX] int  NOT NULL,
  [petCode] int DEFAULT 0 NOT NULL,
  [petRank] tinyint DEFAULT 0 NOT NULL,
  [petLevel] int DEFAULT 0 NOT NULL,
  [petExp] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [logType] tinyint DEFAULT 0 NOT NULL,
  [logSubType] int DEFAULT 0 NOT NULL,
  [logNote] varchar(200) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_pet] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_piece_divide
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_piece_divide]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_piece_divide]
GO

CREATE TABLE [dbo].[log_data_piece_divide] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [itemType] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [materialCode] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_piece_divide] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_piece_mix
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_piece_mix]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_piece_mix]
GO

CREATE TABLE [dbo].[log_data_piece_mix] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [mixType] smallint DEFAULT 0 NOT NULL,
  [mixCode] int DEFAULT 0 NOT NULL,
  [resultType] tinyint DEFAULT 0 NOT NULL,
  [useA] int DEFAULT 0 NOT NULL,
  [useB] int DEFAULT 0 NOT NULL,
  [resultA] int DEFAULT 0 NOT NULL,
  [resultB] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_piece_mix] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_piece_obtain
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_piece_obtain]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_piece_obtain]
GO

CREATE TABLE [dbo].[log_data_piece_obtain] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(50) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL,
  [step] tinyint DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_piece_obtain] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_play
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_play]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_play]
GO

CREATE TABLE [dbo].[log_data_play] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [playType] int DEFAULT 0 NOT NULL,
  [modeType] int DEFAULT 0 NOT NULL,
  [subType1] int DEFAULT 0 NOT NULL,
  [subType2] int DEFAULT 0 NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL,
  [deathTime] int DEFAULT 0 NOT NULL,
  [peso] int DEFAULT 0 NOT NULL,
  [win] int DEFAULT 0 NOT NULL,
  [lose] int DEFAULT 0 NOT NULL,
  [kill] int DEFAULT 0 NOT NULL,
  [death] int DEFAULT 0 NOT NULL,
  [roomNumber] int DEFAULT 0 NOT NULL,
  [contribution] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [pcnum] int DEFAULT 0 NOT NULL,
  [blueTeamMember] int DEFAULT 0 NOT NULL,
  [redTeamMember] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_play] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_play_old
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_play_old]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_play_old]
GO

CREATE TABLE [dbo].[log_data_play_old] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [playType] int DEFAULT 0 NOT NULL,
  [modeType] int DEFAULT 0 NOT NULL,
  [subType1] int DEFAULT 0 NOT NULL,
  [subType2] int DEFAULT 0 NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL,
  [deathTime] int DEFAULT 0 NOT NULL,
  [peso] int DEFAULT 0 NOT NULL,
  [win] int DEFAULT 0 NOT NULL,
  [lose] int DEFAULT 0 NOT NULL,
  [kill] int DEFAULT 0 NOT NULL,
  [death] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [pcnum] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_play_old] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_quest
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_quest]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_quest]
GO

CREATE TABLE [dbo].[log_data_quest] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [mainIDX] int DEFAULT 0 NOT NULL,
  [subIDX] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_quest] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_quest_vfun
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_quest_vfun]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_quest_vfun]
GO

CREATE TABLE [dbo].[log_data_quest_vfun] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [mainIDX] int DEFAULT 0 NOT NULL,
  [subIDX] int DEFAULT 0 NOT NULL,
  [channelingType] int  NOT NULL,
  [success] int  NOT NULL,
  [reason] varchar(256) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_quest_vfun] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_roominfo
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_roominfo]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_roominfo]
GO

CREATE TABLE [dbo].[log_data_roominfo] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [RoomNumber] int DEFAULT 0 NOT NULL,
  [BlueWin] int DEFAULT 0 NOT NULL,
  [BlueLose] int DEFAULT 0 NOT NULL,
  [BlueTeamMember] int DEFAULT 0 NOT NULL,
  [RedWin] int DEFAULT 0 NOT NULL,
  [RedLose] int DEFAULT 0 NOT NULL,
  [RedTeamMember] int DEFAULT 0 NOT NULL,
  [PlayType] int DEFAULT 0 NOT NULL,
  [ModeType] int DEFAULT 0 NOT NULL,
  [ModeSubType] int DEFAULT 0 NOT NULL,
  [RegDate] datetime DEFAULT getdate() NOT NULL,
  [Tier1] int DEFAULT 0 NOT NULL,
  [Tier2] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_roominfo] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_spirit_change
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_spirit_change]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_spirit_change]
GO

CREATE TABLE [dbo].[log_data_spirit_change] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [NickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserLevel] int  NOT NULL,
  [SetSpiritCode] int  NOT NULL,
  [SetSpiritCount] int  NOT NULL,
  [GetSpiritCode] int  NOT NULL,
  [GetSpiritCount] int  NOT NULL,
  [CriticalType] tinyint  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_spirit_change] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_spirit_divide
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_spirit_divide]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_spirit_divide]
GO

CREATE TABLE [dbo].[log_data_spirit_divide] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [NickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserLevel] int  NOT NULL,
  [HeroType] int  NOT NULL,
  [SpiritCode] int  NOT NULL,
  [SpiritCount] int  NOT NULL,
  [SoulStoneCount] int  NOT NULL,
  [CriticalType] tinyint  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_spirit_divide] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_spirit_mix
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_spirit_mix]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_spirit_mix]
GO

CREATE TABLE [dbo].[log_data_spirit_mix] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [NickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserLevel] int  NOT NULL,
  [HeroType] int  NOT NULL,
  [SpiritCode] int  NOT NULL,
  [SpiritCount] int  NOT NULL,
  [UnknownSpiritCode] int  NOT NULL,
  [UnknownSpiritCount] int  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_spirit_mix] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_spirit_obtain
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_spirit_obtain]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_spirit_obtain]
GO

CREATE TABLE [dbo].[log_data_spirit_obtain] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [NickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserLevel] int  NOT NULL,
  [SpiritCode] int  NOT NULL,
  [SpiritCount] int  NOT NULL,
  [Value] int  NOT NULL,
  [logType] tinyint  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_spirit_obtain] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_spirit_peso
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_spirit_peso]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_spirit_peso]
GO

CREATE TABLE [dbo].[log_data_spirit_peso] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [NickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserLevel] int  NOT NULL,
  [PieceCount] int  NOT NULL,
  [DimensionCount] int  NOT NULL,
  [Peso] int  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_spirit_peso] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_time
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_time]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_time]
GO

CREATE TABLE [dbo].[log_data_time] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_time] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_trade
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_trade]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_trade]
GO

CREATE TABLE [dbo].[log_data_trade] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickname] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [itemType] int DEFAULT 0 NOT NULL,
  [value1] int DEFAULT 0 NOT NULL,
  [value2] int DEFAULT 0 NOT NULL,
  [price] bigint DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [userIP] varchar(16) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [note] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_trade] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_data_tutorial
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_tutorial]') AND type IN ('U'))
	DROP TABLE [dbo].[log_data_tutorial]
GO

CREATE TABLE [dbo].[log_data_tutorial] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [step] int DEFAULT 0 NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_tutorial] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_define
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_define]') AND type IN ('U'))
	DROP TABLE [dbo].[log_define]
GO

CREATE TABLE [dbo].[log_define] (
  [objName] varchar(32) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [code] int  NOT NULL,
  [itemNameKO] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [itemNameID] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [itemNameEN] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL
)
GO

ALTER TABLE [dbo].[log_define] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_error_billing
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_error_billing]') AND type IN ('U'))
	DROP TABLE [dbo].[log_error_billing]
GO

CREATE TABLE [dbo].[log_error_billing] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [cpType] smallint DEFAULT 0 NOT NULL,
  [errType] int DEFAULT 0 NOT NULL,
  [note] varchar(200) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_error_billing] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_event_bingo
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_event_bingo]') AND type IN ('U'))
	DROP TABLE [dbo].[log_event_bingo]
GO

CREATE TABLE [dbo].[log_event_bingo] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [choiceType] tinyint DEFAULT 0 NOT NULL,
  [number] tinyint DEFAULT 0 NOT NULL,
  [stateType] tinyint DEFAULT 0 NOT NULL,
  [regDate] datetime  NOT NULL
)
GO

ALTER TABLE [dbo].[log_event_bingo] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_event_cash
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_event_cash]') AND type IN ('U'))
	DROP TABLE [dbo].[log_event_cash]
GO

CREATE TABLE [dbo].[log_event_cash] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [amount] int DEFAULT 0 NOT NULL,
  [eventType] tinyint DEFAULT 0 NOT NULL,
  [userIP] nvarchar(16) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_event_cash] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for Log_game_concurrent
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[Log_game_concurrent]') AND type IN ('U'))
	DROP TABLE [dbo].[Log_game_concurrent]
GO

CREATE TABLE [dbo].[Log_game_concurrent] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [serverID] bigint DEFAULT 0 NOT NULL,
  [serverIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [serverPort] int  NOT NULL,
  [serverName] varchar(32) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [concurrent] int DEFAULT 0 NOT NULL,
  [cpType] smallint DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[Log_game_concurrent] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for Log_play_character
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[Log_play_character]') AND type IN ('U'))
	DROP TABLE [dbo].[Log_play_character]
GO

CREATE TABLE [dbo].[Log_play_character] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [userID] varchar(12) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [playType] int DEFAULT 0 NOT NULL,
  [modeType] int DEFAULT 0 NOT NULL,
  [sub1Type] int DEFAULT 0 NOT NULL,
  [sub2Type] int DEFAULT 0 NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL,
  [characterType] int DEFAULT 0 NOT NULL,
  [cnt_kill] int DEFAULT 0 NOT NULL,
  [cnt_killed] int DEFAULT 0 NOT NULL,
  [cnt_selfkilled] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[Log_play_character] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for Log_play_game
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[Log_play_game]') AND type IN ('U'))
	DROP TABLE [dbo].[Log_play_game]
GO

CREATE TABLE [dbo].[Log_play_game] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [userID] varchar(12) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [playType] int DEFAULT 0 NOT NULL,
  [modeType] int DEFAULT 0 NOT NULL,
  [sub1Type] int DEFAULT 0 NOT NULL,
  [sub2Type] int DEFAULT 0 NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL,
  [deathTime] int DEFAULT 0 NOT NULL,
  [basicPeso] int DEFAULT 0 NOT NULL,
  [total_peso] int DEFAULT 0 NOT NULL,
  [total_emblem] int DEFAULT 0 NOT NULL,
  [total_play_num] int DEFAULT 0 NOT NULL,
  [total_round] int DEFAULT 0 NOT NULL,
  [total_contribute] int DEFAULT 0 NOT NULL,
  [total_win] int DEFAULT 0 NOT NULL,
  [total_lose] int DEFAULT 0 NOT NULL,
  [cnt_kill] int DEFAULT 0 NOT NULL,
  [cnt_killed] int DEFAULT 0 NOT NULL,
  [cnt_selfkilled] int DEFAULT 0 NOT NULL,
  [logType] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[Log_play_game] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for Log_play_tutorial
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[Log_play_tutorial]') AND type IN ('U'))
	DROP TABLE [dbo].[Log_play_tutorial]
GO

CREATE TABLE [dbo].[Log_play_tutorial] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [userID] varchar(12) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [step] int DEFAULT 0 NOT NULL,
  [playTime] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[Log_play_tutorial] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_present
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_present]') AND type IN ('U'))
	DROP TABLE [dbo].[log_present]
GO

CREATE TABLE [dbo].[log_present] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickname] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [receiveIDX] int  NOT NULL,
  [presentType] smallint DEFAULT 0 NOT NULL,
  [value1] int DEFAULT 0 NOT NULL,
  [value2] int DEFAULT 0 NOT NULL,
  [eventType] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] varchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_present] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for Log_system_info
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[Log_system_info]') AND type IN ('U'))
	DROP TABLE [dbo].[Log_system_info]
GO

CREATE TABLE [dbo].[Log_system_info] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [logType] varchar(32) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [serverIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [concurrent] int  NULL,
  [cpu] int  NULL,
  [memory] int  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[Log_system_info] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_temp_bckim
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_temp_bckim]') AND type IN ('U'))
	DROP TABLE [dbo].[log_temp_bckim]
GO

CREATE TABLE [dbo].[log_temp_bckim] (
  [accountIDX] int  NULL,
  [regdate] datetime  NULL,
  [regdate_str] varchar(10) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL
)
GO

ALTER TABLE [dbo].[log_temp_bckim] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_trace_prisoner_option
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_trace_prisoner_option]') AND type IN ('U'))
	DROP TABLE [dbo].[log_trace_prisoner_option]
GO

CREATE TABLE [dbo].[log_trace_prisoner_option] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [BlueMember] int DEFAULT 0 NOT NULL,
  [RedMember] int DEFAULT 0 NOT NULL,
  [BlueMaxMember] int DEFAULT 0 NOT NULL,
  [RedMaxMember] int DEFAULT 0 NOT NULL,
  [TeamMixOption] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL,
  [closedRoomOption] int DEFAULT 0 NOT NULL,
  [userModeOption] int DEFAULT 0 NOT NULL
)
GO

ALTER TABLE [dbo].[log_trace_prisoner_option] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_trace_prisoner_start
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_trace_prisoner_start]') AND type IN ('U'))
	DROP TABLE [dbo].[log_trace_prisoner_start]
GO

CREATE TABLE [dbo].[log_trace_prisoner_start] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [ServerID] bigint DEFAULT 0 NOT NULL,
  [MakeRoom] int DEFAULT 0 NOT NULL,
  [QuickStart] int DEFAULT 0 NOT NULL,
  [ListSelect] int DEFAULT 0 NOT NULL,
  [RegDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_trace_prisoner_start] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for Log_use_item
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[Log_use_item]') AND type IN ('U'))
	DROP TABLE [dbo].[Log_use_item]
GO

CREATE TABLE [dbo].[Log_use_item] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [nickname] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [itemType] int DEFAULT 0 NOT NULL,
  [itemCode] int DEFAULT 0 NOT NULL,
  [rowIDX] int DEFAULT 0 NOT NULL,
  [colIDX] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [note] varchar(200) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[Log_use_item] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for LosaGamelog_TEMP_QUEST_LOGIN_BCKIM
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM]') AND type IN ('U'))
	DROP TABLE [dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM]
GO

CREATE TABLE [dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM] (
  [AccountIDX] int  NOT NULL,
  [Term_05220612] int DEFAULT 0 NULL,
  [Term_06120619] int DEFAULT 0 NULL,
  [Term_05220619] int DEFAULT 0 NULL,
  [progress] int DEFAULT 0 NULL,
  [result] int DEFAULT 0 NULL
)
GO

ALTER TABLE [dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for LosaGamelog_TEMP_QUEST_LOGIN_BCKIM_logdate
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM_logdate]') AND type IN ('U'))
	DROP TABLE [dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM_logdate]
GO

CREATE TABLE [dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM_logdate] (
  [AccountIDX] int  NOT NULL,
  [logincnt] int  NOT NULL
)
GO

ALTER TABLE [dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM_logdate] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for LosaGamelog_TEMP_QUEST_LOGIN_BCKIM_progress
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM_progress]') AND type IN ('U'))
	DROP TABLE [dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM_progress]
GO

CREATE TABLE [dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM_progress] (
  [AccountIDX] int  NOT NULL,
  [progress] int  NULL
)
GO

ALTER TABLE [dbo].[LosaGamelog_TEMP_QUEST_LOGIN_BCKIM_progress] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for SQL_ERROR_LOG
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[SQL_ERROR_LOG]') AND type IN ('U'))
	DROP TABLE [dbo].[SQL_ERROR_LOG]
GO

CREATE TABLE [dbo].[SQL_ERROR_LOG] (
  [ErrorID] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [ErrorNo] int  NOT NULL,
  [ErrorProcedure] varchar(50) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [ErrorLine] int  NULL,
  [ErrorServerity] int  NULL,
  [ErrorState] int  NULL,
  [ErrorMessage] varchar(500) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [ErrorTime] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[SQL_ERROR_LOG] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for TBL_LOG_HACK
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[TBL_LOG_HACK]') AND type IN ('U'))
	DROP TABLE [dbo].[TBL_LOG_HACK]
GO

CREATE TABLE [dbo].[TBL_LOG_HACK] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [NickName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [UserLevel] int DEFAULT 0 NOT NULL,
  [PlayType] int DEFAULT 0 NOT NULL,
  [ModeType] int DEFAULT 0 NOT NULL,
  [SubType1] int DEFAULT 0 NOT NULL,
  [SubType2] int DEFAULT 0 NOT NULL,
  [ItemType] int DEFAULT 0 NOT NULL,
  [ItemCode] int DEFAULT 0 NOT NULL,
  [ItemValue] int DEFAULT 0 NOT NULL,
  [RegDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[TBL_LOG_HACK] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for TBL_LOG_HACK_MESSAGE
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[TBL_LOG_HACK_MESSAGE]') AND type IN ('U'))
	DROP TABLE [dbo].[TBL_LOG_HACK_MESSAGE]
GO

CREATE TABLE [dbo].[TBL_LOG_HACK_MESSAGE] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [AccountIDX] int  NOT NULL,
  [Msg] nvarchar(1000) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [RegDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[TBL_LOG_HACK_MESSAGE] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- procedure structure for log_data_tutorial_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_tutorial_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_tutorial_add]
GO

CREATE PROCEDURE [dbo].[log_data_tutorial_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@step int
,	@playTime int
)
As

	INSERT INTO log_data_tutorial (accountIDX, nickName, step, playTime, regDate)
	VALUES (@accountIDX, @nickName, @step, @playTime, getdate())
GO


-- ----------------------------
-- procedure structure for log_data_time_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_time_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_time_add]
GO

CREATE PROCEDURE [dbo].[log_data_time_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@playTime int
,	@logType int
)
As

	INSERT INTO log_data_time (accountIDX, nickName, playTime, logType, regDate)
	VALUES (@accountIDX, @nickName, @playTime, @logType, getdate())
GO


-- ----------------------------
-- procedure structure for log_data_spirit_peso_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_spirit_peso_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_spirit_peso_add]
GO

CREATE PROCEDURE [dbo].[log_data_spirit_peso_add]

	@ACCOUNT_IDX		INT,
	@NICK_NAME			NVARCHAR(20),
	@USER_LEVEL			INT,
	@PIECE_COUNT		INT,
	@DIMENSION_COUNT	INT,
	@GET_PESO			INT

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.log_data_spirit_peso (
		AccountIDX, NickName, UserLevel, PieceCount, DimensionCount, Peso, regDate
	)
	VALUES (
		@ACCOUNT_IDX, @NICK_NAME, @USER_LEVEL, @PIECE_COUNT, @DIMENSION_COUNT, @GET_PESO, GETDATE()
	);
GO


-- ----------------------------
-- procedure structure for log_data_spirit_obtain_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_spirit_obtain_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_spirit_obtain_add]
GO

CREATE PROCEDURE [dbo].[log_data_spirit_obtain_add]

	@ACCOUNT_IDX	INT,
	@NICK_NAME		NVARCHAR(20),
	@USER_LEVEL		INT,
	@SPIRIT_CODE	INT,
	@SPIRIT_COUNT	INT,
	@VALUE			INT,
	@LOG_TYPE		TINYINT

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.log_data_spirit_obtain (
		AccountIDX, NickName, UserLevel, SpiritCode, SpiritCount, Value, logType, regDate
	)
	VALUES (
		@ACCOUNT_IDX, @NICK_NAME, @USER_LEVEL, @SPIRIT_CODE, @SPIRIT_COUNT, @VALUE, @LOG_TYPE, GETDATE()
	);
GO


-- ----------------------------
-- procedure structure for log_data_spirit_mix_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_spirit_mix_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_spirit_mix_add]
GO

CREATE PROCEDURE [dbo].[log_data_spirit_mix_add]

	@ACCOUNT_IDX			INT,
	@NICK_NAME				NVARCHAR(20),
	@USER_LEVEL				INT,
	@HERO_TYPE				INT,
	@SPIRIT_CODE			INT,
	@SPIRIT_COUNT			INT,
	@UNKNOWN_SPIRIT_CODE	INT,
	@UNKNOWN_SPIRIT_COUNT	INT

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.log_data_spirit_mix (
		AccountIDX, NickName, UserLevel, HeroType, SpiritCode, SpiritCount, UnknownSpiritCode, UnknownSpiritCount, regDate
	)
	VALUES (
		@ACCOUNT_IDX, @NICK_NAME, @USER_LEVEL, @HERO_TYPE, @SPIRIT_CODE, @SPIRIT_COUNT, @UNKNOWN_SPIRIT_CODE, @UNKNOWN_SPIRIT_COUNT, GETDATE()
	);
GO


-- ----------------------------
-- procedure structure for log_data_spirit_divide_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_spirit_divide_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_spirit_divide_add]
GO

CREATE PROCEDURE [dbo].[log_data_spirit_divide_add]

	@ACCOUNT_IDX		INT,
	@NICK_NAME			NVARCHAR(20),
	@USER_LEVEL			INT,
	@HERO_TYPE			INT,
	@SPIRIT_CODE		INT,
	@SPIRIT_COUNT		INT,
	@SOUL_STONE_COUNT	INT,
	@CRITICAL_TYPE		TINYINT

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.log_data_spirit_divide (
		AccountIDX, NickName, UserLevel, HeroType, SpiritCode, SpiritCount, SoulStoneCount, CriticalType, regDate
	)
	VALUES (
		@ACCOUNT_IDX, @NICK_NAME, @USER_LEVEL, @HERO_TYPE, @SPIRIT_CODE, @SPIRIT_COUNT, @SOUL_STONE_COUNT, @CRITICAL_TYPE, GETDATE()
	);
GO


-- ----------------------------
-- procedure structure for log_data_spirit_change_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_spirit_change_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_spirit_change_add]
GO

CREATE PROCEDURE [dbo].[log_data_spirit_change_add]

	@ACCOUNT_IDX		INT,
	@NICK_NAME			NVARCHAR(20),
	@USER_LEVEL			INT,
	@SET_SPIRIT_CODE	INT,
	@SET_SPIRIT_COUNT	INT,
	@GET_SPIRIT_CODE	INT,
	@GET_SPIRIT_COUNT	INT,
	@CRITICAL_TYPE		TINYINT

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.log_data_spirit_change (
		AccountIDX, NickName, UserLevel, SetSpiritCode, SetSpiritCount, GetSpiritCode, GetSpiritCount, CriticalType, regDate
	)
	VALUES (
		@ACCOUNT_IDX, @NICK_NAME, @USER_LEVEL, @SET_SPIRIT_CODE, @SET_SPIRIT_COUNT, @GET_SPIRIT_CODE, @GET_SPIRIT_COUNT, @CRITICAL_TYPE, GETDATE()
	);
GO


-- ----------------------------
-- procedure structure for log_data_quest_vfun_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_quest_vfun_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_quest_vfun_add]
GO

CREATE PROCEDURE [dbo].[log_data_quest_vfun_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@userLevel int
,	@mainIDX int
,	@subIDX int
,	@channelingType int
,	@success int
,	@reason varchar(256)
)
As

	INSERT INTO log_data_quest_vfun (accountIDX, nickName, userLevel, mainIDX, subIDX, channelingType, success, reason, regDate)
	VALUES (@accountIDX, @nickName, @userLevel, @mainIDX, @subIDX, @channelingType,@success,@reason,getdate())
GO


-- ----------------------------
-- procedure structure for log_data_quest_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_quest_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_quest_add]
GO

CREATE PROCEDURE [dbo].[log_data_quest_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@userLevel int
,	@mainIDX int
,	@subIDX int
,	@logType int
)
As

	INSERT INTO log_data_quest (accountIDX, nickName, userLevel, mainIDX, subIDX, logType, regDate)
	VALUES (@accountIDX, @nickName, @userLevel, @mainIDX, @subIDX, @logType, getdate())
GO


-- ----------------------------
-- procedure structure for log_data_play_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_play_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_play_add]
GO

CREATE PROCEDURE [dbo].[log_data_play_add]

	@accountIDX			INT,
	@nickName			VARCHAR(20),
	@playType			INT,
	@modeType			INT,
	@subType1			INT,
	@subType2			INT,
	@playTime			INT,
	@deathTime			INT,
	@peso				INT,
	@win				INT,
	@lose				INT,
	@kill				INT,
	@death				INT,
	@logType			INT,
	@pcnum				INT,
	@roomNumber			INT,
	@contribution		INT,
	@blueTeamMember		INT,
	@redTeamMember		INT

AS  

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.log_data_play (
		accountIDX, nickName, playType, modeType, subType1, subType2, playTime, deathTime, peso, win, lose, [kill], death, roomNumber, contribution, logType, pcnum, blueTeamMember, redTeamMember, regDate
	)
	VALUES (
		@accountIDX, @nickName, @playType, @modeType, @subType1, @subType2, @playTime, @deathTime, @peso, @win, @lose, @kill, @death, @roomNumber, @contribution, @logType, @pcnum, @blueTeamMember, @redTeamMember, GETDATE()
	)
GO


-- ----------------------------
-- procedure structure for log_data_play_room_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_play_room_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_play_room_add]
GO

CREATE PROCEDURE [dbo].[log_data_play_room_add]      
      
 @RoomNumber   INT,      
 @BlueWin   INT,      
 @BlueLose   INT,      
 @BlueTeamMember  INT,      
 @RedWin    INT,      
 @RedLose   INT,      
 @RedTeamMember  INT,      
 @PlayType   INT,      
 @ModeType   INT,      
 @ModeSubType  INT,      
 @Tier1    INT,      
 @Tier2    INT,    
 @LogType  INT,
 @playTime INT      
      
AS          
      
SET NOCOUNT ON;      
SET LOCK_TIMEOUT 10000;      
      
INSERT INTO dbo.log_data_roominfo (      
 RoomNumber, BlueWin, BlueLose, BlueTeamMember, RedWin, RedLose, RedTeamMember, PlayType, ModeType, ModeSubType, RegDate, Tier1, Tier2, LogType, playTime      
)      
VALUES (      
 @RoomNumber, @BlueWin, @BlueLose, @BlueTeamMember, @RedWin, @RedLose, @RedTeamMember, @PlayType, @ModeType, @ModeSubType, GETDATE(), @Tier1, @Tier2, @LogType, @playTime      
)
GO


-- ----------------------------
-- procedure structure for log_data_piece_obtain_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_piece_obtain_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_piece_obtain_add]
GO

CREATE PROCEDURE [dbo].[log_data_piece_obtain_add]
(
	@accountIDX int
,	@nickName nvarchar(20)
,	@userLevel int
,	@playTime int
,	@step tinyint
,	@amount int
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_data_piece_obtain (
	accountIDX, nickName, userLevel, playTime, step, amount, regDate
)
VALUES (
	@accountIDX, @nickName, @userLevel, @playTime, @step, @amount, GETDATE()
)
GO


-- ----------------------------
-- procedure structure for log_data_piece_mix_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_piece_mix_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_piece_mix_add]
GO

CREATE PROCEDURE [dbo].[log_data_piece_mix_add]
(
	@accountIDX int
,	@nickName nvarchar(20)
,	@userLevel int
,	@mixType smallint
,	@mixCode int
,	@resultType tinyint
,	@useA int
,	@useB int
,	@resultA int
,	@resultB int
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_data_piece_mix (
	accountIDX, nickName, userLevel, mixType, mixCode, resultType, useA, useB, resultA, resultB, regDate
)
VALUES (
	@accountIDX, @nickName, @userLevel, @mixType, @mixCode, @resultType, @useA, @useB, @resultA, @resultB, GETDATE()
)
GO


-- ----------------------------
-- procedure structure for log_data_piece_divide_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_piece_divide_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_piece_divide_add]
GO

CREATE PROCEDURE [dbo].[log_data_piece_divide_add]
(
	@accountIDX int
,	@nickName nvarchar(20)
,	@userLevel int
,	@itemType int
,	@itemCode int
,	@amount int
,	@materialCode int
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_data_piece_divide (
	accountIDX, nickName, userLevel, itemType, itemCode, amount, materialCode, regDate
)
VALUES (
	@accountIDX, @nickName, @userLevel, @itemType, @itemCode, @amount, @materialCode, GETDATE()
)
GO


-- ----------------------------
-- procedure structure for log_data_pet_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_pet_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_pet_add]
GO

CREATE PROCEDURE [dbo].[log_data_pet_add]

	@ACCOUNT_IDX	INT,			-- 사용자 고유키
	@NICKNAME		NVARCHAR(20),	-- 닉네임
	@USERLEVEL		INT,			-- 유저 레벨
	@PET_IDX		INT,			-- 펫 고유키
	@PTE_CODE		INT,			-- 펫 인덱스
	@PET_RANK		TINYINT,		-- 랭크
	@PET_LEVEL		INT,			-- 레벨
	@PET_EXP		INT,			-- 경험치
	@ITEM_CODE		INT,			-- 펫 획득 가챠 코드
	@LOG_TYPE		TINYINT,		-- 로그 구분 - 1: 생성 2: 삭제 3: 장착 4: 랭크업 5: 레벨업 6: 육성 7:교배
	@LOG_SUB_TYPE	INT,			-- LogType에 해당하는 값. 없으면 0;
	@LOG_NOTE		VARCHAR(200)	-- 기타 비고란.
	
AS

	SET NOCOUNT ON
	SET LOCK_TIMEOUT 10000

	BEGIN

		INSERT dbo.log_data_pet WITH(ROWLOCK, XLOCK) (accountIDX, nickName, userLevel, petIDX, petCode, petRank, petLevel, petExp, itemCode, logType, logSubType, logNote) VALUES
		(@ACCOUNT_IDX, @NICKNAME, @USERLEVEL, @PET_IDX, @PTE_CODE, @PET_RANK, @PET_LEVEL, @PET_EXP, @ITEM_CODE, @LOG_TYPE, @LOG_SUB_TYPE, @LOG_NOTE)
	END
GO


-- ----------------------------
-- procedure structure for log_data_peso_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_peso_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_peso_add]
GO

CREATE PROCEDURE [dbo].[log_data_peso_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@peso int
,	@logType int
)
As

	INSERT INTO log_data_peso (accountIDX, nickName, peso, logType, regDate)
	VALUES (@accountIDX, @nickName, @peso, @logType, getdate())
GO


-- ----------------------------
-- procedure structure for log_data_oakbarrel_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_oakbarrel_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_oakbarrel_add]
GO

CREATE PROCEDURE [dbo].[log_data_oakbarrel_add]

	@ACCOUNT_IDX		INT,
	@NICK_NAME			NVARCHAR(20),
	@USER_LEVEL			INT,
	@ITEM_TYPE			INT,
	@ITEM_CODE			INT,
	@ITEM_VALUE			INT,
	@SWORD_COUNT		INT,
	@LOG_TYPE			INT

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO log_data_oakbarrel (AccountIDX, NickName, UserLevel, ItemType, ItemCode, ItemValue, SwordCount, LogType, RegDate)
	VALUES (@ACCOUNT_IDX, @NICK_NAME, @USER_LEVEL, @ITEM_TYPE, @ITEM_CODE, @ITEM_VALUE, @SWORD_COUNT, @LOG_TYPE, GETDATE())
GO


-- ----------------------------
-- procedure structure for log_data_pcroom_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_pcroom_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_pcroom_add]
GO

CREATE PROCEDURE [dbo].[log_data_pcroom_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@playTime int
,	@userIP varchar(15)
,	@pcnum int
,	@logType int
,	@pcrType int
)
AS

INSERT INTO log_data_pcroom (accountIDX, nickName, playTime, userIP, pcnum, logType, pcrType, regDate)
VALUES (@accountIDX, @nickName, @playTime, @userIP, @pcnum, @logType, @pcrType, getdate())
GO


-- ----------------------------
-- procedure structure for log_data_medal_extend_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_medal_extend_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_medal_extend_add]
GO

CREATE PROCEDURE [dbo].[log_data_medal_extend_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@userLevel int
,	@classType int
,	@slotNum tinyint
,	@period int
,	@logType int
)
AS

INSERT INTO dbo.log_data_medal_extend (
	accountIDX, nickName, userLevel, classType, slotNum, period, logType, regDate
)
VALUES (
	@accountIDX, @nickName, @userLevel, @classType, @slotNum, @period, @logType, getdate()
)
GO


-- ----------------------------
-- procedure structure for log_data_medal_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_medal_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_medal_add]
GO

CREATE PROCEDURE [dbo].[log_data_medal_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@medalType int
,	@limitType int
,	@logType int
)
As

	INSERT INTO log_data_medal (accountIDX, nickName, medalType, limitType, logType, regDate)
	VALUES (@accountIDX, @nickName, @medalType, @limitType, @logType, getdate())
GO


-- ----------------------------
-- procedure structure for log_data_matchmode2_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_matchmode2_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_matchmode2_add]
GO

CREATE PROCEDURE [dbo].[log_data_matchmode2_add]        
        
 @ACCOUNT_IDX   INT,        
 @NICK_NAME    NVARCHAR(20),        
 @USER_LEVEL    INT,        
 @TIER1     INT,        
 @TIER2     INT,        
 @MATCH_TIME    INT,        
 @MATCH_POINT INT,        
 @WINNING_STREAK_COUNT INT,        
 @LOG_TYPE    INT,        
 @ROOM_NUMBER   INT,  
 @MATCH_TYPE INT        
        
AS        
        
        
 SET NOCOUNT ON;        
 SET LOCK_TIMEOUT 10000;        
        
 INSERT INTO dbo.log_data_matchmode2 (AccountIDX, nickName, userLevel, Tier1, Tier2, MatchTime, MatchPoint, WinningStreakCount, logType, MatchType, RoomNumber, regDate)        
 VALUES (@ACCOUNT_IDX, @NICK_NAME, @USER_LEVEL, @TIER1, @TIER2, @MATCH_TIME, @MATCH_POINT, @WINNING_STREAK_COUNT, @LOG_TYPE, @MATCH_TYPE, @ROOM_NUMBER, GETDATE());
GO


-- ----------------------------
-- procedure structure for log_data_matchmode_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_matchmode_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_matchmode_add]
GO

CREATE PROCEDURE [dbo].[log_data_matchmode_add]

	@ACCOUNT_IDX		INT,
	@NICK_NAME			NVARCHAR(20),
	@USER_LEVEL			INT,
	@TIER1				INT,
	@TIER2				INT,
	@MATCH_TIME			INT,
	@LOG_TYPE			INT,
	@ROOM_NUMBER		INT

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.log_data_matchmode (AccountIDX, nickName, userLevel, Tier1, Tier2, MatchTime, logType, regDate, RoomNumber)
	VALUES (@ACCOUNT_IDX, @NICK_NAME, @USER_LEVEL, @TIER1, @TIER2, @MATCH_TIME, @LOG_TYPE, GETDATE(), @ROOM_NUMBER);
GO


-- ----------------------------
-- procedure structure for log_data_gear_upgrade_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_gear_upgrade_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_gear_upgrade_add]
GO

CREATE PROCEDURE [dbo].[log_data_gear_upgrade_add]
(
	@accountIDX				INT,			-- 유저 인덱스
	@nickName				NVARCHAR(20),	-- 유저 닉네임
	@userLevel				INT,			-- 유저 레벨
	@gearCode				INT,			-- 강화 장비 코드
	@nowUpgradeValue		TINYINT,		-- 업그레이드 전 강화 값
	@resultUpgradeValue		TINYINT,		-- 업그레이드 이후 강화 값
	@pieceCode				INT,			-- 조각 코드
	@logType				INT				-- 로그 구분 [1: 강화 성공, 2: 강화 실패]
)	
AS

SET NOCOUNT ON
SET LOCK_TIMEOUT 10000

BEGIN

	INSERT dbo.log_data_gear_upgrade (
		accountIDX, nickName, userLevel, gearCode, nowUpgradeValue, resultUpgradeValue, pieceCode, logType, regDate
	)
	VALUES (
		@accountIDX, @nickName, @userLevel, @gearCode, @nowUpgradeValue, @resultUpgradeValue, @pieceCode, @logType, GETDATE()
	)

END
GO


-- ----------------------------
-- procedure structure for log_data_localinfo_add_2
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_localinfo_add_2]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_localinfo_add_2]
GO

CREATE PROCEDURE [dbo].[log_data_localinfo_add_2]
(
	@accountIDX int
,	@nickName varchar(20)
,	@userLevel int
,	@os nvarchar(100)
,	@ie nvarchar(100)
,	@directx nvarchar(100)
,	@cpu nvarchar(100)
,	@gpu nvarchar(100)
,	@memory nvarchar(100)
,	@systemResolution nvarchar(20)
,	@losaResolution nvarchar(20)
,	@screenType tinyint
,	@userIP varchar(15)
,	@user_hdd_serial nvarchar(100)
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_data_localinfo (
	accountIDX, nickName, userLevel, os, ie, directx, cpu, gpu, memory, systemResolution, losaResolution, screenType, userIP, regDate, hdd_serial
)
VALUES (
	@accountIDX, @nickName, @userLevel, @os, @ie, @directx, @cpu, @gpu, @memory, @systemResolution, @losaResolution, @screenType, @userIP, GETDATE(),@user_hdd_serial
)
GO


-- ----------------------------
-- procedure structure for log_data_localinfo_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_localinfo_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_localinfo_add]
GO

CREATE PROCEDURE [dbo].[log_data_localinfo_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@userLevel int
,	@os nvarchar(100)
,	@ie nvarchar(100)
,	@directx nvarchar(100)
,	@cpu nvarchar(100)
,	@gpu nvarchar(100)
,	@memory nvarchar(100)
,	@systemResolution nvarchar(20)
,	@losaResolution nvarchar(20)
,	@screenType tinyint
,	@userIP varchar(15)
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_data_localinfo (
	accountIDX, nickName, userLevel, os, ie, directx, cpu, gpu, memory, systemResolution, losaResolution, screenType, userIP, regDate
)
VALUES (
	@accountIDX, @nickName, @userLevel, @os, @ie, @directx, @cpu, @gpu, @memory, @systemResolution, @losaResolution, @screenType, @userIP, GETDATE()
)
GO


-- ----------------------------
-- procedure structure for log_data_league_present_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_league_present_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_league_present_add]
GO

CREATE PROCEDURE [dbo].[log_data_league_present_add]
(
	@accountIDX int
,	@nickName nvarchar(20)
,	@leagueIDX int
,	@currentRound tinyint
,	@presentCode1 int
,	@presentCode2 int
,	@presentCode3 int
,	@presentCode4 int
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_data_league_present (
	accountIDX, nickName, leagueIDX, currentRound, presentCode1, presentCode2, presentCode3, presentCode4, regDate
)
VALUES (
	@accountIDX, @nickName, @leagueIDX, @currentRound, @presentCode1, @presentCode2, @presentCode3, @presentCode4, GETDATE()
)
GO


-- ----------------------------
-- procedure structure for log_data_DiceGame_update
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_DiceGame_update]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_DiceGame_update]
GO

CREATE PROCEDURE [dbo].[log_data_DiceGame_update]          
          
 @ACCOUNT_IDX		INT, 
 @Game_State		INT, 
 @DiceCountUsed		INT, 
 @BoardCountUsed	INT, 
 @RewardCountUsed	INT,  
 @Position			INT,             
 @Trace01			INT,
 @Trace02			INT,
 @Trace03			INT,
 @Trace04			INT,
 @Trace05			INT,
 @Trace06			INT,
 @Board				TINYINT,    
 @Reward01			INT,
 @Reward02			INT,
 @Reward03			INT,
 @Reward04			INT,
 @Reward05			INT,
 @Reward06			INT,
 @Reward07			INT,
 @Reward08			INT,
 @Reward09			INT,
 @Reward10			INT 
AS          
 SET NOCOUNT ON;          
 SET LOCK_TIMEOUT 10000;          
	
BEGIN TRAN
	IF EXISTS( SELECT * FROM [dbo].[log_data_DiceGame] WHERE @ACCOUNT_IDX = [AccountIDX] AND [GameState] = 0 )
		BEGIN 				
			UPDATE [dbo].[log_data_DiceGame] WITH (XLOCK, ROWLOCK) 
			SET [GameState] = @Game_State,[DiceCountUsed] = [DiceCountUsed] + @DiceCountUsed,[BoardCountUsed] = [BoardCountUsed] + @BoardCountUsed,	[RewardCountUsed] = [RewardCountUsed] + @RewardCountUsed, 
			[Position] = @Position,[Trace01] = @Trace01,[Trace02] = @Trace02,[Trace03] = @Trace03,[Trace04] = @Trace04,[Trace05] = @Trace05,[Trace06] = @Trace06,[Board] = @Board,
			[RewardStep01] = @Reward01,[RewardStep02] = @Reward02,[RewardStep03] = @Reward03,[RewardStep04] = @Reward04,[RewardStep05] = @Reward05,
			[RewardStep06] = @Reward06,[RewardStep07] = @Reward07,[RewardStep08] = @Reward08,[RewardStep09] = @Reward09,[RewardStep10] = @Reward10, [EndTime] = GETDATE()
			WHERE @ACCOUNT_IDX = [AccountIDX] AND [GameState] = 0
		END
	ELSE
		BEGIN
			INSERT INTO [dbo].[log_data_DiceGame] WITH(XLOCK, ROWLOCK) 
			([AccountIDX],[GameState],[DiceCountUsed],[BoardCountUsed],[RewardCountUsed],[Position],[Trace01],[Trace02],[Trace03],[Trace04],[Trace05],[Trace06],[Board],
			[RewardStep01],[RewardStep02],[RewardStep03],[RewardStep04],[RewardStep05],[RewardStep06],[RewardStep07],[RewardStep08],[RewardStep09],[RewardStep10],[StartTime],[EndTime] )
			VALUES ( @ACCOUNT_IDX,@Game_State,@DiceCountUsed,@BoardCountUsed,@RewardCountUsed,@Position,@Trace01,@Trace02,@Trace03,@Trace04,@Trace05,@Trace06,@Board,
			@Reward01,@Reward02,@Reward03,@Reward04,@Reward05,@Reward06,@Reward07,@Reward08,@Reward09,@Reward10, GETDATE(),GETDATE())
		END 
COMMIT TRAN
GO


-- ----------------------------
-- procedure structure for log_data_custom_medal_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_custom_medal_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_custom_medal_add]
GO

CREATE PROCEDURE [dbo].[log_data_custom_medal_add]  
  
 @ACCOUNT_IDX  INT,  
 @MEDAL_IDX   INT,  
 @MEDAL_CODE   INT,  
 @BASIC_GROWTH1  INT,  
 @BASIC_GROWTH2  INT,  
 @BASIC_GROWTH3  INT,  
 @BASIC_GROWTH4  INT,  
 @SKILL_GROWTH1  INT,  
 @SKILL_GROWTH2  INT,  
 @SKILL_GROWTH3  INT,  
 @SKILL_GROWTH4  INT,  
 @LIMIT_TYPE   INT,  
 @LIMIT_DATE   DATETIME,  
 @LOG_TYPE   TINYINT  
  
AS  
  
 SET NOCOUNT ON;  
 SET LOCK_TIMEOUT 10000;  
   
 INSERT INTO dbo.log_data_custom_medal (  
  AccountIDX, MedalIDX, MedalCode, BasicGrowth1, BasicGrowth2, BasicGrowth3, BasicGrowth4, SkillGrowth1, SkillGrowth2, SkillGrowth3, SkillGrowth4, LimitType, LimitDate, LogType, RegDate  
 )  
 VALUES (  
  @ACCOUNT_IDX, @MEDAL_IDX, @MEDAL_CODE, @BASIC_GROWTH1, @BASIC_GROWTH2, @BASIC_GROWTH3, @BASIC_GROWTH4, @SKILL_GROWTH1, @SKILL_GROWTH2, @SKILL_GROWTH3, @SKILL_GROWTH4, @LIMIT_TYPE, @LIMIT_DATE, @LOG_TYPE, GETDATE()  
 )
GO


-- ----------------------------
-- procedure structure for log_data_clover_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_clover_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_clover_add]
GO

CREATE PROCEDURE [dbo].[log_data_clover_add]
(
	@userIDX int
,	@FriendIDX int
,	@Type smallint
,	@Count int
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_data_clover( accountIDX, friendIDX, eventType, CloverCount, regDate )
VALUES( @userIDX, @FriendIDX, @Type, @Count, GETDATE() )
GO


-- ----------------------------
-- procedure structure for log_data_cheating_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_cheating_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_cheating_add]
GO

CREATE PROCEDURE [dbo].[log_data_cheating_add]

	@accountIDX		INT,
	@userID			VARCHAR(20),
	@userLevel		INT,
	@userIP			VARCHAR(20),
	@mainIDX		INT,
	@subIDX			INT 

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.log_data_cheating (
		accountIDX, userID, userLevel, userIP, mainIDX, subIDX, regDate
	)
	VALUES (
		@accountIDX, @userID, @userLevel, @userIP, @mainIDX, @subIDX, GETDATE()
	)
GO


-- ----------------------------
-- procedure structure for log_data_character_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_character_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_character_add]
GO

CREATE PROCEDURE [dbo].[log_data_character_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@playType int
,	@modeType int
,	@subType1 int
,	@subType2 int
,	@playTime int
,	@characterType int
,	@kill int
,	@death int
)
As

	INSERT INTO log_data_character (accountIDX, nickName, playType, modeType, subType1, subType2, playTime, characterType, [kill], death, regDate)
	VALUES (@accountIDX, @nickName, @playType, @modeType, @subType1, @subType2, @playTime, @characterType, @kill, @death, getdate())
GO


-- ----------------------------
-- procedure structure for log_data_cardmatching_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_cardmatching_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_cardmatching_add]
GO

CREATE PROCEDURE [dbo].[log_data_cardmatching_add]

	@ACCOUNT_IDX		INT,
	@NICK_NAME			NVARCHAR(20),
	@USER_LEVEL			INT,
	@LOG_TYPE			INT,
	
	@MISSION_TYPE		INT,
	@MISSION_MARK1		INT,
	@MISSION_MARK2		INT,
	@USER_MARK1			INT,
	@USER_MARK2			INT,
	
	@REWARD_STEP		INT,
	@ITEM_TYPE			INT,
	@ITEM_CODE			INT,
	@ITEM_VALUE			INT	
AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO log_data_cardmatching (AccountIDX, NickName,UserLevel,LogType,MissionType,MissionMark1,MissionMark2,UserMark1,UserMark2,RewardStep,ItemType,ItemCode, ItemValue,RegDate)
	VALUES (@ACCOUNT_IDX, @NICK_NAME, @USER_LEVEL, @LOG_TYPE, @MISSION_TYPE,@MISSION_MARK1,@MISSION_MARK2,@USER_MARK1,@USER_MARK2,@REWARD_STEP, @ITEM_TYPE, @ITEM_CODE, @ITEM_VALUE, GETDATE())
GO


-- ----------------------------
-- procedure structure for log_data_awake_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_awake_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_awake_add]
GO

CREATE PROCEDURE [dbo].[log_data_awake_add]
(
	@accountIDX		INT,			-- 사용자 고유키
	@nickName		NVARCHAR(20),	-- 닉네임
	@userLevel		INT,			-- 유저 레벨
	@classType		INT,			-- 용병 코드
	@pieceCode		INT,			-- 조각 코드
	@pieceUseCount	SMALLINT,		-- 사용 된 조각 개수
	@awakeType		TINYINT			-- 각성 타입 (1: 일반각성, 2: 초월각성)
)	
AS

SET NOCOUNT ON

BEGIN

INSERT dbo.log_data_awake (
	accountIDX, nickName, userLevel, classType, pieceCode, pieceUseCount, awakeType, regDate
)
VALUES 	(
	@accountIDX, @nickName, @userLevel, @classType, @pieceCode, @pieceUseCount, @awakeType, GETDATE()
)

END
GO


-- ----------------------------
-- procedure structure for log_data_accessory_upgrade_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_accessory_upgrade_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_accessory_upgrade_add]
GO

CREATE PROCEDURE [dbo].[log_data_accessory_upgrade_add]      
(      
 @accountIDX    INT,   -- 유저 인덱스      
 @nickName    NVARCHAR(20), -- 유저 닉네임      
 @userLevel    INT,   -- 유저 레벨      
 @itemCode    INT,   -- 강화 악세서리 코드    
 @nowUpgradeValue  INT,  -- 업그레이드 전 강화 값      
 @resultUpgradeValue  INT,  -- 업그레이드 이후 강화 값      
 @pieceCode    INT,   -- 강화에 사용한 악세서리 코드      
 @logType    INT    -- 로그 구분 [1: 강화 성공, 2: 강화 실패]      
)       
AS      
      
SET NOCOUNT ON      
SET LOCK_TIMEOUT 10000      
      
BEGIN      
      
 INSERT dbo.log_data_accessory_upgrade (      
  accountIDX, nickName, userLevel, itemCode, nowUpgradeValue, resultUpgradeValue, pieceCode, logType, regDate      
 )      
 VALUES (      
  @accountIDX, @nickName, @userLevel, @itemCode, @nowUpgradeValue, @resultUpgradeValue, @pieceCode, @logType, GETDATE()      
 )      
      
END
GO


-- ----------------------------
-- procedure structure for backup_log_item_gold_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[backup_log_item_gold_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[backup_log_item_gold_add]
GO

CREATE PROCEDURE [dbo].[backup_log_item_gold_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@userLevel int
,	@itemType int
,	@itemCode int
,	@itemValue int
,	@amount int
,	@cpType smallint
,	@billingID varchar(64)
,	@userIP varchar(15)
,	@note varchar(100)
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_buy_item_gold (
	accountIDX, nickname, userLevel, itemType, itemCode, itemValue, amount, cpType, billingID, userIP, note, regDate
)
VALUES (
	@accountIDX, @nickname, @userLevel, @itemType, @itemCode, @itemValue, @amount, @cpType, @billingID, @userIP, @note, GETDATE()
)
GO


-- ----------------------------
-- procedure structure for game_log_use_item
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[game_log_use_item]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[game_log_use_item]
GO

CREATE PROCEDURE [dbo].[game_log_use_item]
(
	@accountIDX int
,	@nickname varchar(12)
,	@itemType int
,	@itemCode int
,	@itemRowIDX int
,	@itemColIDX int
,	@userIP varchar(15)
,	@note varchar(200)
)
AS
	INSERT INTO Log_use_item (accountIDX, nickname, itemType, itemCode, rowIDX, colIDX, userIP, note, regDate)
	VALUES (@accountIDX, @nickname, @itemType, @itemCode, @itemRowIDX, @itemColIDX, @userIP, @note, getDate())
GO


-- ----------------------------
-- procedure structure for game_log_system_add_data
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[game_log_system_add_data]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[game_log_system_add_data]
GO

CREATE PROCEDURE [dbo].[game_log_system_add_data]
(
	@logType varchar(32)
,	@serverIP varchar(15)
,	@concurrent int
,	@cpu int
,	@memory int
)
As
	INSERT INTO Log_system_info (logType, serverIP, concurrent, cpu, memory)
	VALUES (@logType, @serverIP, @concurrent, @cpu, @memory)
GO


-- ----------------------------
-- procedure structure for game_log_play_tutorial
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[game_log_play_tutorial]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[game_log_play_tutorial]
GO

CREATE PROCEDURE [dbo].[game_log_play_tutorial]
(
	@userID varchar(12)
,	@step int
,	@playTime int
)
As

	INSERT INTO Log_play_tutorial (userID, step, playTime, regDate)
	VALUES (@userID, @step, @playTime, getdate())
GO


-- ----------------------------
-- procedure structure for game_log_play_game
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[game_log_play_game]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[game_log_play_game]
GO

CREATE PROCEDURE [dbo].[game_log_play_game]
(
	@userID varchar(12)
,	@playType int
,	@modeType int
,	@sub1Type int
,	@sub2Type int
,	@playTime int
,	@deathTime int
,	@basicPeso int
,	@total_peso int
,	@total_emblem int
,	@total_play_num int
,	@total_round int
,	@total_contribute int
,	@total_win int
,	@total_lose int
,	@cnt_kill int
,	@cnt_killed int
,	@cnt_selfkilled int
,	@logType int
)
As

	INSERT INTO Log_play_game (userID, playType, modeType, sub1Type, sub2Type, playTime, deathTime, basicPeso, total_peso, total_emblem, total_play_num, total_round, total_contribute, total_win, total_lose, cnt_kill, cnt_killed, cnt_selfkilled, logType, regDate)
	VALUES (@userID, @playType, @modeType, @sub1Type, @sub2Type, @playTime, @deathTime, @basicPeso, @total_peso, @total_emblem, @total_play_num, @total_round, @total_contribute, @total_win, @total_lose, @cnt_kill, @cnt_killed, @cnt_selfkilled, @logType, getdate())
GO


-- ----------------------------
-- procedure structure for game_log_play_character
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[game_log_play_character]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[game_log_play_character]
GO

CREATE PROCEDURE [dbo].[game_log_play_character]
(
	@userID varchar(12)
,	@playType int
,	@modeType int
,	@sub1Type int
,	@sub2Type int
,	@playTime int
,	@characterType int
,	@cnt_kill int
,	@cnt_killed int
,	@cnt_selfkilled int
)
As

	INSERT INTO Log_play_character (userID, playType, modeType, sub1Type, sub2Type, playTime, characterType, cnt_kill, cnt_killed, cnt_selfkilled, regDate)
	VALUES (@userID, @playType, @modeType, @sub1Type, @sub2Type, @playTime, @characterType, @cnt_kill, @cnt_killed, @cnt_selfkilled, getdate())
GO


-- ----------------------------
-- procedure structure for game_log_concurrent
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[game_log_concurrent]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[game_log_concurrent]
GO

CREATE PROCEDURE [dbo].[game_log_concurrent]
(
	@serverID bigint
,	@serverIP varchar(15)
,	@serverPort int
,	@serverName varchar(32)
,	@concurrent int
,	@cpType smallint
)
As

	INSERT INTO Log_game_concurrent (serverID, serverIP, serverPort, serverName, concurrent, cpType, regDate)
	VALUES (@serverID, @serverIP, @serverPort, @serverName, @concurrent, @cpType, getdate())
GO


-- ----------------------------
-- procedure structure for game_log_buy_item
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[game_log_buy_item]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[game_log_buy_item]
GO

CREATE PROCEDURE [dbo].[game_log_buy_item]
(
	@userID varchar(12)
,	@applyType char(2)
,	@amount int
,	@userIP varchar(16)
,	@playType int
,	@modeType int
,	@sub1Type int
,	@sub2Type int
,	@classType int
,	@kindred int
,	@decoType int
,	@decoCode int
,	@itemType int
,	@buyType int
,	@note varchar(100)
)
As

	INSERT INTO Log_buy_item (userID, applyType, userIP, playType, modeType, sub1Type, sub2Type, classType, kindred, decoType, decoCode, itemType, buyType, amount, note, regDate)
	VALUES (@userID, @applyType, @userIP, @playType, @modeType, @sub1Type, @sub2Type, @classType, @kindred, @decoType, @decoCode, @itemType, @buyType, @amount, @note, getdate())
GO


-- ----------------------------
-- procedure structure for game_log_buy_gold_item
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[game_log_buy_gold_item]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[game_log_buy_gold_item]
GO

CREATE PROCEDURE [dbo].[game_log_buy_gold_item]
(
	@accountIDX int
,	@nickname varchar(12)
,	@itemType int
,	@itemCode int
,	@amount int
,	@userIP varchar(15)
,	@note varchar(200)
)
AS

	INSERT INTO Log_buy_gold_item (accountIDX, nickname, itemType, itemCode, amount, userIP, note, regDate)
	VALUES (@accountIDX, @nickname, @itemType, @itemCode, @amount, @userIP, @note, getdate())
GO


-- ----------------------------
-- procedure structure for log_event_cash_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_event_cash_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_event_cash_add]
GO

CREATE PROCEDURE [dbo].[log_event_cash_add]
(
	@accountIDX int
,	@nickName nvarchar(20)
,	@userLevel int
,	@itemCode int
,	@amount int
,	@eventType tinyint
,	@userIP nvarchar(16)
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_event_cash (accountIDX, nickName, userLevel, itemCode, amount, eventType, userIP, regDate)
VALUES (@accountIDX, @nickName, @userLevel, @itemCode, @amount, @eventType, @userIP, GETDATE())
GO


-- ----------------------------
-- procedure structure for USP_LOG_HACK_SET_ADD
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[USP_LOG_HACK_SET_ADD]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[USP_LOG_HACK_SET_ADD]
GO

CREATE PROCEDURE [dbo].[USP_LOG_HACK_SET_ADD]

	@ACCOUNT_IDX	INT,
	@NICK_NAME		NVARCHAR(20),
	@USER_LEVEL		INT,
	@PLAY_TYPE		INT,
	@MODE_TYPE		INT,
	@SUB_TYPE1		INT,
	@SUB_TYPE2		INT,
	@ITEM_TYPE		INT,
	@ITEM_CODE		INT,
	@ITEM_VALUE		INT

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.TBL_LOG_HACK (
		AccountIDX, NickName, UserLevel, PlayType, ModeType, SubType1, SubType2, ItemType, ItemCode, ItemValue, RegDate
	)
	VALUES (
		@ACCOUNT_IDX, @NICK_NAME, @USER_LEVEL, @PLAY_TYPE, @MODE_TYPE, @SUB_TYPE1, @SUB_TYPE2, @ITEM_TYPE, @ITEM_CODE, @ITEM_VALUE, GETDATE()
	);
GO


-- ----------------------------
-- procedure structure for USP_LOG_HACK_MESSAGE_SET_ADD
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[USP_LOG_HACK_MESSAGE_SET_ADD]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[USP_LOG_HACK_MESSAGE_SET_ADD]
GO

CREATE PROCEDURE [dbo].[USP_LOG_HACK_MESSAGE_SET_ADD]

	@ACCOUNT_IDX	INT,
	@MSG			NVARCHAR(1000)

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.TBL_LOG_HACK_MESSAGE (
		AccountIDX, Msg, RegDate
	)
	VALUES (
		@ACCOUNT_IDX, @MSG, GETDATE()
	);
GO


-- ----------------------------
-- procedure structure for log_trace_prisoner_start_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_trace_prisoner_start_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_trace_prisoner_start_add]
GO

CREATE PROCEDURE [dbo].[log_trace_prisoner_start_add]

	@SERVER_ID		BIGINT,
	@MAKE_ROOM		INT,
	@QUICK_START	INT,
	@LIST_SELECT	INT

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.log_trace_prisoner_start (ServerID, MakeRoom, QuickStart, ListSelect, RegDate)
	VALUES (@SERVER_ID, @MAKE_ROOM, @QUICK_START, @LIST_SELECT, GETDATE())
GO


-- ----------------------------
-- procedure structure for log_view_present
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_present]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_present]
GO

CREATE PROCEDURE [dbo].[log_view_present]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, presenttype, value1, value2, eventtype, regdate
	FROM log_present WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_piece_obtain
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_piece_obtain]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_piece_obtain]
GO

CREATE PROCEDURE [dbo].[log_view_piece_obtain]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickName, userLevel, playTime, step, amount, regdate
	FROM log_data_piece_obtain WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_piece_mix
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_piece_mix]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_piece_mix]
GO

CREATE PROCEDURE [dbo].[log_view_piece_mix]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickName, userLevel, mixType, mixCode, resultType, useA, useB, resultA, resultB, regdate
	FROM log_data_piece_mix WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_piece_divide
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_piece_divide]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_piece_divide]
GO

CREATE PROCEDURE [dbo].[log_view_piece_divide]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickName, userLevel, itemType, itemCode, amount, materialCode, regdate
	FROM log_data_piece_divide WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_define_data
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_define_data]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_define_data]
GO

CREATE PROCEDURE [dbo].[log_view_define_data]
	@OBJ_NAME		VARCHAR(32)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT code, ISNULL(itemNameKO, '') AS itemNameKO, ISNULL(itemNameID, '') AS itemNameID
	FROM log_define WITH(NOLOCK)
	WHERE objName=@OBJ_NAME
	ORDER BY code ASC
END
GO


-- ----------------------------
-- procedure structure for log_view_data_trade
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_data_trade]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_data_trade]
GO

CREATE PROCEDURE [dbo].[log_view_data_trade]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, itemType, value1, value2, price, logType, userIP, note, regdate
	FROM log_data_trade WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_data_time
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_data_time]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_data_time]
GO

CREATE PROCEDURE [dbo].[log_view_data_time]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, playtime, logtype, regdate
	FROM log_data_time WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_data_quest
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_data_quest]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_data_quest]
GO

CREATE PROCEDURE [dbo].[log_view_data_quest]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, userlevel, mainidx, subidx, logtype, regdate
	FROM log_data_quest WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_data_play
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_data_play]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_data_play]
GO

CREATE PROCEDURE [dbo].[log_view_data_play]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, playtype, modetype, subtype1, subtype2, playtime, deathtime, peso, win, lose, [kill], death, logtype, pcnum, regdate
	FROM log_data_play WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_data_peso
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_data_peso]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_data_peso]
GO

CREATE PROCEDURE [dbo].[log_view_data_peso]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, peso, logtype, regdate
	FROM log_data_peso WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_data_medal
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_data_medal]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_data_medal]
GO

CREATE PROCEDURE [dbo].[log_view_data_medal]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, medalType, limitType, logType, regdate
	FROM log_data_medal WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_buy_special
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_buy_special]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_buy_special]
GO

CREATE PROCEDURE [dbo].[log_view_buy_special]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, itemtype, itemValue, eventtype, amount, userip, note, regdate
	FROM log_buy_item_special WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_buy_sbox
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_buy_sbox]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_buy_sbox]
GO

CREATE PROCEDURE [dbo].[log_view_buy_sbox]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, userLevel, presentType, value1, value2, amount, cpType, billingID, logType, userIP, note, limitDate, regdate
	FROM log_buy_item_sbox WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_buy_gold
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_buy_gold]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_buy_gold]
GO

CREATE PROCEDURE [dbo].[log_view_buy_gold]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, userLevel, itemType, itemCode, itemValue, amount, cpType, billingID, userIP, note, regdate
	FROM log_buy_item_gold WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_buy_equip
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_buy_equip]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_buy_equip]
GO

CREATE PROCEDURE [dbo].[log_view_buy_equip]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, itemtype, itemcode, reinforce, machinetype, limitdate, eventtype, amount, userip, note, regdate
	FROM log_buy_item_equip WITH(NOLOCK)
	WHERE 
		CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_buy_deco
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_buy_deco]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_buy_deco]
GO

CREATE PROCEDURE [dbo].[log_view_buy_deco]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, classtype, kindred, itemtype, itemcode, eventtype, amount, userip, note, regdate
	FROM log_buy_item_decoration WITH(NOLOCK)
	WHERE CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_view_buy_class
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_view_buy_class]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_view_buy_class]
GO

CREATE PROCEDURE [dbo].[log_view_buy_class]
	@SEARCH_NICK		VARCHAR(20),
	@SEARCH_SDATE		VARCHAR(10),
	@SEARCH_EDATE		VARCHAR(10)
AS
BEGIN
	SET NOCOUNT ON;

	SELECT TOP 1000 accountIdx, nickname, classtype, limittype, eventtype, amount, userip, note, regdate
	FROM log_buy_item_class WITH(NOLOCK)
	WHERE CASE WHEN @SEARCH_NICK='' THEN '' ELSE nickname END = @SEARCH_NICK
		AND regdate >= @SEARCH_SDATE AND regdate < DATEADD(day, 1, @SEARCH_EDATE)
	ORDER BY idx DESC
END
GO


-- ----------------------------
-- procedure structure for log_item_special_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_item_special_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_item_special_add]
GO

CREATE PROCEDURE [dbo].[log_item_special_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@itemType int
,	@itemValue int
,	@eventType int
,	@amount int
,	@userIP varchar(15)
,	@note varchar(100)
)
AS
	INSERT INTO log_buy_item_special (accountIDX, nickName, itemType, itemValue, eventType, amount, userIP, note, regDate)
	VALUES (@accountIDX, @nickName, @itemType, @itemValue, @eventType, @amount, @userIP, @note, getdate())
GO


-- ----------------------------
-- procedure structure for log_item_sbox_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_item_sbox_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_item_sbox_add]
GO

CREATE PROCEDURE [dbo].[log_item_sbox_add]
(
	@accountIDX INT
,	@nickName NVARCHAR(20)
,	@userLevel INT
,	@presentType SMALLINT
,	@value1 INT
,	@value2 INT
,	@amount INT
,	@cpType INT
,	@billingID VARCHAR(64)
,	@logType INT
,	@userIP VARCHAR(15)
,	@note NVARCHAR(100)
,	@limitDate INT
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_buy_item_sbox (
	accountIDX, nickName, userLevel, presentType, value1, value2, amount, cpType, billingID, logType, userIP, note, limitDate, regDate
)
VALUES (
	@accountIDX, @nickName, @userLevel, @presentType, @value1, @value2, @amount, @cpType, @billingID, @logType, @userIP, @note, @limitDate, GETDATE()
)
GO


-- ----------------------------
-- procedure structure for log_item_gold_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_item_gold_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_item_gold_add]
GO

CREATE PROCEDURE [dbo].[log_item_gold_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@userLevel int
,	@itemType int
,	@itemCode int
,	@itemValue int
,	@amount int
,	@cpType smallint
,	@billingID varchar(64)
,	@userIP varchar(15)
,	@note varchar(100)
,	@buyType tinyint
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_buy_item_gold (
	accountIDX, nickname, userLevel, itemType, itemCode, itemValue, amount, cpType, billingID, buyType, userIP, note, regDate
)
VALUES (
	@accountIDX, @nickname, @userLevel, @itemType, @itemCode, @itemValue, @amount, @cpType, @billingID, @buyType, @userIP, @note, GETDATE()
)
GO


-- ----------------------------
-- procedure structure for log_item_equip_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_item_equip_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_item_equip_add]
GO

CREATE PROCEDURE [dbo].[log_item_equip_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@itemType int
,	@itemCode int
,	@reinforce int
,	@machineType int
,	@limitDate int
,	@eventType int
,	@amount int
,	@userIP varchar(15)
,	@note varchar(100)
)
AS
	INSERT INTO log_buy_item_equip (accountIDX, nickName, itemType, itemCode, reinforce, machineType, limitDate, eventType, amount, userIP, note, regDate)
	VALUES (@accountIDX, @nickName, @itemType, @itemCode, @reinforce, @machineType, @limitDate, @eventType, @amount, @userIP, @note, getdate())
GO


-- ----------------------------
-- procedure structure for log_item_decoration_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_item_decoration_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_item_decoration_add]
GO

CREATE PROCEDURE [dbo].[log_item_decoration_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@classType int
,	@kindred int
,	@itemType int
,	@itemCode int
,	@eventType int
,	@amount int
,	@userIP varchar(15)
,	@note varchar(100)
)
AS
	INSERT INTO log_buy_item_decoration (accountIDX, nickName, classType, kindred, itemType, itemCode, eventType, amount, userIP, note, regDate)
	VALUES (@accountIDX, @nickName, @classType, @kindred, @itemType, @itemCode, @eventType, @amount, @userIP, @note, getdate())
GO


-- ----------------------------
-- procedure structure for log_item_costume_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_item_costume_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_item_costume_add]
GO

CREATE PROCEDURE [dbo].[log_item_costume_add]
(
	@accountIDX INT
,	@nickName NVARCHAR(20)
,	@userLevel INT
,	@itemCode INT
,	@eventType INT
,	@amount INT
,	@userIP VARCHAR(15)
,	@note VARCHAR(100)
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_buy_item_costume (
	accountIDX, nickName, userLevel, itemCode, eventType, amount, userIP, note, regDate
)
VALUES (
	@accountIDX, @nickName, @userLevel, @itemCode, @eventType, @amount, @userIP, @note, GETDATE()
)
GO


-- ----------------------------
-- procedure structure for log_item_class_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_item_class_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_item_class_add]
GO

CREATE PROCEDURE [dbo].[log_item_class_add]
(
	@accountIDX int
,	@nickName varchar(20)
,	@userLevel int
,	@classType int
,	@limitType int
,	@eventType int
,	@amount int
,	@userIP varchar(15)
,	@note varchar(100)
)
AS
	INSERT INTO log_buy_item_class (accountIDX, nickName, userLevel, classType, limitType, eventType, amount, userIP, note, regDate)
	VALUES (@accountIDX, @nickName, @userLevel, @classType, @limitType, @eventType, @amount, @userIP, @note, getdate())
GO


-- ----------------------------
-- procedure structure for log_item_accessory_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_item_accessory_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_item_accessory_add]
GO

CREATE PROCEDURE [dbo].[log_item_accessory_add]

	@accountIDX		INT,
	@nickName		NVARCHAR(20),
	@userLevel		INT,
	@itemCode		INT,
	@eventType		INT,
	@amount			INT,
	@userIP			VARCHAR(15),
	@note			VARCHAR(100)

AS

SET NOCOUNT ON;

INSERT INTO dbo.log_buy_item_accessory (
	accountIDX, nickName, userLevel, itemCode, eventType, amount, userIP, note, regDate
)
VALUES (
	@accountIDX, @nickName, @userLevel, @itemCode, @eventType, @amount, @userIP, @note, GETDATE()
)
GO


-- ----------------------------
-- procedure structure for log_event_bingo_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_event_bingo_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_event_bingo_add]
GO

CREATE PROCEDURE [dbo].[log_event_bingo_add]
(
	@accountIDX int
,	@nickName	nvarchar( 20 )
,	@choiceType tinyint
,	@number		tinyint
,	@stateType	tinyint
)
AS

SET NOCOUNT ON

INSERT INTO dbo.log_event_bingo (accountIDX, nickName, choiceType, number, stateType, regDate)
VALUES (@accountIDX, @nickName, @choiceType, @number, @stateType, GETDATE())
GO


-- ----------------------------
-- procedure structure for log_data_trade_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_trade_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_trade_add]
GO

CREATE PROCEDURE [dbo].[log_data_trade_add]
(
	@accountIDX int
,	@nickname varchar(20)
,	@itemType int
,	@value1 int
,	@value2 int
,	@price bigint
,	@logType int
,	@userIP varchar(16)
,	@note varchar(100)
)
AS

	INSERT INTO log_data_trade (accountIDX, nickname, itemType, value1, value2, price, logType, userIP, note, regDate)
	VALUES (@accountIDX, @nickName, @itemType, @value1, @value2, @price, @logType, @userIP, @note, getdate())
GO


-- ----------------------------
-- procedure structure for log_errorLog_set_log
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_errorLog_set_log]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_errorLog_set_log]
GO

CREATE PROCEDURE [dbo].[log_errorLog_set_log]

	@ACCOUNT_IDX		INT

AS
		
	SET NOCOUNT ON
	
	DECLARE @ERROR_NO			INT
	DECLARE @ERROR_PROC			VARCHAR(50)
	DECLARE @ERROR_LINE			INT
	DECLARE @ERROR_SEVERITY		INT
	DECLARE @ERROR_STATE		INT
	DECLARE @ERROR_MESSAGE		VARCHAR(500)
				
	SELECT  @ERROR_NO		= ERROR_NUMBER(), 
			@ERROR_PROC		= ERROR_PROCEDURE(), 
			@ERROR_LINE		= ERROR_LINE(), 
			@ERROR_SEVERITY	= ERROR_SEVERITY(), 
			@ERROR_STATE	= ERROR_STATE(), 
			@ERROR_MESSAGE	= ERROR_MESSAGE()


	BEGIN TRAN

		INSERT dbo.SQL_ERROR_LOG VALUES 
		(@ACCOUNT_IDX, @ERROR_NO, @ERROR_PROC, @ERROR_LINE, @ERROR_SEVERITY, @ERROR_STATE, @ERROR_MESSAGE, GETDATE())

	COMMIT TRAN
	
	RETURN 1
GO


-- ----------------------------
-- procedure structure for log_error_billing_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_error_billing_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_error_billing_add]
GO

CREATE PROCEDURE [dbo].[log_error_billing_add]
(
	@cpType smallint
,	@errType int
,	@note varchar(200)
)
AS
	INSERT INTO log_error_billing (cpType, errType, note, regDate)
	VALUES (@cpType, @errType, @note, getdate())
GO


-- ----------------------------
-- procedure structure for log_present_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_present_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_present_add]
GO

CREATE PROCEDURE [dbo].[log_present_add]
(
	@accountIDX int
,	@nickname varchar(20)
,	@receiveIDX int
,	@presentType smallint
,	@value1 int
,	@value2 int
,	@eventType int
,	@userIP varchar(15)
,	@note varchar(100)
)
AS

	INSERT INTO log_present (accountIDX, nickname, receiveIDX, presentType, value1, value2, eventType, userIP, note, regDate)
	VALUES (@accountIDX, @nickName, @receiveIDX, @presentType, @value1, @value2, @eventType, @userIP, @note, getdate())
GO


-- ----------------------------
-- procedure structure for log_trace_prisoner_option_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_trace_prisoner_option_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_trace_prisoner_option_add]
GO

CREATE PROCEDURE [dbo].[log_trace_prisoner_option_add]

	@BLUE_MEMBER			INT,
	@RED_MEMBER				INT,
	@BLUE_MAX_MEMBER		INT,
	@RED_MAX_MEMBER			INT,
	@TEAM_MIX_OPTION		INT

AS

	SET NOCOUNT ON;
	SET LOCK_TIMEOUT 10000;

	INSERT INTO dbo.log_trace_prisoner_option (BlueMember, RedMember, BlueMaxMember, RedMaxMember, TeamMixOption, RegDate)
	VALUES (@BLUE_MEMBER, @RED_MEMBER, @BLUE_MAX_MEMBER, @RED_MAX_MEMBER, @TEAM_MIX_OPTION, GETDATE())
GO


-- ----------------------------
-- procedure structure for log_Excavating_log_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_Excavating_log_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_Excavating_log_add]
GO

CREATE PROCEDURE [dbo].[log_Excavating_log_add]

	@LOG_TYPE		INT,		
	@ACCOUNT_IDX	INT,
	@USER_ID		VARCHAR(20),	
	@USER_NAME		VARCHAR(20),
	@USER_EX_LEVEL	INT,
	
	@USER_EX_EXP	INT,
	@CLASS_TYPE		INT,
	@CLASS_LEVEL	INT,	
	@CLASS_EXPERT	INT,
	@REMAIN_COUNT	INT,
	
	@MAP_ID			INT,
	@X				INT,
	@Y				INT,
	@Z				INT,
	@REWARD_TYPE	INT,	
	
	@INDEX			INT,
	@PRICE			INT,
	@MULIPLE		INT,
	@RESULT_MONEY	BIGINT,
	@USER_IP		VARCHAR(15)	
AS

	SET NOCOUNT ON
	SET LOCK_TIMEOUT 10000

	DECLARE @REG_DATE			DATETIME
	SET @REG_DATE=GETDATE()

	BEGIN TRY
		
		BEGIN TRAN
			INSERT dbo.log_data_excavating_new WITH (XLOCK, ROWLOCK) ([RegDate],	
			[LogType],[AccountIDX],[UserID],[UserName],[ExLevel],
			[ExEXP],[CType],[CLevel],[CExpert],[RCount],
			[MapID],[X],[Y],[Z],[RewardType],
			[Index],[Price],[Mutiple],[ResultMoney],[UserIP] )
			VALUES (@REG_DATE, 
			@LOG_TYPE,@ACCOUNT_IDX,@USER_ID, @USER_NAME,@USER_EX_LEVEL,
			@USER_EX_EXP,@CLASS_TYPE,@CLASS_LEVEL,@CLASS_EXPERT,@REMAIN_COUNT,	
			@MAP_ID,@X,@Y,@Z,@REWARD_TYPE,
			@INDEX,@PRICE,@MULIPLE,@RESULT_MONEY,@USER_IP
			)
		COMMIT TRAN
				
	END TRY
	BEGIN CATCH

		ROLLBACK TRAN				
		EXEC dbo.log_errorLog_set_log @ACCOUNT_IDX
		RETURN -1

	END CATCH

	RETURN 0;
GO


-- ----------------------------
-- procedure structure for log_gameLog_set_log
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_gameLog_set_log]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_gameLog_set_log]
GO

CREATE PROCEDURE [dbo].[log_gameLog_set_log]

	@LOG_TYPE			INT,
	@ACCOUNT_IDX		INT,
	@USER_ID			VARCHAR(20),
	@USER_NAME			VARCHAR(20),
	@USER_LEVEL			INT,
	@USER_EXP			INT,
	@CHANNEL_TYPE		INT,
	@TBL_INDEX			INT,
	@OBJECT_CODE		INT,
	@EVENT_TYPE			TINYINT,	
	@PARAM_1			INT,
	@PARAM_2			INT,
	@PARAM_3			INT,
	@PARAM_4			INT,
	@PARAM_5			VARCHAR(50),
	@USER_IP			VARCHAR(15)
	
AS

	SET NOCOUNT ON
	SET LOCK_TIMEOUT 10000

	DECLARE @nReturn			INT	
	DECLARE @REG_DATE			DATETIME

	SET @nReturn=0			-- True
	SET @REG_DATE=GETDATE()

	

	BEGIN TRY
		
		BEGIN TRAN
			INSERT dbo.GAME_LOG WITH (XLOCK, ROWLOCK) (RegDate, LogType, AccountIDX, UserID, UserName, UserLevel, UserExp, CpType, TBLIDX, ObjCode, EventType, Param1, Param2, Param3, Param4, Param5, UserIP)
			VALUES (@REG_DATE, @LOG_TYPE, @ACCOUNT_IDX, @USER_ID, @USER_NAME, @USER_LEVEL, @USER_EXP, @CHANNEL_TYPE, @TBL_INDEX, @OBJECT_CODE, @EVENT_TYPE, @PARAM_1, @PARAM_2, @PARAM_3, @PARAM_4, @PARAM_5, @USER_IP)
		COMMIT TRAN
				
	END TRY
	BEGIN CATCH

		ROLLBACK TRAN				
		EXEC dbo.log_errorLog_set_log @ACCOUNT_IDX
		RETURN -1

	END CATCH

	RETURN 0;
GO


-- ----------------------------
-- procedure structure for game_mission_data_delete
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[game_mission_data_delete]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[game_mission_data_delete]
GO

CREATE PROCEDURE [dbo].[game_mission_data_delete]          
 @YEAR VARCHAR(5),  
 @MONTH VARCHAR(5),  
 @DAY    VARCHAR(5)  
AS          
          
 DECLARE @REG_DATE VARCHAR(20)  
 SET @REG_DATE = @YEAR+'-'+@MONTH+'-'+@DAY  
 SET NOCOUNT ON;          
 SET LOCK_TIMEOUT 10000;          
    
  DELETE FROM dbo.userMissionDB WHERE RegDate < @REG_DATE
GO


-- ----------------------------
-- Auto increment value for GAME_LOG
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[GAME_LOG]', RESEED, 594)
GO


-- ----------------------------
-- Primary Key structure for table GAME_LOG
-- ----------------------------
ALTER TABLE [dbo].[GAME_LOG] ADD CONSTRAINT [PK_GAME_LOG_LogIndex] PRIMARY KEY CLUSTERED ([RegDate], [LogIDX])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for Log_buy_gold_item
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[Log_buy_gold_item]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for Log_buy_item
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[Log_buy_item]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table Log_buy_item
-- ----------------------------
CREATE CLUSTERED INDEX [idx_regDate]
ON [dbo].[Log_buy_item] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [idx_userID]
ON [dbo].[Log_buy_item] (
  [userID] ASC
)
GO


-- ----------------------------
-- Auto increment value for log_buy_item_accessory
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_buy_item_accessory]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_buy_item_accessory
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_log_buy_item_accessory_accountIDX]
ON [dbo].[log_buy_item_accessory] (
  [accountIDX] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_buy_item_accessory
-- ----------------------------
ALTER TABLE [dbo].[log_buy_item_accessory] ADD CONSTRAINT [PK_log_buy_item_accessory] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_buy_item_class
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_buy_item_class]', RESEED, 5)
GO


-- ----------------------------
-- Auto increment value for log_buy_item_costume
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_buy_item_costume]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_buy_item_costume
-- ----------------------------
CREATE CLUSTERED INDEX [CL_log_buy_item_costume]
ON [dbo].[log_buy_item_costume] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [NC_log_buy_item_costume_accountIDX]
ON [dbo].[log_buy_item_costume] (
  [accountIDX] ASC
)
GO


-- ----------------------------
-- Auto increment value for log_buy_item_decoration
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_buy_item_decoration]', RESEED, 36)
GO


-- ----------------------------
-- Auto increment value for log_buy_item_equip
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_buy_item_equip]', RESEED, 55)
GO


-- ----------------------------
-- Auto increment value for log_buy_item_gold
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_buy_item_gold]', RESEED, 33)
GO


-- ----------------------------
-- Auto increment value for log_buy_item_sbox
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_buy_item_sbox]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_buy_item_special
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_buy_item_special]', RESEED, 174)
GO


-- ----------------------------
-- Auto increment value for log_data_accessory_upgrade
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_accessory_upgrade]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_data_awake
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_awake]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_awake
-- ----------------------------
CREATE CLUSTERED INDEX [CI_log_data_awake]
ON [dbo].[log_data_awake] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [NC_log_data_awake_accountIDX]
ON [dbo].[log_data_awake] (
  [accountIDX] ASC
)
GO

CREATE NONCLUSTERED INDEX [NC_log_data_awake_idx]
ON [dbo].[log_data_awake] (
  [idx] ASC
)
GO


-- ----------------------------
-- Auto increment value for log_data_cardmatching
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_cardmatching]', RESEED, 3)
GO


-- ----------------------------
-- Primary Key structure for table log_data_cardmatching
-- ----------------------------
ALTER TABLE [dbo].[log_data_cardmatching] ADD CONSTRAINT [PK_log_data_cardmatching] PRIMARY KEY CLUSTERED ([RegDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_character
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_character]', RESEED, 22)
GO


-- ----------------------------
-- Auto increment value for log_data_cheating
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_cheating]', RESEED, 14)
GO


-- ----------------------------
-- Indexes structure for table log_data_cheating
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_log_data_cheating_accountIDX]
ON [dbo].[log_data_cheating] (
  [accountIDX] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_data_cheating
-- ----------------------------
ALTER TABLE [dbo].[log_data_cheating] ADD CONSTRAINT [PK_log_data_cheating] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_clover
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_clover]', RESEED, 8)
GO


-- ----------------------------
-- Indexes structure for table log_data_clover
-- ----------------------------
CREATE CLUSTERED INDEX [idx_regDate]
ON [dbo].[log_data_clover] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [idx_accountIDX]
ON [dbo].[log_data_clover] (
  [accountIDX] ASC
)
GO

CREATE NONCLUSTERED INDEX [idx_eventType]
ON [dbo].[log_data_clover] (
  [eventType] ASC
)
GO


-- ----------------------------
-- Auto increment value for log_data_custom_medal
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_custom_medal]', RESEED, 1)
GO


-- ----------------------------
-- Primary Key structure for table log_data_custom_medal
-- ----------------------------
ALTER TABLE [dbo].[log_data_custom_medal] ADD CONSTRAINT [PK_log_data_custom_medal] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_excavating_new
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_excavating_new]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_excavating_new
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_log_data_excavating_new_AccountIDX]
ON [dbo].[log_data_excavating_new] (
  [AccountIDX] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_data_excavating_new
-- ----------------------------
ALTER TABLE [dbo].[log_data_excavating_new] ADD CONSTRAINT [PK_log_data_excavating_new_idx] PRIMARY KEY CLUSTERED ([RegDate], [LogIDX])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_gear_upgrade
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_gear_upgrade]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_gear_upgrade
-- ----------------------------
CREATE CLUSTERED INDEX [CL_log_data_gear_upgrade]
ON [dbo].[log_data_gear_upgrade] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [NC_log_data_pet_accountIDX]
ON [dbo].[log_data_gear_upgrade] (
  [accountIDX] ASC
)
GO

CREATE NONCLUSTERED INDEX [NC_log_data_pet_idx]
ON [dbo].[log_data_gear_upgrade] (
  [idx] ASC
)
GO


-- ----------------------------
-- Auto increment value for log_data_league_present
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_league_present]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_data_localinfo
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_localinfo]', RESEED, 82)
GO


-- ----------------------------
-- Auto increment value for log_data_matchmode
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_matchmode]', RESEED, 1)
GO


-- ----------------------------
-- Primary Key structure for table log_data_matchmode
-- ----------------------------
ALTER TABLE [dbo].[log_data_matchmode] ADD CONSTRAINT [PK_log_data_matchmode] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_matchmode2
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_matchmode2]', RESEED, 1)
GO


-- ----------------------------
-- Primary Key structure for table log_data_matchmode2
-- ----------------------------
ALTER TABLE [dbo].[log_data_matchmode2] ADD CONSTRAINT [PK_log_data_matchmode2] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_medal
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_medal]', RESEED, 11)
GO


-- ----------------------------
-- Indexes structure for table log_data_medal
-- ----------------------------
CREATE CLUSTERED INDEX [idx_regDate]
ON [dbo].[log_data_medal] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [idx_accountIDX]
ON [dbo].[log_data_medal] (
  [accountIDX] ASC
)
GO

CREATE NONCLUSTERED INDEX [idx_eventType]
ON [dbo].[log_data_medal] (
  [logType] ASC
)
GO


-- ----------------------------
-- Auto increment value for log_data_medal_extend
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_medal_extend]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_data_oakbarrel
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_oakbarrel]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_oakbarrel
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_log_data_oakbarrel_accountIDX]
ON [dbo].[log_data_oakbarrel] (
  [AccountIDX] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_data_oakbarrel
-- ----------------------------
ALTER TABLE [dbo].[log_data_oakbarrel] ADD CONSTRAINT [PK_log_data_oakbarrel] PRIMARY KEY CLUSTERED ([RegDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_pcroom
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_pcroom]', RESEED, 146)
GO


-- ----------------------------
-- Auto increment value for log_data_peso
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_peso]', RESEED, 283)
GO


-- ----------------------------
-- Auto increment value for log_data_pet
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_pet]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_pet
-- ----------------------------
CREATE CLUSTERED INDEX [CI_log_data_pet]
ON [dbo].[log_data_pet] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [NX_log_data_pet_accountIDX]
ON [dbo].[log_data_pet] (
  [accountIDX] ASC
)
GO

CREATE NONCLUSTERED INDEX [NX_log_data_pet_idx]
ON [dbo].[log_data_pet] (
  [idx] ASC
)
GO


-- ----------------------------
-- Auto increment value for log_data_piece_divide
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_piece_divide]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_data_piece_mix
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_piece_mix]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_data_piece_obtain
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_piece_obtain]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_data_play
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_play]', RESEED, 22)
GO


-- ----------------------------
-- Indexes structure for table log_data_play
-- ----------------------------
CREATE NONCLUSTERED INDEX [NX_log_data_play_accountIDX]
ON [dbo].[log_data_play] (
  [accountIDX] ASC
)
GO

CREATE NONCLUSTERED INDEX [NX_log_data_play_logType]
ON [dbo].[log_data_play] (
  [logType] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_data_play
-- ----------------------------
ALTER TABLE [dbo].[log_data_play] ADD CONSTRAINT [PK_log_data_play_regDate] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_play_old
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_play_old]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_data_quest
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_quest]', RESEED, 473)
GO


-- ----------------------------
-- Auto increment value for log_data_quest_vfun
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_quest_vfun]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_data_roominfo
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_roominfo]', RESEED, 2)
GO


-- ----------------------------
-- Primary Key structure for table log_data_roominfo
-- ----------------------------
ALTER TABLE [dbo].[log_data_roominfo] ADD CONSTRAINT [PK_log_data_roominfo] PRIMARY KEY CLUSTERED ([RegDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_spirit_change
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_spirit_change]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_spirit_change
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_log_data_spirit_change_AccountIDX]
ON [dbo].[log_data_spirit_change] (
  [AccountIDX] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_data_spirit_change
-- ----------------------------
ALTER TABLE [dbo].[log_data_spirit_change] ADD CONSTRAINT [PK_log_data_spirit_change] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_spirit_divide
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_spirit_divide]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_spirit_divide
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_log_data_spirit_divide_AccountIDX]
ON [dbo].[log_data_spirit_divide] (
  [AccountIDX] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_data_spirit_divide
-- ----------------------------
ALTER TABLE [dbo].[log_data_spirit_divide] ADD CONSTRAINT [PK_log_data_spirit_divide] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_spirit_mix
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_spirit_mix]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_spirit_mix
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_log_data_spirit_mix_AccountIDX]
ON [dbo].[log_data_spirit_mix] (
  [AccountIDX] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_data_spirit_mix
-- ----------------------------
ALTER TABLE [dbo].[log_data_spirit_mix] ADD CONSTRAINT [PK_log_data_spirit_mix] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_spirit_obtain
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_spirit_obtain]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_spirit_obtain
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_log_data_spirit_obtain_AccountIDX]
ON [dbo].[log_data_spirit_obtain] (
  [AccountIDX] ASC,
  [logType] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_data_spirit_obtain
-- ----------------------------
ALTER TABLE [dbo].[log_data_spirit_obtain] ADD CONSTRAINT [PK_log_data_spirit_obtain] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_spirit_peso
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_spirit_peso]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_spirit_peso
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_log_data_spirit_peso_AccountIDX]
ON [dbo].[log_data_spirit_peso] (
  [AccountIDX] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_data_spirit_peso
-- ----------------------------
ALTER TABLE [dbo].[log_data_spirit_peso] ADD CONSTRAINT [PK_log_data_spirit_peso] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_data_time
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_time]', RESEED, 83)
GO


-- ----------------------------
-- Auto increment value for log_data_trade
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_trade]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_data_tutorial
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_tutorial]', RESEED, 1)
GO


-- ----------------------------
-- Primary Key structure for table log_define
-- ----------------------------
ALTER TABLE [dbo].[log_define] ADD CONSTRAINT [PK_define_manage] PRIMARY KEY CLUSTERED ([objName], [code])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_error_billing
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_error_billing]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_event_bingo
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_event_bingo]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_event_cash
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_event_cash]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for Log_game_concurrent
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[Log_game_concurrent]', RESEED, 67218)
GO


-- ----------------------------
-- Indexes structure for table Log_game_concurrent
-- ----------------------------
CREATE CLUSTERED INDEX [idx_regDate]
ON [dbo].[Log_game_concurrent] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO


-- ----------------------------
-- Auto increment value for Log_play_character
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[Log_play_character]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table Log_play_character
-- ----------------------------
CREATE CLUSTERED INDEX [idx_regDate]
ON [dbo].[Log_play_character] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [idx_userID]
ON [dbo].[Log_play_character] (
  [userID] ASC
)
GO


-- ----------------------------
-- Auto increment value for Log_play_game
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[Log_play_game]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table Log_play_game
-- ----------------------------
CREATE CLUSTERED INDEX [idx_regDate]
ON [dbo].[Log_play_game] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [idx_userID]
ON [dbo].[Log_play_game] (
  [userID] ASC
)
GO


-- ----------------------------
-- Auto increment value for Log_play_tutorial
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[Log_play_tutorial]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table Log_play_tutorial
-- ----------------------------
CREATE CLUSTERED INDEX [idx_regDate]
ON [dbo].[Log_play_tutorial] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [idx_userID]
ON [dbo].[Log_play_tutorial] (
  [userID] ASC
)
GO


-- ----------------------------
-- Auto increment value for log_present
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_present]', RESEED, 576)
GO


-- ----------------------------
-- Auto increment value for Log_system_info
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[Log_system_info]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table Log_system_info
-- ----------------------------
CREATE CLUSTERED INDEX [idx_regDate]
ON [dbo].[Log_system_info] (
  [regDate] ASC
)  
FILESTREAM_ON [NULL]
GO

CREATE NONCLUSTERED INDEX [idx_logType]
ON [dbo].[Log_system_info] (
  [logType] ASC
)
GO


-- ----------------------------
-- Auto increment value for log_trace_prisoner_option
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_trace_prisoner_option]', RESEED, 1)
GO


-- ----------------------------
-- Primary Key structure for table log_trace_prisoner_option
-- ----------------------------
ALTER TABLE [dbo].[log_trace_prisoner_option] ADD CONSTRAINT [PK_log_trace_prisoner_option] PRIMARY KEY CLUSTERED ([regDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for log_trace_prisoner_start
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_trace_prisoner_start]', RESEED, 6078)
GO


-- ----------------------------
-- Primary Key structure for table log_trace_prisoner_start
-- ----------------------------
ALTER TABLE [dbo].[log_trace_prisoner_start] ADD CONSTRAINT [PK_log_trace_prisoner_start] PRIMARY KEY CLUSTERED ([RegDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for Log_use_item
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[Log_use_item]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for SQL_ERROR_LOG
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[SQL_ERROR_LOG]', RESEED, 1)
GO


-- ----------------------------
-- Primary Key structure for table SQL_ERROR_LOG
-- ----------------------------
ALTER TABLE [dbo].[SQL_ERROR_LOG] ADD CONSTRAINT [PK__SQL_ERRO__358565CA7AA2554B] PRIMARY KEY CLUSTERED ([ErrorID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for TBL_LOG_HACK
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[TBL_LOG_HACK]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table TBL_LOG_HACK
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_TBL_LOG_HACK_AccountIDX]
ON [dbo].[TBL_LOG_HACK] (
  [AccountIDX] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table TBL_LOG_HACK
-- ----------------------------
ALTER TABLE [dbo].[TBL_LOG_HACK] ADD CONSTRAINT [PK_TBL_LOG_HACK] PRIMARY KEY CLUSTERED ([RegDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for TBL_LOG_HACK_MESSAGE
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[TBL_LOG_HACK_MESSAGE]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table TBL_LOG_HACK_MESSAGE
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_TBL_LOG_HACK_MESSAGE_AccountIDX]
ON [dbo].[TBL_LOG_HACK_MESSAGE] (
  [AccountIDX] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table TBL_LOG_HACK_MESSAGE
-- ----------------------------
ALTER TABLE [dbo].[TBL_LOG_HACK_MESSAGE] ADD CONSTRAINT [PK_TBL_LOG_HACK_MESSAGE] PRIMARY KEY CLUSTERED ([RegDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO

