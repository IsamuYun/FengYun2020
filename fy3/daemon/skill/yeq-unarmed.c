// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改
// xgchen
// 长孙无情
// 金钱帮第三代弟子
// 13720000
// 男性
// unarmed
// 野球拳





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「给招式」，二掌直出，攻向$n的$l",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "瘀伤",
"skill_name" : "给招式"
]),
// ZHAOSHI :1

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「招式起」，二掌直出，攻向$n的$l",
"damage" :80,
"dodge" :-10,
"parry" :-10,
"damage_type": "瘀伤",
"skill_name" : "招式起"
]),
// ZHAOSHI :2

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的$l",
"damage" :100,
"dodge" :-20,
"parry" :-20,
"damage_type": "瘀伤",
"skill_name" : "后腿脚"
]),
// ZHAOSHI :3

([
"action" :"或者武器类例：$N纵身一跃，手中武器一招「金光泻地」对准的$l斜斜刺出一剑",
"damage" :130,
"dodge" :-30,
"parry" :-30,
"damage_type": "瘀伤",
"skill_name" : "请与长孙"
]),
// ZHAOSHI :4

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「出世」，二掌直出，攻向$n的$l",
"damage" :150,
"dodge" :-50,
"parry" :-40,
"damage_type": "瘀伤",
"skill_name" : "野球"
]),
// ZHAOSHI :5

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「出世」，二掌直出，攻向$n的$l",
"damage" :180,
"dodge" :-60,
"parry" :-50,
"damage_type": "瘀伤",
"skill_name" : "聊天讨论"
]),
// ZHAOSHI :6

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「出世」，二掌直出，攻向$n的$l7",
"damage" :200,
"dodge" :-80,
"parry" :-60,
"damage_type": "瘀伤",
"skill_name" : "厉害"
]),
// ZHAOSHI :7

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「出世」，二掌直出，攻向$n的$l8",
"damage" :220,
"dodge" :-90,
"parry" :-70,
"damage_type": "瘀伤",
"skill_name" : "厉害吧"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"野球拳"+"必须空手。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力太弱，无法练"+"野球拳"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
int effective_level() { return 20;}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("force") < 30 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 30);
	me->add("force", -30);
	return 1;
} 
string *parry_msg = ({
        "$n利用身法引偏了$N的$w。\n",
});
string *unarmed_parry_msg = ({
        "$n轻描淡写的化解了$N的攻势。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus()
{
        return 30;
}
int practice_bonus()
{
        return -30;
}
int black_white_ness()
{
        return 320;
}
string perform_action_file(string action)
{
        return CLASS_D("player") + "/"+"unarmed"+"/" + action;
}
