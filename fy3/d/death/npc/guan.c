// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�ض�ү", ({ "master guan", "master" }) );
        set("gender", "����" );
        set("age", 44);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 20);
        set("long",
"
����������������ܸ����壬ǧ����ɩ�������ն�����Ĺض�ү\n"
	);
        set("combat_exp", 1000000);
        set("agi",25);
        set("int",30);
        set_skill("move", 70);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("literate", 60);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
        setup();
        carry_object("/obj/cloth")->wear();
}


int is_ghost() { return 1; }
