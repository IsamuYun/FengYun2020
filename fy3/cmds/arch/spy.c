#include <ansi.h>
inherit F_CLEAN_UP;
int main()
{
        object me,where,*list;
        int i,j,k,temp,tempp,temppp; 
        me = this_player();
        
        list=users();

//������
        tell_object(me,HIW"�� �����ˣ� \n"NOR);
        tell_object(me,"��������������������������������������������������������������������������\n");
        i=sizeof(list);
        while(i--)
             {
             if (!wizardp(list[i])&&list[i]->query_temp("apply/name"))
                {
                temp=1;
                where = environment(list[i]);
                printf(list[i]->query("name")+"("+list[i]->query("id")+")"+"������"+(string)where->query("short")+
                "("+(string)file_name(where)+")"+"��װ�����ˡ�\n");
                }
             
        }
        if(temp==0)
        {
                tell_object(me,"���ڻ�û���˼�װ��\n");
        }
 

        tell_object(me,"\n��������������������������������������������������������������������������\n\n\n");    
        return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : spy
 
���ָ���������鿴��������λ��Ҽ�װ�����ˡ����ں�ͨ����.
 
HELP
    );
    return 1;
}

