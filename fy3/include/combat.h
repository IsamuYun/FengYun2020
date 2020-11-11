// combat.h

#ifndef __COMBAT__
#define __COMBAT__

//一些技能的熟练等级最大值定义

#define MAX_PFMLEVEL	10

#define TYPE_REGULAR	0
#define TYPE_RIPOSTE	1
#define TYPE_QUICK	2

#define RESULT_DODGE	-1
#define RESULT_PARRY	-2
#define RESULT_PROTECT  -3
// This is used as skill_power()'s argument to indicate which type of skill
// usage will be used in calculating skill power.
#define SKILL_USAGE_ATTACK		1
#define SKILL_USAGE_DEFENSE		2
#define SKILL_USAGE_MOVE		3
#define SKILL_USAGE_DODGE		4
#define SKILL_USAGE_DAMAGE		5
#define SKILL_USAGE_MATTACK		6
#define SKILL_USAGE_MDEFENSE		7
#define SKILL_USAGE_MDODGE		8
#define SKILL_USAGE_MDAMAGE		9
#endif

