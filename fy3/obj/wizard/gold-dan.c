// gold-dan.c - ��ת��

#include <ansi.h>

inherit PILL;

void create()
{
        set_name( HIY "��ת��" NOR, ({ "gold dan", "dan" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
���ǿ����ڷ���use����$HIY$��ת��$NOR$��������ֻ�����ɲ�ӵ�еĶ�����
TEXT
                );
                
                set("unit", "Щ");
                set("base_unit", "��");
                set("base_weight", 10);
                set("value", 0 );
        }

        set_amount(1);

        setup();
}

void get_effect( object who ) 
{
        int increasement;

        increasement = 3000 + random( 2000 );
        who->add("potential", increasement);
        tell_object(who, "���Ǳ��������" + chinese_number( increasement ) + "�㣡\n");
}
