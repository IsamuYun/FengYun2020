inherit ITEM;
void create()
{
        set_name( "铁镐", ({"gao", "mattock", "tie gao"}) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long","一根约三尺多长的铁镐。\n");
                set("material", "iron");
        }
        setup();
}
void init()
{
        add_action("do_dig","dig");
}

int do_dig()
{
        object me;
        me = this_player();
	if (!environment(me)->dig_notify()) return notify_fail("你拿出一把铁镐狠狠地向地上刨去。\n");;
    return 1;
}