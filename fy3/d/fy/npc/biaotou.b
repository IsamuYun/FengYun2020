
inherit NPC;
#include <ansi.h>
object cart;
object *protector;
mapping default_dirs = ([
        "north":                "北",
        "south":                "南",
        "east":                 "东",
        "west":                 "西",
        "northup":              "北边",
        "southup":              "南边",
        "eastup":               "东边",
        "westup":               "西边",
        "northdown":            "北边",
        "southdown":            "南边",
        "eastdown":             "东边",
        "westdown":             "西边",
        "northeast":            "东北",
        "northwest":            "西北",
        "southeast":            "东南",
        "southwest":            "西南",
        "up":                   "上",
        "down":                 "下",
        "enter":                "里",
        "out":                  "外",
]);
void give_reward();
int ask_arrived();
void to_rob();
void be_protect();
//int ask_start();
void create()
{
	object ob;
	set_name("李镖头", ({ "biaotou" }) );
	set("gender", "男性" );
	set("age", 25);
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("vendetta_mark", "authority");
        set("no_get",1);
        set("per",2);
        set("inquiry", ([
//                "出发" : (: ask_start :),
                               "抵达" : (: ask_arrived :),
        ]));
        	set("chat_chance", 15);
    set("chat_msg",({
    	"李镖头喝道：“闲杂人等闪开了。”\n",
    	"李镖头喝道：“快走快走，别偷懒！”\n",
    }) );
    set("chat_chance_combat",90);
    set("chat_msg_combat", ({
    	"李镖头大喊道：“不好了，有人劫镖了。”\n",
    	(: be_protect :),
    }) );
	
	set("force",500);
	set("max_force",500);
	set("force_factor",2);
	set_skill("blade",150);
	set_skill("shortsong-blade",150);
	set_skill("force",140);
	set_skill("parry",150);
	set_skill("dodge",150);
	set_skill("iron-cloth",120);
	map_skill("blade","shortsong-blade");
	map_skill("parry","spring-blade");
	setup();
  	add_money("silver", 50);
    carry_object(__DIR__"obj/jinzhuang")->wear();
    carry_object("/obj/weapon/blade")->wield();
	carry_object("/obj/example/wineskin");

}
void init()
{
        add_action("do_move","move");
}
int do_move(string arg)
{
        object me, ob, env;
        mapping exit;
        int busy, kar,i;
        me = this_player();
        ob = this_object();
        env = environment(me);
        kar = me->query("kar");

        if( !living(ob) )
              return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

        if (ob->query_temp("owner/id") != me->query("id")) {
                command("? " + me->query("id"));
                return notify_fail("\n");
                }
        
        if (!arg) {
                command("kick " + me->query("id"));
                command("say 你要我赶到哪儿去？");
                return notify_fail("\n");
                }

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                command("?");
                command("say 这个方向没有路呃。");
                return notify_fail("\n");
                }

        if (ob->is_busy()) {
                command("say 我这儿正忙着呢！");
                return notify_fail("\n");
                }

        if (me->is_busy()) {
                command("say 你自己都忙不过来，还催我干什么？");
                return notify_fail("\n");
                }

        if (me->is_fighting()) {
                command("say 请你先把我的对手料理了吧！\n");
                
                }
        if (me->query_temp("quest/biao_b")!=1) {
                command("say 你只能运一次镖!");
                return notify_fail("\n");
             }

        command("go " + arg); 
        ob->start_busy(3 + random(3));
        me->move(environment(ob));
        message_vision(HIC "镖头用警惕的眼光观察着四周。\n" NOR,me);
        busy = 2 + random(30 - kar);
        if (busy > 3) busy = 3;
        me->start_busy(busy);
           for (i=0;i<=random(5)+1;i++)
       {        ob=new(__DIR__"gangster2");
		ob->move(environment());
                ob->kill_ob(this_player());
		this_object()->kill_ob(ob);
                ob->invocation(me);
        	ob->set_leader(this_object());
	}	
   	message_vision(HIC"忽然间跳出一群劫匪！\n"NOR,this_object());
               
        return 1;
}
/*
int ask_start()
{
        object ob = this_object(), me = this_player();

        if (ob->query_temp("started")) {
                command("say 不是已经在路上了吗？");
                return 1;
                }

        if (me->query("quest/yunbiao") ==1) {
                ob->set_temp("started",1);
                ob->set_temp("owner/id",me->query("id"));
                command("say 好吧，我们出发！");
                return 1;
                }
        
        if (ob->query_temp("owner/id") != me->query("id")) {
                command("slap " + me->query("id"));
                command("say 又没有让你护镖，来瞎闹什么？");
                return 1;
                }
        call_out("leave", 300);
        return 1;
}
*/
int ask_arrived()
{
        object me, ob;
        int exp, pot, kar, ggold, score;
        
        me = this_player();
        ob = this_object();
        kar = me->query("kar");

        if (ob->query_temp("owner/id") != me->query("id")) {
                command("say " + me->query("name") + "想冒领他人功劳！");
                command("grin " + me->query("id"));
                return 1;
                }
                     if (me->query_temp("quest/biao_b")!=1) {
                command("say 你只能运一次镖!");
                return notify_fail("\n");
                     }
        if (ob->is_busy()) {
                command("say 我这儿正忙着呢！");
                return notify_fail("\n");
                }

        if (me->is_fighting()) {
                command("say 请你先把我的对手料理了吧！\n");
                return notify_fail("\n");
                }

        if (file_name(environment(ob)) !="/d/chenxiang/nanbank") {
                         command("say 你想半途而废？");
                       return 1;
                       }
        if (!present("nangong", environment(ob))) {
                       command("say 南宫不在，不好交差啊！");
                       return 1;
                       }
  

        me->set("quest/yunbiao",0);
        me->set("quest/biao_b",0);
        exp = (7000 + random(12000));
        pot = (2000 + random(2000));
        ggold = (500000+random(500000));
        score = (random(7));
        message_vision(HIW "$N被奖励了：\n"
                + HIG + chinese_number(exp) + "点实战经验，\n"  
                + HIC + chinese_number(pot) + "点潜能，\n"
                + HIY + chinese_number(ggold / 10000) + "两黄金，\n" 
                + HIR + chinese_number(score) + "点评价。 \n"NOR,me);
         me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set("quest/yunbiao",0);
        me->add("deposit",ggold);
        me->add("score",score);

        message_vision(CYN "镖师往钱庄里间离去了。\n" NOR,me);
        destruct(ob);

        return 1;
}
   
void leave()
{
        message_vision(HIC "镖头急急忙忙地离开了。\n" NOR,this_object());
        destruct(this_object());
}

void set_protector(object *prot)
{	protector=prot;	}
object *query_protector()
{	return protector;	}

void set_cart(object dartcart)
{	cart=dartcart;	}
object query_cart()
{	return cart;	}

void die()
{
	object killer,goldd;
	killer=query_temp("last_damage_from");
		if (objectp(killer))
		{
			command("chat 镖银被"+killer->name()+"抢走了！");
			message_vision("$N搜索了镖头身上，抢走了其中的镖银！\n",killer);

				
				if (userp(killer))
				{
	      			goldd = new("obj/money/gold");
	      			goldd->set_amount(100+random(100));
	                        goldd->set("name",HIY" 南宫金票"NOR);
	                        goldd->move(killer);
				killer->add("vendetta/authority",1);
				killer->add("score",-100);
				}
				else{
       			        goldd = new("obj/money/gold");
				goldd->set("name",HIY" 南宫金票"NOR);
				goldd->move(killer);
			     }
			}
		::die();
}


