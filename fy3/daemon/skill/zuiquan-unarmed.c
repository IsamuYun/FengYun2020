// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改
// xiaoliu
// 令狐雪儿
// 新丰狼帮　第三代总瓢把子
// 13367281
// 女性
// unarmed
// 新丰醉拳





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N酒意攻心，很随意的一拳攻向$n的心口",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "瘀伤",
"skill_name" : "卡捞醉酒"
]),
// ZHAOSHI :1

([
"action" :"$N一个表情，疯疯颠颠，一式「小凯盲猪古」，全身抽筋，吓缩$n的令。",
"damage" :80,
"dodge" :15,
"parry" :15,
"damage_type": "瘀伤",
"skill_name" : "小凯盲猪古"
]),
// ZHAOSHI :2

([
"action" :"$N一个表情，疯疯颠颠，一式「小凯盲猪古」，全身抽筋，吓缩$n的令。",
"damage" :100,
"dodge" :20,
"parry" :20,
"damage_type": "瘀伤",
"skill_name" : "小凯盲猪古"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"新丰醉拳"+"必须空手。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力太弱，无法练"+"新丰醉拳"+"。\n");
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
