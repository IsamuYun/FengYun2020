// medicine.c

inherit ITEM;

void create()
{
	set_name("�ⶾ��",({"jiedu"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "һ�Žⶾ���� �����ã�����壩���ⶾ ��\n");
	    set("unit","��");
	    set("value", 10000);
	}
}

void init()
{
  if(this_player()==environment())
	add_action("apply_medicine","use");
}

int apply_medicine(string arg)
{
	if (arg == "jiedu")
	{
	if(this_player()->is_fighting())
	    return notify_fail("ս���в�����ҩ����\n");
	    
	message_vision("$N�ýⶾ���ⶾ��\n",this_player());
	this_player()->set_temp("poison_del",1);
	destruct(this_object());
	return 1;
	}
	return 0;
}

