inherit NPC;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("С��", ({ "fang"}) );
        set("title", HIR "�����������" NOR);
        set("gender", "Ů��" );
        set("age", 20);
        set("per", 55);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 10);
        set("long",
"
С���ǳ���������ķ��ˣ��õ���������ķ��������������޵еģ�\n"
        );
        set("combat_exp", 1);
        setup();
        carry_object("obj/cloth")->wear();
}


