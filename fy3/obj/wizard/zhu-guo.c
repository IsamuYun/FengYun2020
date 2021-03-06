// zhu-guo.c - 朱果

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( HIR "朱果" NOR, ({ "zhu guo", "guo" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是可以吃（eat）的$HIR$朱果$NOR$，它们是只有神仙才拥有的东西。
它可以使你获得一百点潜能和两百点经验。
TEXT
                );
                
                set("unit", "些");
                set("base_unit", "个");
                set("base_weight", 500);
                set("value", 0 );
        }


        setup();
}

void get_effect( object who ) 
{
        who->add("potential", 100);
        tell_object(who, "你的潜能增加了" + chinese_number( 100 ) + "点！\n");
        who->add("combat_exp", 200);
        tell_object(who, "你的经验增加了" + chinese_number( 200 ) + "点！\n");
}
