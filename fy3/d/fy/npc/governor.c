#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();
int ask_money();
string *yz_west = ({//这里定义的可能产生地
        "/u/guanwai/octostreet",
        "/u/resort/smallroad4",
        "/u/ghost/lroad3",
        "/u/quicksand/mroad2",
        "/u/guanwai/octo7",
        "/u/resort/front_yard",
        "/u/quicksand/sandroad",
			"/u/quicksand/desert4",
			"/u/quicksand/desert5",
			"/u/quicksand/desert3",
			"/u/quicksand/desert2",
            "/u/resort/front_yard",
              "/u/resort/bookhouse",
              "/d/shaolin/tianwang",
              "/d/shaolin/qianfe",
              "/d/shaolin/cj",
   });

string *yz_south = ({//这里定义的可能产生地
        "/d/fy/sroad1",
        "/d/manglin/groupn2",
        "/d/fy/sroad2",
        "/d/wanmei/playground",
        "/d/qianjin/corror1",
        "/d/wanmei/cleft",
        "/d/wanmei/right",
             "/d/manglin/groups2",
        "/d/qianjin/secfloor",
        "/d/wanmei/backyard",
		"d/manglin/groupe2",
			"d/manglin/groupe3",
			"d/manglin/groupe4",
		 "/d/fy/pusheng",
        });

string *yz_north = ({//这里定义的可能产生地
        "/d/tieflag/road",
		"/d/shenshui/midao3",
		"/d/shenshui/midao5",
        "/d/laowu/town1",
        "/d/laowu/street",
        "/d/laowu/street3",
        "/u/taoguan/road1",
        "/u/taoguan/lake1",
        "/u/taoguan/kitchen",
        "/d/qianfo/fangsheng",
        "/d/qianfo/changlang",
        "/d/qianfo/fudi",
              "/d/shenshui/gong",
        });

string *yz_east = ({//这里定义可能产生地
        "/u/wudang/road1",
        "/d/tieflag/troad1",
        "/d/bat/shushi",
        "/d/tieflag/troad3",
		"/d/tieflag/rock0",
		"/d/tieflag/cloudinn",
        "/u/palace/intersection",
        "/u/palace/smalllake",
        "/u/palace/interroad",
        "/u/palace/keng",
        "/u/palace/garden3",
        "/u/palace/house2",
        "/u/palace/gate",
        "/u/palace/tang",
        "/u/chuenyu/dustyroad0",
        "/u/chuenyu/dustyroad2",
        "/u/chuenyu/smallyard",
       "/d/wanmei/rightcave",
 });
void create()
{
        set_name("殷正廉", ({ "master yin", "master","yin" }) );
        set("long",
                "风云城中最高的官，有至高无上的权力\n");
	set("nickname", RED"一品钦差"NOR);
	set("class","official");
        set("attitude", "heroism");
	set("student_title","官员");
	create_family("朝廷",6,"官员");
	set("vendetta_mark", "authority");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
        }) );
         set("inquiry", ([
                "job" : (:ask_job():),
                "任务" : (: ask_job() :),
                "俸禄" : (: ask_money() :),
                "失败" : (: ask_fail() :),
                   ]));
    set("combat_exp", 90000000);
	set("no_arrest",1);
	set_temp("apply/damage",500);
        set_skill("unarmed", 1000);
        set_skill("force",500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("changquan",1000);
        set_skill("jingxinforce",1000);
        set_skill("move", 500);
       set_skill("danei-sword",1000);
       set_skill("liuyun-steps",1000);
       set_skill("sword",500);
            set_skill("literate",500);
	set_skill("leadership",1000);
	set_skill("strategy",1000);
	map_skill("unarmed","changquan");	
	map_skill("dodge","liuyun-steps");
	map_skill("force","jingxinforce");
	map_skill("sword","danei-sword");

        setup();

        carry_object(__DIR__"obj/guanfu")->wear();
}

void attempt_apprentice(object me)
{
	if( me->query("class"))
	{
	command("stare");
	command("say 你已经有自己的门派了！\n");
	}
	else if( me->query("national") == "汉族" )
	{
	command("smile");
	command("say 很好！朝廷正在用人之时，努力吧！\n");
            command("recruit " + me->query("id") );
	}
	else
	command("say 朝廷只收汉族之人！\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "official");
		ob->set("vendetta_mark", "authority");

}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","朝廷七品芝麻官");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","朝廷六品官");
                return ;
        } else if ( exp <= 29 ) {
                student->set("title","朝廷五品官");
                return ;
        } else if ( exp <= 37 ) {
                student->set("title","朝廷四品官");
                return ;
        } else if ( exp <= 44 ) {
                student->set("title","朝廷三品官");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","朝廷二品官");
                return ;
        } else if ( exp <= 55 ) {
                student->set("title","朝廷一品官");
                return ;
        } else if ( exp <= 65 ) {
                student->set("title","朝廷钦差大臣");
                return ;
        } else if ( exp <= 75 ) {
                student->set("title","朝廷兵马统领");
                return ;
        } else if ( exp <= 80 ) {
                student->set("title","朝廷兵马总统领");
                return ;
        } else if ( exp <= 95 ) {
                student->set("title","镇远将军");
                return ;
        } else
                student->set("title","定国大将军");
                return ;

}

