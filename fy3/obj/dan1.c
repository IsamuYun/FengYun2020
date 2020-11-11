// magic_seal.c

inherit ITEM;

void create()
{
	set_name("���ߵ�",({"qingshedan"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "һ���嶾�����Ƶ���ҩ��ֻ�лƶ���С���ж���\n");
	    set("unit","��");
	    set("value", 20000);
	}
}


int unequip()
{
	set("equipped", 0);
	return 1;
}
void init()
{
  if(this_player()==environment())
	add_action("apply_medicine","yong");
}

int apply_medicine(string arg)
{
	object victim;
	if(!arg || !objectp(victim=present(arg,environment(this_player()))))
	victim = this_player();
	if(this_player()->is_fighting() || environment(victim)->query("no_magic"))
	    return notify_fail("���ڲ�����ҩ����\n");
        if(victim != this_player() && random((int)victim->query("combat_exp")) >
        (int)   this_player()->query("combat_exp"))
	{
		message_vision("$N��$n�ȵ����󵨣�������Ϲ���𣿾��Ҷ����¶�����\n",victim,this_player());
		victim->kill_ob(this_player());
		this_player()->kill_ob(victim);
		this_player()->start_busy(2);
	}
	tell_object(this_player(),"����˲�����ָ�׽����ߵ���ɷ�ĩ������ص���"+
	victim->name()+"���ϡ�\n");
		victim->apply_condition("unknown",random(20)+5);
	destruct(this_object());
	return 1;
}
