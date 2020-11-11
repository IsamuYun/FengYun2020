
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��������", ({ "song" }) );
        set("gender", "����" );
        set("age", 65);
    set("reward_npc", 1);
    set("difficulty", 20); 

        set("str", 6);
	set("title", HIG "�꺮����" NOR);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);
	  set_temp("kf_tufei",57);
        set("pursuer", 1);

	set("intellgent",1);
        set("attitude", "peaceful");

        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );


        set("long",     "������̵����󻤷�֮һ\n");


        set("combat_exp", 999999);

        set_skill("unarmed", 120);
        set_skill("throwing", 100);
	set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);

        set_skill("demon-force", 100);
        set_skill("demon-strike", 80);
        set_skill("demon-steps", 10);

        map_skill("unarmed", "demon-strike");
        map_skill("dodge", "demon-steps");

        setup();

        carry_object(__DIR__"obj/stone")->wield();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        object me;
        me = this_player();
        if(interactive(me) && me->query("marks/����˪")
        && (int) me->query("combat_exp") > 20000) call_out("chase_him", 1,me );


}

int chase_him(object me)
{
	message_vision("$N��$n�ȵ�������͵�����̵���ɲ�ƣ�������\n",this_object(),me);
	set_leader(me);
	kill_ob(me);	
	me->kill_ob(this_object());
	return 1;
}
int accept_object(object who, object ob)
{
	if( (string)ob->query("name") == "��ɲ��")
	{
		who->set("marks/����˪",0);
		message_vision("$N��$n�����������ǵ�ǰ�Ӿ�Թ��һ��赣�������\n",this_object(),who);
		who->remove_all_killer();
		return 1;
	}
	return 0;
}
