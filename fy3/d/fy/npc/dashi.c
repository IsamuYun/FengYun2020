// waiter.c

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("�ҳ���", ({ "xian" }) );
	set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 20); 

	set("age", 45);
       set("reward_npc", 1);
        set("difficulty", 20); 
	set("title",HIY  "�����Ѳ�" NOR);
	set("long",
		"��λ�������Ѳ������ҳ��������۹��ܵ�������\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set_skill("unarmed",250);
	set("force",10000);
	set("max_force",10000);
	set("force_factor",50);
	set_skill("dodge",50);
	setup();
	carry_object(__DIR__"obj/daopao")->wear();
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
	switch( random(3) ) {
		case 0:
message_vision("$N��$n˵������ӡ�÷��ڣ�ɲ��͸��ͥ�����죡����֮��һ����ʬ��ͷ��\n",this_object(),ob);
			break;
		case 1:
message_vision("$N��$n��Цһ�����㻹��ȥ���ڹײİɣ�\n",this_object(),ob);
			break;
		case 2:
message_vision("$N����$nһ�ۣ�һ�Ҵ�С���ٶ����ˣ�������\n",this_object(),ob);
			break;
	}
}

int accept_object(object me, object obj)
{
	if( (int) obj->value() >= (10000000))
	{
		message_vision("$N������һ�꣡����\n",me);
me->add("mud_age",3600*24*2);
		return 1;	
	}
}
