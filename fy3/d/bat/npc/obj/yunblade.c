// yunblade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(MAG"嫺�����"NOR, ({ "yunblade" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("material", "iron");
		set("long", "����һ������ѩ���ĳ��������м�������Ѫ��������
������ƥ��ӳ��������\n");
		set("wield_msg", "ֻ�������һ����$n���ʷɳ�������Ծ��$N
���С�˲ʱ��ʼ���Ʊ�ɫ������������������һƬ�ޱ�ɱ�⡣\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_blade(400);
	setup();
}
