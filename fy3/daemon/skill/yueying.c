#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) 
{ 
return (usage=="iron-cloth" || usage=="force");
}

int valid_learn(object me) {
     return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("月影神功古往今来，只有具大毅力者才能在探索和研究中练到高深。\n");
}

int effective_level() { return 35;}

string *absorb_msg = ({
        "$n神功默运，凛烈的罡气如潮水般澎湃而出！\n",
        "$n反背双手，神态悠然，对$N的攻势不避不让！\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
	return 40;
}

int learn_bonus()
{
	return -5000;
}

int practice_bonus()
{
	return -5000;
}

int black_white_ness()
{
	return 200;
}
string exert_function_file(string func)
{
        return CLASS_D("moon") + "/yueying/" + func;
}


//}

