inherit ITEM;

void create()
{
        set_name("马鞭",({ "mabian" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "steel");
                set("long", "一根红樱马鞭,看上去可以甩动(wave)一下。n");
            set("value", 50000);
        }
}

void init()
{
        add_action("do_wave", "wave");
}

int do_wave(string arg)
{
        if( arg != "mabian" ) return 0;

        message_vision("$N拿起一根" + this_object()->name() + "甩了甩。\n", this_player() );
        environment(this_player())->mabian_notify();;

        return 1;
}
