// zombie.c

#include <ansi.h>

inherit NPC;

void do_bite();

void create()
{
        set_name("��ʬ", ({ "zombie" }) );
        set("long",
                
"����һ�߱����÷�����ƵĽ�ʬ�������԰׵����Ͽ������κ�ϲŭ���֡�\n");
        set("max_gin", 400);
        set("max_kee", 400);
        set("max_sen", 60);
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("str", 60);
        set("cor", 40);
	set("haunt", 0);
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "��ʬ���з����ɺɵĽ�����\n",
                "��ʬ�����Ͽ�ʼ���Σ�һ��鴤�������Ƶش�С�\n",
                "��ʬ��ָ���ţ�ҧ���гݣ�¶��������Ц�ݡ�\n",
                (: do_bite :),
        }) );
        set_skill("unarmed", 40);
        set_skill("dodge", 30);
        set_skill("move", 30);

        set_temp("apply/damage", 225);

        setup();
}

void init()
{
	object	ob, targ;
	string	target;

	::init();
	if(query("haunt") == 1) {
        	target = query("haunttar");
		if(objectp(targ = present(target, environment()))) {
			message_vision("$N�۾���Ȼ�������૵�˵����" RED
"ɱ....��....$n....\n" NOR, this_object(), targ);
			this_object()->kill_ob(targ);
			this_object()->set_leader(targ);
			targ->kill_ob(this_object());
                }
	}
}
int is_zombie() { return 1; }
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
	ob ->set("max_gin",i*450);
	ob ->set("gin",i*450);
	ob ->set("max_kee",i*450);
	ob ->set("kee",i*450);
	ob ->set("max_sen",i*450);
	ob ->set("sen",i*450);
	ob ->set("eff_gin",i*450);
	ob ->set("eff_kee",i*450);
	ob ->set("eff_sen",i*450);
	return ;
}


void animate(object who, int level)
{
	int lv;
        set("possessed", who);
        set_leader(who);
        set_skill("unarmed", 100+random(level/2));
        set_skill("dodge", 100+random(level/2));
        set_skill("move", 100+random(level/2));
        set("level", who->query("level")+who->query("level")/2);
	lv = (int)this_object()->query("level");
            setup_npc(this_object(),lv);

}

void dispell()
{
        object corpse;

        if( environment() ) {
                say( name() + "�����ص�����������Ϊһ̲Ѫˮ��\n");
        }

        destruct(this_object());
}

int heal_up()
{
        object 	master, leader;
	int	lvl;

        if( objectp(master = query("possessed"))) { 
		lvl = (int)master->query_skill("necromancy", 1);
        	if((int)master->query("atman") > lvl ) {
                	message("tell", HIR + name() +  "�����㣺��...��...Ҫ...��...��...��...��...\n" NOR, master );
                	master->add("atman", -lvl);
                	master->receive_damage("gin", lvl/10);
                	::heal_up();
                	return 1;            
        	} 
       	} 
        call_out("dispell", 1);
        return ::heal_up();
}

void do_bite()
{
        object *enemy;

        say( name() + "�������һ��������Ż�ĳ�����ʹ�����ͷ�����͡�\n" );
        enemy = query_enemy();
        for(int i=0; i<sizeof(enemy); i++) {
                if( !enemy[i] ) continue;
                enemy[i]->receive_damage("gin", 20);
                COMBAT_D->report_status(enemy[i], "gin");
        }
}
 
