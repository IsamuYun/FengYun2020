// qiangdao  by tiandi

#include <ansi.h>

inherit NPC;
void create()
{

    set_name("拦路强盗", ({ "qiang dao" }) );
    set("long", "一个专门拦路打劫财物的强盗。\n");
    set("str", 60);
    set("cor", 160);
    set("cps", 30);
    set("spi", 30);
    set("dur", 30);
    set("tol", 30);
	
    set("per", 30);
    set("fle", 30);
    set("agi", 130);
    set("kar", 30);
    set("int", 30);
    set("con", 30);
 set("no_arrest",1);

    set("combat_exp", 1000000);
    set_skill("sword", 60);
    set_skill("parry", 60);
    set_skill("dodge", 60);
    set_skill("move", 60);
    set_skill("magic", 60);
    set_skill("feixian-sword", 60);
    set_skill("feixian-steps", 60);

    set_skill("force", 60);

    map_skill("sword","feixian-sword");
    map_skill("dodge","feixian-steps");

    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "dodge.tianwaifeixian" :),
      }) );
    set("chat_chance", 50);
    set("chat_msg", ({
                "最近手头紧，得想点法子搞点银子花花。\n",
	                (: random_move :),
        }) );

    setup();

    carry_object("/obj/weapon/sword")->wield();
}
void init()
{
        call_out("leave",900);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "拦路强盗找不到觅食的方向，一溜烟地闪了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
}

void die()
{
       
	int exp,pot,score,reb,ti,doubletime,doubletype,lv;
	object me ,ob,gift,gold,owner;
	mapping quest;
	me = this_object()->query_temp("last_damage_from");
	ob = this_object();
	if(owner = me->query("possessed"))  
		me = owner;

	if(me->query("name") == ob->query("owner"))
		{
	   	     if ((int) me->query("tiequest_time") < time() )
      			  {
    			    tell_object(me,"你的任务时间已经过了！\n");
    			    }
  		      else
   			     {
  			      tell_object(me,"\n恭喜你！你又完成了一个忠义任务！\n");
       			   reb = me->query("reborned");
					 exp = me->query("level");
					doubletime = me->query("doubletime");
					doubletype = (int)me->query("doubletype");
					ti = me->query_temp("tiejobtemp");
					exp = 100*exp;
					exp = exp + exp/10*ti;
					exp = exp + exp/5*reb;
					//write(exp+"/20000*"+ti);
			if (doubletime - time() > 0)
				exp = exp*(doubletype+1);
			exp = exp / 2;
			pot = exp / 7 * 4;
			score = reb+1;  
			me->add("combat_exp",exp);
			me->add("potential",pot);
        	me->add("score",score);
  			tell_object(me,HIW"你被奖励了：\n" +
			chinese_number(exp) + "点实战经验\n"+
			chinese_number(pot) + "点潜能\n"+
			chinese_number(score)+"点评价\n" NOR);
			if (ti==10)
				{
				if ( me->query("level")>89)
					gift=new("/d/wiz/fyup/obj/hongbao5");
				else if ( me->query("level")>79)
					gift=new("/d/wiz/fyup/obj/hongbao4");
				else if ( me->query("level")>69)
					gift=new("/d/wiz/fyup/obj/hongbao3");
				else if ( me->query("level")>59)
					gift=new("/d/wiz/fyup/obj/hongbao2");
				else if ( me->query("level")>49)
					gift=new("/d/wiz/fyup/obj/hongbao1");	
				else gift=new("/d/wiz/fyup/obj/hongbao");
				gift->move(me);
				score = 60 + random(40);
				score = score + score/5*reb;
				gold=new("/obj/money/gold");
			    gold->set_amount(exp/100);
				gold->move(me);
				me->add("score",score);
  				tell_object(me,HIY"你被额外奖励了：\n" +
				chinese_number(score)+"点评价\n" NOR);
				tell_object(me,HIY"你的包裹好像重了一点。\n"NOR);
				}
			ti ++;

			if (!ti) ti = 1;
			if (ti >10) ti = 1;
			me->set_temp("tiejobtemp", ti );
			me->delete("tieplace");
         			me->add("tiejob", 1 );
			me->set("tiequest",0);
       			 }
	}
	else
	{
   	 tell_object(me,"\n你怎么乱杀人啊？\n");
       			   reb = me->query("reborned");
       			   exp = me->query("level");
					doubletime = me->query("doubletime");
					doubletype = (int)me->query("doubletype");
					ti = me->query_temp("tiejobtemp");
					exp = 100*exp;
					exp = exp + exp/10*ti;
					exp = exp + exp/5*reb;
					//write(exp+"/20000*"+ti);
			if (doubletime - time() > 0)
				exp = exp*(doubletype+1);
			pot = exp / 7;
			score = 10*lv;
			me->add("combat_exp",-exp);
			me->add("potential",-pot);
			if (me->query("potential")<0)
				me->set("potential",0);
        			  me->add("score",-score);
  			tell_object(me,HIW"你被惩罚了：\n" +
			chinese_number(exp) + "点实战经验\n"+
			chinese_number(pot) + "点潜能\n"+
			chinese_number(score)+"点评价\n" NOR);
			me->set_temp("tiejobtemp", 0 );
         			me->set("tiequest",0);
			me->delete("tieplace");

       	  }

    ::die();
}
