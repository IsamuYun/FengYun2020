// huantong-dan.c - ��ͯ��
// bye ��(Zen)
#include <ansi.h>

inherit PILL;

void create()
{
        set_name( HIC "��ͯ��" NOR, ({ "huantong dan", "dan" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
����һ�Ų��ɶ�õĻ�ͯ������ʦ�����������й��׵��ˡ�
TEXT
                );
                
                set("unit", "Щ");
                set("base_unit", "��");
                set("base_weight", 200);
                set("value", 0 );
        }

        set_amount(1);

        setup();
}

void get_effect( object who ) 
{
        who->add("mud_age", -86400);
        who->add("age", -1);
        tell_object(who, "�㿴����������������ࡣ\n");
}
