// writted by Tiandi
inherit ITEM;
void create()
{
        set_name("���ڵ�", ({ "mhyr"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","һ���ɾ������湦Ч���񵤡���˵ʳ��֮����������Ѿ���ɵĺ����������������\n");
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
	if (arg == "mhyr")
	{
        if (me->query_temp("no_eat"))
			{
				return notify_fail("��Ŀǰ��״̬����ʹ���κ�ҩƷ��\n");
			}
        if (me->query("level")>50)
			{
				return notify_fail("��Ŀǰ��״̬����ô��Ҳû�����ˡ�\n");
			}
        message_vision("$Nһ������" + this_object()->query("name") + "������ȥ��\n", this_player());
        write("��о�����ȥ���Ժ����������ˡ�\n");
		me->add("killhyr",-50);
		if (me->query("killhyr")<0)
		{
			me->set("killhyr",0);
		}
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());
	}
        return 0;
}
