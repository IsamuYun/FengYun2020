#include <ansi.h>
inherit F_DBASE;
void vote(object ob,object me);
int vote_list(object ob1,object ob2);
void send_gift(object ob,int rank);
void start_vote();
void gift_who(object who,int rank);
private void count_time(int min);
void count_vote();

void create()
{
	seteuid(ROOT_UID);
	message("system", HIY"【天神频道】"HIW"\n\n各位玩家，新年又到了，在本年度里，涌现出了无数的好人好事，
因此，我们现在特恳请各位朋友为自己所知道的乐于帮助玩家的人
投上一票，风云巫师组将代表【郑州风云】全体成员表彰一位最受
大家感激的最受欢迎的玩家，并给他（她）一些奖励！好了，投票
活动正式开始！请大家使用

    ynvote <id>指令

为你最感谢的一名玩家投下宝贵的一票！\n\n"NOR, users());
	start_vote(); // 开始投票！
}

void start_vote()
{
	message("system",HIY"【天神频道】"HIW"各位玩家，别急，您有现实10分钟时间供您决定投谁的票。\n" NOR,users());
	set_temp("voting",1); // 现在正在投票
        call_out("count_time",500,1); // "10"是指整个投票时间10分钟，可以自己修改
}

private void count_time(int min)
{
	min--;
	if( min ) {
                message("system",HIY"【天神频道】"HIW"各位玩家，别急，您还有现实" + chinese_number(min) +"分钟的时间，想好了再投！\n"NOR,users() );
		call_out("count_time", 10, min); // 告诉大家还有几分钟时间
	} else {
                message("system",HIY"【天神频道】"HIW"各位玩家，本次辞旧迎新新年投票活动已经圆满结束！\n\t现在工作人员正在紧张计票中！\n"NOR,users() );
		call_out("count_vote", 3); // 到点啦
	}
}

int vote_list(object ob1, object ob2)  // 计算谁的得票多
{
	int score1,score2;
	score1 = ob1->query_temp("voted");
	score2 = ob2->query_temp("voted");
	return score2 - score1;
}

void count_vote()
{
	object *ob =filter_array(objects(), (: userp($1) && !wizardp($1) :)); // imm以上的巫师不算！
	object *list = sort_array(ob,(: vote_list :)); // 用efun sort_array()采用上面的函数对玩家的得票数进行排列
	string msg;
	int i;
	if (!list){
	message("system",HIY"【天神频道】"HIW"因为本年度投票者太少，辞旧迎新投票活动因故取消，真遗憾！\n"NOR,users());
	for(i=0; i<sizeof(ob); i++){
	ob[i]->delete("have_voted");
	}
	if (i>=sizeof(ob)) {
		return;
		}
	}
	else {
	msg =  HIW"\n           "+WHT+MUD_NAME+"新年投票前三名"WHT"\n";
	msg += HIW"┏━━━┯━━━━━━━━━━┯━━━━┯━━━━┓\n";
	msg += HIW"┃ "RED"名次"WHT" │   "WHT"好  人  姓  名"WHT"   │ "RED"门  派"WHT" │ "WHT"票  数"WHT" ┃\n";
	msg += HIW"┠───┴──────────┴────┴────┨\n";
	for (i = 0 ;i < 3 ; i++) { // 3是只列出前三个，如果你的MUD人多的话，就搞什么5个10个吧，就如鲁迅先生说过，中国人向来是有“十景症”的……
	if( i >= sizeof(list)) msg += WHT"┃"RED"好人难找，唉……                                "WHT"┃\n";
		else {
		msg += sprintf(WHT"┃  "WHT"%-5s "RED"%-22s"WHT"%-10s "RED"%5d  "WHT"┃\n",chinese_number(i+1),list[i]->query("name")+"("+
        capitalize(list[i]->query("id"))+")", list[i]->query("family")?  list[i]->query("family/family_name"):"普通百姓",
	list[i]->query_temp("voted"));
		}
			 }
	msg += WHT"┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	msg += HIY+"\n新年投票圆满完成。\n"NOR;
	delete_temp("voting"); // 投票结束！
	message("system",msg,users() );
	gift_who(list[0],1); // 给前三名发奖励呀
	gift_who(list[1],2);
	gift_who(list[2],3);
	return;
	}
}

void gift_who(object who,int rank)
{
	object *ob=users();
	int i;
	message("system",HIY"【天神频道】"HIW"本年度的最受欢迎玩家的荣誉称号将授予"HIR+who->name()+"("+who->query("id")+")"HIW"！\n"NOR,users());
	send_gift(who,rank);
	for(i=0; i<sizeof(ob); i++){
	ob[i]->delete("have_voted"); // 删掉投过票的记号
	}
	if (i>=sizeof(ob)) {
	return;
	}
}

void send_gift(object ob,int rank) // 名次不同，给的奖励的多少也不同
{
	string gift;
        int i=(10000+random(ob->query("combat_exp")/50))/rank; // 不算太多吧？一年才一次。
        int j=(1000+random(ob->query("combat_exp")/100))/rank; 
        int k=(500+random(500))/rank;
	object obj;
// 我这里给了3种奖励，你自己可以增加一些
	switch (random(3))
	{
		case 0:
			gift=chinese_number(i)+"点经验";
			ob->add("combat_exp",i);
			break;
		case 1:
			gift=chinese_number(j)+"点潜能";
			ob->add("potential",j);
			break;
		case 2:
			obj=new(GOLD_OB);
			obj->set_amount(k);
                        gift=chinese_number(obj->query_amount())+"两黄金";
			obj->move(ob);
			break;
	}
	tell_object(ob,HIM"祝贺你，"WHT+ob->name()+HIM"，你在这一年出色的表现使你当选了"WHT+MUD_NAME+RED"
最受欢迎的玩家，你获得的奖励是"HIW+gift+HIM"，开心吗！\n"NOR);
	return;
}
