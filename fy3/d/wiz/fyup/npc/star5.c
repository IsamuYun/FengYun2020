// by Tiandi for upgrading lifecombine
inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIG"心宿天君"NOR, ({ "tianjun" }) );
	set("gender", "男性" );
	set("age", 1233);
	set("title","合成大师");
	set("long", "为东方第五宿，为苍龙腰部。心为火，是夏季第一个月应候的星宿，常和房宿连用，\N心宿恶星元非横，起造男女事有伤，坟葬不可用此日，三年之内见瘟亡 。\n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_chance_combat", 50 );
	set("chat_msg", ({   "心宿天君道：天宫二十八星，每一星都有自己的职责，而我的职责就是提升合成能力！\n",}) );
	set("chat_msg_combat", ({"心宿天君怒道：敢在我的地盘闹事，不想活了！\n", "心宿天君道：我也好久没有舒展胫骨了！\n", }) );
	set("inquiry", (["合成术" : "每一块强化石都可以同类强化石合成为更高级的强化石，二十八星中，只有我有这个能力提升(upgrade)合成技巧。",   
		           "东方七宿" : "东宫苍龙所属七宿是：角、亢、氐、房、心、尾、箕。" ,
		           "合成地点" : "合成强化石只有在有铁炉的地方才可以。" ,
			"升级合成术": "提升合成技巧需要消耗经验，潜能以及评价。" ]));
	setup();
}
void init(){
	object ob;
     	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	 {
		 remove_call_out("greeting");
		 call_out("greeting", 1, ob);
	  }
	add_action("do_upgrade", "upgrade");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) 
		return;
	say( "心宿天君说道：提升合成技巧是要付出一定代价的，慎重选择啊。。。\n");
}
int do_upgrade()
{
	object me;
	me=this_player();
	if (!me->query("lifecombine"))  
	{
	message_vision("$N说道：$n还不会合成技巧，你让我如何帮你提升啊！\n",this_object(), me);    
           	return 1;  
	}
	if (me->query("lifecombine") > 19)
	{	
	write("你的合成术不能再提升了。\n"); 
			return 1;
	}
	if (me->query("combat_exp") < 7000 *me->query("lifecombine"))
	 {
	 	write("你的经验不足"+chinese_number(7000 *me->query("lifecombine"))+"。\n"); 
		return 1;
	}
	if (((int)me->query("potential") - (int) me->query("learned_points")) < 1000*me->query("lifecombine"))    
	{
		write("你的潜能不足"+chinese_number(1000 *me->query("lifecombine"))+"。\n");
		return 1;
	}
	if (me->query("score") < 20*me->query("lifecombine"))    
	{
		write("你的评价不足"+chinese_number(20 *me->query("lifecombine"))+"。\n");
		return 1;
	}
	if((int)me->query("lifecombine_exp") < ((int)me->query("lifecombine") * (int)me->query("lifecombine"))  )
	{
		write("目前的合成技巧你还没有完全掌握，再去熟练一下吧\n");
		return 1;
	}
	me->add("max_lifetili",10);
	me->add("combat_exp",-7000 *me->query("lifecombine"));
	me->add("potential",-1000*me->query("lifecombine"));
	me->set("lifecombine_exp",0);
	me->add("lifecombine",1);
	me->add("score",-20*me->query("lifecombine"));
	message_vision("$N教了$n一遍合成的心得，$n顿时茅塞顿开。$N拍着$n的脑袋说道：孺子可教啊！\n",this_object(), me);
	write(HIW"你的合成技巧进步了。\n"NOR);
	if (me->query("lifecombine")==20)
		message("system",HIC "\n【快乐风云】谜题任务："+me->query("name")+"在合成技巧上突飞猛进，获得了"HIY"【以多换少】"HIC"的称号。\n" NOR,users());

	return 1;
}

