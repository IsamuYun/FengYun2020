#include <ansi.h>
inherit F_CLEAN_UP;
int main()
{
        object me,where,*list;
        int i,j,k,temp,tempp,temppp; 
        me = this_player();
        
        list=users();

//蒙面人
        tell_object(me,HIW"■ 蒙面人： \n"NOR);
        tell_object(me,"─────────────────────────────────────\n");
        i=sizeof(list);
        while(i--)
             {
             if (!wizardp(list[i])&&list[i]->query_temp("apply/name"))
                {
                temp=1;
                where = environment(list[i]);
                printf(list[i]->query("name")+"("+list[i]->query("id")+")"+"现在在"+(string)where->query("short")+
                "("+(string)file_name(where)+")"+"假装蒙面人。\n");
                }
             
        }
        if(temp==0)
        {
                tell_object(me,"现在还没有人假装！\n");
        }
 

        tell_object(me,"\n─────────────────────────────────────\n\n\n");    
        return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : spy
 
这个指令可以让你查看在线有那位玩家假装蒙面人、运镖和通缉犯.
 
HELP
    );
    return 1;
}

