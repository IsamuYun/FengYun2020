// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����", ({ "shaolin monk", "monk"}) );
        create_family("������", 20, "����");
        set("gender", "����" );
        set("age",random(20)+ 32);
	set("nickname","��ɮ");
        set("long", "���������µĹ�ɮ��\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(100000)+10000);
        set("attitude", "friendly");
        set_skill("staff", 5+random(100));
	set_skill("xingyi-stick",random(100)+20);
	set_skill("move",400);
	set_skill("force",200);
	map_skill("staff", "xingyi-stick");
	set("force",100);
        set("max_force",100);
	set("force_factor",10);
        set("chat_chance", 10);
        set("chat_msg", ({
                name()+"ͷһƫ�������˲��˯���ڵ��ϡ�\n",
                name()+"��ɫ��ׯ�����������дǡ�\n",
                name()+"˫��΢�գ��촽΢��������\n",
		name()+"ȫ�����һ��ʯͷһ����һ��������\n"
        }) );
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}

