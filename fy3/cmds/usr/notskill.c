#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string wmp;
        if(!arg = me->quest_skill("arg"))
                return notify_fail("�㲻�봫��ʲô��\n");

        if(!me->query("env/no_teachskill"))
                me->set("env/no_teachskill", wmp+">");
        else
                me->set("env/no_teachskill", me->query("env/no_teachskill")+wmp+">");
        return 1;
}
 
int help(object me)
{
write(@HELP
ָ���ʽ : notskill <�书>
���ָ���������ò�����ʲô�书�����ӵ�
HELP
    );
    return 1;
}
