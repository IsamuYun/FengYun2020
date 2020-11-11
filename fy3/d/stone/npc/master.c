// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("叶孤城", ({ "master ye", "master", "master gucheng" }) );
        set("nickname", HIW "白云城主"NOR);
        set("gender", "男性" );
set("reward_npc", 1);
	set("class","baiyun");
    set("difficulty", 230); 
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 100);
	set("max_kee",99999999);
        set("max_gin",999999);
        set("max_sen",999999);
	set("eff_kee",999999);
	set("kee",999999);
	set("tianwaifeixian",10);
	set("inquiry", (["寻宝" : "听说有一群盗墓者从皇陵中拿到了不少金银珠宝，官府派老夫来协助调查此事，有兴趣之士可以参加。(job)",   
		"寻宝失败" : "放弃任务请用。(jobfail)",  
						]));

        set("chat_chance", 1);
        set("chat_msg", ({
                "叶孤城从点点血斑的白袍撕下一条布条。\n叶孤城用从点点血斑的白袍撕下的布条替自己裹伤。\n",
        }) );

        set("long",
"
白云城主以前充满了尊荣和光采．而现在．．．
他知道那被唐门暗器所伤的伤口已完全溃烂．．．
\n"
	);
        create_family("白云城", 2, "城主");

        set("combat_exp", 100000000);
        set("score", 200000);
       set("no_arrest",1);
        set_skill("move", 500);
	set_skill("daode",1000);
        set_skill("parry", 1000);
        set_skill("dodge", 500);
        set_skill("force", 500);
        set_skill("literate", 800);
	set_skill("sword", 1000);
	set_skill("feixian-steps",1000);
	set_skill("feixian-sword",1000);
        set_skill("jingyiforce",1000);
        set_skill("feixianforce",1000);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");


        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/bsword")->wield();
	carry_object(__DIR__"obj/bcloth")->wear();

}
void init()
{
	add_action("do_quest", "job");
	add_action("do_questfail", "jobfail");
}


void attempt_apprentice(object me)
{
	if( me->query("class")&&me->query("class") != "baiyun")
	{
	command("stare");
	command("say 你已经有自己的门派了！\n");
	}
	else if( me->query("national") == "汉族" )
	{
	command("smile");
	command("say 很好！我白云城就靠你来发扬光大了！\n");
            command("recruit " + me->query("id") );
	}
	else
	command("say 白云城只收汉族之人！\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "baiyun");
}
 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","白云城弟子");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","白云城领班");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","白云城小管家");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","白云城管家");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","白云城大管家");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","白云城总管");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","白云城大总管");
                return ;
        } else
                student->set("title","白云城副城主");
                return ;

}
int do_questfail()
{
	if (this_player()->query("score")<100)
		return notify_fail("你想半途而废？赶紧去完成任务！\n");
	this_player()->add("score",-100);
	command("say 好吧，扣除你一百点评价作为惩罚。");
	this_player()->delete("inyequest");
	return 1;
}


