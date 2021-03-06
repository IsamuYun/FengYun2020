// wujiang.c - 武将
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com		1997.6

#include <ansi.h>
#include <net/dns.h>

inherit NPC;

#define SET_SKILL	100			// 定义基本武功的值，自动生成经验
#define SPE_SKILL	50			// 定义特殊武功的值
#define SET_SEN		50			// 定义正气的值

void create()
{
        set_name("武将", ({ "wu jiang", "jiang" }) );

        set("long", @LONG
这是个专门负责看守城门的武将。
LONG
	);

	set("rank_info/respect", "将军");	// 尊称
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("gender", "男性" );			// 性别
        set("age", 36);				// 年纪

	set("str", 30);				// 膂力		
	set("cps", 30);				// 定力
	set("cor", 30);				// 胆识		
	set("per", 26);				// 容貌
	set("con", 30);				// 根骨

        set("combat_exp", SET_SKILL * SET_SKILL * SET_SKILL / 10 * ( 10 + random( 10 ) ) / 10);
	set("SEN", SET_SEN);

        set("env/wimpy", 30);			//

	set("max_atman", 0);		set("atman", 0);
	set("max_force", 1000);		set("force", 2000);	set("force_factor", 100);
	set("max_mana", 0);		set("mana", 0);

        set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
	}) );

	set_skill("force",   SET_SKILL);  set_skill("hunyuan-force", SPE_SKILL);
	set_skill("sword",   SET_SKILL);  set_skill("fumo-sword",    SPE_SKILL);
	set_skill("unarmed", SET_SKILL);  set_skill("luohan-quan",   SPE_SKILL);
	set_skill("parry",   SET_SKILL);
	set_skill("move",    SET_SKILL);  set_skill("yiwei-steps",   SPE_SKILL);
	set_skill("dodge",   SET_SKILL);
	set_skill("literate",SET_SKILL);

	map_skill("force", 	"hunyuan-force");
	map_skill("sword", 	"fumo-sword");
	map_skill("unarmed", 	"luohan-quan");
	map_skill("parry", 	"fumo-sword");
	map_skill("move", 	"yiwei-steps");
	map_skill("dodge", 	"yiwei-steps");

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "武将喝道：还不快放下武器束手就缚？\n",
                "武将喝道：大胆刁民竟敢拒捕？反了！反了！\n"
        }) );

        setup();
        
	carry_object("/obj/cloth/tie-kui")->wear();	// 装备
	carry_object("/obj/cloth/iron-baojia")->wear();	
	carry_object("/obj/cloth/zhan-boots")->wear();	

	carry_object("/obj/weapon/longsword")->wield();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}

void greeting(object ob)
{
       	if( !ob || !present(ob, environment(this_object())) ) return;
        if(!ob->query("kill_flag") )	return;
	message_vision("$N把告示中的人像和$n对了一对，大喝了一声：还想走？\n", this_object(), ob);
	command("kill "+ob->query("id") );
}

int accept_object(object who, object ob)
{
	int exp,sen,gold;
	object gold_ob;

 	if(!userp(ob) || (!ob->query("kill_flag")) )	return 0;
	if(query_ip_name(ob) == query_ip_name(who) ) {
		command("say 请多看一看游戏规则！下不为例！");
		return 0;
	}
	command("say 做得好！本官一定重重赏你。");
	exp = 100 + random(10 * (int)who->query("kar"));
	sen = 100 + random(10 * (int)who->query("kar"));
	gold = 10 + random((int)who->query("kar"));
	tell_object(who, sprintf("你获得了：\n%d点战斗经验。\n%d点正神。\n%d两黄金。\n", exp, sen, gold) );
	who->add("combat_exp", exp);
	who->add("SEN", sen);
	if(!gold_ob=present("gold",who)) {
		gold_ob=new("/obj/money/gold");
		gold_ob->move(who);
		gold_ob->set_amount(gold);
	}
	else	gold_ob->add_amount(gold);
	ob->move("/d/death/prison");
	ob->set("startroom","/d/death/prison");
	ob->set("in_prison",1);
	return 0;
}
