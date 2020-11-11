// exert.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string force;
        int result;
        
        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能施用内功。\n"); 
        if( me->query("combat_exp")<2000 )
                return notify_fail("（你的实战经验太低了，不能施用内功。） \n");
        if( !arg ) return notify_fail("你要用内功做什麽？\n");

        if( stringp(force = me->query_skill_mapped("force")) ) {
                notify_fail("你所学的内功中没有这种功能。\n");
        //if(SKILL_D(force)->belong()!=me->query("class"))
	//return notify_fail("只有该技能的门派成员才可以使用。\n");
        if( environment(me)->query("no_exert") )
                return notify_fail("这里不准用内功。\n");
        if(!me->is_fighting())
                me->start_busy(1);
                if( SKILL_D(force)->exert_function(me, arg) ) {
                        return 1;
                } else if( SKILL_D("force")->exert_function(me, arg) ) {
                        return 1;
                }
                return 0;
        }

        return notify_fail("你请先用 enable 指令选择你要使用的内功。\n");
}

int help (object me)
{
        write(@HELP
指令格式：exert <功能名称> [<施用对象>] [<内力点数>] 

用内力进行一些特异功能，你必需要指定<功能名称>，<施用对象>则可有可无。
在你使用某一种内功的特异功能之前，你必须先用 enable 指令来指定你要使用
的内功。

请参考 help force 可得知一些大部分内功都有的功能，至於你所用的内功到底
有没有该功能，试一试或参考其他说明便知。

注：如果你改变自己的内功，你原本蓄积的内力并不能直接转换过去，必须
    从 0 开始。
 
HELP
        );
        return 1;
}
 
