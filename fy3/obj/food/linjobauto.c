inherit ITEM;
void create()
{
        set_name("��ϸ����", ({ "linjob dan"}) );
        set_weight(350);
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("long", "ʳ�ú�һСʱ������ϸ������Զ����㵽��ϸ���ڵ�.\n");
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

		if (arg == "linjob dan")
		{
		me->set("linjobauto", (int) time()+ 3600);
        message_vision("$Nһ������" + this_object()->query("name") + "������ȥ��\n", this_player());
        write("��Լ�ϸ������������ġ�\n");
        destruct(this_object());

	}
        return 0;
}
