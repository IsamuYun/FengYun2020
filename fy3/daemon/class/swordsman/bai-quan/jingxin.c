// counterattack.c

#include <ansi.h>
#include <command.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl;
	int gin,kee,sen,eff_gin,eff_kee,eff_sen;
	if( !target ) target = me;
	if(me->is_fighting() )
		return notify_fail("�۾��ķ��ݲ�����ս����ʹ�á�\n");
	if( target != me)
		return notify_fail("�۾��ķ���ֻ�ܶ��Լ�ʹ�á�\n");
        lvl = (int)me->query_skill("bai-quan");
	if(!me->query("marks/�׼���"))
		return notify_fail("��İ׼�ȭ���������\n");	

	msg = YEL "$N����ƽ����̤̤ʵʵ��ʩչ��һ�˰׼�ȭ��\n" NOR;
	gin = (int)me->query("gin");
        kee = (int)me->query("kee");
        sen = (int)me->query("sen");
        eff_gin = (int)me->query("eff_gin");
        eff_kee = (int)me->query("eff_kee");
        eff_sen = (int)me->query("eff_sen");

	if(lvl+gin > eff_gin) me->set("gin",eff_gin); else me->add("gin", lvl);
        if(lvl+kee > eff_kee) me->set("kee",eff_kee); else me->add("kee", lvl);
        if(lvl+sen > eff_sen) me->set("sen",eff_sen); else me->add("sen", lvl);
	me->add("bellicosity",-lvl);
        message_vision(msg, me);
	me->start_busy(8);
	return 1;
}
