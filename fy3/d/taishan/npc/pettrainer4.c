// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("王虎", ({ "wanghu" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long","一个身形高大的汉子\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("chat_chance", 15);
        set("chat_msg", ({
   //             (: random_move :)
        }) );
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "train");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "王虎说道：这位" + RANK_D->query_respect(ob)
                                + "，我能替你训练宠物的技能，你付金子？\n");
                        break;
                case 1:
                        say( "王虎笑道：这位" + RANK_D->query_respect(ob)
                                + "，放心！它一定会很强的！\n");

                        break;
        }
}

int do_train(string arg)
{
	object me,pet,gold;
	int cost,pot,amount,myskill,balance,learn_flag;
	string skill;
        me = this_player();
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
	if(!arg || sscanf(arg,"%s %s",arg,skill) != 2)
        return notify_fail("王虎道：＂你要教什么呀？(train <petid> <petskill>)＂\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("王虎道：＂你要什么呀？＂\n");
	if(pet->query("possessed") != me )
	return notify_fail("王虎道：＂那好象不是你的吧？＂\n");
		 if(!myskill = pet->query_skill(skill,1))
	return notify_fail("这项技能你的宠物好象还没领悟呢！\n");

//okey we identified the target, now the cost:
//by tiandi调整learn为直接升级
	amount = myskill* 20;
	if( amount < 2) 
		amount = 2;
//	printf("%d\n",amount);
	pot = amount;
//	printf("%d\n",pot);
	if(pot < 0) pot =0;
	pot +=1;
            if( (int)me->query("potential") - (int)me->query("learned_points") < pot )
	{
              	  printf("你的潜能不够%d点，无法教会宠物。\n",pot);
				  return 1;
	}
	if(me->query("score")< 1)
	{
              	  printf("你的评价不够一点，无法教会宠物。\n",pot);
				  return 1;
	}
		//by tiandi 调整学习的技能上限不超过本身等级*10
	if(myskill >=	(int)pet->query("level")*10 ) 
			{
			printf("由于你的%s等级太低，无法领会这么高深的技能。\n", pet->query("name"));
			return 1;
			}
		 if(random(100) > pet->query("obedience") )
	{
				 pet->command("emote 很不情愿地哼了一声。");
				 return 1;
	}
		balance = me->query("deposit");
		if (balance >10*(myskill+1)*100 )
		{
			me->add("deposit",- 10*(myskill+1)*100);
			printf("系统直接从银行中扣除了相关钱款。\n"); 
			learn_flag = 1;
		}
			else
	{
            gold = present("silver_money", me);
            if(!gold) {
				printf("你银行的存款不够了，身上也没有银子。\n"); 
				return 1;
			}
            if((int) gold->query_amount() < (10*(myskill+1)))
			{
				printf("你银行的存款不够了，身上也没有%s两银子。\n",chinese_number(20*(myskill+1)));
				return 1;
			}
	}

	 		 printf("你交了%s两银子作为学费。\n",chinese_number(10*(myskill+1)));
			 message_vision(sprintf("$N不厌其烦地教$n「%s」。\n",to_chinese(skill)),this_object(),pet);
			  pet->set_skill(skill,myskill+1);
			  if (!learn_flag)
					gold->add_amount(-10*(myskill+1));
			message_vision(sprintf("$N似乎真的学会了一些「%s」！\n",to_chinese(skill)),pet);
			pet->save();
		  return 1;
}
