// gold.c
#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(HIY "�Ϲ���Ʊ" NOR, ({"gold"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "gold");
                set("long", HIY "�ƳγεĽ��ӣ��˼��˰��Ľ��ӣ����������ӣ�\n" NOR);
		set("unit", "Щ");
		set("base_value", 10000 );
		set("base_unit", "��");
		set("base_weight", 37);
	}
        set_amount(100+random(100));
}

