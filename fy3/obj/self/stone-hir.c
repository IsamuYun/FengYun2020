// stone-hir.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "��ɫ��ʯ" NOR, ({ "red stone", "stone" }) );
	set_weight( 10000 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ɫ����ʯ�����溬��һЩϡ�е����ʡ�\n");
		set("value", 100);
    };
}

