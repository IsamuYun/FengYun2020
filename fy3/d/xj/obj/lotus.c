inherit ITEM;

void create()
{
	set_name("��ɽѩ��",({"snow lotus","��ɽѩ��","ѩ��"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "һ����ɽѩ��\n");
	    set("unit","��");
	    set("value", 50000);
	}
}

void init()
{
	add_action("apply_medicine","eat");
}

int apply_medicine(string arg)
{
	object me;
	
	if (arg!="snow lotus" || arg!="��ɽѩ��" || arg!="ѩ��") return 1;
	me=this_player();
	message_vision("$N����һ����ɽѩ��\n",me);
        if(!me->query("m_success/��ɽѩ��"))
        {
                me->set("m_success/��ɽѩ��",1);
                me->add("score",400);
        }


	destruct(this_object());
	return 1;
}