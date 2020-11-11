inherit NPC;
#include <ansi.h>
int time_period(int timep, object me,int i);
string sysmsg;
void create()
{
	set_name(HIY "阿铁" NOR, ({ "tie", "a tie" }) );

	set("gender", "男性");
	set("age", 35);
	set("long",
		"风云中谁人不知，谁人不晓．．．阿铁有个怪癖，喜欢收集奇奇怪怪的东西．\n");
	set("attitude", "peaceful");
	set("str", 100);
	set("per", 130);
	set("int", 100);
	set("cps", 30);

	set("combat_exp", 130000000);
	set("inquiry", ([ "忠义" : "男儿志在四方，却以忠孝为先。你是否要接受忠义任务呢？（quest）" 
	  ]));

          set("title", HIC"风云始祖"NOR);
	setup();
}
void init()
{
        add_action("give_quest", "quest");
}
int accept_object(object who, object ob)
{
        object gift,gold;
        int  exp, pot, score, val, extra, reb,ti,doubletime,doubletype;
	string test,file,*name;
	mapping quest;

        if(!(quest =  who->query("tiequest")))
	{
        tell_object(who,"阿铁说道：我虽然爱好收集各种小玩意，但此时却毫无兴趣。\n");
	return 0;
	}
        if( (string)ob->query("name") != quest["quest"])
        {
        tell_object(who,"阿铁说道：这好像。。。不是我想要的东西吧。\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"阿铁说道：朋友，你这算什么意思。\n");
        return 0;
        }
        if ((int) who->query("tiequest_time") < time() )
        {
        tell_object(who,"阿铁叹道：你来晚了，我已经收集到想要的东西了！\n");
                        return 1;
        }
        else
        {
        tell_object(who,"阿铁说道：恭喜你！你又完成了一个忠义任务！\n");
    //by tiandi 08.1.30修正，删除已经交掉的自造物品
	if (ob->query("selfmaking"))
	{
	seteuid(ROOT_UID);
	rm(base_name(ob) + ".o");
	rm(base_name(ob) + ".c");
	ob->move(environment(who));
	destruct(ob);
	seteuid(getuid());
	}
		
	reb = who->query("reborned");
    exp = who->query("level");
	doubletime = who->query("doubletime");
	doubletype = (int)who->query("doubletype");
	ti = who->query_temp("tiejobtemp");
	exp = 100*exp;
	exp = exp + exp/10*ti;
	exp = exp + exp/5*reb;
	//write(exp+"/20000*"+ti);
	if (doubletime - time() > 0)
		exp = exp*(doubletype+1);
	exp = exp /2;
	pot = exp /7 *4;
	score = reb+1;  

	who->add("combat_exp",exp);
	who->add("potential",pot);
    who->add("score",score);
  	tell_object(who,HIW"你被奖励了：\n" +
	chinese_number(exp) + "点实战经验\n"+
	chinese_number(pot) + "点潜能\n"+
	chinese_number(score)+"点评价\n" NOR);
	if (ti==10)
		{
		if ( who->query("level")>89)
				gift=new("/d/wiz/fyup/obj/hongbao5");
		else if ( who->query("level")>79)
				gift=new("/d/wiz/fyup/obj/hongbao4");
		else if ( who->query("level")>69)
				gift=new("/d/wiz/fyup/obj/hongbao3");
		else if ( who->query("level")>59)
				gift=new("/d/wiz/fyup/obj/hongbao2");
		else if ( who->query("level")>49)
				gift=new("/d/wiz/fyup/obj/hongbao1");	
		else gift=new("/d/wiz/fyup/obj/hongbao");
		gift->move(who);
		score = 60 + random(40);
		score = score + score/5*reb;
		gold=new("/obj/money/gold");
	    gold->set_amount(exp/100);
	    gold->move(who);
		who->add("score",score);
		who->add("combat_exp",exp);
		who->add("potential",pot);
  		tell_object(who,HIY"你被额外奖励了：\n" +
		chinese_number(exp) + "点实战经验\n"+
		chinese_number(pot) + "点潜能\n"+
		chinese_number(exp/100) + "两黄金\n"+
		chinese_number(score)+"点评价\n" NOR);
		tell_object(who,HIY"你的包裹好像重了一点。\n"NOR);
		}
	ti ++;
	if (!ti) ti = 1;
	if (ti >10) ti = 1;
	who->set_temp("tiejobtemp", ti );
          who->add("tiejob", 1 );
	who->set("tiequest",0);
            return 1;
        }
                return 1;
}

int give_quest(string arg)
{
	mapping quest ;
	object me,room,qiangdao;
	int j, combatexp, timep,lv ;
	string file,location,*roomlines;
 	room = load_object("/d/fy/fysquare");
	me = this_player();

	if((int) me->is_ghost())
	{
		write("鬼魂不可要任务．\n");
		return 1;
	}
	if ((me->query("tiejob") - 650) > me->query("TASK"))
	{
		write("目前你的忠义任务完成次数已经达到上限。\n");
		return 1;
	}

        if((quest =  me->query("tiequest")))
	{
	if( ((int) me->query("tiequest_time")) >  time() )
		return 0;
	else
		me->delete_temp("tiejobtemp");
	}
    	quest = QUEST_D("tie3")->query_quest();
	timep = 900;   // each quest give 10 mins.
// A factor here to make time random
	timep = random(timep/2)+timep/2;
	if (!me->query_temp("tiejobtemp"))    
		me->set_temp("tiejobtemp",1);
	tell_object(me,"当前第"+me->query_temp("tiejobtemp")+"个忠义任务。\n");
	if (quest["quest_type"] == "寻")
	{
	
        tell_object(me,"阿铁说道：现在风云城里紧缺"+quest["quest"]+"，请你" NOR);
	time_period(timep, me,1);
	sysmsg +="找回『"+quest["quest"]+"』。";
	}
	if (quest["quest_type"] == "欣赏")
        {
	
        tell_object(me,"阿铁说道：身在江湖，总不能天天打打杀杀，听说『"+quest["quest"]+"』风景不错，适合云游，请你" NOR);
	time_period(timep, me,2);
	sysmsg +="欣赏『"+quest["quest"]+"』。";
        }
	if (quest["quest_type"] == "拜访")
        {
	
        tell_object(me,"阿铁说道：好久没有拜访『"+quest["quest"]+"』了，请你" NOR);
	time_period(timep, me,3);
	sysmsg +="拜访『"+quest["quest"]+"』。";
        }
	if (quest["quest_type"] == "杀")
        {
	  timep= 900 +random(60);
	  file = read_file("/quest/dynamic_location");
        roomlines = explode(file,"\n"); 
        location = roomlines[random(sizeof(roomlines))];

                if( catch(load_object(location)) || !load_object(location) )
                {
                        write("地点刷新出现问题，请留下相关报错信息留给WIZ处理，错误位置为"+location+"。\n");
                        return 1;               
                }
	qiangdao = new(__DIR__"qd");
//	write ("地点是"+location);
	qiangdao ->move(location);
	room = environment(qiangdao);
	qiangdao ->set("owner",me->query("name"));
	qiangdao->set("level",me->query("level")+10); 
	lv = qiangdao->query("level");
		 qiangdao->set("str",6*lv);
		 qiangdao->set("cor",6*lv);
		 qiangdao->set("int",6*lv);
		 qiangdao->set("spi",6*lv);
		 qiangdao->set("cps",6*lv);
		 qiangdao->set("per",6*lv);
		 qiangdao->set("con",6*lv);
		 qiangdao->set("kar",6*lv);
		 qiangdao->set("agi",6*lv);
		 qiangdao->set("dur",6*lv);
		 qiangdao->set("fle",6*lv);
		 qiangdao->set("tol",6*lv);
		 qiangdao->set("max_kee",me->query("max_kee")*2);
		 qiangdao->set("eff_kee",qiangdao->query("max_kee"));
		 qiangdao->set("kee",qiangdao->query("max_kee"));
		 qiangdao->set("max_gin",me->query("max_gin")*2);
		 qiangdao->set("eff_gin",qiangdao->query("max_gin"));
		 qiangdao->set("gin",qiangdao->query("max_gin"));
		 qiangdao->set("max_sen",me->query("max_sen")*2);
		 qiangdao->set("eff_sen",qiangdao->query("max_sen"));
		 qiangdao->set("sen",qiangdao->query("max_sen"));

	qiangdao ->set("long",qiangdao->query("long")+"据说"+me->query("name")+"正准备清剿。");
        tell_object(me,"阿铁说道：听说『"+room->query("short")+"』一带常有拦路强盗在为非作歹了，请你" NOR);
	time_period(timep, me,4);
	sysmsg +="杀了『"+room->query("short")+"』的拦路强盗。";
        }
	me->set("tiequest", quest);
	me->set("tieplace",room->query("short"));
	me->set("tiequest_time", (int) time()+(int) timep);
//	CHANNEL_D->do_channel(this_object(), "qst", sprintf("%s(%s)：%s", 
//	me->query("name"),me->query("id"),sysmsg));

return 1;
}

int time_period(int timep, object me,int i)
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
	if (i==1) 
	{
	       tell_object(me, sprintf("在" + time + "内找来给我。\n"));
	}
	if(i==2)
	{
	        tell_object(me,sprintf("在" + time + "内前去观赏一下。\n"));
	}
	if(i==3)
	{
	        tell_object(me,sprintf("在" + time + "内前去拜访一下。\n"));
	}
	if(i==4)
	{
	        tell_object(me,("在" + time + "内前去清除恶孽。\n"));
	}

	sysmsg = "在" + time + "内";
        return 1;
}
