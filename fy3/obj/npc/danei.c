// heaven_soldier.c

#include <ansi.h>

inherit NPC;
void backattack();

void create()
{

	set_name("大内高手", ({ "guard", "body guard" }) );
	set("long", "这是一位大内高手，专门担任保护之责。\n");
	set("attitude", "friendly");

	set("combat_exp", 100000);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("move", 70);

	setup();

	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}
void setup_npc(object ob,int i)
{
	ob ->set("str",random(20)  + 6*i);
	ob ->set("cor",random(20)  + 6*i);
	ob ->set("int",random(20)  + 6*i);
	ob ->set("spi",random(20)  + 6*i);
	ob ->set("cps",random(20)  + 6*i);
	ob ->set("per",random(20)  + 6*i);
	ob ->set("con",random(20)  + 6*i);
	ob ->set("kar",random(20)  + 6*i);
	ob ->set("agi",random(20)  + 6*i);
	ob ->set("dur",random(20)  + 6*i);
	ob ->set("fle",random(20)  + 6*i);
	ob ->set("tol",random(20)  + 6*i);
	ob ->set("max_gin",i*200);
	ob ->set("gin",i*200);
	ob ->set("max_kee",i*200);
	ob ->set("kee",i*200);
	ob ->set("max_sen",i*200);
	ob ->set("sen",i*200);

	return ;
}


void leave()
{
	object owner;
	message("vision",
		 name() + "说道：如再有变化，发哨为警！\n\n"
		+ name() + "闪了闪就消失不见了。\n" , environment(),
		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
		owner->add_temp("max_guard",-1);
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i,lv;
	object *enemy;
            set("level", who->query("level")+10);   
	lv = (int)this_object()->query("level");
            setup_npc(this_object(),lv);
	set_skill("sword", 70 + level*2);
	set_skill("parry", 70 + level*2);
	set_skill("dodge", 70 + level*2);
	set_skill("move", 70 +level*2);

	message("vision",
		 name() + "喝道：大胆！竟敢和朝廷命官过不去！\n" NOR,
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
	set_leader(who);
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
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

	}

}

void die()
{
	object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
        message("vision",
                 name() + "死了。\n" NOR,
                environment(), this_object() );
//	backattack();
//	::die();
	destruct(this_object());
}
