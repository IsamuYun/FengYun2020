// yiru@hero
// tu_god.c

#include <ansi.h>
#include <condition.h>

inherit NPC;
void backattack();
void summon_action(string arg);
void create()
{

        set_name(HIG"山神"NOR, ({ "tu god", "god" }) );
        set("long", "这是来自仙界的山神。\n");
        set("attitude", "heroism");

        set("gender", "男性");
        set("age", 1000);

        set("max_atman", 1000);
        set("atman", 10000);
        set("max_force", 1000);
set("force", 10000000);
        set("max_mana", 1000);
        set("mana", 10000);

        set("dur", 100);
        set("str", 100);
        set("cor", 100);
        set("cps", 100);
        set("spi", 100);
        set("tol", 100);

        set("per", 300);
        set("fle", 100);
        set("agi", 100);
        set("kar", 100);
        set("int", 100);
        set("con", 100);

        set("atman_factor", 100);
        set("force_factor", 100);
        set("mana_factor", 100);

        set("combat_exp", 1000000);
        
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);

        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move", 100);
        set_skill("incarnation", 100);
        set_skill("magic", 100);
        set_skill("force", 100);
        set_skill("spells", 100);

        set_skill("five-summon", 290);

        map_skill("incarnation","five-summon");
        
    set("chat_chance_combat", 34);
    set("chat_msg_combat", ({
        (: summon_action, "tu" :),
    }) );

        set_temp("apply/astral_vision",1);
        setup();

}

int heal_up()
{
        set("force", query("max_force"));
        set("atman", query("max_atman"));
        set("mana", query("max_mana"));
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        object owner;
        message("vision",
                name()+HIG"不知什么时候已经消失不见了。\n" NOR, environment(),this_object() );
        if(objectp(owner=this_object()->query("possessed")))
            owner->delete_temp("guards/tu");
        destruct(this_object());
}

void invocation(object who, int level)
{
        int i;
        object *enemy;
set_skill("incarnation", 1000+random(level));
        set_skill("unarmed", 100+random(level/2));
        set_skill("parry", 100+random(level/2));
        set_skill("dodge", 100+random(level/2));
        set_skill("move", 100+random(level/2));

set("combat_exp", 10000000 + random(level*level*level)/25 );
        set("str", level/3);
set("force_factor", 200+random(level)/3);
		set_temp("apply/armor", level/2);
		
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(enemy[0]);
        set("possessed",who);
}

void backattack()
{
        int i;
        object owner, *enemy;
        if(objectp(owner=this_object()->query("possessed")))
        {
                enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->fight_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

        }

}

void die()
{
        object owner;
        if(objectp(owner=this_object()->query("possessed")))
            owner->delete_temp("guards/tu");
    message("vision", name()+HIG"死了。\n" NOR, environment(),this_object() );
	destruct(this_object());
//        backattack();
//        ::die();
}

void summon_action(string arg)
{
    command("zhaohuan "+arg);
}
