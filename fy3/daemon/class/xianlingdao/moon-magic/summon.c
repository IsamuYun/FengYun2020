// yiru@hero

inherit SSERVER;
#include <ansi.h>

int conjure(object me, object target)
{
	int lvl;
	object soldier;

	if(me->query_temp("guards/wu"))
	{
		return notify_fail("���Ѿ��ٻ������ˣ�\n");
	}

    if( !me->is_fighting() )
    {
		return notify_fail("ֻ��ս���в����ٻ�����\n");
	}
	
    lvl = me->query_skill("shuiyue-xianfa",1) + me->query_skill("five-summon",1);

    if(lvl < 500)
    {
		return notify_fail("�㻹ûѧ�������ٻ�����\n");
	}
	
	if(userp(me))
	{
        if( (int)me->query("atman") < lvl)
                return notify_fail("������������ˣ�\n");
        if( (int)me->query("force") < lvl)
                return notify_fail("������������ˣ�\n");
        if( (int)me->query("mana") < lvl)
                return notify_fail("��ķ��������ˣ�\n");
        me->add("atman", -lvl);
        me->add("force", -lvl);
        me->add("mana", -lvl);
	}

	message_vision(HIW"$N���������ٻ���...\n"NOR, me);

    soldier = new("/u/xianlingdao/npc/wu_god");
    soldier->move(environment(me));
    soldier->invocation(me, lvl);
    soldier->set("possessed", me);

    me->set_temp("guards/wu", 1);
	me->start_busy(1);
	return 1;
}
