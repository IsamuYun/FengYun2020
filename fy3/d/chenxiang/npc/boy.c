// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int give_him();
void create()
{
	set_name("�����ɿ��С����", ({ "boy","little boy" }) );
	set("gender", "����" );
	set("age", 5);
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("per",2);
	set("arrive_msg", "����Ť椵����˹���");
	set("leave_msg", "����Ť椵�������");
        set("chat_chance", 15);
        set("chat_msg", ({
		                (: random_move :)
        }) );
        set("inquiry", ([
                "���ɿ�" : (: give_him :),
		"kaidang" : (: give_him :),
        ]));
	setup();
}
int give_him()
{
	object me , obj;
	me = this_player();
	if( !query("given")) {
	obj = new(__DIR__"obj/kaidang");
	message_vision("$N�����ɿ�������������$n��\n",this_object(), me);
	obj->move(me);
	set("given",1);
	return 1;
	}
	return 0;
}

void reset()
{
delete("given");
}

