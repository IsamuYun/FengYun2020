// guanbing.c
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com		1997.6

#include <ansi.h>

inherit NPC;

#define SET_SKILL	100			// 定义基本武功的值（随机），自动生成经验
#define SET_SEN		10			// 定义正气的值

void create()
{
	int n;

        set_name("兵丁", ({ "bing ding", "bing" }) );

        set("long", @LONG
这是个专门负责看守城门的兵丁。
LONG
	);

        set("attitude", "heroism");
        set("vendetta_mark", "authority");
	set("gender", "男性" );
	set("age", 30);

	set("str", 30);				// 膂力		
	set("cps", 30);				// 定力
	set("cor", 30);				// 胆识		
	set("per", 26);				// 容貌
	set("con", 30);				// 根骨

        set("combat_exp", SET_SKILL * SET_SKILL * SET_SKILL / 10 * ( 10 + random( 10 ) ) / 10);
	set("SEN", SET_SEN);

        set("env/wimpy", 30);			//

	n = SET_SKILL + random(10) - 5;		set_skill("unarmed", (n <= 0) ? 1 : n); 
	n = SET_SKILL + random(10) - 5;		set_skill("parry",   (n <= 0) ? 1 : n);
	n = SET_SKILL + random(10) - 5;		set_skill("dodge",   (n <= 0) ? 1 : n);

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "官兵喝道：还不快放下武器束手就缚？\n",
                "官兵喝道：大胆刁民竟敢拒捕？反了！反了！\n"
        }) );

        setup();
        
	carry_object("/obj/cloth/tou-kui")->wear();	// 装备
	carry_object("/obj/cloth/binding-cloth")->wear();
	carry_object("/obj/cloth/boots")->wear();
	
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
	command("kill "+ob->query("id") );
}
