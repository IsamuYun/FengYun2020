// heaven_soldier.c

#include <ansi.h>

inherit NPC;
void backattack();
void create()
{

	 set_name("����ˮ", ({ "qiushui", "xiao qiushui" }) );
        set("long",
"һ��������һ��������ΪѰ�Һ��֪���Ʒ����س�������\n");
        set("nickname", RED"һ������"NOR);
        set("attitude", "heroism");
        create_family("���ݽ���",1,"����");
set("str", 80);
        set("cor", 80);
        set("cps", 80);
	set("agi",80);
	set("int",80);
        set("combat_exp", 10000000);
	 set("max_force", 100000);
        set("force", 100000);
        set("force_factor", 30);
       set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "����ˮ�ʵ�������λС�ֵܣ��Ƿ񿴼��Ʒ���\n",
                "����ˮ�ʵ�������λС����Ƿ񿴼��Ʒ���\n",
	
        }) );
        set("chat_chance", 80);
        set("chat_msg", ({
        }) );

        set("chat_msg_combat", ({
                (: perform_action, "sword.jingtianyijian" :),
  (: perform_action, "dodge.hongyeluanfei" :),
  (: perform_action, "sword.jingtianyijian" :),
   (: exert_function, "junwang" :),
 (: exert_function, "jinduan" :),
        }) );
	set_temp("apply/damage",500);
	set_skill("sword",150);
	set_skill("force",100);
        set_skill("parry",120);
        set_skill("dodge",100);
	set_skill("noloveforce",120);
       set_skill("literate",100);
	set_skill("huanhua-sword",200);
       set_skill("huanhua-steps",200);
	map_skill("dodge","huanhua-steps");
	map_skill("force","noloveforce");
	map_skill("sword","huanhua-sword");
        setup();

        
        carry_object("/obj/ruxue")->wield();
}

int heal_up()
{
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
		 name() + "˵���������ҵ����ˣ��Ʒ����һ�ȥһ�����Ͼ�����\n\n"
		+ name() + "�����һ����ʧ�ˡ�\n" , environment(),
		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
	
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i;
	object *enemy;
		message("vision",
		 name() + "ŭ���������Ʒ�Ҳ��ɱ��������\n" NOR,
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
               
	backattack();
	::die();
}
int is_ghost() { return 1; }