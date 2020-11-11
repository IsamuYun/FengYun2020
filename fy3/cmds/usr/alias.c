//xgchen@zzfy
// alias.c

inherit F_CLEAN_UP;
#include <ansi.h>;
int main(object me, string arg)
{
        int i;
        mapping alias;
        string verb, replace, *vrbs;

        if( !arg ) {
                alias = me->query_all_alias();
                if( !sizeof(alias) ) {
                        write("��Ŀǰ��û���趨�κ� alias��\n");
                        return 1;
                } else  {
                        write("��Ŀǰ�趨�� alias �У�\n");
                        vrbs = keys(alias);
                        for(i=0; i<sizeof(vrbs); i++)
                                printf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
                        return 1;
                }
        }

        if( sscanf(arg, "%s %s", verb, replace)!=2 )
                me->set_alias(arg, 0);
        else if( verb=="alias" )
                return notify_fail("�㲻�ܽ� \"alias\" ָ���趨������;��\n");
        else if( verb=="" )
                return notify_fail("��Ҫ��ʲ�� alias��\n");
        else if(sizeof(replace)>150)
                return notify_fail("���\"alias\"̫���ˣ�\n");
        else
           {
                write("������� "HIR+verb+NOR" ����� "HIG+replace+NOR" ���\n");
                write("Ok.\n");
                return me->set_alias(verb, replace);
           }
        return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ : alias <���趨ָ֮��> <ϵͳ�ṩָ֮��>
 
��ʱϵͳ���ṩָ֮����Ҫ����ܳ����ִ�, ��ʹ��ʱ(�����Ǿ����õ���)
������о�������, ��ʱ��(��)�����ô�һָ���趨�����ԭ��ָ֮�
 
����:
        'alias sc score' ���� sc ȡ�� score ָ�
        'alias' �᲻�Ӳ������г������е����ָ�
        'alias sc' ������ sc ������ָ� (���������Ļ�)
 
���п����� $1, $2, $3 .... ��ȡ����һ���ڶ������������������� $* ȡ��
���еĲ������磺
        'alias pb put $1 in $2'

��ÿ����(��)��
        pb bandage bag

�ͻ�ȡ���ɣ�
        put bandage in bag
        
HELP
);
        return 1;
}
