inherit SKILL;
string *dodge_msg = ({
        "$n身影一晃，霎那间挪至$N的背后。\n",
        "$n上身微微晃动，整个人飘出丈外。\n",
        "$n身体随风微微舞动，整个人瞬间就弹出了$N的攻击范围。\n",
        "$n双肩微耸，人即化为三重幻影，使$N无法确定攻击的目标。\n",
        "$n腰身一拱，整个人横移出丈外。\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)

{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力太差了，不能练逍遥游。\n");
        me->receive_damage("kee", 30);
        return 1;
}
int effective_level() { return 20;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;

}
int black_white_ness()
{
        return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("piaomiao") + "/xiaoyao-steps/" + action;
}

