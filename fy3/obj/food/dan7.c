// writted by Tiandi
inherit ITEM;
void create()
{
        set_name("�����ɵ�", ({ "lydan"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","һ����ĳ���������������������ɵ�����˵ʳ��֮����Իָ��������ĵ�������\n");
           set("unit", "��");
           set("value",100);
		   set("pet_gin",8000);
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
	if (arg == "lydan")
	{
        if (me->query_temp("no_eat"))
			{
				return notify_fail("��Ŀǰ��״̬����ʹ���κ�ҩƷ��\n");
			}
        me ->add("force",2500);
		if (me->query("force")>me->query("max_force"))
		{
			me->set("force",me->query("max_force"));
		}
        message_vision("$Nһ������" + this_object()->query("name") + "������ȥ��\n", this_player());
        write("��о������ָ��ˡ�\n");
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());

	}
        return 0;
}