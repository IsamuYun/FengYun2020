//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

// Directories

#define COMMAND_DIR             "/cmds/"
#define CONFIG_DIR              "/adm/etc/"
#define BACKUP_DIR              "/backup/"
#define DATA_DIR                "/data/"
#define HELP_DIR                "/doc/"
#define LOG_DIR                 "/log/"

// Daemons
#define BR_D			"/adm/daemons/brd"
#define BN_D			"/adm/daemons/bnd"
#define BAN_D			"/adm/daemons/band"
#define ALIAS_D                 "/adm/daemons/aliasd"
#define EXAMINE_D       "/adm/daemons/examined"
#define CHANNEL_D               "/adm/daemons/channeld"
#define CHAR_D                  "/adm/daemons/chard"
#define YNVOTE_D                "/adm/daemons/ynvoted"
#define CHINESE_D               "/adm/daemons/chinesed"
#define COMBAT_D                "/adm/daemons/combatd"
#define COMMAND_D               "/adm/daemons/cmd_d"
#define EMOTE_D                 "/adm/daemons/emoted"
#define FINGER_D                "/adm/daemons/fingerd"
#define UPGRADE_D		"/adm/daemons/upgraded"
#define INQUIRY_D               "/adm/daemons/inquiryd"
#define LOGIN_D                 "/adm/daemons/logind"
#define NATURE_D                "/adm/daemons/natured"
#define PROFILE_D               "/adm/daemons/profiled"
#define RANK_D                  "/adm/daemons/rankd"
#define SECURITY_D              "/adm/daemons/securityd"
#define UPDATE_D                "/adm/daemons/updated"
#define VIRTUAL_D               "/adm/daemons/virtuald"
#define WEAPON_D                "/adm/daemons/weapond"
#define WHO_D			"/adm/daemons/whod"
#define TASK_D			"/adm/daemons/questd"
#define STATUS_D		"/adm/daemons/statusd"
#define VOTE_D			"/adm/daemons/voted"
#define CRON_D                  "/adm/daemons/cron"
#define STORY_D					"/adm/daemons/storyd"
//��Ϣʹ�ò�Ҫɾ��
#define CONVERT_D                  "/adm/daemons/convertd"
// added by Tie for questing

#define QUEST_D(x)		("/quest/qlist" + x)
#define CLASS_D(x)              ("/daemon/class/" + x)
#define SKILL_D(x)              ("/daemon/skill/" + x)
#define CONDITION_D(x)  ("/daemon/condition/" + x)
#define TONGJI_D(x)            ("/tongji/qlist" + x)


#define TOPTEN_D            "/adm/daemons/toptend" 
#define TOPTEN_RICH         "/data/topten/rich.txt"
#define TOPTEN_PKER         "/data/topten/pker.txt"
#define TOPTEN_EXP          "/data/topten/exp.txt"
#define TOPTEN_AGE          "/data/topten/age.txt"
#define TOPTEN_TASKER       "/data/topten/tasker.txt"
#define TOPTEN_KILLED       "/data/topten/killed.txt"
#define RICH_B             "ʮ�������а�"
#define PKER_B              "ʮ��ħͷ���а�"
#define EXP_B              "ʮ��������а�"
#define AGE_B              "ʮ���������а�"
#define TASKER_B           "ʮ��ʹ���������а�"
#define KILLED_B           "ʮ�����������а�"
//�Դ�skillʹ��
#define SKILL_MODEL_UNARMED    "/meskill/skill_model_unarmed.c"
#define SKILL_MODEL_WEAPON     "/meskill/skill_model_weapon.c"
#define SKILL_MODEL_DEFAULT    "/meskill/skill_model_default.c"
//��������֪ͨ��
// xgchen //

#define COIN_OB                 "/obj/money/coin"
#define CORPSE_OB               "/obj/corpse"
#define LOGIN_OB                "/obj/login"
#define MASTER_OB               "/adm/obj/master"
#define	MESSAGE_D	"/adm/daemons/network/messaged"
#define MAILBOX_OB              "/obj/mailbox"
#define SILVER_OB               "/obj/money/silver"
#define GOLD_OB                 "/obj/money/gold"
#define THCASH_OB               "/obj/money/thousand-cash"
#define TECASH_OB               "/obj/money/tenthousand-cash"
#define SIMUL_EFUN_OB   "/adm/obj/simul_efun"
#define USER_OB                 "/obj/user"
#define VOID_OB                 "/obj/void"

// Inheritable Standard Objects

#define BANK                    "/std/room/bank"
#define BULLETIN_BOARD  "/std/bboard"
#define CHARACTER               "/std/char"
#define CLASS_GUILD             "/std/room/class_guild"
#define COMBINED_ITEM   "/std/item/combined"
#define EQUIP                   "/std/equip"
#define FORCE                   "/std/force"
#define HOCKSHOP                "/std/room/hockshop"
#define ITEM                    "/std/item"
#define SHEET  "/std/sheet"
#define LIQUID                  "/std/liquid"
#define MONEY                   "/std/money"
#define NPC                             "/std/char/npc"
#define POWDER                  "/std/medicine/powder"
#define ROOM                    "/std/room"
#define SKILL                   "/std/skill"
#define SSERVER                 "/std/sserver"
// User IDs

#define ROOT_UID                "Root"
#define BACKBONE_UID    "Backbone"

// Features

#define F_ACTION                "/feature/action.c"
#define F_ALIAS                 "/feature/alias.c"
#define F_PAWN			"/feature/pawn.c"
#define F_APPRENTICE    	"/feature/apprentice.c"
#define F_ATTACK                "/feature/attack.c"
#define F_ATTRIBUTE             "/feature/attribute.c"
#define F_AUTOLOAD              "/feature/autoload.c"
#define F_CLEAN_UP              "/feature/clean_up.c"
#define F_COMMAND               "/feature/command.c"
#define F_CONDITION             "/feature/condition.c"
#define F_DAMAGE                "/feature/damage.c"
#define F_DBASE                 "/feature/dbase.c"
#define F_EDIT                  "/feature/edit.c"
#define F_EQUIP                 "/feature/equip.c"
#define F_FINANCE               "/feature/finance.c"
#define F_FOOD                  "/feature/food.c"
#define F_LIQUID                "/feature/liquid.c"
#define F_MASTER                "/std/char/master.c"
#define F_MESSAGE               "/feature/message.c"
#define F_MORE                  "/feature/more.c"
#define F_MOVE                  "/feature/move.c"
#define F_NAME                  "/feature/name.c"
#define F_SAVE                  "/feature/save.c"
#define F_SKILL                 "/feature/skill.c"
#define F_TEAM                  "/feature/team.c"
#define F_TREEMAP               "/feature/treemap.c"
#define F_VENDOR                "/feature/vendor.c"
// added by Tie Yu@fengyun 4/96
#define F_QUEST			"/feature/quest.c"
// added by Tie@fengyun 8/96
#define F_PAWNOWNER		"/feature/pawnowner.c"
#define F_BANKOWNER		"/feature/bankowner.c"
#define F_BANKPAWNOWNER		"/feature/bankpawnowner.c"
// added by tie@fy3 for mudosv22b9
#define SAVE_EXTENSION		".o"
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS
