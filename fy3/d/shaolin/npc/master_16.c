// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("�޻�", ({ "master wu", "master"}) );
        set("nickname", HIM "��ɮ" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("age", 34);
	set("per", 55);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
���ֵĵ�ʮ������ţ��������Ѹߣ������ڴˡ�
\n"
	);
        create_family("������", 16, "����");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qiankun" :)
        }) );
        set("chat_chance", 10);
        set("chat_msg", ({
name()+"����һ��һ���Ϊ��ʦ��衣����\n",
name()+"�������������ˣ������Ҿ�˵����Ψһ���ƻ�����ƻ��ľ����㡣\n"
        }) );
        set("combat_exp", 5000000);
        set_skill("move", 90);
        set_skill("dodge", 90);
        set_skill("force", 90);
        set_skill("literate", 90);
	set_skill("unarmed",90);
	set_skill("puti-steps",90);
	set_skill("yiyangzhi",90);
	set_skill("buddhism",110);
	set_skill("chanting",90);
	set_skill("xiaochengforce",90);
	set_skill("staff",90);
	set_skill("parry",90);
	map_skill("parry","fumostaff");
        map_skill("dodge", "puti-steps");
	map_skill("force", "dachengforce");
	map_skill("unarmed", "yiyangzhi");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
}

void attempt_apprentice(object me)
{
	command("shake");
	command("say �ҳ����������⣬�㻹��ȥ�ҷ��ɰɡ�\n");
}
void init()
{
	if(this_player()->query_temp("��һ��ˮ"))
	call_out("confess",13+random(3),this_player());
}
int confess(object me)
{
me->delete_temp("��һ��ˮ");
command("say ������ʲô��֪���ˡ�����\n");
command("say ����������û�ҡ�����\n");
message_vision("$N˵�գ��ԶϾ����������ĵ��ڵ��ϡ�����\n",this_object());
this_object()->die();
        if(!me->query("m_success/��ƽ���ַ粨"))
        {
                me->set("m_success/��ƽ���ַ粨",1);
                me->add("score",1000);

        }
}

