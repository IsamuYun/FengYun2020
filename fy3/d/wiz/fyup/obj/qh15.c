// ǿ��ʯͷ by tiandi

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(MAG"ǿ��ʯ" NOR, ({ "stone" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ǿ������װ����ʯͷ��ǿ���ȼ�ʮ�弶��\n");
		set("qianghua",15);
		set("value", 100000);
	
	}
	setup();
}
