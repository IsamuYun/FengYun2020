// ken 1999.12.7

#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("�޺õĽ�������", ({ "goodjinyi" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����˿����Ƭ���ɵ�����������ȥ������һ�����ס�\n");
		set("material", "cloth");
                set("value", 10000);
		set("armor_prop/armor",80);		
	}
	setup();
}
