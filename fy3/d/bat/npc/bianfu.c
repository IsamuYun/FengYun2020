#include <ansi.h>
inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name(RED"血蝙蝠"NOR, ({ "bloody bat" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一只非常可怕的血蝙蝠\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "killer");
        set("str",20+random(20));
        set_skill("dodge", random(300));
        set("combat_exp", random(400000));
	    set("bellicosity", 3000 );
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) 
                kill_ob(ob);
        
}

