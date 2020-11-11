// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("����С����", ({ "toughman" }) );
	set("gender", "����" );
	set("age", 47);
	set("long", "�����һ���������������ˡ�\n");
	set("combat_exp", 10000);
	set("str", 27);
	set("force", 30);
	set("max_force", 30);
	set("force_factor", 1);
	setup();
	set("chat_chance", 1);
	set("chat_msg", ({
		"����С���ܸ�����������ӵĵ��������ˣ���Ҳû����һ����\n",
	}) );
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/miaodao")->wield();
	add_money("gold", 1);
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say ��л��λ" + RANK_D->query_respect(me) + "��");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
	return 0;
}
