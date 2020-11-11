// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("�Ϲ���", ({ "master nangong", "master"}) );
        set("nickname", HIR "����" NOR);
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 30); 

        set("age", 34);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 30);
        set("long",
"
�������µ�һ���İ�����ǰ�ϰ����δȵİ��ӡ�
\n"
	);
        create_family("ؤ��", 7, "��ͷ����");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :)
        }) );
        set("combat_exp", 2000000);
        set_skill("move", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
	set_skill("unarmed",150);
	set_skill("doggiesteps",100);
	set_skill("dragonstrike",100);
	set_skill("huntunforce",100);
	set_skill("staff",150);
	set_skill("dagou-stick",150);
	set_skill("begging",120);
	set_skill("inquiry",120);
        map_skill("dodge", "doggiesteps");
	map_skill("force", "huntunforce");
	map_skill("unarmed", "dragonstrike");
	map_skill("staff","dagou-stick");
	map_skill("parry","dagou-stick");
        set("inquiry", ([
                "ıɱ" : (: kill_him :),
                "�δ�" : (: kill_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/9bagcloth")->wear();

}
/*
void attempt_apprentice(object me)
{
	if((int)me->query("deposit")<=0)
	{
	command("say ������һƶ��ϴ�ķ��ϣ��Ҿ�����Ϊͽ�ɣ�\n");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("sigh");
        command("say ��������������з磬����Ǯ���Ƶģ�ΪʲôҪ������ؤ�\n");

	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "beggar");
}
int kill_him()
{
	object me;
	me = this_player();
	command("say �������Ѿ�֪����̫���ˣ��� \n");
	this_object()->kill_ob(me);
	me->kill_ob(this_object());
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
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
	if(ob) 
	ob->set_temp("killed_master_nangong",1);
        ::die();
}
