// sppearl.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY "������" NOR, ({ "sppearl"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
         else { 
        set("long",
                "һ�Ž��ɫ�������顣\n");
        set("unit", "��");
        set("value", 10000);
               }
}



