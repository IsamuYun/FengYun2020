// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("��ҩ���ϰ�", ({ "medman" }) );
	set("gender", "����" );
	set("age", 45);
	set("long",
		"
һ����æ�ò��ɿ�������ҩ���ϰ壬������������
\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("per",1);
        set("vendor_goods", ([
                __DIR__"obj/astragalt" : 10,
                __DIR__"obj/dioscoreae" : 10,
                __DIR__"obj/codonopsis" : 12,
                __DIR__"obj/pilosulae" : 10,
                __DIR__"obj/lycii" : 10,
        ]) );
        set("inquiry", ([
                "���鲹Ѫ����" : "�����Ҫ�򣺱��Σ���ɽ�����Σ���ӣ��͵��飮\n",
		"soup" : "�����Ҫ�򣺱��Σ���ɽ�����Σ���ӣ��͵��飮\n",
        ]));

	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	add_action("do_vendor_list", "list");
}
