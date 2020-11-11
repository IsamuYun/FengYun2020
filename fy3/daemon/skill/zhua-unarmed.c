// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改
// wdl
// 罗曼蒂克
// 我烦，我烦，我有点儿烦
// 15000000
// 女性
// unarmed
// 抓奶龙爪功





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N忽然跃起，双手直奔$n的$l抓去，忽然身形一转，原来是个虚招，真正的杀招原来是《天龙抓奶》，让人防不胜防，果然高明，每爪必中",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "瘀伤",
"skill_name" : "天龙抓奶"
]),
// ZHAOSHI :1

([
"action" :"$N纵身跳到场外，阴声喝道：“无奶不抓”，$n的$l忽然被一只隐形黑手重击",
"damage" :80,
"dodge" :-10,
"parry" :-10,
"damage_type": "瘀伤",
"skill_name" : "无奶不抓"
]),
// ZHAOSHI :2

([
"action" :"$N悄悄问道：“谁想吃奶？”，$n急呼，“我要，我要！”可是$l突然受到重创，昏倒在地",
"damage" :100,
"dodge" :-20,
"parry" :-20,
"damage_type": "瘀伤",
"skill_name" : "谁想吃奶"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"抓奶龙爪功"+"必须空手。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力太弱，无法练"+"抓奶龙爪功"+"。\n");
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
        return CLASS_D("player") + "/"+"抓奶龙爪功"+"/" + action;
}
