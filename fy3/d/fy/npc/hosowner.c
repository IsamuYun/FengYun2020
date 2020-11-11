// waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("普生", ({ "pusheng" }) );
	set("gender", "男性" );
	set("age", 31);
	set("title", GRN "赛华陀" NOR);
	set("long",
		"这位普生堂老板武功，医道精湛。救死扶伤无数。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
		  set_temp("kf_tufei",27);
        set("pursuer", 1);
set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/sendrug":12,
                __DIR__"obj/keedrug":22,
                __DIR__"obj/gindrug":12,

	]) );
	set("inquiry", ([ 
			"疗伤" : "十级以下本人可以免费治疗(heal)，十级以上就需要收费了。\n" 
	]));

	set_skill("unarmed",50);
	set_skill("dodge",150);
	set_skill("changquan",150);
	map_skill("unarmed", "changquan");
	setup();
	carry_object(__DIR__"obj/fycloth")->wear();
        carry_object("/d/qianjin/npc/obj/chungongtu");
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
	add_action("do_heal", "heal");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(20) ) {
		case 0:
message_vision("$N望了$n一眼，低声说道：你面黄肌瘦，肾水亏空，是否．．．过度？\n",this_object(),ob);
			break;
	}
}
int do_heal()
{
	object me,gold;
	int lv;
	me = this_player();
	lv = me->query("level");
	if (me->query("kee")>= me->query("max_kee")){
		write("你状况很好，不需要接受治疗。\n");
		return 1;
	}
	gold = present("gold_money", me);
	if (lv< 10)
	{
	me->set("eff_kee",me->query("max_kee"));
	me->set("kee",me->query("max_kee"));
	me->set("eff_sen",me->query("max_sen"));
	me->set("sen",me->query("max_sen"));
	me->set("eff_gin",me->query("max_gin"));
	me->set("gin",me->query("max_gin"));
		write("普生道：好了！\n");
		return 1;
	}
	if (!gold)
			return notify_fail("普生只收金子!\n");
	if (gold->query_amount() < lv/10)
			return notify_fail("你身上的金子不够"+lv/10+"两!\n");
	gold->add_amount(-lv/10);
	me->set("eff_kee",me->query("max_kee"));
	me->set("kee",me->query("max_kee"));
	me->set("eff_sen",me->query("max_sen"));
	me->set("sen",me->query("max_sen"));
	me->set("eff_gin",me->query("max_gin"));
	me->set("gin",me->query("max_gin"));
	write("普生道：好了！\n");
	return 1;
}

