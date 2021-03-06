// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "说道：您太客气了，这怎麽敢当？\n",
        "像是受宠若惊一样，说道：请教？这怎麽敢当？\n",
        "笑著说道：您见笑了，我这点雕虫小技怎够资格「指点」您什麽？\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)

{
        string skill, teacher, master;
        object ob, *list, marry_card,gold;
        int master_skill, my_skill, gin_cost;
        string target, cardname;
        int i,marry_flag,balance,learn_flag;
		int amount=0, pot;

        if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
                return notify_fail("指令格式：learn <技能> from <某人>\n");

        if( me->is_fighting() )
                return notify_fail("临阵磨枪？来不及啦。\n");

        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("你要向谁求教？\n");

        if( !living(ob) )
                return notify_fail("嗯....你得先把" + ob->name() +
"弄醒再说。\n");
	
       if( !me->is_apprentice_of(ob) )
		if( !(ob->recognize_apprentice(me)) )
    		 	return notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
// until here we deicde that me can learn from ob!



       if (ob->query("env/no_teachskill") && strsrch(ob->query("env/no_teachskill"), skill+">") >= 0)
                return notify_fail(ob->name() + "不愿意教你这项技能。\n");
//        if( master_skill+">" = strsrch(ob->query("env/no_teachskill" )))
//       return notify_fail("但是" + ob->name() + "不想授予你这种武学。\n")
        if( !master_skill = ob->query_skill(skill,1) )
				return notify_fail("这项技能你恐怕必须找别人学了。\n");
        if( !master_skill = ob->query_skill_eff_lvl(skill) )
                return notify_fail("这项技能你恐怕必须找别人学了。\n");

        if( ob->prevent_learn(me, skill) )
                return notify_fail(ob->name() + "不愿意教你这项技能。\n");
        my_skill = me->query_skill_eff_lvl(skill);
        if( my_skill >= master_skill )
                return notify_fail("这项技能你的程度已经不输你师父了。\n");
		if( me->query_skill(skill,1) >= 1000 )
                return notify_fail("这项技能你已经不能再学了。\n");

   //     notify_fail("依你目前的能力，没有办法学习这种技能。\n");

//by tiandi去除精力消耗

        if( !SKILL_D(skill)->valid_learn(me) )  return 0;
//	casue problem under query-skill-eff-lvl
        if( (int)me->query_skill(skill,1) == 0 ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }
     	tell_object(me,"你向"+ob->name()+"请教有关「"+to_chinese(skill)+"」的疑问。\n");
        if( ob->query("env/no_teach") )
                return notify_fail("但是" + ob->name() +"现在并不准备回答你的问题。\n");
        tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n", me->name(), to_chinese(skill)));


//by tiandi调整learn为直接升级
	my_skill = me->query_skill(skill,1);

	amount = my_skill   * 10;
	if( amount < 2) 
		amount = 2;
//	printf("%d\n",amount);
	pot = amount;
//	printf("%d\n",pot);
	if(pot < 0) pot =0;
	pot +=1;
            if( (int)me->query("potential") - (int)me->query("learned_points") < pot )
	{
              	  printf("你的潜能不够%d点，此技能无法升级。\n",pot);
				  return 1;
	}
	//by tiandi 调整学习的技能上限不超过本身等级*10
	if(my_skill  >=	(int)me->query("level")*10 ) 
			{
			printf("由于你的等级太低，你对%s的回答总是无法领会。\n", ob->name() );
			return 1;
			}
		balance = me->query("deposit");
		if (balance > (my_skill + 1) * 100)
		{
			me->add("deposit", -(my_skill + 1) * 100);
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
            if((int) gold->query_amount() < (my_skill + 1))
			{
				printf("你银行的存款不够了，身上也没有%s两银子。\n", chinese_number(my_skill + 1));
				return 1;
			}
	}

	 		 printf("你交了%s两银子作为学费，听了%s的指导，%s上升到了%d级。\n",chinese_number(my_skill + 1),ob->name(),to_chinese(skill), my_skill + 1);
                me->add("learned_points", pot);
			  me->set_skill(skill, my_skill + 1);
			  if (!learn_flag)
					gold->add_amount(-(my_skill + 1));
		  return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : learn <技能> from <某人>

这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教的对象在这
项技能上的造诣必须比你高，而你经由这种方式学习得来的技能也不可能高於你所请
教的人，然而因为这种学习方式相当於一种「经验的传承」，因此学习可以说是熟悉
一种新技能最快的方法。

通常，一个人刚学到一种新技能是不会有什麽疑难问题的，而是经由实际上的应用中
遭遇问题，这些问题对於学习一种新技能的过程是很重要的，尤其是各种作为其他技
能基础的基本技能，更需要经由「发现问题—解决问题」的过程才能得到较好的效果
因此我们将这种发现问题的过程用「潜能」的观念表示，一个人能够自己发现某些问
题，表示他(她)有解决这项问题的潜能，当你具有这样的潜能时就可以利用这个指令
来向其他人请教，而获得进步。
(PS. 潜能还有其他更广义的定义，这里只是其中之一 )

此外学习也需要消耗一些金钱，金钱的消耗和你学习的技能等级有关。

至於如何知道你能从对方学到什麽技能，如果对方是你的师父，可以用 skills 指令
直接查看，如果不是你的师父，那麽通常会有其他的提示，你只好自己想办法。

其他相关指令 : practice、study
HELP
        );
        return 1;
}

