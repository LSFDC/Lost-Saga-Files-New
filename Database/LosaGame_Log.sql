/*
 Navicat Premium Data Transfer

 Source Server         : [LSFD] LS
 Source Server Type    : SQL Server
 Source Server Version : 16004105 (16.00.4105)
 Source Host           : 172.17.191.44:1433
 Source Catalog        : LosaGame_Log
 Source Schema         : dbo

 Target Server Type    : SQL Server
 Target Server Version : 16004105 (16.00.4105)
 File Encoding         : 65001

 Date: 24/03/2024 14:29:05
*/


-- ----------------------------
-- Table structure for log_cash
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_cash]') AND type IN ('U'))
	DROP TABLE [dbo].[log_cash]
GO

CREATE TABLE [dbo].[log_cash] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [userIP] varchar(16) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [DBID] varchar(16) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [applyType] char(2) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [amount] int  NOT NULL,
  [note] varchar(500) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [regDate] datetime  NOT NULL
)
GO

ALTER TABLE [dbo].[log_cash] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_class_buytime
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_class_buytime]') AND type IN ('U'))
	DROP TABLE [dbo].[log_class_buytime]
GO

CREATE TABLE [dbo].[log_class_buytime] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [classType] int DEFAULT 0 NOT NULL,
  [buyTime] bigint DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_class_buytime] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_class_rental_history
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_class_rental_history]') AND type IN ('U'))
	DROP TABLE [dbo].[log_class_rental_history]
GO

CREATE TABLE [dbo].[log_class_rental_history] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [friendIDX] int  NOT NULL,
  [classType] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_class_rental_history] SET (LOCK_ESCALATION = TABLE)
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
  [eventType] smallint  NOT NULL,
  [CloverCount] int  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_data_clover] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_event_marble
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_event_marble]') AND type IN ('U'))
	DROP TABLE [dbo].[log_event_marble]
GO

CREATE TABLE [dbo].[log_event_marble] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountidx] int  NOT NULL,
  [userID] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [cpType] int  NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_event_marble] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_event_openbeta_coin
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_event_openbeta_coin]') AND type IN ('U'))
	DROP TABLE [dbo].[log_event_openbeta_coin]
GO

CREATE TABLE [dbo].[log_event_openbeta_coin] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [coin] int  NOT NULL,
  [flag] int DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_event_openbeta_coin] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_guild_mark
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_guild_mark]') AND type IN ('U'))
	DROP TABLE [dbo].[log_guild_mark]
GO

CREATE TABLE [dbo].[log_guild_mark] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [guildIDX] int  NOT NULL,
  [accountIDX] int  NOT NULL,
  [havepeso] bigint  NOT NULL,
  [markprice] int  NOT NULL,
  [nowmark] int  NOT NULL,
  [changemark] int  NOT NULL,
  [flag] int DEFAULT 0 NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_guild_mark] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_league_cheer
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_league_cheer]') AND type IN ('U'))
	DROP TABLE [dbo].[log_league_cheer]
GO

CREATE TABLE [dbo].[log_league_cheer] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [cheerIDX] int  NOT NULL,
  [startDate] int  NOT NULL,
  [accountIDX] int  NOT NULL,
  [leagueIDX] int  NOT NULL,
  [teamIDX] int  NOT NULL,
  [regDate] datetime  NOT NULL,
  [insertDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_league_cheer] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_league_info_user
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_league_info_user]') AND type IN ('U'))
	DROP TABLE [dbo].[log_league_info_user]
GO

CREATE TABLE [dbo].[log_league_info_user] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [infoIDX] int  NULL,
  [leagueIDX] int  NULL,
  [leagueName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [maxRound] smallint  NULL,
  [bannerA] int  NULL,
  [bannerB] int  NULL,
  [modeType] int  NULL,
  [maxcount] tinyint  NULL,
  [autoType] tinyint  NULL,
  [announce] nvarchar(512) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [recruitDate] int  NULL,
  [waitDate] int  NULL,
  [regDate] datetime  NULL,
  [insertDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_league_info_user] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_league_list
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_league_list]') AND type IN ('U'))
	DROP TABLE [dbo].[log_league_list]
