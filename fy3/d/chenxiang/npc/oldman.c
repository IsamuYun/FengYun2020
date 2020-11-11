// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("���������", ({ "oldman" }) );
	set("gender", "����" );
	set("age", 65);
	set("long",
		"
�������������Ѿ��ܴ��ˣ���Ŀ�Ѿ��е㲻���ˣ�˵��Ҳ��̫�������
���Ǵ������������ϰ�һ�������˼��������һ������û�в�ҵ��Ҳû
�����ˡ�����������ͬ���ļ������ࡣ
\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("per",1);
	set("vendor_goods", ([
		__DIR__"obj/hezi" : 100,
		__DIR__"obj/caomian" : 100,
		"/obj/example/wineskin" : 50,
	]) );
        set("inquiry", ([
                "ɱ�˰�" : "�Ǽһ��аѵ��������ĵ���������ɱ�ģ�\n",
		"murder" : "�Ǽһ��аѵ��������ĵ���������ɱ�ģ�\n",
        ]));

	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:
command("say �ҿ첻���ˣ��ü����������кðɣ�\n");	
			break;
	}
}

int accept_object(object me, object obj)
{
	object ob;
	if( obj->value() > 500 && (int) query("given") < 10)
	{
        command("say ��л��λ" + RANK_D->query_respect(me) +
"����С���������ɣ�");
	ob = new(__DIR__"obj/qiju");
	ob->move(me);
	add("given",1);
	}
	else
	command("say ��л��λ" + RANK_D->query_respect(me) + "\n");	
        return 1;
}

void reset()
{
delete("given");
}
