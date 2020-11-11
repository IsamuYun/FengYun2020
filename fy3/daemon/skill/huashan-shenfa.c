// huashan-shenfa.c 华山身法

inherit SKILL;

mapping *action = ({
([	"action" : "$n一式「巨鹏亮翅」，两臂鹏举如翼，在剌剌风声中，从$N头顶横跃而过。\n",
	"dodge"  : 10
]),
([	"action" : "$n一式「风送紫霞」，如一阵清风，舒缓地闪过了$N的凌厉攻势。\n",
	"dodge"  : 20
]),
([	"action" : "$n一式「燕回朝阳」，轻盈地一跃，一转眼间便绕到了$N的身后。\n",
	"dodge"  : 30
]),
([	"action" : "$n一式「却别苍松」，一转身间，向后飘出近一丈远\n",
	"dodge"  : 40
]),
([	"action" : "$n一式「旭日初升」，全身笔直，拔地而起，在半空中一转，已落到几丈远的地方。\n",
	"dodge"  : 50
]),
([	"action" : "$n一式「金雁横空」，身体如一只金雁般行云流水地滑出丈余。\n",
	"dodge"  : 60
]),
([	"action" : "$n一式「晚月朗星」，双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
	"dodge"  : 70
]),
([	"action" : "$n一式「幻眼云湮」，身形陡地变得飘忽不定，令$N无法看清。\n",
	"dodge"  : 80
]),
([	"action" : "$n一式「苍龙盘岭」，宛若一条矫矢苍龙，围着$N急速地盘旋了几圈。\n",
	"dodge"  : 90
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("huashan-shenfa");

	if (level < 80 )
		zhaoshu--;

	if (level < 60 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力太差了，不能练华山身法。\n");
	me->receive_damage("kee", 30);
	return 1;
}
string perform_action_file(string action)
{
	 return CLASS_D("huashan") + "/huashan-shenfa/" + action;
}

