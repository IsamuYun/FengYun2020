// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
void create()
{
	set_name("�ּ�"NOR, ({ "gangjia" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
        set("value", 1);
		set("armor_prop/armor", 30);
		set("long", "����һ���ּס�\n");


	}
	setup();
}
