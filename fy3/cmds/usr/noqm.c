//edit by xgchen@zzfy
//ȡ��ǩ��ָ��

#include "ansi.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string *txt;

        if( !arg ) return notify_fail("ָ���ʽ��noqm me<id>\n");
          if(arg!=me->query("id")) return notify_fail("ָ���ʽ��noqm me<id>\n");

        me->delete("qianminglong");
        write("Ok.\n");
        return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��qianming <����>

���ָ�������趨�������Ե�ʱ������ʾ���ǩ����
ǩ������һ��ʱ����ʹ��to qianming��
TEXT
        );
        return 1;
}


