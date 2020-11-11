// banker.c

#include <ansi.h>

inherit NPC;
inherit F_BANKOWNER;
int askfor();

void create()
{
        set_name("�Ϲ�ʮ����", ({ "shier" }) );
        set("title", RED "Ǯׯ����" NOR);
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("age", 22);
        set("richness",5000000);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long",
                
                "��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����Ϲ�ʮ������Ǯׯ����\n");

        set("combat_exp", 1000000);
        set("attitude", "friendly");

        set("max_atman", 1000);
        set("atman", 1000);
        set("atman_factor", 3);
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 3);
        set("max_mana", 1000);
        set("mana", 1000);
	set("mana_factor", 3);

        set("chat_chance", 3 );
        set("chat_msg", ({
                (: exert_function, "powerfade" :),
        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("celestrike", 100);
        set_skill("celestial", 100);
        set_skill("chaos-steps", 100);

        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");
        map_skill("dodge", "chaos-steps");
        
        set("inquiry", ([
                "����" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
                "rob" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
	    "������װ" : (: askfor :),

        ]) );

        setup();
        
        carry_object("/obj/cloth")->wear();

     //   add_money("gold", 10);
}

void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
        add_action("do_loan","loan");
}
int askfor()
{
	object ob,me,obj;
	me = this_player();
	ob = this_object();

	if (me->query("marks/newbie"))
		{
		message_vision("$n�ɻ��Ŷ���$N˵�����㲻���Ѿ��ù�������װ�ˣ�\n",me,ob);
		return 1;
		}
	if (!me->query_temp("askfornewbie"))
		{
		message_vision("$n�ɻ��Ŷ���$N˵����������ʲô��\n",me,ob);
		return 1;
		}
	else 	if (me->query_temp("askfornewbie")>1 && me->query_temp("askfornewbie") < 3)
                   {
		me->set_temp("askfornewbie",3);
		message_vision(me->query("name")+"�����Ϲ�ʮ�����ʵ���ʮ������˵�Ѿ���ʮ�����������˵�һ�������ӻ��ˣ��Ƿ����д��£�\n
�Ϲ�ʮ���ɶ���"+me->query("name")+"���˵�ͷ��\n�Ϲ�ʮ���ɻش�"+me->query("name")+"����һ�������ӣ�ǰЩ������ȷʵ��ʮ�����ˣ���ô��ʲô������\n
��������������������˰ɣ��Ͻ���ȥ����������˰ɡ�\n",me);
		return 1;
	}else
	message_vision("$n�ɻ��Ŷ���$N˵�����㻹��������ʲô��\n",me,ob);
	return 1;
}


