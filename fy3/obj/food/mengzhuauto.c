inherit ITEM;
void create()
{
        set_name("��������", ({ "mengzhu dan"}) );
        set_weight(350);
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("long", "ʳ�ú�һСʱ��������������Զ����㵽�����������ͽ���ڵ�.\n");
           set("unit", "��");
           //set("value", 10000);
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

		if (arg == "mengzhu dan")
		{
		me->set("mengzhuauto", (int) time()+ 3600);
        message_vision("$Nһ������" + this_object()->query("name") + "������ȥ��\n", this_player());
        write("���������������������ġ�\n");
        destruct(this_object());

	}
        return 0;
}
