// 莲花幻步

inherit SKILL;

string *dodge_msg = ({
        "但是$n身形飘忽，轻轻一纵，极其优雅的避开这一击。\n",
        "$n身随意转，如莲花般窜开数尺，避开了。\n",
        "$n似真似幻，身形往上拔起，一个转折落在数尺之外。\n"
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
        return notify_fail("莲花幻步只能通过向师傅学习来提升。\n");
        return 1;
}
int effective_level() { return 10;}

int learn_bonus()
{
          return -60;
}
int practice_bonus()
{
        return -10;
}
int black_white_ness()
{
        return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("xingguo") + "/lotus-steps/" + action;
}
string belong()
{
	return "xingguo";

}