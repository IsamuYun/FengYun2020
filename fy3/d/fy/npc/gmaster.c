inherit NPC;
#include <ansi.h>

string *npc = ({
"南宫十一郎",
"南宫十三郎",
"南宫十二郎",
"葛伦",
"黄麻子",
"李一摸",
"叶孤城",
"上官金虹",
"丁白云",
"丁乘风",
"蓝天锤",
"西门吹雪",
"箫王孙",
"楚留香",
"李红袖",
"原随云",
"羽天白",
"姬冰雁",
"曲无容",
"石观音",
"冰冰",
"太白逸",
"风四娘",
"李红樱",
"金凤凰",
"柳无眉",
"萧十一郎",
"厉青锋",
"玉兰溪",
"逍遥侯",
"兴国大师",
"任慈",
"阿飞",
"心湖",
"白水娘娘",
"白三空",
"李大嘴",
"傅红雪",
"淳于怀太",
"胭松",
"黑珍珠",
"铁少",
"雪蕊儿",
"石雁",
   });

void create()
{
      set_name("查猛", ({ "meng", "cha meng" }) );
      set("title", HIY "金狮掌" NOR);
      set("gender", "男性" );
      set("age", 42);
      set("skill_public",1);
      create_family("少林俗家", 21, "弟子");

      set("long",
                "金狮掌查猛是少林俗家弟子，人不但性情豪爽，且广交朋友．
凡是想向他求教的，只要为镖局出点力，他就肯教．\n"
                );
	set("inquiry", ([ "运镖" : "最近镖局生意太多，我们人手不够，你愿意协助我吗？（quest）" 
	  ]));

       set("chat_chance", 1);
       set("chat_msg", ({
                "查猛说道：这个月镖局生意不错！\n",
        }) );        
        set("attitude", "peaceful");
        set_skill("unarmed", 60);
        set_skill("changquan", 50);
        set_skill("literate", 60);
        set_skill("force", 70);
        set_skill("dodge",60);
        set_skill("parry",50);
        map_skill("unarmed", "changquan");
        set("combat_exp", 190000);
        setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
}
void init()
{
        add_action("give_quest", "quest");
}

int give_quest(string arg)
{
	mapping quest ;
	object me,room,qiangdao;
	int j, combatexp, timep,gold ;
	string file,location,*roomlines;
	me = this_player();

	if((int) me->is_ghost())
	{
		write("鬼魂不可要任务．\n");
		return 1;
	}
	if (me->query("level")<10)
	{
		write("护镖还是需要一定实力才能做的，目前你的实力还不够资格。\n");
		return 1;
	}
//	if ((me->query("hubiaojob") - 100) > me->query("TASK"))
//	{
//		write("目前你的护镖任务完成次数已经达到上限。\n");
//		return 1;
//	}
	if( ((int) me->query("lasthbtime")+60*5) >  time() )
	{
		write("两次护镖任务的间隔时间不得少于五分钟。\n");
		return 1;
	}
	if( ! me->query("hubiao") )
	{
		combatexp = me->query("level");
		gold = combatexp;
		write("查猛道：想替我护镖？太好了，不过你总得把押金付了吧。\n");
		write("查猛道：按照您目前的等级，您需要交纳"+chinese_number(gold)+"两黄金。\n");
		me->set_temp("yajinok",1);
		return 1;
	}
	if( me->query("hubiao") )
	{
		write("查猛道：你到现在还没有完成护镖任务，你的押金我没收了！\n");
		me->delete("hubiao");
		me->delete("no_fly");
		return 1;
	}
	else
	{
		write("查猛道：没有合适的任务。\n");
		return 1;
	}
}

int accept_object(object who, object ob)
{
	int val,gold,combatexp;
	object bag;
	val = ob->value();
	combatexp = who->query("level");
	gold = combatexp;

            if (val/10000 >= gold)
	{
		if (!who->query_temp("yajinok"))
		 {
			tell_object(who,"查猛道：你无缘无故给我东西干吗？\n");
			return 0;
		}
		else
		{
		who->delete_temp("yajinok");
		who->set("lasthbtime", (int) time());
		who->set("hubiao",npc[random(sizeof(npc))]);
		who->set("no_fly",1);
		who->apply_condition("biaojob",99);
       		tell_object(who,"查猛说道：我这里有送给『"+who->query("hubiao")+"』的包裹，麻烦您代我送过去。\n" NOR);
		bag = new("/obj/bag");
		bag->move(who);
		bag->set("long","一个送给"+who->query("hubiao")+"的包裹，弄丢了可要赔偿的。到达指定NPC后用finish <id>来完成任务。\n");
		return 1;
		}
	}
	else
	{
		tell_object(who,"查猛道：这些东西够当押金么？\n");
		return 0;
	}
}