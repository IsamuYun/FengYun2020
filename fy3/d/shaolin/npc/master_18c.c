// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�ۿ�", ({ "master hui", "master"}) );
        set("vendetta_mark","shaolin");
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("title", "���ֶ���" );
        set("age", 101);
	set("agi",30);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
���ֵڶ������ϣ���Բ�ź�һֱ���ػ������־�ѧ�����ܣ�\n"
	);
        create_family("������", 2, "����");
        set("combat_exp", 130000000);
	set_temp("apply/damage",2000);
        set_skill("move", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("literate", 220);
        set_skill("unarmed",200);
        set_skill("puti-steps",200);
        set_skill("dabei-strike",200);
        set_skill("buddhism",200);
        set_skill("chanting",200);
        set_skill("xiaochengforce",200);
        set_skill("staff",200);
        set_skill("parry",200);
        set_skill("fumostaff",200);
        set_skill("blade",200);
        set_skill("sword",200);
        set_skill("whip",200);
        set_skill("tianlongwhip",200);
        set_skill("suiyuan-sword",200);
        set_skill("lianxin-blade",200);
        set_skill("xingyi-stick",200);
	map_skill("sword","suiyuan-sword");
	map_skill("staff","xingyi-stick");
	map_skill("parry","lianxin-blade");
        map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "dabei-strike");
	map_skill("blade","lianxin-blade");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();

}
void init()
{
	add_action("do_say","say");
}
int do_say(string arg)
{
if (!arg || arg != "���־�ѧ��ʲô��") return 0;
message_vision("$N΢΢һЦ����̫���ˣ����������ܳм����־�ѧ�ˣ�\n",this_object());
this_player()->set("juexue",1);
return 1;
}
int is_ghost() { return 1; }
