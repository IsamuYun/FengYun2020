// silver-dan.c - ����

#include <ansi.h>

inherit PILL;

void create()
{
        set_name( HIW "��ת��" NOR, ({ "silver dan", "dan" }) );

        set("no_transfer", 1);
        
        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
���ǿ����ڷ���use����$HIW$��ת��$NOR$��������ֻ�����ɲ�ӵ�еĶ�����
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

        increasement = 2000 + random( 1000 );
        who->add("potential", increasement);
        tell_object(who, "���Ǳ��������" + chinese_number( increasement ) + "�㣡\n");
}