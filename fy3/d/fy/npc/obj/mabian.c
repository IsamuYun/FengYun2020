inherit ITEM;

void create()
{
        set_name("���",({ "mabian" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
                set("long", "һ����ӣ���,����ȥ����˦��(wave)һ�¡��\n");
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

        message_vision("$N����һ��" + this_object()->name() + "˦��˦��\n", this_player() );
        environment(this_player())->mabian_notify();;

        return 1;
}
