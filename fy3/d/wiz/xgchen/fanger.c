inherit NPC;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("小芳", ({ "fang"}) );
        set("title", HIR "长孙无情夫人" NOR);
        set("gender", "女性" );
        set("age", 20);
        set("per", 55);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 10);
        set("long",
"
小芳是长孙无情最爱的夫人！得到长孙无情的法力现在是天下无敌的！\n"
        );
        set("combat_exp", 1);
        setup();
        carry_object("obj/cloth")->wear();
}