int ask_money()
{
	mapping quest ;
	int lv;
	object me,money;
	me = this_player();
	lv = me->query("level");
	if(  me->query("class") !="official" )
	{
		command("say 只有朝廷官员才可以领取俸禄。\n");
		return 1;
	}
	if( ((int) me->query("lastctmoney")+60*10080) >  time() )
	{
		write("领取俸禄的间隔时间不得少于七天。\n");
		return 1;
	}
	if(  me->query("score") <  (lv*50) )
	{
		write("看来你在江湖中的评价还够啊！\n");
		return 1;
	}
	me->add("score",- lv*10);
 	money = new("/obj/money/gold");
	money->set_amount(lv*10);
	money->move(me);
	me->set("lastctmoney",time());
	command("say 这是朝廷根据江湖对你的评价而给你的最近七天的俸禄"+chinese_number(lv*10)+"两黄金！请再继续为朝廷服务。");
	return 1;
}
int ask_job()
{

        object me = this_player(), ob;
        mapping skl; 
        string *sname, place;
        int i, skill = 0;

        skl = me->query_skills();

                if(this_player()->query("killhyr") > 6000)
                {
                        command("say 你为朝廷做的贡献已经非常完满了，去接其它更有挑战性的任务吧！");
                        return 1;       
                }
  
        if (me->query("level") < 20){
                command("say " + RANK_D->query_respect(me) + "你的本事还没有到家呢,恐怕此去路途险恶,你还不能胜任！\n");
                return 1;
        }
        if (me->query("level") > 50){
                command("say " + RANK_D->query_respect(me) + "你已经不适合做这种小任务了！\n");
                return 1;
        }


        if ( !skl ) {
                tell_object(me, "你去学一些本事先吧！\n");
                return 1;
                }

//by tiandi job NPC的SKILL为玩家的LEVEL的10倍
 /*       sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")
                        skill = skl[sname[i]];
                        
        if (skill < 50) skill = 50;
        if (skill > 100) skill = 100;
*/
 skill = me->query("level")*10;      
        if (me->query("level") > 50) {
                command("say " + RANK_D->query_respect(me) + "乃是国之栋梁，岂敢劳您大架！");
                return 1;
        }
        if (me->query("kill_qiangdao") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "能热心为朝廷服务，真是太好了。");
                me->set("kill_qiangdao", 1);
                me->set("quest/quest_type", "杀");
                me->set("quest/quest", "强盗");
                me->set("task_time", time() + 300);
                switch(random(3)) {
                case 0 :
                        ob = new("/job/npc/qiangdao");
                        ob->set("long", "他是被朝廷开除的小官，现在专靠盗窃营生，长了一脸横肉，让人望而生畏。\n"
                        "他是" + me->query("name") + "(" + me->query("id") + ")" + "的目标。\n");
                        ob->set_skill("jingyiforce", skill);
                        ob->set_skill("feixian-steps", skill);
                                             ob->set_skill("move", skill);
                       ob->set_skill("parry", skill);
			     ob->set_skill("dodge", skill);
                                              ob->set("chat_chance_combat", 10);
                                     break;

                default : 
                        ob = new("/job/npc/qiangdao");                   
                        ob->set("long", "他是天宗弟子，尖尖的下巴上挂着几屡胡须，一看就知道他是个邪魔外道之辈。\n"
                        "他是" + me->query("name") + "(" + me->query("id") + ")" + "的目标。\n");
                        ob->set_skill("jingyiforce", skill);
                        ob->set_skill("feixian-steps", skill);
                                            ob->set_skill("move", skill);
                    	    ob->set_skill("parry", skill);
                                          ob->set_skill("sword", skill);

                                     ob->set("chat_chance_combat", 10);
                         break;

                  }

                                 
                switch(random(4)) {
                        case 0 :
                                place = yz_east[random(sizeof(yz_east))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " 一个蒙面黑衣人偷了本官的手谕，\n向风云城东边的"+place->query("short")+"逃跑了,你去把他杀掉。");                           
                                break;
                        case 1 :
                                place = yz_south[random(sizeof(yz_south))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " 一个蒙面黑衣人偷了本官的官印，\n向风云城南边的"+place->query("short")+"逃跑了,你去把他杀掉。");                           
                                break;
                        case 2 :
                                place = yz_north[random(sizeof(yz_north))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " 一个蒙面黑衣人偷了本官的令牌，\n向风云城北边的"+place->query("short")+"逃跑了,你去把他杀掉。");                           
                                break;
                        default :
                                place = yz_west[random(sizeof(yz_west))];
                                ob->move(place);

                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " 一个蒙面黑衣人偷了本官的案卷，\n向风云城西边的"+place->query("short")+"逃跑了,你去把他杀掉。");                           
                }               
                ob->set_temp("owner/id",me->query("id"));
                ob->set("level", me->query("level"));
                ob->set("eff_kee", me->query("max_kee") *2);
                ob->set("max_kee", me->query("max_kee") *2);
                ob->set("kee", me->query("max_kee") *2);
                ob->set("eff_gin", me->query("max_gin") *2);
                ob->set("max_gin", me->query("max_gin") *2);
                ob->set("gin", me->query("max_gin") *2);
                ob->set("eff_sen", me->query("max_sen")*2 );
                ob->set("max_kee", me->query("max_sen") *2);
                ob->set("sen", me->query("sen") *2);
                ob->set("force", me->query("force") * 2);
                ob->set("force_factor", random(100));   
				if (me->query("heiyirenauto")-time()>0)
				{
					write("你使用的黑衣人任务丹发挥功效了.\n");
					me->move(place);
				}
                return 1;
                }
        return 1;
}
int ask_fail()
{
        object me = this_player();
        if (me->query("kill_qiangdao") == 1) {
                command("heng");
                command("say 你身手这么差,本官当初看错了人。");
                command("qst " + me->query("name") + "狂妄自大。来人啦，杖责八十，逐出堂外！");
                me->move("/d/fy/wcloud2");
                me->delete("kill_qiangdao");
				me->start_busy(5);
				return 1;
                }
        else return 0;
}

