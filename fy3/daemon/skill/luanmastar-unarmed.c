// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改
// yog
// 阳光普照
// 关外胡家　第三代弟子
// 9884346
// 男性
// unarmed
// 乱马流星拳





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N纵身半空，双手藏于背后，猝然间，你暗暗地聚气，一照流星追月，双手闪电般的挥出",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "瘀伤",
"skill_name" : "流星追日"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"乱马流星拳"+"必须空手。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力太弱，无法练"+"乱马流星拳"+"。\n");
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
        return CLASS_D("player") + "/"+"乱马流星拳"+"/" + action;
}
