inherit ITEM;

void create()
{
        set_name("�ΰ�", ({ "salt rock", "�ΰ�"}) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "һ���ΰ�\n");
	    set("unit","��");
	 set("value",10);
	}
}

void init()
{
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("ָ���ʽ: pour �ΰ� in <����>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("������û�� " + what + " ����������\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "��ʲ��Ҳû�У���װЩˮ���С�\n");

	ob->set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		]));
	message_vision("$N��" + name() + "�Ž�" + ob->name() 
		+ "��ҡ���˼��¡�\n", this_player());

	destruct(this_object());
	return 1;
}
