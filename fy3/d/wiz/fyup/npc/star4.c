// by Tiandi for open max weapon of lifeskill
inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIG"房宿天君"NOR, ({ "tianjun" }) );
	set("gender", "男性" );
	set("age", 1233);
	set("title","成长研究大师");
	set("long", "是东方第四宿，为苍龙的颈。龙颈，有龙角之护卫，变者带动全身，故多吉。 房宿之星事可求，婚姻祭祀有来头，葬埋必出有官贵，开门放水出公侯。\n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_chance_combat", 50 );
	set("chat_msg", ({   "房宿天君道：天宫二十八星，每一星都有自己的职责，而我的职责就是提升武器装备的最大能力！\n",}) );
	set("chat_msg_combat", ({"房宿天君怒道：敢在我的地盘闹事，不想活了！\n", "房宿天君道：我也好久没有舒展胫骨了！\n", }) );
	set("inquiry", (["提升" : "每一把锻造而来的兵刃铠甲都是带有一定成长空间的，凡人都想方设法开启他们的最大能力，\n但却不知道，二十八星中，只有我有这个能力提升(uplevel)它们的成长空间。",   
		           "东方七宿" : "东宫苍龙所属七宿是：角、亢、氐、房、心、尾、箕。" ,
			"查看":"你可以让我帮你查看(check)物品的成长属性。" ]));
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
	add_action("do_jifa", "uplevel");
	add_action("do_jifa2", "check");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) 
		return;
	say( "房宿天君缓缓地说道：兵器的成长可分为二十个阶段。。。\n");
}
int do_jifa(string arg)
{
	object me, ob,gold;
	int lv,score,itemlv;
	me = this_player();
	if( !arg ) 
		return notify_fail("你要提升什麽东西的能力？\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	if( !ob->query("selfmaking") )
		return notify_fail("你只能提升锻造或者炼制的东西。\n");
	if( ob->query("equipped") )
		return notify_fail("这个东西正装备着呢。\n");
	//   if( !ob->query("owner") )
	// return notify_fail("这东西好像不是你弄出来的吧。\n");
	lv = ob->query("level");
	if( !objectp(gold = present("level sheet", me)) )
		return notify_fail("你身上没有冶炼符。\n");
	score=me->query("score");
	if (score < 10)
		return notify_fail("你的评价不够10点。\n");

	message_vision("$n毕恭毕敬地把手中的"+ob->query("name")+"交给$N，笑嘻嘻地对$N说道：那就拜托天君帮我看看"+ob->query("name")+"是否还有剩余的能力可以开通的吧。\n"NOR,this_object(),me);
	if(lv>19)
		{
      	message_vision(HIB"$N接过$n手中的"+ob->query("name")+"，一边看一边道：这东西已经到了它的最大能力，没有什么成长空间了。\n"NOR,this_object(),me);
		message_vision("$N把"+ob->name()+"归还给了$n。\n",this_object(),me);
		return 1;
		}
	else
		{
		message_vision(HIB"$N接过$n手中的"+ob->query("name")+"，霎那间"+ob->query("name")+"发出无比绚丽的色彩，如有灵性一般，自动返回到$n的手中。\n"NOR,this_object(),me);
		ob->set("level",lv+1);
		
		message_vision("$N说道：好了。"+ob->query("name")+"已经成长为第"+chinese_number(ob->query("level"))+"阶段。\n"NOR,this_object(),me);
		
		me->start_busy(1);
		seteuid(ROOT_UID);
		ob->save();
		ob->restore();
		if(ob->move(me))
			{
			message_vision("$N把"+ob->name()+"归还给了$n。\n",this_object(),me);
			write ("你消耗了10点评价。\n");
			me->add("score",-10);
			}
 		seteuid(getuid());
		destruct(gold);
		return 1;
		}
}

int do_jifa2(string arg)
{
	object me, ob;
	me = this_player();
         if( !arg ) 
		return notify_fail("你要查看什麽东西？\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	if( !ob->query("selfmaking") )
		return notify_fail("你只能了查看造或者炼制的物品成长度。\n");
	write(ob->query("name")+"的成长度为第"+chinese_number(ob->query("level"))+"阶段。\n");
 	me->start_busy(1);
return 1;
}
