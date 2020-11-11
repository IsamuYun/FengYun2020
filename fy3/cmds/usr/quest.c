// quest by tiandi 20080801

#include <ansi.h>

inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object ob, string arg)
{
	int nowtime = time();
	object me;
	if (!wizardp(ob) || arg == "") me = ob;
	else
	{
	if( arg ){
	me = present(arg, environment(ob));
	if (!me) me =  find_player(arg);
	if (!me) return notify_fail("你要察看谁的任务？\n");
			}
			else
				me = ob;
	}
	if(!me->query("longstory"))
		write (HIY"【成长任务之初入江湖】初入江湖张铁匠正在找你。\n"NOR);
	else if(me->query("longstory")==1)
		write (HIY"【成长任务之初入江湖】张铁匠说沉香可以钓鱼，去试试吧。\n"NOR);
	else if(me->query("longstory")==2)
		write (HIY"【成长任务之初入江湖】老太婆找人帮忙，去看看她吧。\n"NOR);
	else if(me->query("longstory")==3)
		write (HIY"【成长任务之初入江湖】角宿天君正在风云城的天空等你呢，五级以后去找他一下。\n"NOR);
	else if(me->query("longstory")==4)
		write (HIY"【成长任务之初入江湖】那个天机老人也在找你，六级以后去找他一下。\n"NOR);
	else if(me->query("longstory")==5)
		write (HIY"【成长任务之初入江湖】你已经正式踏入江湖，可以去拜师学艺了。\n"NOR);

	if(!me->query("quest")&&!me->query("tiequest"))
		return notify_fail("你现在没有任何任务！\n");
	if (me->query("quest"))
	{
	if( mapp(me->query("quest")))
	{
	mapping quest;
	quest =  me->query("quest");
	write("【天机任务】你现在的任务是" + quest["quest_type"] +
 "『" + quest["quest"] + "』。\n");
	}
	else
	{
	string quest;
	quest =  me->query("quest");
	write("你现在的任务是关于" + quest+ "。\n");
	}
	nowtime = (int) me->query("task_time") - time();
	if( nowtime  > 0 )
		time_period(nowtime, me);
	else
		write("但是你已经没有足够的时间来完成它了。\n");
	}
	if( mapp(me->query("tiequest")))
	{
	mapping quest;
	quest =  me->query("tiequest");
	if (me->query_temp("tiejobtemp")< 1)
		me->set_temp("tiejobtemp",1);
	write("【忠义任务】当前第"+me->query_temp("tiejobtemp")+"个，内容是" + quest["quest_type"] +
 "『" + quest["quest"] + "』。\n");
	
	nowtime = (int) me->query("tiequest_time") - time();
	if( nowtime  > 0 )
		time_period(nowtime, me);
	else
		write("但是你已经没有足够的时间来完成它了。\n");
	}
	return 1;
}
int time_period(int timep, object me)
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
        tell_object(me,"你还有" + time + "去完成它。\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quest
 
这个指令可以显示出你当前的任务。
HELP
        );
        return 1;
}
