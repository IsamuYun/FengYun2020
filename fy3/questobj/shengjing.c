#include <ansi.h>
#include <armor.h>

inherit ITEM;

void create()
{
	set_name(CYN "ʥ��" NOR, ({ "shengjing"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����������д��ʥ����\n");
		set("unit", "��");
		
		
	}
	setup();
}

