// level sheet.c by tiandi

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW  "�����ĲƱ�" NOR, ({ "money box" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ɵ�Ĺ��͵�ڳ����ĲƱ��䡣\n");
		set("value", 100000);
	
	}
	setup();
}
