//copy to /d/shenshui/npc/obj/kuzhi.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("����֦", ({ "kuzhi" }) );
	set_weight(4000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
		set("long", "��֦����ͨ�����������пڿ��������ý������ģ�\n");
	}
	init_blade(5);
	setup();
}
