// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("�ĺ�", ({ "master hu", "master"}) );
        set("vendetta_mark","shaolin");
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("gender", "����" );
        set("chat_chance", 20);
        set("chat_msg", ({
                        name()+"��������һ���ٶ���˭����ȥ�ؾ�¥��\n"
        }) );
        set("age", 84);
	set("per", 35);
	set("agi",30);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
���������������ˣ��������ֳ������飬����ϲŭ�޳����������ؾ���
�ĵ���������֡�
\n"
	);
        create_family("������", 17, "����");
        set("combat_exp", 5000000);
        set_skill("move", 140);
        set_skill("dodge", 140);
        set_skill("force", 140);
        set_skill("literate", 140);
	set_skill("fanwen",100);
set_skill("unarmed",140);
	set_skill("puti-steps",140);
	set_skill("dabei-strike",140);
	set_skill("buddhism",160);
	set_skill("chanting",140);
	set_skill("xiaochengforce",140);
	set_skill("yiyangzhi",140);
        map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "yiyangzhi");
        set("inquiry", ([
"�ؾ�¥": "����ȥ���زؾ�¥��....��....���˾������Ҫ��������ֵģ��㲻���𣿣�answer��\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/staff")->wield();

}
/*
void attempt_apprentice(object me)
{
	if(me->query_temp("won_master_yi"))
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
                student->set("title","�����³���");
                return ;
}
void init()
{
add_action("do_answer","answer");

}
int do_answer(string arg)
{
	object ob;
if(arg == "����" ) {
command("say �ã���ȥ�ɣ�\n");
command("say �������ҵ����ͣ����ã�wave�����ſ����ϲؾ�¥��\n");
ob = new(__DIR__"obj/shouyu");
if(ob) ob->move(this_player());
return 1;
}
return 0;
}
