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
	if (!me) return notify_fail("��Ҫ�쿴˭������\n");
			}
			else
				me = ob;
	}
	if(!me->query("longstory"))
		write (HIY"���ɳ�����֮���뽭�������뽭���������������㡣\n"NOR);
	else if(me->query("longstory")==1)
		write (HIY"���ɳ�����֮���뽭����������˵������Ե��㣬ȥ���԰ɡ�\n"NOR);
	else if(me->query("longstory")==2)
		write (HIY"���ɳ�����֮���뽭������̫�����˰�æ��ȥ�������ɡ�\n"NOR);
	else if(me->query("longstory")==3)
		write (HIY"���ɳ�����֮���뽭��������������ڷ��Ƴǵ���յ����أ��弶�Ժ�ȥ����һ�¡�\n"NOR);
	else if(me->query("longstory")==4)
		write (HIY"���ɳ�����֮���뽭�����Ǹ��������Ҳ�����㣬�����Ժ�ȥ����һ�¡�\n"NOR);
	else if(me->query("longstory")==5)
		write (HIY"���ɳ�����֮���뽭�������Ѿ���ʽ̤�뽭��������ȥ��ʦѧ���ˡ�\n"NOR);

	if(!me->query("quest")&&!me->query("tiequest"))
		return notify_fail("������û���κ�����\n");
	if (me->query("quest"))
	{
	if( mapp(me->query("quest")))
	{
	mapping quest;
	quest =  me->query("quest");
	write("��������������ڵ�������" + quest["quest_type"] +
 "��" + quest["quest"] + "����\n");
	}
	else
	{
	string quest;
	quest =  me->query("quest");
	write("�����ڵ������ǹ���" + quest+ "��\n");
	}
	nowtime = (int) me->query("task_time") - time();
	if( nowtime  > 0 )
		time_period(nowtime, me);
	else
		write("�������Ѿ�û���㹻��ʱ����������ˡ�\n");
	}
	if( mapp(me->query("tiequest")))
	{
	mapping quest;
	quest =  me->query("tiequest");
	if (me->query_temp("tiejobtemp")< 1)
		me->set_temp("tiejobtemp",1);
	write("���������񡿵�ǰ��"+me->query_temp("tiejobtemp")+"����������" + quest["quest_type"] +
 "��" + quest["quest"] + "����\n");
	
	nowtime = (int) me->query("tiequest_time") - time();
	if( nowtime  > 0 )
		time_period(nowtime, me);
	else
		write("�������Ѿ�û���㹻��ʱ����������ˡ�\n");
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

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        tell_object(me,"�㻹��" + time + "ȥ�������\n");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : quest
 
���ָ�������ʾ���㵱ǰ������
HELP
        );
        return 1;
}