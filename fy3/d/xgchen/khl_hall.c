#include <ansi.h>
inherit ROOM;

void greeting(object me);
int give_him(object who,object host);
void create()
{
	set("short","宴会大厅");
	set("long",@LONG
这里是快活林的宴会大厅，房间很大，摆放了很多八仙桌椅，东侧
摆放的屏风上绘画的清明上河图更显房间的典雅气派。房间内侧正对门
口的地方有个小戏台，一般办酒席的主人都在这里接受大家的贺喜。
还不快向主人贺喜？(hexi)
LONG
	);
	set("exits",([
		"out" : "/d/fy/kuaihuolin",
		]));
	set("no_burn",1);
	set("no_quit",1);
	set("no_fight",1);
	set("no_magic",1);
	set("no_spells",1);
	set("no_huanlong",1);
	set("no_dazuo",1);
	set("coor/x",5);
	set("coor/y",5);
	set("coor/z",5);
	setup();
}
void init()
{
	object me;
	me=this_player();
	add_action("do_hexi","hexi");
	greeting(me);
	return;
}

int valid_leave(object me,string dir)
{
	if (userp(me))
	if ( dir=="out" && me->query_temp("host"))
	{
		return notify_fail("你是酒席主人啊？酒席没有结束怎么能离开呢？\n");
	}
	else {
		if (dir=="out" && me->query_temp("guest"))
		{
			me->delete_temp("guest");
			me->delete_temp("hongbao_given");
			return 1;
		}
		else{
			return 1;
		}
	}
}
void greeting(object me)
{
	message_vision(HIG"只见$N扑向桌子，狼吞虎咽一番。\n"NOR,me);
	me->set("food",200);
	me->set("water",200);
	return;
}
int do_hexi()
{
	object who,host,*ob;
	int key=0,i;
	who=this_player();
	ob=all_inventory(environment(who));
	if (who->query_temp("host"))
		return notify_fail("不能向自己贺喜啊？\n");
	for (i=0;i<sizeof(ob);i++)
	{
		if ((ob[i]->query_temp("host")))
		{
			host=ob[i];
			key=1;
			break;
		}
		else {
			continue;
		}
	}
	if (!key) {return notify_fail("主人不在这里，向谁贺喜啊？\n");}
	if (!(who->query_temp("hongbao_given")))
	{
		give_him(who,host);	
		return 1;
	}
	else {
		message_vision(HIC"$N向$n说道：恭喜，恭喜。\n"NOR,who,host);
		message_vision(HIY"$N哈哈大笑向$n说道：同喜，同喜。\n"NOR,host,who);
		return 1;
	}
}
int give_him(object guest,object master)
{
	object hongbao;
	int deposit;
	hongbao=new("/d/fy/npc/obj/hongbao");
	hongbao->set_temp("account",master->query_temp("gold"));
	deposit=master->query("deposit");
	message_vision(HIC"$N向$n说道：恭喜，恭喜。\n"NOR,guest,master);
	message_vision(HIY"$N哈哈大笑,向$n道：同喜，同喜。\n"NOR,master,guest);
	if (deposit < (master->query_temp("gold")*10000))
	{
		message_vision(HIM"$N脸一红，原来$P的存款不够发红包了。\n"NOR,master);
		return 1;
	}
	else{
		message_vision(HIR"只见$N从怀里掏出一个红包递给$n。\n"NOR,master,guest);
		guest->set_temp("hongbao_given",1);
		hongbao->move(guest);
		master->add("deposit",-(master->query_temp("gold")*10000));
		return 1;
	}
}