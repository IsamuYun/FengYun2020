// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("������", ({ "master jin", "master", "master jinwu" }) );
        set("nickname", RED"���ֽ�"NOR);
        set("gender", "����" );

       set("reward_npc", 1);
       set("difficulty", 50); 

        set("age", 44);
        set("str", 30);
        	  set_temp("kf_tufei",32);
        set("pursuer", 1);
set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 3);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 3);


        set("long",
"
���˵�����վ�ø�ֱ����ͦ��������һ��ǹ����������������ľ���Ȳ�֪ʹ����
Ҳ��֪���֡�
\n"
	);
        create_family("��Ǯ��", 2, "����");

        set("combat_exp", 1000000);
        set("score", 200000);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duxin" :),
		(: perform_action, "sword.sharenruma" :),
		(: exert_function, "calm" :),
		(: perform_action, "dodge.canglongyixian" :),
        }) );

        set_skill("move", 90);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 100);
        set_skill("literate", 100);
        set_skill("jingxing",90);
        set_skill("sword", 150);
        set_skill("jinhong-steps",90);
        set_skill("lefthand-sword",100);
        set_skill("sharen-sword",180);
        map_skill("dodge", "jinhong-steps");
	map_skill("sword", "sharen-sword");
	map_skill("force", "jingxing");


        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object("/obj/longsword")->wield();
}
/*
void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "assassin");
}
 
*/
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��Ǯ�����");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","��Ǯ�︱����");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��Ǯ������");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","��Ǯ�︱̳��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��Ǯ��̳��");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","��Ǯ�︱����");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��Ǯ�����");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","��Ǯ�ﻤ��");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��Ǯ��󻤷�");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��Ǯ�ﳤ��");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��Ǯ�����");
                return ;
        } else
                student->set("title","��Ǯ�︱����");
                return ;

}

