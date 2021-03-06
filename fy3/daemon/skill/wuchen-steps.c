// tang-steps.c 唐门千秋步 

inherit SKILL;

string *dodge_msg = ({
	"$n漫不经心的向左迈出一步，刚好避过$N的凌厉攻势。\n",
	"可是$n恰巧往右走了一步，躲过了$N这一招。\n",
	"只见$n一招「尘归尘」，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
	"$n一个「土归土」，向后纵出数丈之远，避开了$N的凌厉攻势。\n",
	"$n使出「天归天」，向一旁飘然纵出，轻轻着地。\n"
        "但是$n身形飘忽，轻轻一纵，早已避开。\n",
       "$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
        "可是$n侧身一让，$N这一招扑了个空。\n",
        "却见$n足不点地，往旁窜开数尺，躲了开去。\n",
        "$n身形微晃，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，没有办法练优游无尘步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
       return notify_fail("你的体力太差了，迈不开优游无尘步。\n");
        me->receive_damage("kee", 30);
return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("quanli") + "/wuchen-steps/" + action;
}



