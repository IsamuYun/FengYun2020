// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("���", ({ "master tian", "master"}) );
        set("nickname", HIW "ǰ�η���" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 60); 

        set("age", 94);
	set("per", 25);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
���ֵĵ�ʮ������ţ��������Ѹߣ������ڴˡ�
\n"
	);
        create_family("������", 15, "��ʦ");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qiankun" :)
        }) );
        set("chat_chance", 10);
        set("chat_msg", ({
name()+"�����������������ã�һ��ƷζƷζ���ɡ�����\n",
name()+"̾����������ѽ������\n"
        }) );
        set("combat_exp", 9000000);
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
	command("say ���������Ѹߣ��㻹��ȥ�����Űɣ�\n");
}
