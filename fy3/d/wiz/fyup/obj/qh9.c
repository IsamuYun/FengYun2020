// ǿ��ʯͷ by tiandi

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIY"ǿ��ʯ" NOR, ({ "stone" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ǿ������װ����ʯͷ��ǿ���ȼ��ż���\n");
		set("qianghua",9);
		set("value", 100000);
	
	}
	setup();
}
