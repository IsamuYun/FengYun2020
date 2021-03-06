// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改
// pltd
// 霹雳天刀
// 风云小学　前任校长
// 9801914
// 女性
// unarmed
// 主席拳法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N一挥手,一招[江山如此多娇],神拳击向$n的$l",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "瘀伤",
"skill_name" : "江山如此多娇"
]),
// ZHAOSHI :1

([
"action" :"$N一摆手，一招[无数英雄竞折腰]，神掌砍向$n的$l",
"damage" :80,
"dodge" : 10,
"parry" :-10,
"damage_type": "瘀伤",
"skill_name" : "无数英雄折腰"
]),
// ZHAOSHI :2

([
"action" :"$N一摆手，一招[秦汉略输文采]，神掌砍向$n的$l",
"damage" :100,
"dodge" : 10,
"parry" :-20,
"damage_type": "瘀伤",
"skill_name" : "秦汉略输文采"
]),
// ZHAOSHI :3

([
"action" :"$N一举手，一招[唐宗宋祖稍逊风骚］，手掌刺向$n的$l",
"damage" :130,
"dodge" :25,
"parry" :30,
"damage_type": "瘀伤",
"skill_name" : "唐宋稍逊风骚"
]),
// ZHAOSHI :4

([
"action" :"$N的手像利箭一样，一招耍滔�$n的$l---〉",
"damage" :150,
"dodge" :30,
"parry" :40,
"damage_type": "瘀伤",
"skill_name" : "思汗弯弓射雕"
]),
// ZHAOSHI :5

([
"action" :"$N把双手一扬， 一招剩� 无穷的劲力向$n的$l冲击！",
"damage" :180,
"dodge" :40,
"parry" :50,
"damage_type": "瘀伤",
"skill_name" : "数风流人物"
]),
// ZHAOSHI :6

([
"action" :"$N把手指向前方，一招唬钪娴牧α看┕�$n的$l！",
"damage" :200,
"dodge" :50,
"parry" :60,
"damage_type": "瘀伤",
"skill_name" : "还看霹雳天刀"
]),
// ZHAOSHI :7

([
"action" :"$N把右手向后一扬，一招停�$n的$l被思想征服了！",
"damage" :220,
"dodge" :80,
"parry" :70,
"damage_type": "瘀伤",
"skill_name" : "同志们辛苦了"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"主席拳法"+"必须空手。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力太弱，无法练"+"主席拳法"+"。\n");
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
