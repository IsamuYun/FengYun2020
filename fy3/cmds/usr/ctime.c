#include <localtime.h>
#include <ansi.h>
inherit F_CLEAN_UP;
/*
 * if like chinese's time show ,can list here type to return
 * type = 1 , return string like һ�žŰ���ʮ����ʮһ�������ʮ�� ������
 * type = 2 , return string like һ�žŰ���ʮ����ʮһ�������ʮ��
 * type = 3 , return string like ʮ����ʮһ�������ʮ�� ������
 * type = 4 , return string like ʮ����ʮһ�������ʮ��
 * type = 5 , return string like 1998��10��31��3��20��
 * type = 6 , return string like 10��31��3��20��
 * if not define type, default return string like define type =1
 * if need conversion time not now() can define string get_time
 * but get_time must like "Sun May  3 00:52:12 1998"
 * example chinese_time(1,ctime(time())
 * Make By Luky@Hero
 * Make By XGCHEN 2001
 */
string chinese_time(int type,string get_time)
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
                "Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

        if ( stringp(get_time) )
                e_time = get_time;
        else e_time = ctime(time());

        // e_time must is ctime(time string) like "Sun May  3 00:52:12 1998"
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);

        c_week  = chinese_number(member_array(week, week_name) + 1);
        c_month = chinese_number(member_array(month, month_name) + 1);

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "��";
        c_month  = c_month + "��";
        c_week = " ����"+c_week;

        c_time = chinese_number(day) + "��";
        c_time += chinese_number(hour) + "��";
        c_time += chinese_number(minute) + "��";
        // maybe not need srcond to show
        // c_time += chinese_number(second) + "��";

        if (type) {
                switch( type ) {
                        case 1: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 5: return year+"��"+(member_array(month, month_name) + 1)+
                                "��"+day+"��"+hour+"��"+minute+"��";
                        case 6: return (member_array(month, month_name) + 1)+
                                "��"+day+"��"+hour+"��"+minute+"��";
                          case 7: return hour+":"+minute+":"+second;
                           case 8: return year+":"+month+":"+day;
                       default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}

int main(object me, string arg)
{
        int i;

        if(!arg||sscanf(arg,"%d",i)!=1)
                write(HIG"�����Ǳ���ʱ��" + chinese_time(1,(string)localtime(time())) + "��\n"NOR);
        else
                write("������" + chinese_time(i,(string)localtime(time())) + "��\n");
        return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: rtime

���ָ������(��)֪�����ڵ�ʵ��ʱ�䡣
���Դ�����1-8��ͬ�ĸ�ʽ��ʾ��

HELP
    );
    return 1;
}


