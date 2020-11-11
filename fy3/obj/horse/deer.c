// deer.c

inherit ITEM;

#define MAX_LIFE        50

void create()
{
        set_name("梅花鹿", ({ "deer" }) );
        set("horse_prop/max_life", MAX_LIFE);
        set("horse_prop/life", MAX_LIFE);
        set_max_encumbrance(100000);
        set("no_put", 1);
        set("prep", "on");
        set_weight( 0 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", @LONG 
这是一只梅花鹿，它可以快速地使你到达某个地方。而且还可以帮你运东西。
LONG
                );

                set("value", 100000);
    };
}

int is_container() { return 1; }