GO

CREATE TABLE [dbo].[log_league_list] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [leagueIDX] int  NULL,
  [accountIDX] int  NULL,
  [startDate] int  NULL,
  [endDate] int  NULL,
  [leagueType] tinyint  NULL,
  [leagueState] tinyint  NULL,
  [regDate] datetime  NULL,
  [insertDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_league_list] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_league_list_user
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_league_list_user]') AND type IN ('U'))
	DROP TABLE [dbo].[log_league_list_user]
GO

CREATE TABLE [dbo].[log_league_list_user] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [leagueIDX] int  NULL,
  [accountIDX] int  NULL,
  [startDate] int  NULL,
  [endDate] int  NULL,
  [leagueType] tinyint  NULL,
  [leagueState] tinyint  NULL,
  [regDate] datetime  NULL,
  [insertDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_league_list_user] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_league_round_user
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_league_round_user]') AND type IN ('U'))
	DROP TABLE [dbo].[log_league_round_user]
GO

CREATE TABLE [dbo].[log_league_round_user] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [roundIDX] int  NULL,
  [infoIDX] int  NULL,
  [roundType1_playDate] int  NULL,
  [roundType1_presentCode1] int  NULL,
  [roundType1_presentCode2] int  NULL,
  [roundType1_presentCode3] int  NULL,
  [roundType1_presentCode4] int  NULL,
  [roundType2_playDate] int  NULL,
  [roundType2_presentCode1] int  NULL,
  [roundType2_presentCode2] int  NULL,
  [roundType2_presentCode3] int  NULL,
  [roundType2_presentCode4] int  NULL,
  [roundType3_playDate] int  NULL,
  [roundType3_presentCode1] int  NULL,
  [roundType3_presentCode2] int  NULL,
  [roundType3_presentCode3] int  NULL,
  [roundType3_presentCode4] int  NULL,
  [roundType4_playDate] int  NULL,
  [roundType4_presentCode1] int  NULL,
  [roundType4_presentCode2] int  NULL,
  [roundType4_presentCode3] int  NULL,
  [roundType4_presentCode4] int  NULL,
  [roundType5_playDate] int  NULL,
  [roundType5_presentCode1] int  NULL,
  [roundType5_presentCode2] int  NULL,
  [roundType5_presentCode3] int  NULL,
  [roundType5_presentCode4] int  NULL,
  [roundType6_playDate] int  NULL,
  [roundType6_presentCode1] int  NULL,
  [roundType6_presentCode2] int  NULL,
  [roundType6_presentCode3] int  NULL,
  [roundType6_presentCode4] int  NULL,
  [roundType7_playDate] int  NULL,
  [roundType7_presentCode1] int  NULL,
  [roundType7_presentCode2] int  NULL,
  [roundType7_presentCode3] int  NULL,
  [roundType7_presentCode4] int  NULL,
  [roundType8_playDate] int  NULL,
  [roundType8_presentCode1] int  NULL,
  [roundType8_presentCode2] int  NULL,
  [roundType8_presentCode3] int  NULL,
  [roundType8_presentCode4] int  NULL,
  [roundType9_playDate] int  NULL,
  [roundType9_presentCode1] int  NULL,
  [roundType9_presentCode2] int  NULL,
  [roundType9_presentCode3] int  NULL,
  [roundType9_presentCode4] int  NULL,
  [roundType10_playDate] int  NULL,
  [roundType10_presentCode1] int  NULL,
  [roundType10_presentCode2] int  NULL,
  [roundType10_presentCode3] int  NULL,
  [roundType10_presentCode4] int  NULL,
  [roundType11_playDate] int  NULL,
  [roundType11_presentCode1] int  NULL,
  [roundType11_presentCode2] int  NULL,
  [roundType11_presentCode3] int  NULL,
  [roundType11_presentCode4] int  NULL,
  [regDate] datetime  NULL,
  [insertDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_league_round_user] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_league_team
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_league_team]') AND type IN ('U'))
	DROP TABLE [dbo].[log_league_team]
GO

