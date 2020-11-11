// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("һ��", ({ "master yi", "master"}) );
        set("nickname", HIM "�ؾ�¥����" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("age", 64);
	set("agi",30);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
���ֲؾ�¥��������ʮ����δ�²ؾ�¥һ��\n"
	);
        create_family("������", 18, "����");
        set("combat_exp", 130000000);
	set_temp("apply/damage",2000);
        set_skill("move", 130);
        set_skill("dodge", 130);
        set_skill("force", 130);
        set_skill("literate", 130);
	set_skill("unarmed",130);
	set_skill("puti-steps",130);
	set_skill("dabei-strike",130);
	set_skill("buddhism",150);
	set_skill("chanting",130);
	set_skill("xiaochengforce",100);
	set_skill("staff",130);
	set_skill("parry",130);
	set_skill("fumostaff",130);
	set_skill("blade",130);
	set_skill("sword",130);
	set_skill("whip",130);
	set_skill("tianlongwhip",130);
	set_skill("suiyuan-sword",130);
	set_skill("lianxin-blade",130);
	set_skill("xingyi-stick",130);
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
if (!arg || arg != "�����ˣ�") return 0;
message_vision("$N����˫�۵�����ģ�̫���ˣ�\n$N˫��΢΢������������ͻȻ�����ˣ�\n",this_object());
destruct(this_object());
return 1;
}
