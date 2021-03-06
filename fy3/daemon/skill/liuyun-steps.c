inherit SKILL;
string *dodge_msg = ({
        "$n一招流云步法中的「拨云式」，步法奇异，身形飘动，$N的招式落空。\n",
        "只见$n凝神不动，忽然一个鹰击长空，使出流云步法中的「积云式」，轻松地躲在一旁。\n",
        "$n使出流云步法中的「唤云式」，纵身一跃。\n",
        "$n左足一点，一招流云步法中的「踏云式」腾空而起，避了开去。\n",
        "可是$n使一招流云步法中的「驾云式」，步法飘忽不定，$N的攻击失去了准头。\n",
        "$n经藉一招流云步法中的「流云式」，身形飘退，轻轻闪过。\n",
        "但是$n一招流云步法中的「排云式」使出，身形晃动，幻出数道身影，自己早已飘出三丈开外！\n",
});
int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move") ;
}
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练流云步法。\n");
        return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        return notify_fail("流云步法只能靠向师傅学习来提升。\n"); 
}
int effective_level()
 {
 return 10;
}
int learn_bonus()
{
        return -100;
}
int practice_bonus()
{
        return -50;
}
int black_white_ness()
{
        return 100;
}
string perform_action_file(string action)
{
        return CLASS_D("official") + "/liuyun-steps/" + action;
}
string belong()
{
	return "official";
}