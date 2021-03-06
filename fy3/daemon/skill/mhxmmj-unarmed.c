// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改
// xmmj
// 晨风
// 梦幻城　[1;31m刀神[2;37;0m
// 7600779
// 男性
// unarmed
// 梦幻风舞拳





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N全身拔地而起使出一招幻想云落,$N的拳疾如闪电，拳风无处不在地向$n的$l攻去",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "瘀伤",
"skill_name" : "幻想云落"
]),
// ZHAOSHI :1

([
"action" :"$N身行斗转「幻世狂风」呼啸而出，瞬间化作龙卷狂风攻向$n的$l",
"damage" :80,
"dodge" :-10,
"parry" :-10,
"damage_type": "瘀伤",
"skill_name" : "幻世狂风"
]),
// ZHAOSHI :2

([
"action" :"$N一声长啸，一招「风卷残云」击出，强烈的拳风扑向$n的$l",
"damage" :100,
"dodge" :-20,
"parry" :-20,
"damage_type": "瘀伤",
"skill_name" : "风卷残云"
]),
// ZHAOSHI :3

([
"action" :"$N身行一闪，一招「斗转星移」双拳化作漫天繁星向$n$l攻去",
"damage" :130,
"dodge" :-30,
"parry" :-30,
"damage_type": "瘀伤",
"skill_name" : "斗转星移"
]),
// ZHAOSHI :4

([
"action" :"$N双腿如行云般踢出，一个空翻，头朝下，双拳连环击出「覆雨翻云」，攻向$n$l",
"damage" :150,
"dodge" :-50,
"parry" :-40,
"damage_type": "瘀伤",
"skill_name" : "覆雨翻云"
]),
// ZHAOSHI :5

([
"action" :"$N飕然停住，心静如「井中之月」，人一动不动，整个拳发出的劲风扩向$n$l",
"damage" :180,
"dodge" :-60,
"parry" :-50,
"damage_type": "瘀伤",
"skill_name" : "井中之月"
]),
// ZHAOSHI :6

([
"action" :"$N飞身而起，双拳化着万千拳影，一招「击奇雪涌」,拳风如大雪般卷向$n$l",
"damage" :200,
"dodge" :-80,
"parry" :-60,
"damage_type": "瘀伤",
"skill_name" : "击奇雪涌"
]),
// ZHAOSHI :7

([
"action" :"$N全身旋转起来，瞬间化成如梦如幻的身影，绝学「梦幻风舞」呼啸而出，向$n$l击出致命一拳",
"damage" :220,
"dodge" :-90,
"parry" :-70,
"damage_type": "瘀伤",
"skill_name" : "梦幻风舞"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"梦幻风舞拳"+"必须空手。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力太弱，无法练"+"梦幻风舞拳"+"。\n");
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
