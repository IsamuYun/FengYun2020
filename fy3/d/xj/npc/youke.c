//

inherit NPC;

void create()
{
        set_name("游客", ({ "you ke" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "一个慕名前来游玩柏孜克里克千佛洞的人。\n");
	setup();
        carry_object("/d/xj/npc/obj/cloth")->wear();
}
