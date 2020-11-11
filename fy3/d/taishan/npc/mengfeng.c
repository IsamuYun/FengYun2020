
inherit NPC;

void create()
{
        set_name("�ɹŴ�", ({ "menggu" }) );
	set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 90); 

	set("age", 42);
	set("long",
                "���������ɹŵı��δ󺺡�\n");
        set("combat_exp", 1500000);
        set("per",10);
        set("max_kee",10000);
        set("kee",10000);
        set("max_atman",100);
        set("atman",100);
	set("attitude", "friendly");
	set_skill("iron-cloth", 200);
	set_skill("jin-gang",100);
	set_skill("unarmed", 100);
	set_skill("bloodystrike", 100);
	map_skill("unarmed", "bloodystrike");
	map_skill("iron-cloth", "jin-gang");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:
message_vision("$Nһ��ͷ������ԭ�ķ羰��Ĳ���\n",this_object());
			break;
		case 1:
message_vision("$N�����˵�����ɨ��$nһ�ۣ��ƺ������л������ĳ\n",this_object(),ob);
			break;
		case 2:
message_vision("$N�þ�����������´�����$n��\n",this_object(),ob);
			break;
	}
}
void die()
{
        object me;
        me=this_object()->query_temp("last_damage_from");
        if(objectp(me))
        me->set_temp("marks/menggu",1);
::die();
}

