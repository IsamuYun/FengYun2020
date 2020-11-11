// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("Բ��", ({ "master yuan", "master"}) );
        set("nickname", HIG "ãΪ" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 10); 

        set("age", 64);
	set("agi",30);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
���ֵڶ�ʮ������ʦ������ר�Ŵ���������Ů�׼ҵ����书��
\n"
	);
        create_family("������", 22, "����");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "staff.hequhecong" :)
        }) );
        set("combat_exp", 500000);
        set_skill("move", 90);
        set_skill("dodge", 90);
        set_skill("force", 90);
        set_skill("literate", 90);
	set_skill("unarmed",90);
	set_skill("puti-steps",90);
	set_skill("dabei-strike",90);
	set_skill("buddhism",110);
	set_skill("chanting",90);
	set_skill("dachengforce",90);
	set_skill("staff",90);
	set_skill("parry",90);
	set_skill("fumostaff",90);
	map_skill("staff","fumostaff");
	map_skill("parry","fumostaff");
        map_skill("dodge", "puti-steps");
	map_skill("force", "dachengforce");
	map_skill("unarmed", "dabei-strike");
        set("inquiry", ([
"������": "�������....��....����ʲô���𣿣�answer��\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/staff")->wield();

}
/*
void attempt_apprentice(object me)
{
	if(me->query_temp("won_master_kong"))
	{
	command("smile");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("shake");
	}
}
*/
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
}
void re_rank(object student)
{
                student->set("title","�������׼ҵ���");
                return ;

}
int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name") &&
	   me->query("family/master_id") == query("id"))
        {
        command("say �ã���Ӯ���ң���Ϳ���ȥ�������и������ʦ���ˣ�\n");
        return 1;
        }
        else
        {
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say �����ӷ�ͽ����ҪŬ��ѽ��\n");
}
void lose_enemy(object winner)
{
command("say �����ӷ������ȥ�ұ��ʦ��ȥ�����ˡ�\n");
winner->set_temp("won_master_yuan",1);
}
void init()
{
add_action("do_answer","answer");

}
int do_answer(string arg)
{
if(arg == "��Ҫ��" ) {
command("say �ã���ȥ�ɣ�\n");
this_player()->set_temp("see_fangzhang",1);
}
}
