
inherit NPC;

void create()
{
        set_name("花蝴蝶", ({ "hudie" }) );
//	set("title", HIY "花"+ HIR "蝴" +  HIC"蝶" NOR);
        set("race", "野兽");
        set("age", 1);
        set("long", "一五颜六色的美丽的蝴蝶\n");
        set("max_kee", 1);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
         set("chat_chance", 3);
       set("chat_msg", ({
                "美丽的蝴蝶飞上了你的肩头。\n",
                "黄色的蝴蝶飞过你眼前。\n",
		  "红色的蝴蝶飞走了。\n",
        }) );

        set_skill("dodge", 200);

        setup();
}