int do_quest()
{
	object me,ob;
	string place,placename;
	int lv,i;
	me = this_player();
	lv = me->query("level");
	if (lv < 71)
		return notify_fail("你的等级还不满七十一级。\n");
	if (me->query("inyequest"))
		return notify_fail("你已经接了任务，赶快去做啊，墨迹个啥呀。\n");

	ob = new("/d/wiz/fyup/npc/daomu");
	i = random(100);
	if (i < 10)
	{
		place = "/d/xj/zhenlong";
		placename = "葬在了新疆的镇龙塔";
		me->set_temp("daomu",1);
	}
	else if (i < 20)
	{
		place = "/d/bat/ren3";
		placename = "葬在了蝙蝠岛上的孤峰绝顶";
		me->set_temp("daomu",2);
	}
	else if (i < 30)
	{
		place = "/d/taishan/nantian";
		placename = "葬在了泰山上的南天门";
		me->set_temp("daomu",3);
	}
	else if (i < 40)
	{
		place = "/u/guanwai/inn";
		placename = "葬在了关外的迎梅客栈";
		me->set_temp("daomu",4);
	}
	else if (i < 50)
	{
		place = "/u/wudang/zhixiao";
		placename = "葬在了武当的紫霄宫";
		me->set_temp("daomu",5);
	}
	else if (i < 60)
	{
		place = "/u/resort/back_yard";
		placename = "葬在了铁雪的山庄后院";
		me->set_temp("daomu",6);
	}
	else if (i < 70)
	{
		place = "/u/palace/dating";
		placename = "葬在了帝王谷的大厅";
		me->set_temp("daomu",7);
	}
	else if (i < 80)
	{
		place = "/d/tieflag/rock0";
		placename = "葬在了长春岛的礁石";
		me->set_temp("daomu",8);
	}
	else if (i < 90)
	{
		place = "/d/shenshui/ruanhong";
		placename = "葬在了神水宫的软红山庄";
		me->set_temp("daomu",9);
	}
		else 
	{
		place = "/d/qingping/garden";
		placename = "葬在了清平山庄的后花园";
		me->set_temp("daomu",10);
	}

	ob->set("owner",me->query("name"));
	command("say 从朝廷发来的消息，听说某一帝王的坟墓就"+placename+"附近，而最近在这一带发现了大量的盗墓者，官府怀疑这匹盗墓者已经得手了。");
	command("say 你速速前去将盗墓者得手的宝物夺回！");
	ob->move(place);
	ob->set("owner",me->query("id"));
	ob->set("name",me->query("name")+"负责擒拿的盗墓者");
	me->set("inyequest",1);
	me->apply_condition("daomujob", 99);
	
	return 1;
}
int accept_object(object who, object ob)
{
        object gift,gold;
        int  exp, pot, score, val,lv, extra, reb,ti,doubletime,doubletype;
	string test,file,*name;
	mapping quest;

	if(ob->query("name") == "七彩丝缎带" && ob->query("realsilk"))
{
	command("say 我身受重伤，还是你画妆成我去吧！\n");
	command("say 但你武功低微．．．．\n");
	command("say 兴国禅寺的主持是我的好友，也许他可帮上你．\n");
	who->set_temp("marks/ye",1);
	return 1;
}
        if(!(quest =  who->query("inyequest")))
	{
        tell_object(who,"叶孤城说道：我有交给你过任务么？\n");
	return 0;
	}
        if( (string)ob->query("id") != "money box")
        {
        tell_object(who,"叶孤城说道：这好像不是什么财宝吧。\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"叶孤城说道：朋友，你这算什么意思。\n");
        return 0;
        }
        else
        {
        tell_object(who,"叶孤城说道：好好好！果然替我拿回了帝王的财宝，这下看朝廷的人还拿什么和我叶某人攀比！\n");
	lv = who->query("level");
	reb = who->query("reborned");
    exp = who->query("level");
	doubletime = who->query("doubletime");
	doubletype = (int)who->query("doubletype");
	ti = who->query_temp("yejobtemp");
	exp = 100*exp;
	exp = exp + exp/10*ti;
	exp = exp + exp/5*reb;
	//write(exp+"/20000*"+ti);
	if (doubletime - time() > 0)
		exp = exp*(doubletype+1);
	pot = exp /7;
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
	    gold->set_amount(lv);
	    gold->move(who);
		who->add("score",score);
		who->add("combat_exp",exp);
		who->add("potential",pot);
  		tell_object(who,HIY"你被额外奖励了：\n" +
		chinese_number(exp) + "点实战经验\n"+
		chinese_number(pot) + "点潜能\n"+
		chinese_number(lv) + "两黄金\n"+
		chinese_number(score)+"点评价\n" NOR);
		tell_object(who,HIY"由于你完成一轮夺宝任务，叶孤城特赏你一只阿铁给他的忠义盒。\n"NOR);
		}
	ti ++;
	if (!ti) ti = 1;
	if (ti >10) ti = 1;
	who->set_temp("yejobtemp", ti );
          who->add("yejob", 1 );
	who->set("inyequest",0);
            return 1;
        }
                return 1;
}
