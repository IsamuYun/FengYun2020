// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("�γ�", ({ "master meng", "master"}) );
        set("nickname", HIC "��˪" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("age", 64);
	set("agi",30);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
���ֵڶ�ʮ�����ϣ�ר�Ŵ������ֹ�ɮ�书��\n"
	);
        create_family("������", 20, "����");
        set("combat_exp", 900000);
        set_skill("move", 110);
        set_skill("dodge", 110);
        set_skill("force", 110);
        set_skill("literate", 110);
	set_skill("unarmed",110);
	set_skill("puti-steps",110);
	set_skill("dabei-strike",110);
	set_skill("buddhism",130);
	set_skill("chanting",110);
	set_skill("xiaochengforce",70);
	set_skill("staff",110);
	set_skill("parry",110);
	set_skill("fumostaff",110);
	set_skill("blade",110);
	set_skill("lianxin-blade",110);
	set_skill("xingyi-stick",110);
	map_skill("staff","xingyi-stick");
	map_skill("parry","lianxin-blade");
        map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "dabei-strike");
	map_skill("blade","lianxin-blade");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/staff")->wield();

}
/*
void attempt_apprentice(object me)
{
	if(me->query("gender") != "����")
	{
	command("say ���ֹ�ɮֻ�������е��ӡ�����\n");
	return;
	}
	if(me->query_temp("won_master_xu"))
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
                student->set("title","�����¹�ɮ");
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
winner->set_temp("won_master_meng",1);
}
