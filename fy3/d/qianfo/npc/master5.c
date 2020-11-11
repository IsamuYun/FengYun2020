// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("�δ�", ({ "master renci", "master"}) );
        set("nickname", HIR "ǰ�ΰ���" NOR);
    set("reward_npc", 1);
    set("difficulty", 80); 

        set("gender", "����" );
        set("age", 64);
	set("per", 25);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 30);
        set("long",
"
�δ���ؤ���ǰ�ΰ�����ֻ���������ಡ����λ���Ϲ�
\n"
	);
        create_family("ؤ��", 6, "����");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :)
        }) );
        set("combat_exp", 4000000);
        set_skill("move", 150);
        set_skill("parry",150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("literate", 80);
	set_skill("unarmed",150);
        set_skill("begging",150);
        set_skill("inquiry",150);
	set_skill("doggiesteps",150);
	set_skill("dragonstrike",150);
	set_skill("huntunforce",150);
	set_skill("staff",150);
	set_skill("dagou-stick",150);
        set("inquiry", ([
                "�Ϲ���" : (: kill_him :),
                "master nangong" : (: kill_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/9bagcloth")->wear();

}
/*
void attempt_apprentice(object me)
{
	if((int)me->query_temp("killed_master_nangong"))
	{
	command("say ������Ϊ���ֳ�һ�󺦵ķ��ϣ��Ҿ�����Ϊͽ�ɣ�\n");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("sigh");
        command("say ���Ѿ������ǰ����ˣ��㻹��ȥ���Ϲ��ɣ�\n");

	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "beggar");
}
int kill_him()
{
	command("say �Ϲ�������ΪТ˳��ÿ������һ�룬��δ��ϣ�\n");
	return 1;
}
void re_rank(object student)
{
	int exp;
	exp = (int) student->query("combat_exp");
	if( exp <= 32000 ) {
		student->set("title","ؤ���������");
		return ;	
	} else if ( exp <= 64000 ) {
		student->set("title","ؤ��һ������");
		return ;
        } else if ( exp <= 128000 ) {
                student->set("title","ؤ����������");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","ؤ����������");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","ؤ���Ĵ�����");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","ؤ���������");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","ؤ����������");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","ؤ���ߴ�����");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","ؤ��˴�����");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","ؤ��Ŵ�����");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","ؤ�ﳤ��");
                return ;
        } else 
                student->set("title","ؤ�︱����");
                return ;

}
*/
