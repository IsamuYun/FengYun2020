// writted by Tiandi
inherit ITEM;
void create()
{
        set_name("���˵�", ({ "mmeng"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","һ���ɾ������湦Ч���񵤡���˵ʳ��֮����������Ѿ���ɵ����������������\n");
           set("unit", "��");
           set("value",100);
        }
        setup();
}
void init()
{
        if(this_player()==environment())
        add_action("eat_dan","eat");
}
int eat_dan(string arg)
{
        object me;
        me = this_player();
	if (arg == "mmeng")
	{
        if (me->query_temp("no_eat"))
			{
				return notify_fail("��Ŀǰ��״̬����ʹ���κ�ҩƷ��\n");
			}
        if (me->query("level")>80)
			{
				return notify_fail("��Ŀǰ��״̬����ô��Ҳû�����ˡ�\n");
			}
        message_vision("$Nһ������" + this_object()->query("name") + "������ȥ��\n", this_player());
        write("��о�����ȥ���Լ�ϸ�����ˡ�\n");
		me->add("mengzhujob",-50);
		if (me->query("mengzhujob")< 0)
		{
			me->set("mengzhujob",0);
		}
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());
	}
        return 0;
}
