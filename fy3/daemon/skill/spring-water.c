
#include <ansi.h>
inherit SKILL;

int valid_enable(string usage) { return usage=="iron-cloth"; }

int valid_learn(object me) 
{
    if( (string)me->query("gender") != "女性" ) {
        return notify_fail("春水罗衫是只有女子才能练的武功。\n");
        }

        return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("春水罗衫只能通过学习来提高。\n");
}

 
int effective_level() { return 28;}

string *absorb_msg = ({
        "$n秀眉微蹙，施展「两重心字罗衣」，周身衣衫飘舞，竟然似乎有点点微光浮动。\n",
        "$n施展春水罗衫的「梦后楼台高锁」，暗劲绵密，缕缕寒气传入$N的体内。\n",
        "$n微微侧身，一式「落花人独立」，在$N的攻势下，衣带飘飘，如风吹花舞。\n",
        "$n施展出「微雨燕双飞」，双袖飞展，接下$N的一击。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
	return 10;
}

int learn_bonus()
{
	return -1000;
}
int practice_bonus()
{
	return -5;
}
int black_white_ness()
{
	return 20;
}

