// xueblade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(RED"��Ѫ��"NOR, ({ "xueblade" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "iron");
		set("long", "����һ�ѳ���а����ɱ���ĸֵ���\n");
		set("wield_msg", " $N���һ�����$n�������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_blade(50);
	setup();
}
