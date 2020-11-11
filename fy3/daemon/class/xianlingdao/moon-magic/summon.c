// yiru@hero

inherit SSERVER;
#include <ansi.h>

int conjure(object me, object target)
{
	int lvl;
	object soldier;

	if(me->query_temp("guards/wu"))
	{
		return notify_fail("你已经召唤武神了！\n");
	}

    if( !me->is_fighting() )
    {
		return notify_fail("只有战斗中才能召唤武神！\n");
	}
	
    lvl = me->query_skill("shuiyue-xianfa",1) + me->query_skill("five-summon",1);

    if(lvl < 500)
    {
		return notify_fail("你还没学会武神召唤术。\n");
	}
	
	if(userp(me))
	{
        if( (int)me->query("atman") < lvl)
                return notify_fail("你的灵力不够了！\n");
        if( (int)me->query("force") < lvl)
                return notify_fail("你的内力不够了！\n");
        if( (int)me->query("mana") < lvl)
                return notify_fail("你的法力不够了！\n");
        me->add("atman", -lvl);
        me->add("force", -lvl);
        me->add("mana", -lvl);
	}

	message_vision(HIW"$N运起武神召唤术...\n"NOR, me);

    soldier = new("/u/xianlingdao/npc/wu_god");
    soldier->move(environment(me));
    soldier->invocation(me, lvl);
    soldier->set("possessed", me);

    me->set_temp("guards/wu", 1);
	me->start_busy(1);
	return 1;
}
