// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("������", ({ "feng siniang", "feng"}) );
        set("gender", "Ů��" );
        set("age",32);
        set("long", "��ϲ�����ָ����Ĵ̼���ϲ��������������ߵ�ɽ���������Ĳˣ�
�����ҵľƣ��������ĵ���ɱ��ݵ��ˡ�\n");
        set("combat_exp", random(100000)+200000);
        set("attitude", "aggrensive");
	set_skill("move",70);
	set_skill("unarmed",250);
	set_skill("force",20);
	set_skill("dodge",200);
	set_skill("liuquan-steps",40);
        set("chat_chance", 5);
        set("chat_msg", ({
"������գ����Ц����ʧ��ʧ������Ǹ��Ǹ���ұ�������Ϊ�������������أ�\n",
        }) );
        set("max_force",500);
	set("force_factor",20);
	setup();
	carry_object("/obj/cloth")->wear();
}

