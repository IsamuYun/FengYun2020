//by tiandi 升级
#include "ansi.h"
inherit F_CLEAN_UP;
int add_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar);

int main(object me)
{
	int lv,i,j;
	object gold;
	string national;
	lv = me->query("level");
	j=0;
	if(lv>99)
		return notify_fail("您的等级已经是目前的最高级别了。\n");	
	j=2000;
	for(i=0;i<lv;i++)
		j=j+j/9;
	if(me->query("combat_exp") < j)
		return notify_fail("你的经验还不够"+j+"点，不能升级。\n");
	me->add("combat_exp",-j);
	me->add("level",1);
	me->add("gift_points",5);
	national = me->query("national");
	switch(national){
		case "汉族":  //平衡
			add_attribute(me,6,6,6,6,6,6,6,6,6,6,6,6);     
			break;
	            case "苗族": //(灵力型）
 	            	add_attribute(me,9,3,6,3,9,3,6,9,3,6,6,9);
                        	break;
        	 	case "满族": //（体质型）
         	      		add_attribute(me,6,6,3,6,3,6,9,6,3,9,9,3);
                        	break;
        	 	case "蒙古族"://力量
			add_attribute(me,9,9,6,6,3,9,6,6,9,3,3,3);
                        	break;
         		case "白族": //灵巧
            		add_attribute(me,9,6,9,3,3,3,6,6,6,3,9,9);
                      		break;
         		case "藏族"://耐力
			add_attribute(me,6,9,3,9,6,6,6,3,3,9,9,3);
                       		break;
		}	
		me->add("max_lifetili",10);
		write("您的等级到了"+to_chinese(me->query("level"))+"！\n");
		if (me->query("level") == 2)
			write("风云城的张铁匠好像有事情找你。\n");
		if (me->query("level") == 3)
			write("你似乎应该去更远的地方走走了，去沉香钓鱼亭钓鱼看看，听说那里会有鱼贩子收购钓到的鱼。\n");
		if (me->query("level") == 4)
			write("听说上了年纪的老太婆找人帮忙，你去看看吧，说不定能帮上忙呢。\n");
		if (me->query("level") == 5)
			write("恭喜您到了可以学习生活技能的等级，请找角宿天君来了解相关信息。\n");
		if (me->query("level") == 6)
			write("天机老人好像遇上了点麻烦，有空去看看吧。\n");
		if (me->query("level") == 10)
	{
			write("恭喜你到达了十级，护镖任务已经可以做了，快去找风云城的查猛尝试一下吧。\n");
			gold=new("/obj/money/gold");
			gold->set_amount(lv*10);
			gold->move(me);
			write("你获得了一百两黄金的额外奖励。\n");
	}
		if (me->query("level") == 20)
	{
			write("恭喜你到达了二十级，殷正廉好像在找你。\n");
			gold=new("/obj/money/gold");
			gold->set_amount(lv*10);
			gold->move(me);
			write("你获得了两百两黄金的额外奖励。\n");
	}
		if (me->query("level") == 30)
	{
			write("恭喜你到达了三十级。\n");
			gold=new("/obj/money/gold");
			gold->set_amount(lv*10);
			gold->move(me);
			write("你获得了三百两黄金的额外奖励。\n");
	}
		if (me->query("level") == 35)
			write("恭喜你到达了三十五级，按你现在的能力应该可以去尝试捉拿十大恶人了。\n");
		if (me->query("level") == 45)
			write("恭喜你到达了四十五级，按你现在的能力应该可以抓奸细了。\n");	
		if (me->query("level") == 50)
			write("恭喜你到达了五十级，武林盟主正在找你。\n");
		return 1;	
}

int add_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar)
{
user->add("tol",tol);
user->add("fle",fle);
user->add("agi",agi);
user->add("dur",dur);
user->add("int",intt);
user->add("str",str);
user->add("con",con);
user->add("spi",spi);
user->add("per",per);
user->add("cor",cor);
user->add("cps",cps);
user->add("kar",kar);
return 1;
}

int help()
{
        write(@TEXT
指令格式：upgrade

当人物的当前经验超过升级经验时，可以使用upgrade来提高人物
级别，级别越高，各项属性也越高。每次升级都会有5点属性点
可以自由分配。
TEXT
        );
        return 1;
}


