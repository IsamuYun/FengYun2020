// gold-belt.c 黄金腰带

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
        set_name( HIY "打遍天下无敌手" NOR, ({ "gold belt", "belt" }) );

        set("no_get", 1);
        set("no_put", 1);
        set("no_drop", 1);

        set_weight( 1000 );

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @TEXT
这是一条表面镶满珠宝的$HIY$黄金腰带$NOR$。
上面刻着一行金字：“$HIY$打遍天下无敌手$NOR$！”
它的价值不在于它的名贵，而是因为它是荣誉的象征。
TEXT
                );

                set("unit", "件");
                set("value", 0);

                set("material", "gold");
                set("armor_type", TYPE_WAIST);

                set("armor_prop/armor", 5 );
                set("armor_prop/defense", 5 );
                set("armor_prop/dodge", 5 );
        }
        
        setup();
}
