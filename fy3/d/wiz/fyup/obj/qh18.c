// ǿ��ʯͷ by tiandi

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIR"ǿ��ʯ" NOR, ({ "stone" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ǿ������װ����ʯͷ��ǿ���ȼ�ʮ�˼���\n");
		set("qianghua",18);
		set("value", 100000);
	
	}
	setup();
}
