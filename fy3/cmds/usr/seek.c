//seek

#include <ansi.h>

int main(object me, string arg)
{
        int i, n;
        object ob;
        object *user;
        
//        if( !wizardp(me) ) return 0;
        if( !arg ) 
                return notify_fail("��Ҫ��ʲô�ˣ�\n");
        
        write("Ŀǰ���ߵ�����У��� "HIR+arg+NOR+" ���У�\n\n");
        user = users();
        for(i=0,n=0; i<sizeof(user); i++)
        if( user[i]->name()==arg )
        {
                write(user[i]->name()+"("+HIR+getuid(user[i])+NOR+")\n");
                n++;
        }
        if( n==0 ) write("Ŀǰ���ߵ���ҵ���û�н� "+HIR+arg+NOR+" �ġ�\n");
        
        return 1;
}
int help (object me)
{
        write(@HELP
ָ���ʽ : seek [�����������]
 
���ָ������鿴��ҵ������������ĸ�Ӣ�����֣
 
HELP
);
        return 1;
}

