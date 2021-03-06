// Daemon:/adm/daemons/ynvoted.c
/* 新年辞旧迎新投票活动系统文件
    新年投票系统是受一个图形接口的文字MUD，乐斗士的血海飘香的
    类似设计启发而开发的，给自己身边的人投票，甚至是给自己投票，
    来选出一个什么最酷最帅最好心最可爱……的玩家并给与奖励，倒
    不失为一件能够吸引玩家的有趣活动，我想。
    主要的程序思路比较简单，因为投票时间比较短，所以票数是记在
    玩家身上的，而且用的是temp值，请注意，假如某玩家在投票过
    程中退出，他真是不幸，原来投给他的票全没了，其实用add 而不
    用add_temp也可以，注意投完票把票数删掉就行了。因为一年才
    投一次，我这里就懒得删那个temp值了。（不会有人整整一年都在
    线上吧？恐怖呀！）
    这个东东算是给大家的新年礼物吧，hehe。*/

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
	message("system", RED"【新年精灵】"WHT"各位同学，新年又到了，在本年度里，涌现出了无数的好人好事，因此，我们
	    现在特恳请各位同学为自己所知道的乐于帮助同学的好学生投上一票，新年精
	    灵将代表【糊涂泥巴工作室】全体成员表彰一位最受大家感激的优秀学生，并
	    给与他（她）一些奖励！好了，辞旧迎新投票活动正式开始！请大家使用
	    ynvote <id>指令为你最感谢的一名玩家投下宝贵的一票！\n"NOR, users());
	start_vote(); // 开始投票！
}

void start_vote()
{
	message("system",RED"【新年精灵】"WHT"各位同学，别急，您有现实10分钟时间供您决定投谁的票。\n" NOR,users());
	set_temp("voting",1); // 现在正在投票
	call_out("count_time",60,1); // "10"是指整个投票时间10分钟，可以自己修改
}

private void count_time(int min)
{
	min--;
	if( min ) {
		message("system",RED"【新年精灵】"WHT"各位同学，别急，您还有现实" + chinese_number(min) +"分钟的时间，想好了再投！\n"NOR,users() );
		call_out("count_time", 60, min); // 告诉大家还有几分钟时间
	} else {
		message("system",RED"【新年精灵】"WHT"各位同学，本次辞旧迎新新年投票活动已经圆满结束！现在工作人员正在紧张计票中！\n"NOR,users() );
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
	message("system",RED"【新年精灵】"WHT"因为本年度投票者太少，辞旧迎新投票活动因故取消，真遗憾！\n"NOR,users());
	for(i=0; i<sizeof(ob); i++){
	ob[i]->delete("have_voted");
	}
	if (i>=sizeof(ob)) {
		return;
		}
	}
	else {
	msg =  WHT"\n            ┏ "+WHT+MUD_NAME+"新年投票前三名"WHT" ━┓\n";
	msg += WHT"┏━━━┯━┻━━━━━━━━┯━━━━╀━━━━┓\n";
	msg += WHT"┃ "RED"名次"WHT" │   "WHT"好  人  姓  名"WHT"   │ "RED"门  派"WHT" │ "WHT"票  数"WHT" ┃\n";
	msg += WHT"┠───┴──────────┴────┴────┨\n";
	for (i = 0 ;i < 3 ; i++) { // 3是只列出前三个，如果你的MUD人多的话，就搞什么5个10个吧，就如鲁迅先生说过，中国人向来是有“十景症”的……
	if( i >= sizeof(list)) msg += WHT"┃"RED"好人难找，唉……                                "WHT"┃\n";
		else {
		msg += sprintf(WHT"┃  "WHT"%-5s "RED"%-22s"WHT"%-10s "RED"%5d  "WHT"┃\n",chinese_number(i+1),list[i]->query("name")+"("+
	capitalize(list[i]->query("id"))+")", list[i]->query("family")?  list[i]->query("family/family_name"):"普通学生",
	list[i]->query_temp("voted"));
		}
			 }
	msg += WHT"┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	msg += RED+RTIME_D->chinese_time(2,ctime(time()))+"投票圆满完成。\n"NOR;
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
	message("system",RED"【新年精灵】"WHT"本年度的优秀学生的荣誉称号将授予"RED+who->name()+"("+who->query("id")+")"WHT"同学！\n"NOR,users());
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
	int i=(1000+random(ob->query("combat_exp")/3))/rank; // 不算太多吧？一年才一次。
	int j=(100+random(500))/rank;
	int k=(10+random(80))/rank;
	object obj;
// 我这里给了3种奖励，你自己可以增加一些
	switch (random(3))
	{
		case 0:
			gift=chinese_number(i)+"点学分值";
			ob->add("combat_exp",i);
			break;
		case 1:
			gift=chinese_number(j)+"点潜能值";
			ob->add("potential",j);
			break;
		case 2:
			obj=new(GOLD_OB);
			obj->set_amount(k);
			gift=chinese_number(obj->query_amount())+"张百元大钞";
			obj->move(ob);
			break;
	}
	tell_object(ob,RED"祝贺你，"WHT+ob->name()+RED"同学，你在这一年出色的表现使你当选了"WHT+MUD_NAME+RED"
最佳学生，你获得的奖励是"WHT+gift+RED"，Enjoy it！\n"NOR);
	return;
}