// hell_guard.c

#include <ansi.h>

inherit NPC;
void backattack();
void create()
{
	string *order = ({"��", "��", "��", "î", "��", "��", "��", "δ", "��", "��", "��", "��"});

	set_name( (order[random(12)]) + "������", ({ "hell guard", "guard" }) );
	set("long", "����һλ����������ػ���ר�ŵ��λ���֮��\n");
	set("attitude", "friendly");


	set("max_atman", 100);
	set("atman", 100);
	set("max_mana", 100);
	set("mana", 100);



	set_skill("fork", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);
	set_skill("move", 70);

	setup();

	carry_object(__DIR__"obj/steel_armor")->wear();
	carry_object(__DIR__"obj/steel_fork")->wield();
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
	ob ->set("max_gin",i*250);
	ob ->set("gin",i*250);
	ob ->set("max_kee",i*250);
	ob ->set("kee",i*250);
	ob ->set("max_sen",i*250);
	ob ->set("sen",i*250);
	ob ->set("eff_gin",i*250);
	ob ->set("eff_kee",i*250);
	ob ->set("eff_sen",i*250);
	return ;
}
void leave()
{
	object owner;
	message("vision",
		HIB + name() + "˵����ĩ������ٻ��������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n\n"
		+ name() + "�����η����İ������⣬������²����ˡ�\n" NOR, environment(),
		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i,lv;
	object *enemy;

            set("level", who->query("level"));
	lv = (int)this_object()->query("level");
            setup_npc(this_object(),lv);

	set_skill("fork", 90 + random(level/2));
	set_skill("parry", 70 + random(level/2));
	set_skill("dodge", 50 + random(level/2));
	set_skill("move", 70 + random(level/2));

	message("vision",
		HIB "һ������ӵص����������г���һ����ִ�ֲ桢��Ŀ�����Ĺ��䡣\n\n"
		+ name() + "˵����ĩ������ٻ�������������\n" NOR,
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
	backattack();
	::die();
}
