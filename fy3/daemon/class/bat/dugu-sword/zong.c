// po.c ���ܾ�ʽ��
 
#include <ansi.h>
inherit SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon;
	int skill, jing_cost;

	skill = me->query_skill("dugu-sword",1);
	jing_cost = (int)me->query("int") - 45;

        if((string) me->query("class") != "huashan" )
		return notify_fail("�㲻�ǻ�ɽ�ɵĵ��ӣ�����ʹ�á��ܾ�ʽ����\n");

	if( me->is_fighting() )
		return notify_fail("���ܾ�ʽ��������ս����������\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("�������ȥ��һ�ѽ���\n");

	if( !skill || (skill < 20))
		return notify_fail("��Ķ��¾Ž��ȼ�����, �����������ܾ�ʽ����\n");
	if( !skill || (skill > 1000))
		return notify_fail("��Ķ��¾Ž��ȼ��Ѿ����˼�����, �����������ܾ�ʽ����\n");

	if( me->query("force") < 50 )
		return notify_fail("�������������û�������������ܾ�ʽ����\n");
 
	if( me->query("gin") < -jing_cost )
		return notify_fail("������̫���ˣ��޷����о����������ܾ�ʽ����\n");

	msg = HIC "$Nʹ�����¾Ž�֮���ܾ�ʽ����������" + weapon->name() + "���������̡�\n";
	message_vision(msg, me);

	me->add("force", -50);
	me->add("gin", jing_cost);

	if ( skill < 60)
		me->improve_skill("dugu-sword", 10);
	else if (skill < 90)
		me->improve_skill("dugu-sword", 10 + random((int)me->query("int") - 9));
	else if (skill < 140)
		me->improve_skill("dugu-sword", 10 + random((int)me->query("int") * 2 - 9));
	else if (skill < 200)
		me->improve_skill("dugu-sword", 10 + random((int)me->query("int") * 4 - 9));
	else
		me->improve_skill("dugu-sword", 10 + random((int)me->query("int") * 8 - 9));

	msg = MAG"$P�ġ����¾Ž��������ˣ�\n"NOR;
	me->start_busy(3+random(3));

	message_vision(msg, me);

	return 1;
}
