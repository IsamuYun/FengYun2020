// writted by Tiandi
inherit ITEM;
void create()
{
        set_name("������", ({ "fsdan"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","һ����ĳ���������������ķ���������˵ʳ��֮�����ʹ�˻ָ�������\n");
           set("unit", "��");
           set("value",100);
		   set("pet_gin",32000);
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
 	if (arg == "fsdan")
	{
       me ->add("lifetili",200);
	if (me->query("lifetili") >  me->query("max_lifetili"))
		me->set("lifetili",me->query("max_lifetili"));
        message_vision("$Nһ������" + this_object()->query("name") + "������ȥ��\n", this_player());
        write("��о����������ˡ�\n");
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());
	}
        return 0;
}
