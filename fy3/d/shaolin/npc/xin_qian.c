// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("�ļ�", ({ "master jian", "jian"}) );
        set("gender", "����" );
set("reward_npc", 1);
    set("difficulty", 40); 

        set("age",62);
	create_family("������", 17, "����");
        set("long", "�������ߴ����֮һ��\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(600000)+600000);
        set("attitude", "friendly");
        set_skill("yiyangzhi", 70+random(100));
	set_skill("unarmed", 100);
	set_skill("dodge",100);
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"˵�����ؾ����飬�Ϸ���Ը�ڴ����ʮ�ꡣ\n",
        }) );
	set_skill("move",80);
	set_skill("force",200);
	map_skill("unarmed", "yiyangzhi");
        set("chat_chance_combat", 10);
	set("force",5000);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qiankun" :),
        }) );
        set("max_force",5000);
	set("force_factor",55);
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}
void init()
{
	command("say ������ʲô����\n");
	call_out("do_kick",2+random(3),this_player());
}
int do_kick(object me)
{
object room;
if(me && environment(me) == environment() && !me->is_fighting())
{
		command("say û������������ˡ���\n");
		message_vision("$N����һ�ӣ�һ�ɴ�����$n�ͳ����⡣\n",this_object(),me);
		room = 	load_object("/d/shaolin/liuzu");
		if(room) me->move(room);
                message_vision("$N�����ߵ������з��˳��������ص�ˤ�ڵ��£�\n",me);
		me->receive_damage("kee",50);
}
return 1;
}

