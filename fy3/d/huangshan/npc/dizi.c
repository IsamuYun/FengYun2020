// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("̫����", ({ "taibai yi", "taibai"}) );
        set("gender", "����" );
        set("age",32);
        set("long", "һ���嵶�Ļ�ɽ�ɵ��ӡ�\n");
        create_family("��ɽ��", 5, "����");
        set("combat_exp", random(500000)+500000);
        set("attitude", "friendly");
        set_skill("blade", 60+random(10));
	set_skill("qiusheng-blade",random(50)+30);
	set_skill("move",60);
	set_skill("force",20);
	map_skill("blade", "qiusheng-blade");
	set_skill("dodge",100);
	set_skill("liuquan-steps",40+random(40));
	map_skill("dodge","liuquan-steps");
        set("chat_chance", 5);
        set("chat_msg", ({
name()+"˵����ʦ����ϲ��ɱ���ص��ˣ�����\n",
        }) );
        set("chat_chance_combat", 30);
	set("force",500);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jingsheng" :),
        }) );
        set("max_force",500);
	set("force_factor",2);
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/blade")->wield();
}

