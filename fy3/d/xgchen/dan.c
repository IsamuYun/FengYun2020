// shendan.c - ��

#include <ansi.h>

inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name( HIW "��" NOR, ({ "shen dan", "dan" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
���ǳ��������˽���������$HIW$��$NOR$��ŵ�ʱ��̫�ã������Ѿ���ζ�ˡ�
TEXT
                );
                
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 500);
                set("value", 0 );
        }


        setup();
}

void get_effect( object who ) 
{
        who->add("potential", -1);
        tell_object(who, "���������˽ڣ�ף����տ��֣����Ǳ�ܼ�����" + chinese_number( 1 ) + "�㣡\n");
        who->add("combat_exp", -2);
        tell_object(who, "���������˽ڣ�ף����տ��֣���ľ��������" + chinese_number( 2 ) + "�㣡\n");
}

