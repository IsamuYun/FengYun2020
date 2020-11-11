inherit NPC;
//written by Tiandi for uplevel duanzao
#include <ansi.h>
int do_up();
void create(){       
	set_name(HIG"牛宿天君"NOR, ({ "tianjun" }) );
	set("title", "镶嵌大师");
	set("gender", "男性" );
	set("age", 1233);
	set("long", "牛宿为北方第二宿，因其星群组合如牛角而得名，其中最著名的是织女与牵牛星，\n
	虽然牛郎与织女的忠贞爱情能让数代人倾心感动，然最终还是无法逃脱悲剧性的结局，故牛宿多凶。\n
		牛宿值日利不多，一切修造事灾多，葬埋修造用此日，卖尽田庄不记丘。  \n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1 );
	set("chat_chance_combat", 50 );
	set("chat_msg", ({
		"牛宿天君道：我们二十八星，每一星都有自己的职责，而我的职责就是提升镶嵌技能！\n",    }) );
	set("chat_msg_combat", ({
        "牛宿天君怒道：敢在我这闹事，不想活了！\n",           "牛宿天君道：非得逼我出手嘛！\n", }) );
	set("inquiry", ([
		"提升技能" : "提升镶嵌技能需要消耗潜能，评价和金钱。",
        "确认提升" : (: do_up :),
        "东方七宿" : "北宫玄武所属七宿是：牛,牛,女,虚,危,室,壁。"       ]));
	setup();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
		{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
		}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "牛宿天君说道：提升镶嵌技能是要付出一定黄金和评价。。。\n");
}
int do_up()
{
	object me,gold;
	me=this_player();
	if (!me->query("lifexiang"))  
	{
		message_vision("$N说道：$n还不会镶嵌吧，你让我如何帮你提升啊！\n",this_object(), me);                 return 1;  
	}
	if (me->query("lifexiang") > 19)
	{
		write("你的镶嵌不能再提升了。\n"); return 1;
	}

	if (((int)me->query("potential") - (int) me->query("learned_points")) < 100*me->query("lifexiang"))
		{
		write("你的潜能不足。\n");
		return 1;
		}
	if (me->query("score") < 10*me->query("lifexiang"))
		{
		write("你的评价不足。\n");
		return 1;
		}
	gold = present("gold_money", me);
    if(!gold) {
				printf("你身上没有金子。\n"); 
				return 1;
			}
    if((int) gold->query_amount() < 20*me->query("lifexiang"))
	{
				printf("你身上没有%s两黄金。\n",chinese_number(20*me->query("lifexiang")));
				return 1;
	}
	if((int)me->query("lifexiang_exp") < (int)me->query("lifexiang") * 10  )
	{
		write("目前的镶嵌技能你还没有完全掌握，怎么可以学更高级的东西？\n");
		return 1;
		}
	me->add("lifexiang",1);
	gold->add_amount(-20*me->query("lifexiang"));
	me->add("potential",-100*me->query("lifexiang"));
	me->set("lifexiang_exp",0);
	me->add("score",-10*me->query("lifexiang"));
	message_vision("$N教了$n一遍镶嵌的心得，$n顿时茅塞顿开。$N拍着$n的脑袋说道：孺子可教啊！\n",this_object(), me);
	write(HIW"你的镶嵌技能进步了。\n"NOR);
	if (me->query("lifexiang")==20)
		message("system",HIC "\n【快乐风云】谜题任务："+me->query("name")+"在镶嵌技巧上突飞猛进，获得了"HIY"【钻石王老五】"HIC"的称号。\n" NOR,users());
return 1;
}
