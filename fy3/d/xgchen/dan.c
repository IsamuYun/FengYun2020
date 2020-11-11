// shendan.c - 神丹

#include <ansi.h>

inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name( HIW "神丹" NOR, ({ "shen dan", "dan" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是长孙无情的私人礼物，由于$HIW$神丹$NOR$存放的时间太久，可能已经变味了。
TEXT
                );
                
                set("unit", "颗");
                set("base_unit", "个");
                set("base_weight", 500);
                set("value", 0 );
        }


        setup();
}

void get_effect( object who ) 
{
        who->add("potential", -1);
        tell_object(who, "今天是愚人节，祝你节日快乐，你的潜能减少了" + chinese_number( 1 ) + "点！\n");
        who->add("combat_exp", -2);
        tell_object(who, "今天是愚人节，祝你节日快乐，你的经验减少了" + chinese_number( 2 ) + "点！\n");
}

