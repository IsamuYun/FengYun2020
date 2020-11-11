// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("һ��", ({ "master yi", "master"}) );
        set("nickname", HIM "����" NOR);
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
���ֵ�ʮ�˴����ϣ�ר�Ŵ������ֽ���书��\n"
	);
        create_family("������", 18, "����");
        set("combat_exp", 1300000);
        set_skill("move", 130);
        set_skill("dodge", 130);
        set_skill("force", 130);
        set_skill("literate", 130);
	set_skill("unarmed",130);
	set_skill("puti-steps",130);
	set_skill("dabei-strike",130);
	set_skill("buddhism",150);
	set_skill("chanting",130);
	set_skill("xiaochengforce",100);
	set_skill("staff",130);
	set_skill("parry",130);
	set_skill("fumostaff",130);
	set_skill("blade",130);
	set_skill("sword",130);
	set_skill("whip",130);
	set_skill("tianlongwhip",130);
	set_skill("suiyuan-sword",130);
	set_skill("lianxin-blade",130);
	set_skill("xingyi-stick",130);
	map_skill("sword","suiyuan-sword");
	map_skill("staff","xingyi-stick");
	map_skill("parry","lianxin-blade");
        map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "dabei-strike");
	map_skill("blade","lianxin-blade");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();

}
/*
void attempt_apprentice(object me)
{
	if(me->query("gender") != "����")
	{
	command("say ���ֽ��ֻ�������е��ӡ�����\n");
	return;
	}
	if(me->query_temp("won_master_di"))
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
                student->set("title","�����½��");
                return ;

}
int accept_fight(object me)
{
        
        command("say �ã���Ӯ���ң���Ϳ���ȥ�������и������ʦ���ˣ�\n");
        return 1;
        }
       
void win_enemy(object loser)
{
command("say �����ӷ�ͽ����ҪŬ��ѽ��\n");
}
void lose_enemy(object winner)
{
command("say �����ӷ������ȥ�ұ��ʦ��ȥ�����ˡ�\n");
winner->set_temp("won_master_yi",1);
}
int valid_leave(object me, string dir)
{
if(dir == "north" && !me->query_temp("won_master_yi"))
{
message_vision("һ�ɴ�����$N���˻�����
һ�����ϵ�����˵��������һ��������һ�أ��ſ��Դ�ľ���\n",me);
return notify_fail("");
}
return 1;
}

