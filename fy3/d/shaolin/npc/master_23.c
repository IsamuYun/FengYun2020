// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("����", ({ "master kong", "master"}) );
        set("nickname", HIG "��Ϊ" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "����" );
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
        create_family("������", 23, "����");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :)
        }) );
        set("combat_exp", 300000);
        set_skill("move", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("literate", 80);
	set_skill("unarmed",80);
	set_skill("puti-steps",80);
	set_skill("dabei-strike",80);
	set_skill("buddhism",100);
	set_skill("chanting",70);
	set_skill("dachengforce",80);
        map_skill("dodge", "puti-steps");
	map_skill("force", "dachengforce");
	map_skill("unarmed", "dabei-strike");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();


}
/*
void attempt_apprentice(object me)
{
	if((int)me->query_skill("dabei-strike",1)>=30 && 
(int)me->query_skill("puti-steps",1)>=30)
	{
	command("smile");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("smile");
        command("say ��ʦҪ�г��⣬����ȥѧѧ���İɣ�\n");

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
winner->set_temp("won_master_kong",1);
}
