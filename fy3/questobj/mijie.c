#include <ansi.h>
inherit ITEM;
inherit F_FOOD;


void create()
{
        set_name(HIC "��ƽ�۽�" NOR, ({ "mijie"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���ǹ�ƽ�ӳ��Ե��۽�\n");
                set("unit", "��");
                set("food_remaining", 3);
                set("food_supply", 20);
                set("value", 500);
                set("eat_msg", "$N��һ��$n���������\n");
                set("tu_msg", "$N��$n�ĺ����˳�����\n");
     }
       setup();
}
 
