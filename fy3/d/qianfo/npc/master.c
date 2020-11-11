// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("�˹���ʦ", ({ "master xing", "master", "xing" }) );

        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 100); 
	set("class","xingguo");

        set("age", 74);
        set("attitude", "peaceful");
        set("class", "xingguo");
	set("student_title","��ʦ");
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
        }) );
        set("atman", 3000);
        set("max_atman", 3000);
        set("force", 15000);
        set("max_force", 15000);
        set("force_factor", 5);
        set("mana", 3000);
        set("max_mana", 3000);
		set("max_kee",500000);
        set("combat_exp", 100000000);
        set("score", 9000);
        set_skill("unarmed", 300);
		set_skill("luoriquan", 1000);
        set_skill("force", 700);
        set_skill("literate", 480);
        set_skill("move", 500);
        set_skill("parry", 320);
        set_skill("magic", 1000);
        set_skill("lotus-steps", 1000);
        set_skill("lotusforce", 1000);
        set_skill("buddhism", 1000);
        set_skill("essencemagic", 1000);
        map_skill("unarmed", "luoriquan");
        map_skill("force", "lotusforce");
        map_skill("magic", "essencemagic");
        create_family("�˹�����", 3, "ס��");
        setup();
	carry_object("/obj/cloth")->wear();

}

void attempt_apprentice(object ob)
{
	if( ob->query("class")&&ob->query("class") != "xingguo")
	{
	command("stare");
	command("say ���Ѿ����Լ��������ˣ�\n");
	}
	else if( ob->query("national") == "�ɹ���" )
	{
	command("smile");
	command("say �ܺã����˹����¾Ϳ������������ˣ�\n");
            command("recruit " + ob->query("id") );
	}
	else
	command("say �˹�����ֻ���ɹ����ˣ�\n");
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xingguo");
}
int accept_fight(object me)
{
        if( (string)me->query("class")=="bonze" )
                command("say �����ӷ𣡳����˽��ǿ�񶷣����Ĳ���Υ����档");
        else
                command("say ʩ����Ȼ�����գ�����������ǣ�Ҳ���ؽ����ˡ�");

        return 0;
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","�˹����´�ʦ");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","�˹������޺�");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","�˹����½��");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","�˹����¸�ɮ");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","�˹�����ʥɮ");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","�˹�������ɮ");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","�˹����»��");
                return ;
        } else
                student->set("title","�˹����¸�����");
                return ;

}