CREATE TABLE [dbo].[log_league_team] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [teamIDX] int  NULL,
  [leagueIDX] int  NULL,
  [startDate] int  NULL,
  [teamName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [leaderIDX] int  NULL,
  [leagueStartPosition] smallint DEFAULT 0 NULL,
  [leaguePosition] smallint  NULL,
  [maxcount] tinyint  NULL,
  [cheerPoint] int  NULL,
  [currentRound] tinyint  NULL,
  [factionPoint] int  NULL,
  [factionType] tinyint  NULL,
  [regDate] datetime  NULL,
  [insertDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_league_team] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_league_team_member
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_league_team_member]') AND type IN ('U'))
	DROP TABLE [dbo].[log_league_team_member]
GO

CREATE TABLE [dbo].[log_league_team_member] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [teamMemberIDX] int  NULL,
  [startDate] int  NULL,
  [accountIDX] int  NULL,
  [leagueIDX] int  NULL,
  [teamIDX] int  NULL,
  [joinType] tinyint  NULL,
  [regDate] datetime  NULL,
  [insertDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_league_team_member] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_league_team_member_user
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_league_team_member_user]') AND type IN ('U'))
	DROP TABLE [dbo].[log_league_team_member_user]
GO

CREATE TABLE [dbo].[log_league_team_member_user] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [teamMemberIDX] int  NOT NULL,
  [startDate] int  NOT NULL,
  [accountIDX] int  NOT NULL,
  [leagueIDX] int  NOT NULL,
  [teamIDX] int  NOT NULL,
  [joinType] tinyint  NOT NULL,
  [regDate] datetime  NOT NULL,
  [insertDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_league_team_member_user] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_league_team_user
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_league_team_user]') AND type IN ('U'))
	DROP TABLE [dbo].[log_league_team_user]
GO

CREATE TABLE [dbo].[log_league_team_user] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [teamIDX] int  NULL,
  [leagueIDX] int  NULL,
  [startDate] int  NULL,
  [teamName] nvarchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [leaderIDX] int  NULL,
  [leagueStartPosition] smallint  NULL,
  [leaguePosition] smallint  NULL,
  [maxcount] tinyint  NULL,
  [cheerPoint] int  NULL,
  [currentRound] tinyint  NULL,
  [factionPoint] int  NULL,
  [factionType] tinyint  NULL,
  [regDate] datetime  NULL,
  [insertDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_league_team_user] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_level_playtime
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_level_playtime]') AND type IN ('U'))
	DROP TABLE [dbo].[log_level_playtime]
GO

CREATE TABLE [dbo].[log_level_playtime] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [userLevel] int DEFAULT 0 NOT NULL,
  [playTime] bigint DEFAULT 0 NOT NULL,
  [regDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_level_playtime] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_mannerpoint
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_mannerpoint]') AND type IN ('U'))
	DROP TABLE [dbo].[log_mannerpoint]
GO

CREATE TABLE [dbo].[log_mannerpoint] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [playType] int  NOT NULL,
  [modeType] int  NOT NULL,
  [sub1Type] int  NOT NULL,
  [sub2Type] int  NOT NULL,
  [reportIDX] int  NULL,
  [reportNick] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [reportpubIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [reportpriIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [receiveIDX] nchar(10) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [receiveNick] varchar(20) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [receivepubIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [roomInfo] varchar(2000) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [chatInfo] varchar(3000) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [note] varchar(500) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [reason] varchar(2000) COLLATE SQL_Latin1_General_CP1_CI_AS  NULL,
  [flag] tinyint DEFAULT 0 NOT NULL,
  [resultType] tinyint DEFAULT 0 NOT NULL,
  [regDate] datetime  NOT NULL,
  [receivepoint] int  NULL,
  [reportMP] int  NULL,
  [receiveMP] int  NULL
)
GO

ALTER TABLE [dbo].[log_mannerpoint] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_mannerpoint_sitevisit
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_mannerpoint_sitevisit]') AND type IN ('U'))
	DROP TABLE [dbo].[log_mannerpoint_sitevisit]
GO

CREATE TABLE [dbo].[log_mannerpoint_sitevisit] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [accountIDX] int  NOT NULL,
  [point] smallint  NOT NULL,
  [userIP] varchar(15) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [regDate] datetime  NOT NULL
)
GO

