inherit ITEM;
void create()
{
        set_name( "����", ({"gao", "mattock", "tie gao"}) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ��Լ���߶೤�����䡣\n");
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
	if (!environment(me)->dig_notify()) return notify_fail("���ó�һ������ݺݵ��������ȥ��\n");;
    return 1;
}