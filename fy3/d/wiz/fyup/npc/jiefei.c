// qiangdao  by tiandi

#include <ansi.h>

inherit NPC;
void create()
{

    set_name("拦路劫匪", ({ "jie fei" }) );
    set("long", "一个专门拦路打劫镖银的劫匪。说不定他们身上会藏有打劫而来的宝物。\n");
 set("no_arrest",1);

    set("combat_exp", 5000000+random(20000000));
    set_skill("sword", 60);
    set_skill("parry", 60);
    set_skill("dodge", 60);
    set_skill("move", 500);
    set_skill("magic", 60);
    set_skill("sharen-sword", 200);
    set_skill("long-steps",300);

    set_skill("force", 60);

    map_skill("sword","sharen-sword");
    map_skill("dodge","long-steps");
    map_skill("move","long-steps");

    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "sword.sharenruma" :),
      }) );
    set("chat_chance", 5);
    set("chat_msg", ({
                "听说镖局又开始找人托镖了，嘿嘿，得找个机会下手。。。\n",
	                (: random_move :),
        }) );
    setup();

    carry_object("/obj/weapon/sword")->wield();
	if (random(2)) 
	          carry_object("/d/wiz/fyup/obj/baotu");
}
void init()
{
        call_out("leave",900);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "拦路劫匪找不到觅食的方向，一溜烟地闪了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
}

void die()
{
       
	int exp,pot,score,reb,ti;
	object me ,ob,gift;
	mapping quest;
	me = this_object()->query_temp("last_damage_from");
	ob = this_object();

            tell_object(me,"\n恭喜你！斩杀了一名劫匪！\n");
            reb = me->query("reborned");
	me->add("killjiefei",1);
	score = 1 ;  
	exp = random(2000)+1000;
	me->add("combat_exp",exp);
	me->add("score",score);
  	tell_object(me,HIW"你被奖励了：\n" +
	chinese_number(exp) + "点实战经验\n"+
	chinese_number(score)+"点评价\n" NOR);
//	if (random(2)) {
//	gift = new("/d/wiz/fyup/obj/baotu");
//	gift->move(me);
//          tell_object(me,"你从劫匪的身上搜到一张藏宝图！\n");
//	}
    ::die();
}
