inherit ITEM;
void create()
{
        set_name("ɽ�μ���", ({ "jiduan"}) );
        set_weight(350);
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("long", "һֻ��ĳ��������⿵�ɽ�μ��Σ���������θ�ڴ󿪣�����һ����ҩ�ü�ֵ!\n");
           set("unit", "ֻ");
           set("value", 10000);
		   set("pet_kee",128000);
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

		if (arg == "jiduan")
		{
			if (me->query_temp("no_eat"))
			{
				return notify_fail("��Ŀǰ��״̬����ʹ���κ�ҩƷ��\n");
			}
		me->set("kee",me->query("max_kee"));
		me->set("eff_kee",me->query("max_kee"));
        message_vision("$Nһ������" + this_object()->query("name") + "������ȥ��\n", this_player());
        write("��о���Ѫ�ָ��ˡ�\n");
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());

	}
        return 0;
}
