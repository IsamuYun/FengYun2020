#include <ansi.h>
inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name(RED"Ѫ����"NOR, ({ "bloody bat" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ�ǳ����µ�Ѫ����\n");

        set("limbs", ({ "ͷ��", "����", "β��" }) );
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

