// qiangdao  by tiandi

#include <ansi.h>

inherit NPC;
void create()
{

    set_name("��·ǿ��", ({ "qiang dao" }) );
    set("long", "һ��ר����·��ٲ����ǿ����\n");
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
                "�����ͷ��������㷨�Ӹ�����ӻ�����\n",
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
                message_vision(HIC "��·ǿ���Ҳ�����ʳ�ķ���һ���̵����ˡ�\n" NOR,this_object());
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
    			    tell_object(me,"�������ʱ���Ѿ����ˣ�\n");
    			    }
  		      else
   			     {
  			      tell_object(me,"\n��ϲ�㣡���������һ����������\n");
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
  			tell_object(me,HIW"�㱻�����ˣ�\n" +
			chinese_number(exp) + "��ʵս����\n"+
			chinese_number(pot) + "��Ǳ��\n"+
			chinese_number(score)+"������\n" NOR);
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
  				tell_object(me,HIY"�㱻���⽱���ˣ�\n" +
				chinese_number(score)+"������\n" NOR);
				tell_object(me,HIY"��İ�����������һ�㡣\n"NOR);
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
   	 tell_object(me,"\n����ô��ɱ�˰���\n");
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
  			tell_object(me,HIW"�㱻�ͷ��ˣ�\n" +
			chinese_number(exp) + "��ʵս����\n"+
			chinese_number(pot) + "��Ǳ��\n"+
			chinese_number(score)+"������\n" NOR);
			me->set_temp("tiejobtemp", 0 );
         			me->set("tiequest",0);
			me->delete("tieplace");

       	  }

    ::die();
}