// wizlist.c
#include <ansi.h>
int main(object me, string arg)
{
        string str;
	str="";	
        str += HIR"��"HIC"����������������"HIR" ��"HIY" һ������ "HIR"�� "HIC"��������������������"HIR"��\n"NOR;
        str += HIG"\n����������"HIB"����Ϸû�й�����ʦ"HIG"�����������\n"NOR;
        str += "\n"HIR"��"HIC"����������������������������������������������������"HIR"��\n"NOR;
        me->start_more(str);
        return 1;
}
int help(object me)
{
        write("\nָ���ʽ : wizlist\n"
        "��; : �г�Ŀǰ���е���ʦ������\n"
        );
        return 1;
}
