// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("�����", ({ "master yu", "master"}) );
        set("nickname", HIR "��ʤ��ħ" NOR);
    set("reward_npc", 1);
    set("difficulty", 100); 
	set("class","mojiao");
        set("gender", "����" );
        set("age", 64);
	set("attitude","friendly");
        set("max_force", 75000);
        set("force", 75000);
        set("force_factor", 30);
        set("long",
"
���������������еĽ���������׵�����˭Ҳ�������
Ҳû�˸��ʡ������ʹ���֪��������������˶��������׵�
��ʧ�ˡ�
\n"
	);
        create_family("�������", 1, "����");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: exert_function, "mihun" :)
        }) );
        set("combat_exp", 100000000);
        set("score", 200000);

        set_skill("move", 200);
        set_skill("parry",400);
        set_skill("dodge", 200);
        set_skill("force", 500);
        set_skill("literate", 500);
	set_skill("unarmed",200);
	set_skill("demon-steps",1000);
	set_skill("demon-strike",1000);
	set_skill("demon-force",1000);
	set_skill("blade",1000);
	set_skill("demon-blade",1000);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
	map_skill("blade","demon-blade");
	map_skill("parry","demon-blade");
        set("inquiry", ([
                "������" : (: kill_him :),
                "������" : (: kill_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/wufu")->wear();
	carry_object(__DIR__"obj/lou")->wield();

}
void attempt_apprentice(object ob)
{
	if( ob->query("class")&&ob->query("class") != "mojiao")
	{
	command("stare");
	command("say ���Ѿ����Լ��������ˣ�\n");
	}
	else if( ob->query("national") == "�ɹ���" )
	{
	command("smile");
	command("say �������Ϸ�����������\n");
            command("recruit " + ob->query("id") );
	}
	else
	command("say ħ��ֻ���ɹ����ˣ�\n");
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mojiao");
}
int kill_him()
{
	object me;
	me = this_player();
	command("say �������Ѿ�֪���ҵ������ˣ��� \n");
	this_object()->kill_ob(me);
	me->kill_ob(this_object());
	return 1;
}
int accept_object(object me, object obj)
{
	if(obj->query("for_bandit"))
	{
	command("? "+me->query("id"));
        command("say �㣮����ɱ�˱��̵��ˣ�͵�˱��̵Ķ�������������Ū�Ϸ�\n");
	this_object()->kill_ob(me);
	me->kill_ob(this_object());
	return 1;
	}
	if(obj->query("for_bandit2"))
	{
	me->set_temp("for_bandit",1);
	command("smile");
	command("say �ã��ܺ�.\n");
	return 1;	
	}
	return 0;
}
void re_rank(object student)
{
	int exp;
	exp = (int) student->query("level");
	if( exp <= 10 ) {
		student->set("title","������̽�ͽ");
		return ;	
	} else if ( exp <= 20 ) {
		student->set("title","������̸�����");
		return ;
        } else if ( exp <= 30 ) {
                student->set("title","�����������");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","������̸�̳��");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","�������̳��");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","������̸�����");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","������̶���");
                return ;
        } else if ( exp <= 80 ) {
                student->set("title","������̻���");
                return ;
        } else if ( exp <= 90 ) {
                student->set("title","������̴󻤷�");
                return ;
        } else if ( exp <= 100 ) {
                student->set("title","������̳���");
                return ;
        } else if ( exp <= 120 ) {
                student->set("title","������̴���");
                return ;
        } else 
                student->set("title","������̸�����");
                return ;

}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if(ob) 
        ob->set("marks/killyu",1);
        ::die();
}
