inherit NPC;
//written by Tiandi for uplevel duanzao
#include <ansi.h>
int add_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar);

void create(){       
	set_name(HIG"斗宿天君"NOR, ({ "tianjun" }) );
	set("title", "投胎转世");
	set("gender", "男性" );
	set("age", 1233);
	set("long", "斗宿是为北方之首宿，因其星群组合状如斗而得名，古人又称“天庙”，是属于天子的星。\n
	天子之星常人是不可轻易冒犯的，故多凶。斗宿值日不吉良，婚姻祭祀不吉昌，葬埋不可用此日，\n
	百般万事有灾殃。  \n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1 );
	set("chat_chance_combat", 50 );
	set("chat_msg", ({
		"斗宿天君道：我们二十八星，每一星都有自己的职责，而我的职责就是改变民族！\n",    }) );
	set("chat_msg_combat", ({
        "斗宿天君怒道：敢在我这闹事，不想活了！\n",           "斗宿天君道：非得逼我出手嘛！\n", }) );
	set("inquiry", ([
		"改变民族" : "只有普通百姓才可以改变民族（change)，每个民族升级时系统自动加点的方式皆不同哦。",
        "北方七宿" : "北宫玄武所属七宿是：斗,牛,女,虚,危,室,壁。"       ]));
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
	add_action("do_change","change");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "斗宿天君说道：为了方便部分玩家由于选错民族后懊悔不已。。。\n");
}
int do_change(string arg)
{
	object me;
	int lv;
	string national;
	me=this_player();
	lv = me->query("level");
	if  (me->query("class"))   
	{
		message_vision("$N说道：$n已经不是普通百姓了，不能申请改变民族！\n",this_object(), me);    
		return 1;  
	}
	if( !arg ) return notify_fail("你要改变成什么民族？(Etc:change 汉族 \n");
	if (arg != "汉族" && arg !="蒙古族" && arg!="藏族")
		return notify_fail("暂时没有这个"+arg+"这个民族。\n");
	me->set("tol",1);
	me->set("fle",1);
	me->set("agi",1);
	me->set("dur",1);
	me->set("int",1);
	me->set("str",1);
	me->set("con",1);
	me->set("spi",1);
	me->set("per",1);
	me->set("cor",1);
	me->set("cps",1);
	me->set("kar",1);
	switch(arg){
		case "汉族":  
			add_attribute(me,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv);  
			break;
		case "藏族":  
			add_attribute(me,6*lv,9*lv,3*lv,9*lv,6*lv,6*lv,6*lv,3*lv,3*lv,9*lv,9*lv,3*lv);
			break;
		case "蒙古族":
			add_attribute(me,9*lv,9*lv,6*lv,6*lv,3*lv,9*lv,6*lv,6*lv,9*lv,3*lv,3*lv,3*lv);
            break;
	}
	me->set("gift_points",lv*5);
	me->set("used_gift_points",0);
	me->set("national",arg);
	message_vision("$N说到，好了，你已经成功的转变成了"+me->query("national")+"！\n",this_object(), me);
	message("system",HIY "\n【快乐风云】民族转换："+me->query("name")+"由于误选民族，特此申请将民族改成了"HIC+arg+HIY"。\n" NOR,users());
return 1;
}
int add_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar)
{
user->add("tol",tol);
user->add("fle",fle);
user->add("agi",agi);
user->add("dur",dur);
user->add("int",intt);
user->add("str",str);
user->add("con",con);
user->add("spi",spi);
user->add("per",per);
user->add("cor",cor);
user->add("cps",cps);
user->add("kar",kar);
return 1;
}
