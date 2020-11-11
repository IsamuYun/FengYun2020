// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "wanghu" }) );
        set("gender", "����" );
        set("age", 22);
        set("long","һ�����θߴ�ĺ���\n");
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
                        say( "����˵������λ" + RANK_D->query_respect(ob)
                                + "����������ѵ������ļ��ܣ��㸶���ӣ�\n");
                        break;
                case 1:
                        say( "����Ц������λ" + RANK_D->query_respect(ob)
                                + "�����ģ���һ�����ǿ�ģ�\n");

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
        return notify_fail("����һ��������û����ɡ�\n");
	if(!arg || sscanf(arg,"%s %s",arg,skill) != 2)
        return notify_fail("������������Ҫ��ʲôѽ��(train <petid> <petskill>)��\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("������������Ҫʲôѽ����\n");
	if(pet->query("possessed") != me )
	return notify_fail("�����������Ǻ�������İɣ���\n");
		 if(!myskill = pet->query_skill(skill,1))
	return notify_fail("�������ĳ������û�����أ�\n");

//okey we identified the target, now the cost:
//by tiandi����learnΪֱ������
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
              	  printf("���Ǳ�ܲ���%d�㣬�޷��̻���\n",pot);
				  return 1;
	}
	if(me->query("score")< 1)
	{
              	  printf("������۲���һ�㣬�޷��̻���\n",pot);
				  return 1;
	}
		//by tiandi ����ѧϰ�ļ������޲���������ȼ�*10
	if(myskill >=	(int)pet->query("level")*10 ) 
			{
			printf("�������%s�ȼ�̫�ͣ��޷������ô����ļ��ܡ�\n", pet->query("name"));
			return 1;
			}
		 if(random(100) > pet->query("obedience") )
	{
				 pet->command("emote �ܲ���Ը�غ���һ����");
				 return 1;
	}
		balance = me->query("deposit");
		if (balance >10*(myskill+1)*100 )
		{
			me->add("deposit",- 10*(myskill+1)*100);
			printf("ϵͳֱ�Ӵ������п۳������Ǯ�\n"); 
			learn_flag = 1;
		}
			else
	{
            gold = present("silver_money", me);
            if(!gold) {
				printf("�����еĴ����ˣ�����Ҳû�����ӡ�\n"); 
				return 1;
			}
            if((int) gold->query_amount() < (10*(myskill+1)))
			{
				printf("�����еĴ����ˣ�����Ҳû��%s�����ӡ�\n",chinese_number(20*(myskill+1)));
				return 1;
			}
	}

	 		 printf("�㽻��%s��������Ϊѧ�ѡ�\n",chinese_number(10*(myskill+1)));
			 message_vision(sprintf("$N�����䷳�ؽ�$n��%s����\n",to_chinese(skill)),this_object(),pet);
			  pet->set_skill(skill,myskill+1);
			  if (!learn_flag)
					gold->add_amount(-10*(myskill+1));
			message_vision(sprintf("$N�ƺ����ѧ����һЩ��%s����\n",to_chinese(skill)),pet);
			pet->save();
		  return 1;
}
