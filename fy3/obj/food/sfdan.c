// writted by Tiandi
inherit ITEM;
void create()
{
    set_name("ʮ����Ǳ��", ({ "sfdan"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","һ����ĳ����������������ʮ����Ǳ������˵ʳ��֮�����ʹ�˽�һ���־���ת��ΪǱ�ܡ�\n");
           set("unit", "��");
           set("value",50000);
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
        int exp,pot;	
        me = this_player();
	if (arg == "sfdan")
	{
        exp = (int)me->query("combat_exp");
        if (exp < 2000000 ) 
           return notify_fail("��ľ��黹������ʹ�ô˵�ҩ��\n");
        me ->set("combat_exp",exp - 100000);
        me ->add("potential",10000);
        message_vision("$Nһ������" + this_object()->query("name") + "������ȥ��\n", this_player());
        write("��о�Ǳ�������ˣ�\n");
        destruct(this_object());
	}
        return 0;
}
