#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();
int ask_me();
string *yz_west = ({//这里定义的可能产生地
        "/u/guanwai/octostreet",
        "/u/resort/smallroad4",
        "/u/ghost/lroad3",
        "/u/quicksand/mroad2",
        "/u/guanwai/octo7",
        "/u/resort/front_yard",
        "/u/quicksand/sandroad",
            "/u/resort/front_yard",
              "/u/resort/bookhouse",
              "/d/shaolin/tianwang",
              "/d/shaolin/qianfe",
              "/d/shaolin/cj",
              "/u/yihua/houyuan",
   });

string *yz_south = ({//这里定义的可能产生地
        "/d/fy/sroad1",
        "/d/manglin/groupn2",
        "/d/fy/sroad2",
        "/d/wanmei/playground",
        "/d/dali/sroad2",
        "/d/qianjin/corror1",
        "/d/dali/quan1",
        "/d/wanmei/cleft",
        "/d/wanmei/right",
              "/d/wudujiao/dt",
              "/d/wudujiao/mroom",
             "/d/manglin/groups2",
        "/d/qianjin/secfloor",
        "/d/wanmei/backyard",
        });

string *yz_north = ({//这里定义的可能产生地
        "/d/tieflag/road",
        "/d/laowu/town1",
        "/d/laowu/street",
        "/d/laowu/street3",
        "/u/taoguan/road1",
        "/u/taoguan/lake1",
        "/u/taoguan/kitchen",
        "/d/qianfo/fangsheng",
        "/d/qianfo/changlang",
        "/d/qianfo/fudi",
              "/d/baihuagu/mroom",
              "/d/shenshui/gong",
        });

string *yz_east = ({//这里定义可能产生地
        "/u/wudang/road1",
        "/d/tieflag/troad1",
        "/d/bat/shushi",
        "/d/tieflag/troad3",
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
        set("attitude", "heroism");
	set("student_title","官员");
	create_family("朝廷",6,"官员");
	set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
	set("agi",25);
	set("int",30);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
        }) );
         set("inquiry", ([
                "job" : (:ask_job():),
                "捕快" :  "\n任何人只要加入(join chaoting)，就可以为朝廷出力。\n",
                "work" :  "\n任何人只要加入(join chaoting)，就可以为朝廷出力。\n",
                "任务" : (: ask_job() :),
                "失败" : (: ask_fail() :),
                   ]));
    set("combat_exp", 90000000);
	set_temp("apply/damage",500);
        set_skill("unarmed", 200);
        set_skill("sword",120);
        set_skill("force",100);
        set_skill("parry", 120);
        set_skill("dodge", 110);
	set_skill("changquan",200);
        set_skill("feixian-steps",80);
        set_skill("feixian-sword",100);
        set_skill("jingyiforce",80);
        set_skill("move", 100);
        set_skill("literate",150);
	set_skill("leadership",200);
	set_skill("strategy",200);
	map_skill("unarmed","changquan");
	map_skill("dodge","feixian-steps");
	map_skill("force","jingyiforce");
	map_skill("sword","feixian-sword");
        setup();

        carry_object(__DIR__"obj/guanfu")->wear();
}

void attempt_apprentice(object me)
{
	if( !me->query("class"))
	{
	command("smile");
	command("say 很好！朝廷正在用人之时，努力吧！\n");
        command("recruit " + me->query("id") );
	}
	else
	command("say 朝廷不需要你这种不三不四，来历不明之人！\n");
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
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","朝廷七品芝麻官");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","朝廷六品官");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","朝廷五品官");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","朝廷四品官");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","朝廷三品官");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","朝廷二品官");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","朝廷一品官");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","朝廷钦差大臣");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","朝廷兵马统领");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","朝廷兵马总统领");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","镇远将军");
                return ;
        } else
                student->set("title","定国大将军");
                return ;

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
  
        if (me->query("gongxian") > 35000 && me->query("class") == "dali"){
                command("say " + RANK_D->query_respect(me) + "你已经贵为王爷，本官不敢差遣！\n");
                return 1;
        }
        if (me->query("combat_exp") < 100000){
                command("say " + RANK_D->query_respect(me) + "你的本事还没有到家呢,恐怕此去路途险恶,你还不能胜任！\n");
                return 1;
        }

        if ( !skl ) {
                tell_object(me, "你去学一些本事先吧！\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")
                        skill = skl[sname[i]];
                        
        if (skill < 50) skill = 50;
        if (skill > 100) skill = 100;
       
        if (me->query("combat_exp") > 5000000) {
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
                        ob = new("/d/xgchen/npc/qiangdao");
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
                        ob = new("/d/xgchen/npc/qiangdao");                   
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
                                command("whisper " + me->query("id") + " 一个蒙面黑衣人偷了本官的手谕，\n向风云城东边逃跑了,你去把他杀掉。");                           
                                break;
                        case 1 :
                                place = yz_south[random(sizeof(yz_south))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " 一个蒙面黑衣人偷了本官的官印，\n向风云城南边逃跑了,你去把他杀掉。");                           
                                break;
                        case 2 :
                                place = yz_north[random(sizeof(yz_north))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " 一个蒙面黑衣人偷了本官的令牌，\n向风云城北边逃跑了,你去把他杀掉。");                           
                                break;
                        default :
                                place = yz_west[random(sizeof(yz_west))];
                                ob->move(place);

                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " 一个蒙面黑衣人偷了本官的案卷，\n向风云城西边逃跑了,你去把他杀掉。");                           
                }               
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("eff_kee", me->query("max_kee") * 8);
                ob->set("max_kee", me->query("max_kee") * 8);
                ob->set("kee", me->query("max_kee") * 8);
                ob->set("eff_gin", me->query("max_gin") * 8);
                ob->set("max_gin", me->query("max_gin") * 8);
                ob->set("gin", me->query("max_gin") * 8);
                            ob->set("eff_sen", me->query("max_sen") * 8);
                ob->set("max_kee", me->query("max_sen") * 8);
                ob->set("sen", me->query("sen") * 8);
                ob->set("force", me->query("force") * 2);
                            ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                ob->set("force_factor", random(100));   
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
                me->add("kee",-300);
                call_out("delete", 1);
                return 1;
                }
        else return 0;
}

int delete()
{
        this_player()->delete("kill_qiangdao");
        return 1;
}
void init()
{       
        object ob; 
        mapping myfam; 
        ob = this_player();
        ::init();
        add_action("do_join", "join");

        if (interactive(ob = this_player()) &&                 (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="chaoting" )
        return notify_fail("你要加入什么组织？\n"); 
   if(ob->query("kaifengfu")) 
        {
        message_vision(HIC "殷正廉说道：你已经是捕快了。\n" NOR,this_player());
        return 1;
        }
   if (ob->query("combat_exp")<500000)
        {

        message_vision(HIC "殷正廉对$N摇头道：你的实战经验太低。\n" NOR,this_player());
        return 1;
        }
    ob->set("kaifengfu",1);
    ob->set("kainame",1);
    command("tell "+this_player()->query("id")+" 从现在起你就是个实习捕快了.\n");
    ob->add("score",100);
    message_vision(HIC "$N的评价提高了！\n" NOR,ob);
    tell_object(ob, "你现在的评价是" + chinese_number((string)(ob->query("score")))+"。\n"NOR);
    return 1;   
}

