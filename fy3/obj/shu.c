// movebook.c


#include <ansi.h>
inherit ITEM;


void create()
{
	set_name("����", ({ "shu" }));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("for_badp",1);
		set("long",
			"һ������ˮ��ξ�ٶ����š�\n");
	set("value", 0);
		


	}
	setup();
}


