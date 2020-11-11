// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("л����", ({ "master xie", "master", "xiexiaofeng" }) );
        set("nickname", HIG"����"NOR);
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 100); 

        set("age", 34);
        set("str", 40);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","aggresive");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 3);
        set("long",
"
л��������ѧ��,ʮ���꽣��,ʮ����ܻ�����,һ�����ϸ�����ὣ��������˫
��������������,��������Ľ����ݶ����,����һ����ծ����
\n"
	);
        create_family("��ɽׯ", 1, "ׯ��");

        set("combat_exp", 10000000);
        set("score", 200000);
        set_skill("move", 100);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword",320);
	set_skill("softsword",150);
        set_skill("cloudforce",120);
        set_skill("shadowsteps",120);
	map_skill("force", "cloudforce");
	map_skill("parry","softsword");
        map_skill("sword","softsword");
        map_skill("dodge","shadowsteps");
        map_skill("move","shadowsteps"); 
      

        setup();
        carry_object(__DIR__"obj/qingcloth")->wear();
        carry_object(__DIR__"obj/xiesword")->wield();
}
/*
void attempt_apprentice(object me)
{
	if( !me->query("class")){
	command("smile");
        command("recruit " + me->query("id") );
	}
}
*/
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��ɽׯ��ū");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","��ɽׯ����");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��ɽׯ��ʿ");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","��ɽׯ����");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��ɽׯ����");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","��ɽׯ����");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��ɽׯ��ʥ");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","��ɽׯ����");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��ɽׯ���");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��ɽׯ��ɷ");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��ɽׯ����");
                return ;
        } else
                student->set("title","��ɽׯ����");
                return ;

}

