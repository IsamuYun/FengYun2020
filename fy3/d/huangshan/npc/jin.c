// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����", ({ "jin fenghuang", "jin"}) );
        set("gender", "Ů��" );
        set("age",32);
        set("long", "����Ȼ�ѽ����꣬�������������ᣬһ˫������������������˭�����Կ���
��һ���Ǹ��ܲ����ǵ�Ů�ˡ�\n");
        create_family("��ɽ��", 5, "����");
	set("pursuer",1);
        set("combat_exp", random(100000)+100000);
        set("attitude", "aggrensive");
        set_skill("sword", 80+random(10));
	set_skill("siqi-sword",random(50)+30);
	set_skill("move",40);
	set_skill("force",20);
	map_skill("sword", "siqi-sword");
	set_skill("dodge",100);
	set_skill("liuquan-steps",40);
	map_skill("dodge","liuquan-steps");
        set("chat_chance", 5);
        set("chat_msg", ({
"������Ц����ʧ��ʧ������Ǹ��Ǹ���ұ�������Ϊ����һ�����˾�ҧ�ķ蹷��\n",
        }) );
        set("chat_chance_combat", 30);
	set("force",500);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.liushuichanchan" :),
        }) );
        set("max_force",500);
	set("force_factor",10);
	setup();
	carry_object(__DIR__"obj/cuiyi")->wear();
	carry_object(__DIR__"obj/bijian")->wield();
}

