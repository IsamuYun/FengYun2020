//by xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit FORCE;
int valid_enable(string usage) { 
return (usage=="force");
}
int valid_learn(object me)
{
             if(me->query("gender")=="男性")
                return notify_fail("你不能学习明玉神功！\n");
//  if(me->query("class") != "yihua" || "yihuayihuashinv")
//  return notify_fail("你不是移花弟子不能学习。\n")
return 1; 
}
int practice_skill(object me)
{
        return 
notify_fail("明玉神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("yihua") + "/mingyu-shengong/" + func;
}
int effective_level() { return 35;}
int learn_bonus()
{
        return -200;
}

int practice_bonus()
{
        return -1000;
}

int black_white_ness()
{
        return 300;
}
