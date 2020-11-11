// qiangdao  by tiandi

#include <ansi.h>

inherit NPC;
void create()
{

    set_name("��Ĺ��", ({ "daomu ren","daomu" }) );
    set("long", "һ�����µ�Ĺ�������ˡ�\n");
    set("str", 400);
    set("cor", 400);
    set("cps", 400);
    set("spi", 400);
    set("dur", 600);
    set("tol", 400);
//	set_temp("apply/armor",3000);
    set("per", 400);
    set("fle", 400);
    set("agi", 400);
    set("kar", 400);
    set("int", 400);
    set("con", 400);
	set("max_force",6000);
	set("force",6000);
	set("no_arrest",1);
	set("is_jobnpc",1);
    set("level", 80);
    set_skill("sword", 100);
    set_skill("parry", 500);
    set_skill("dodge", 500);
    set_skill("move", 500);
    set_skill("three-sword", 560);
    set_skill("taiji", 560);
	set_skill("taijiforce", 560);
	set("luanhuanjue",6);
	set("nianzijue",6);

    set_skill("force", 560);

    map_skill("unarmed","taiji");
	map_skill("sword","three-sword");
	map_skill("force","taijiforce");

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.luanhuanjue" :),
		(: perform_action, "sword.nianzijue" :),
      }) );
    set("chat_chance", 1);
    set("chat_msg", ({
                "��Ĺ�ߵ����ʵ����ӵĶ��������ðײ��á�\n",
	          //      (: random_move :),
        }) );

    setup();

    carry_object("/obj/weapon/sword")->wield();
}
void init()
{
        call_out("leave",60);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "��Ĺ���ַ����µ�Ŀ���ˣ���ʧ��������ǰ��\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
}

void die()
{
       
	int exp,pot,score,reb,ti,doubletime,doubletype,lv;
	object me ,ob,gift,gold,owner;
	mapping quest;
	me = this_object()->query_temp("last_damage_from");
	ob = this_object();
	if(owner = me->query("possessed"))  
		me = owner;

	if(me->query("id") == ob->query("owner"))
		{
			lv = me->query("level");
			if (random(lv) < 10)
			{
				gift = new("/d/wiz/fyup/npc/obj/caiwu");
				gift->move(me);
				tell_object(me,HIY"\n��ϲ��ӵ�Ĺ�ߵ������ҵ��˵����ĲƱ���\n"NOR);
				me->delete_temp("daomu");
				me->apply_condition("daomujob", 0);
			}
	tell_object(me,"\n��Ĺ�߶���ǰ��������˵���������֡���������ߡ������ҵ��ֵܡ��������ϻ������ҡ���������ģ�\n");
//tell_object(me,HIY"\n��ϲ��ӵ�Ĺ�ߵ������ҵ��˵����ĲƱ���\n"NOR);
		}	
		destruct(ob);
		return;
}