//by xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit FORCE;
int valid_enable(string usage) { 
return (usage=="force");
}
int valid_learn(object me)
{
             if(me->query("gender")=="����")
                return notify_fail("�㲻��ѧϰ�����񹦣�\n");
//  if(me->query("class") != "yihua" || "yihuayihuashinv")
//  return notify_fail("�㲻���ƻ����Ӳ���ѧϰ��\n")
return 1; 
}
int practice_skill(object me)
{
        return 
notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
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
