// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����", ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(20)+ 32);
	set("nickname","��ɮ");
        set("long", "����������ר�����ŵ���ɮ��\n");
	set("vendetta_mark","shaolin");
        create_family("������", 19, "����");
        set("combat_exp", random(100000)+100000);
        set("attitude", "friendly");
        set_skill("whip", 60+random(10));
	set_skill("tianlongwhip",random(10)+70);
	set_skill("move",400);
	set_skill("force",200);
	map_skill("whip", "tianlongwhip");
        set("chat_chance_combat", 30);
	set("force",500);
        set("chat_msg_combat", ({
                (: perform_action, "whip.sijiaotianlong" :),
        }) );
        set("max_force",500);
	set("force_factor",50);
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/whip")->wield();
}

