// level sheet.c by tiandi

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW  "ұ����" NOR, ({ "level sheet" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ŷ��䣬�ƺ���������ĳ�����ص�������\n");
		set("value", 100000);
	
	}
	setup();
}
