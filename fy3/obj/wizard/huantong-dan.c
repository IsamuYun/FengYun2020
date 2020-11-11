// huantong-dan.c - 还童丹
// bye 禅(Zen)
#include <ansi.h>

inherit PILL;

void create()
{
        set_name( HIC "还童丹" NOR, ({ "huantong dan", "dan" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是一颗不可多得的还童丹，巫师用它来奖励有贡献的人。
TEXT
                );
                
                set("unit", "些");
                set("base_unit", "颗");
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
        tell_object(who, "你看起来好象年轻了许多。\n");
}
