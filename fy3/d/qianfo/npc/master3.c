// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("�����ʦ", ({ "master ding", "master", "ding" }) );

        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 30); 

        set("age", 74);
        set("attitude", "peaceful");
        set("class", "bonze");
        set("apprentice_available", 3);
	set("student_title","�׼ҵ���");
        set("str", 27);
        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("spi", 30);
        set("con", 30);
        set("cps", 30);
        set("cor", 20);
        set("atman", 300);
        set("max_atman", 300);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 5);
        set("mana", 300);
        set("max_mana", 300);
        set("combat_exp", 1000000);
        set("score", 9000);
        set_skill("unarmed", 100);
	set_skill("changquan",60);
        set_skill("force", 100);
        set_skill("dodge", 30);
        set_skill("literate", 60);
        set_skill("chanting", 100);
        set_skill("parry", 50);
        set_skill("lotusforce", 100);
        set_skill("buddhism", 100);
        set_skill("notracesnow",40);
        map_skill("force", "lotusforce");
        map_skill("dodge","notracesnow");
	map_skill("unarmed","changquan");
        create_family("�˹�����", 4, "��ʦ");
        setup();
        carry_object(__DIR__"obj/staff")->wield();
	carry_object("/obj/cloth")->wear();
}

/*
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ���ɽ����Ѿ��չ��˵��ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
                ob->set("class","bonze");
                command("say �����ӷ����գ����գ�");
                command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                add("apprentice_availavble", -1);
                return 1;
        }
}

*/
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
                student->set("title","�˹������׼ҵ���");
                return ;

}
