// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_join();
void create()
{
        set_name("�λ���ʦ", ({ "master can", "master", "can" }) );

        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 30); 

        set("age", 74);
        set("attitude", "peaceful");
        set("class", "bonze");
        set("apprentice_available", 3);
        set("str", 27);
        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("spi", 30);
        set("con", 30);
        set("cps", 30);
        set("cor", 20);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
        }) );

        set("atman", 300);
        set("max_atman", 300);

        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 5);

        set("mana", 300);
        set("max_mana", 300);

        set("combat_exp", 1000000);
        set("score", 9000);

        set("inquiry", ([
                "���" : (: ask_for_join :),
                "����" : (: ask_for_join :),
		"apprentice" : (: ask_for_join :),
        ]) );

        set_skill("staff", 100);
        set_skill("unarmed", 80);
        set_skill("force", 100);
        set_skill("dodge", 30);
        set_skill("literate", 60);
        set_skill("chanting", 100);
        set_skill("parry", 50);
        set_skill("magic", 100);

        set_skill("cloudstaff", 70);
        set_skill("lotusforce", 100);
        set_skill("buddhism", 100);
        set_skill("notracesnow",40);

        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        map_skill("force", "lotusforce");
        map_skill("dodge","notracesnow");

        create_family("�˹�����", 4, "ס��");

        setup();

        carry_object(__DIR__"obj/staff")->wield();
}


string ask_for_join()
{
        object me;

        me = this_player();

        if( (string)me->query("class")=="bonze" )
                return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ����Ŀ������Ц��\n";
        if( (string)me->query("gender") != "����" )
                return "�����ӷ�Ůʩ�����������������㵽����ȥ��Ȱɡ�\n";

        me->set_temp("pending/join_bonze", 1);
        return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n"
;
}

int do_kneel()
{
        string *prename =
         ({ "��", "��", "Բ", "��", "��", "��",
                "��", "��", "��", "��" });
        string name, new_name;

        if( !this_player()->query_temp("pending/join_bonze") ) return 0;
        message_vision(
HIC "$N˫�ֺ�ʮ�����������ع���������\n\n"
"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ���������£�\n\n" NOR,
this_player(), this_object() );
        name = this_player()->query("name");
        new_name = prename[random(sizeof(prename))] + name[0..1];
        command("say �ӽ�������ķ�������" + new_name + "��");
        command("smile");
        this_player()->delete_temp("pending/join_bonze");
        this_player()->set("name", new_name);
        this_player()->set("class", "bonze");

        return 1;
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
        if( (string)ob->query("gender") != "����" )
                command("say �����ӷ�Ůʩ����Ҫ�����ɿ���Ц��");
        else if( (string)ob->query("class") != "bonze" )
                command("say �����ӷ�ʩ��Ը����ţ����ȵ�С����ȳ��ҡ�");
        else {
                command("say �����ӷ����գ����գ�");
                command("recruit " + ob->query("id") );
        }
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
