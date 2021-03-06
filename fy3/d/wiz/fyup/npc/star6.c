// by Tiandi for upgrading lifexiang
inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIG"尾宿天君"NOR, ({ "tianjun" }) );
	set("gender", "男性" );
	set("age", 1233);
	set("title","镶嵌大师");
	set("long", "为东方第六宿，尾宿九颗星形成苍龙之尾。龙尾，是斗杀中最易受到攻击部位，故多凶。 \N尾宿之日不可求，一切兴工有犯仇，若是婚姻用此日，三年之内有悲哀。 \n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_chance_combat", 50 );
	set("chat_msg", ({   "尾宿天君道：天宫二十八星，每一星都有自己的职责，而我的职责就是提升镶嵌能力！\n",}) );
	set("chat_msg_combat", ({"尾宿天君怒道：敢在我的地盘闹事，不想活了！\n", "尾宿天君道：我也好久没有舒展胫骨了！\n", }) );
	set("inquiry", (["镶嵌术" : "每一把经过成长的武器装备都可以镶嵌上强化石来达到更好的能力，二十八星中，只有我有这个能力提升(upgrade)镶嵌技巧。",   
		           "东方七宿" : "东宫苍龙所属七宿是：角、亢、氐、房、心、尾、箕。" ,
		           "镶嵌地点" : "镶嵌防具装备只能在有铁炉的地方进行。" ,
			"升级镶嵌术": "提升镶嵌技巧需要消耗经验，潜能以及评价。" ]));
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
	say( "尾宿天君说道：提升镶嵌技巧是要付出一定代价的，慎重选择啊。。。\n");
}
int do_upgrade()
{
	object me;
	me=this_player();
	if (!me->query("lifexiang"))  
	{
	message_vision("$N说道：$n还不会镶嵌技巧，你让我如何帮你提升啊！\n",this_object(), me);    
           	return 1;  
	}
	if (me->query("lifexiang") > 19)
	{	
	write("你的镶嵌术不能再提升了。\n"); 
			return 1;
	}
	if (me->query("combat_exp") < 7000 *me->query("lifexiang"))
	 {
	 	write("你的经验不足"+chinese_number(7000 *me->query("lifexiang"))+"。\n"); 
		return 1;
	}
	if (((int)me->query("potential") - (int) me->query("learned_points")) < 1000*me->query("lifexiang"))    
	{
		write("你的潜能不足"+chinese_number(1000 *me->query("lifexiang"))+"。\n");
		return 1;
	}
	if (me->query("score") < 20*me->query("lifexiang"))    
	{
		write("你的评价不足"+chinese_number(20 *me->query("lifexiang"))+"。\n");
		return 1;
	}
	if((int)me->query("lifexiang_exp") < ((int)me->query("lifexiang") * (int)me->query("lifexiang"))  )
	{
		write("目前的镶嵌技巧你还没有完全掌握，再去熟练一下吧\n");
		return 1;
	}
	me->add("max_lifetili",10);

	me->add("combat_exp",-7000 *me->query("lifexiang"));
	me->add("potential",-1000*me->query("lifexiang"));
	me->set("lifexiang_exp",0);
	me->add("lifexiang",1);
	me->add("score",-20*me->query("lifexiang"));
	message_vision("$N教了$n一遍镶嵌的心得，$n顿时茅塞顿开。$N拍着$n的脑袋说道：孺子可教啊！\n",this_object(), me);
	write(HIW"你的镶嵌技巧进步了。\n"NOR);
	if (me->query("lifexiang")==20)
		message("system",HIC "\n【快乐风云】谜题任务："+me->query("name")+"在镶嵌技巧上突飞猛进，获得了"HIY"【镶钻王老五】"HIC"的称号。\n" NOR,users());

	return 1;
}

