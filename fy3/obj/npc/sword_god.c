// sword_god.c

#include <ansi.h>

inherit NPC;
void backattack();
void create()
{

    set_name("剑神", ({ "sword god", "god" }) );
    set("long", "这是来自仙界的剑神。\n");
    set("attitude", "heroism");

    set("max_atman", 3000);
    set("atman", 3000);
    set("max_force", 3000);
    set("force", 3000);
    set("max_mana", 3000);
    set("mana", 3000);

    set("str", 60);
    set("cor", 60);
    set("cps", 30);
    set("spi", 30);
    set("dur", 30);
    set("tol", 30);

    set("per", 30);
    set("fle", 30);
    set("agi", 30);
    set("kar", 30);
    set("int", 30);
    set("con", 30);

    set("atman_factor", 30);
    set("force_factor", 30);

    set("combat_exp", 1000000);

    set_skill("sword", 60);
    set_skill("parry", 60);
    set_skill("dodge", 60);
    set_skill("move", 60);
    set_skill("magic", 60);
    set_skill("incarnation", 60);
    set_skill("force", 60);

    set_skill("imperialsword", 10);
    set_skill("windcloud-move", 70);
    set_skill("incarnate-body", 10);


    map_skill("incarnation","incarnate-body");
    map_skill("force","incarnate-body");
    map_skill("magic","windcloud-move");
    map_skill("move","windcloud-move");
    map_skill("dodge","windcloud-move");
    map_skill("sword","imperialsword");
    map_skill("parry","imperialsword");

    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "move.yujianfumo" :),
      }) );
    set("chat_chance", 1);
    set("chat_msg", ({
                "尔等冒犯仙人，还不速速伏法！\n",
        }) );

    set_temp("apply/astral_vision",1);

    setup();

    carry_object(__DIR__"obj/god_armor")->wear();
    carry_object(__DIR__"obj/god_sword")->wield();
}

int heal_up()
{
    if( environment() ) {
        call_out("leave", 1);
        return 1;
    }
    return ::heal_up() + 1;
}

void leave()
{
    object owner;
    message("vision",
      HIB "\n一道蓝光掠过，剑神御剑飞行，消失不见了。\n" NOR, environment(),this_object() );
    if(objectp(owner=this_object()->query("possessed")))
        owner->delete_temp("have_guard");
	destruct(this_object());
//    set_temp("no_corpse", 1);
//    ::die();
}

void invocation(object who, int level)
{
    int i;
    object *enemy;

    set_skill("parry", 100 + random(level)/2);
    set_skill("dodge", 100 + random(level)/2);
    set_skill("move", 100 + random(level)/2);
    set_skill("sword", 100 + random(level)/2);
set_skill("imperialsword", 90+random(level)/5);
    set_skill("incarnate-body", 10 + random(level)/2);
    set_skill("incarnation", 120 + random(level)/2);
set_skill("windcloud-move", 100 + random(level)/2);

	set("combat_exp", 1000000 + random(level/40*level*level));
    set("atman_factor", random(level)/3);
    set("force_factor", random(level)/3);

//    init_level(60 + who->query("level")/3 + random(level/2) );

    message("vision",
      HIW "\n只见一道白光掠过，剑神御剑飞行而来！\n" NOR,
      environment(), this_object() );
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
        owner->delete_temp("have_guard");
    message("vision", HIW "剑神死了。\n" NOR, environment(), this_object() );
    destruct(this_object());
//    backattack();
//    ::die();
}
