// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
void create()
{
	set_name(HIY"��˿���"NOR, ({ "ruanjia" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
        set("value", 1);
		set("armor_prop/armor", 200);
		set("long", "����һ���ƽ�ǽ����·��µ���ף������ķų�
���˵Ľ�ɫ��â��һ�������������䡣\n");


	}
	setup();
}