ALTER TABLE [dbo].[log_mannerpoint_sitevisit] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for log_tooni_migration
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_tooni_migration]') AND type IN ('U'))
	DROP TABLE [dbo].[log_tooni_migration]
GO

CREATE TABLE [dbo].[log_tooni_migration] (
  [idx] int  IDENTITY(1,1) NOT NULL,
  [TooniIDX] int  NOT NULL,
  [TooniID] varchar(32) COLLATE SQL_Latin1_General_CP1_CI_AS  NOT NULL,
  [AccountIDX] int  NOT NULL,
  [RegDate] datetime DEFAULT getdate() NOT NULL
)
GO

ALTER TABLE [dbo].[log_tooni_migration] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- procedure structure for game_item_etc_get_self_index
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[game_item_etc_get_self_index]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[game_item_etc_get_self_index]
GO

CREATE PROCEDURE [dbo].[game_item_etc_get_self_index]
(
	@accountIDX int
)
AS
	SELECT TOP 1 idx FROM userItemEtcDB WHERE accountIDX = @accountIDX ORDER BY idx DESC
GO


-- ----------------------------
-- procedure structure for log_data_clover_add
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[log_data_clover_add]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[log_data_clover_add]
GO

CREATE PROCEDURE [dbo].[log_data_clover_add]
(
	@userIDX	int
,	@FriendIDX	int
,	@Type		smallint
,	@Count		int
)
AS

SET NOCOUNT ON

-- 클로버 정보가 없을때 insert
INSERT INTO dbo.log_data_clover( accountIDX, friendIDX, eventType, CloverCount, regDate )
VALUES( @userIDX, @FriendIDX, @Type, @Count, GETDATE() );
GO


-- ----------------------------
-- Auto increment value for log_cash
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_cash]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_class_buytime
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_class_buytime]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_class_rental_history
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_class_rental_history]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_data_clover
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_data_clover]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_data_clover
-- ----------------------------
CREATE NONCLUSTERED INDEX [accountidx]
ON [dbo].[log_data_clover] (
  [accountIDX] ASC
)
GO

CREATE NONCLUSTERED INDEX [regDate]
ON [dbo].[log_data_clover] (
  [regDate] ASC
)
GO


-- ----------------------------
-- Auto increment value for log_event_marble
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_event_marble]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_event_openbeta_coin
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_event_openbeta_coin]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_guild_mark
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_guild_mark]', RESEED, 1001)
GO


-- ----------------------------
-- Auto increment value for log_league_cheer
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_league_cheer]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_league_info_user
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_league_info_user]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_league_list
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_league_list]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_league_list_user
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_league_list_user]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_league_round_user
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_league_round_user]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_league_team
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_league_team]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_league_team_member
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_league_team_member]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_league_team_member_user
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_league_team_member_user]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_league_team_user
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_league_team_user]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_level_playtime
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_level_playtime]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_mannerpoint
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_mannerpoint]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_mannerpoint_sitevisit
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_mannerpoint_sitevisit]', RESEED, 1)
GO


-- ----------------------------
-- Auto increment value for log_tooni_migration
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[log_tooni_migration]', RESEED, 1)
GO


-- ----------------------------
-- Indexes structure for table log_tooni_migration
-- ----------------------------
CREATE NONCLUSTERED INDEX [NC_log_tooni_migration_AccountIDX]
ON [dbo].[log_tooni_migration] (
  [AccountIDX] ASC
)
GO

CREATE NONCLUSTERED INDEX [NC_log_tooni_migration_TooniID]
ON [dbo].[log_tooni_migration] (
  [TooniID] ASC
)
GO


-- ----------------------------
-- Primary Key structure for table log_tooni_migration
-- ----------------------------
ALTER TABLE [dbo].[log_tooni_migration] ADD CONSTRAINT [PK_log_tooni_migration] PRIMARY KEY CLUSTERED ([RegDate], [idx])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO

