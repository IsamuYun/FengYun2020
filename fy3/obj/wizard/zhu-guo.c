// zhu-guo.c - ���

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( HIR "���" NOR, ({ "zhu guo", "guo" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
���ǿ��Գԣ�eat����$HIR$���$NOR$��������ֻ�����ɲ�ӵ�еĶ�����
������ʹ����һ�ٵ�Ǳ�ܺ����ٵ㾭�顣
TEXT
                );
                
                set("unit", "Щ");
                set("base_unit", "��");
                set("base_weight", 500);
                set("value", 0 );
        }


        setup();
}

void get_effect( object who ) 
{
        who->add("potential", 100);
        tell_object(who, "���Ǳ��������" + chinese_number( 100 ) + "�㣡\n");
        who->add("combat_exp", 200);
        tell_object(who, "��ľ���������" + chinese_number( 200 ) + "�㣡\n");
}
