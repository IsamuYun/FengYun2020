//modified for news by ATU 2000/01/10
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int time_period(int timep, object me);
int say_news();
string sysmsg;
static int flag;
void create()
{
        set_name(HIY "天机老人" NOR, ({ "tianji", "Tian ji", "Tian" }) );

        set("gender", "男性");
        set("age", 99);
        set("long",
                "天机老人年过六甲，鹤发童颜。在兵器谱上排名第一，
尤在上官，小李之上．此人亦正亦邪，凡事都由爱恶而定。天机老人收徒极挑剔．．．．\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 26000);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 4);
        set("chat_msg", ({
              "天机老人拿起旱烟抽了几口．．．．\n",
		(: say_news :),

        }) );
	 
        set("force", 40000);
        set("max_force", 80000);
        set("force_factor", 1000);

        set("combat_exp", 10000000);
        set("score", 200000);

        set_skill("unarmed", 120);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_skill("yiqiforce", 30);
        set_skill("dagger",200);
        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);
        map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");

        create_family("潇遥派", 1, "祖师");
        set("title", HIC "闲云野鹤" NOR);
        setup();

//      carry_object(__DIR__"obj/jade-ring")->wear();
//      carry_object(__DIR__"obj/jade-pin")->wear();
//      carry_object(__DIR__"obj/jade-boots")->wear();
//      carry_object(__DIR__"obj/jade-cloth")->wear();
//      carry_object(__DIR__"obj/hanyan")->wield();
}
int accept_fight(object me)
{
        command("say 生命可贵！不要自寻死路！");
        return 0;
}
void init()
{
        add_action("give_quest", "quest");
}

int accept_object(object who, object ob)
{
        object silk;
        int  exp, pot, score, val;
        string test;
        mapping quest;
        val = ob->value();
        if(ob->query("id") == "goodpin")
        {
command("say 这位" + RANK_D->query_respect(who)+ "，真没想到你能把我的发簪修的这样好,这是给你的奖励！\n");
silk = new("/questnew/obj/hongbao");
silk->move(this_object());
command("give full-hongbao to " + who->query("id"));
add("given",1);
        return 1;
        }
        
if (val && val >10000 && val < 20000)
        {
                       who->set("quest", 0 );
                tell_object(who,"天机老人说道：好吧，这个任务就算了吧．．\n");
                who->delete_temp("quest_number");
                return 1;
        }
        if(!(quest =  who->query("quest")))
        {
        tell_object(who,"天机老人说道：这不是我想要的。\n");
        return 0;
        }
        if( (string)ob->query("name") != quest["quest"])
        {
        tell_object(who,"天机老人说道：这不是我想要的。\n");
        return 0;
        }
        if( ob->is_character())
        {
        tell_object(who,"天机老人说道：这不是我想要的。\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"天机老人说道：真可惜！你没有在指定的时间内完成！\n");
                        return 1;
        }
        else
        {
        tell_object(who,"天机老人说道：恭喜你！你又完成了一项任务！\n");
        exp = quest["exp_bonus"] + random(quest["exp_bonus"])+1;
// put a cap
        if(exp > 1500) exp = 1500;
        exp = exp * (int) who->query_temp("quest_number");
        pot = exp / 5 + 1;
//      due to weekly quest, each quet worth 20
//      score = quest["score"]/2 + random(quest["score"]/2);
     score = pot /5;
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"+
        chinese_number(score) + "点综合评价。\n" NOR);
        who->set("quest", 0 );
                        return 1;
        }
                return 1;
}
void attempt_apprentice(object me)
{
        switch(random(4)) {
                case 0:
message_vision("$N对$n笑问道：什么是心剑？\n", this_object(),me);
                        break;
                case 1:
message_vision("$N对$n笑问道：什么是＂敌不动，我不动；敌一动，我先动？＂\n", this_object(),me); 
                        break;
                case 2:
message_vision("$N对$n笑问道：＂有形，无形＂是什么？\n", this_object(),me);             
                        break;
                case 3:
message_vision("$N对$n笑问道：武学的最高境界是什么？\n", this_object(),me);
                        break;
        }
                        return;

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xianren");
}

int give_quest(string arg)
{
        mapping quest ;
        object me;
        int j, combatexp, timep, lvl=0;
        mixed *local;
        int  t;
        string tag = "40000000";
 string *levels = ({
                        "0",
                        "4000",
                        "8000",
                        "16000",
                        "32000",
                        "64000",
                        "128000",
                        "256000",
                        "512000",
                        "1024000",
                        "1536000",
                        "2304000",
                        "3456000",
                        "5184000",
                        "7776000",
                        "11664000",
                        "17496000",
                        "26244000",
                        "40000000"
        });
        if( ! arg || !sscanf(arg, "%d", lvl))
        lvl = 0;
        if(lvl<0) lvl=0;
        me = this_player();
// Let's see if this player is a ghost
        if((int)me->query("combat_exp") >= 8000000)
        {
                write("天机老人已经不会给你任何任务了！\n");
                return 1;
        }
        if((int) me->is_ghost())
        {
                write("鬼魂不可要任务．\n");
                return 1;
        }

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
        if( ((int) me->query("task_time")) >  time() )
                return 0;
        else
                me->set("kee", me->query("kee")/2+1);
                me->delete_temp("quest_number");
        }
        combatexp = (int) me->query("combat_exp");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                                tag = levels[j];
                                if(j < (sizeof(levels)- lvl)) tag = levels[j+lvl];
                                break;
                        }
        }
        if(!random(40) ) tag = "_new";
        if(!random(10) ) tag = "_common";
        quest = QUEST_D(tag)->query_quest();
//      to use less mem...
//      timep = quest["time"];  
        timep = 600;   // each quest give 10 mins.
// A factor here to make time random
        timep = random(timep/2)+timep/2;
        time_period(timep, me);
        if (quest["quest_type"] == "寻")
        {
        tell_object(me,"找回『"+quest["quest"]+"』给天机老人。\n" NOR);
        sysmsg +="找回『"+quest["quest"]+"』。";
        }
                if (quest["quest_type"] == "杀")
        {
        tell_object(me,"替天机老人杀了『"+quest["quest"]+"』。\n" NOR);
        sysmsg +="杀了『"+quest["quest"]+"』。";
        }
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) timep);
        if((int)me->query_temp("quest_number") < 5)
        me->add_temp("quest_number",1);
        CHANNEL_D->do_channel(this_object(), "qst", sprintf("%s(%s)：%s", 
        me->query("name"),me->query("id"),sysmsg));

return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：\n请在" + time + "内");
        sysmsg = "在" + time + "内";
        return 1;
}
int say_news()
{
	string news,str;
	flag-=1;
	this_object()->set("channels", ({ "news"}) );

	if (flag<1){
		str=read_file("/log/news");
		flag=sizeof(explode(str,"\n"));
	}	
	news = read_file("/log/news",flag,1);
       CHANNEL_D->do_channel(this_object(), "news", sprintf("%s",news)); 
//	message("system",HIY"【乱世新闻】"+news+"\n"NOR, users()); 
	return 1;
}
