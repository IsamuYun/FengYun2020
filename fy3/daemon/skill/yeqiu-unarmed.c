// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改
// xgchen
// 长孙无情
// 普通百姓
// 14000000
// 男性
// unarmed
// 野球拳





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N前腿踢出，后腿脚尖点地,一式「乱拳挥舞」，双拳直出，攻向$n的$l",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "乱拳挥舞"
]),
// ZHAOSHI :1



([
"action" :"$N一招「野外狂龙」，身行飘渺如云烟，忽地向$n的$l一拂！",
"damage" :80,
"dodge" :-10,
"parry" :-10,
"damage_type": "瘀伤",
"lvl" : 12,
"skill_name" : "野外狂龙"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"野球拳"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
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
	if( (int)me->query("kee") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
} 
string *parry_msg = ({
        "$n引偏了$N的$w。\n",
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
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -10;
}
