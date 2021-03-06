#include <ansi.h>
inherit NPC;

string host_id;
void create()
{
	set("title",HIY"笑面虎"NOR);
	set_name("余有财",({"yuyoucai","yu"}));
	set("gender","男性");
	set("age",53);
	set("attitude","friendly");
	set("long","一副笑迷迷的样子，一看就是个生意人。\n");
	set("inquiry",([
		"jiuxi" : "嗯，10两金子办一次酒席，无二价。",
		"酒席"  : "嗯，10两金子办一次酒席，无二价。",
		]));
	setup();
    carry_object("/obj/cloth")->wear();

}
int accept_object(object who,object ob)
{
	object yu;
	string arg;
	int val;
	val=ob->value();
	yu=this_object();
	if ( ob->query("name") == HIR"请柬"NOR)
	{
		if (ob->query_temp("id_code") != host_id)
		{
			yu->ccommand("say 这个请柬好像有问题，没收！\n");
			return 1;
		}
		else {
			yu->ccommand("say 好的，大爷里面请。\n");
			who->set_temp("guest",1);
			return 1;
		}
	}
	if ( !val)
		return 0;
	if (yu->query_temp("gold_recieved"))
	{
		write("余老板遗憾的说：对不起，有人已经交下定金了。\n");
		return 0;
	}
	if (val >= 100000)
	{
		yu->ccommand("smile");
		yu->ccommand("say 不知道大爷为什么开办酒席啊？喜金给多少呢？\n");
		write("指定酒席命令：order <数量> gold because <酒席原因>\n");
		who->set_temp("gold_given",1);
		yu->set_temp("gold_recieved",1);
		return 1;
	}
	else
	{	
		yu->ccommand("say 这么点钱够干什么啊？\n");
		return 0;
	}
}
void init()
{
	add_action("do_order","order");
}
int do_order(string arg)
{
	int amount,i;
	object *ob;
	object invitation;
	string reason;
	object who,yu;
	who=this_player();	
	yu=this_object();
	if (who->query_temp("ordered"))
		return notify_fail("你已经定过酒席了。\n");
	if ( !(who->query_temp("gold_given")) )
		return notify_fail("什麽？\n");
	if ( !arg || sscanf(arg,"%d gold because %s",amount,reason) !=2)
		return notify_fail("指令格式：order <数量> gold because <酒席原因>\n");
	if ( amount <= 0)
		return notify_fail("喜金数量好象......\n");
	who->set_temp("gold",amount);
	who->set_temp("reason",reason);
	who->set_temp("ordered",1);
	who->set_temp("host",1);
	ob=filter_array(users(),"filter_accept_qingjian",this_object());
	for (i=0;i<sizeof(ob);i++)
	{
		invitation=new("/d/fy/npc/obj/invitation");
		invitation->set("long",
"尊敬的"+ob[i]->query("name")+":\n"
"    为了庆祝"+who->query_temp("reason")+",本人在快活林酒家开办酒席，欢迎您届时参加，谢谢。\n"
"                                                         "+who->query("name")+"敬上\n"
         );
		invitation->set_temp("id_code",who->query("id"));
		host_id=who->query("id");
		invitation->move(ob[i]);
		tell_object(ob[i],"你收到一封请柬。\n");
	}
	yu->ccommand("say 大爷，酒席马上开始您先进大厅稍等片刻。\n");
	who->delete_temp("gold_given");
	yu->ccommand("chat 为庆祝"+who->query_temp("reason")+","+who->query("name")+"("+who->query("id")
		+")"+"在本酒楼开办酒席，喜金"+chinese_number(who->query_temp("gold"))+"两,现在开始。\n");
	call_out("end_jiuxi",200,who);
	return 1;	 
}
int filter_accept_qingjian(object ppl)
{
	if (!(ppl->query_temp("host")))
	{
		return 1;
	}
	else {
		return 0;
	}
}
int end_jiuxi(object who)
{
	object yu;
	who->delete_temp("host");
	yu=this_object();
	yu->ccommand("chat 为庆祝"+who->query_temp("reason")+","+who->query("name")+"("+who->query("id")
		+")"+"在本酒楼开办的酒席,现在结束，多谢各位的捧场。\n");
	yu->delete_temp("gold_recieved");
	who->delete_temp("ordered");
	return 1;
}