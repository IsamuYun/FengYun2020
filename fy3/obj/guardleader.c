inherit NPC;
#include <ansi.h>
void create()
{
        set_name("大内总管", ({ "soldier"}) );
        set("age", 30);
	set("long",
"这是守卫紫禁城的士兵。\n");
        set("attitude", "peaceful");
        set("no_arrest", 1);
        set("can_carry", 1);
        set("hit_always_on", 1);
        set("str", 80);
        set("combat_exp", 10000000);
        set("limbs", ({ "ＰＰ" }) );
        set_skill("unarmed", 400);
        set_skill("dodge",400);
        set_skill("parry",400);
        create_family("朝廷三品", 1, "兵");
	setup();
}
