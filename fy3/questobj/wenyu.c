// TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
	set_name(HIG  "ǧ������" NOR, ({ "old jade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����˵���ʯ���̵�����ѽ������
����һ��С�֣���ɽ�ɣ����ƺ�����������������\n");
		set("max_cure",10);
		set("material", "stone");
	}
	init_hammer(10);
	setup();
}
void init()
{
	if(environment()==this_player())
	add_action("do_cure","cure");

}

int do_cure()
{
	object me;
	me = this_player();
	if(query("max_cure") <=0)
	return notify_fail("���������Ч�Ѿ����ù��ˣ�\n");
	if(me->query("eff_kee") == me->query("max_kee"))
	return notify_fail("������ֻ�������������ˣ�������û�ã�\n");
	me->set("eff_kee",(int)me->query("max_kee"));
	add("max_cure",-1);
	message_vision("$N��һ��ǧ����������˿��������ද��Ѫ���ܵ��˿�
��Ȼ�漣��������ˣ���\n",me);
	return 1;
}
