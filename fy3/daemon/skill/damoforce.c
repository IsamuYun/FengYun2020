// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { return 1; }
int practice_skill(object me)
{
        return 
notify_fail("���������ľ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("bonze") + "/damoforce/" + func;
}
int effective_level() { return 12;}
int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 30;
}
void skill_improved(object me)
{
        int s;

        s = me->query_skill("damoforce", 1);
        if(!(s%10) && (int)me->query("con") < s/4){ 
                tell_object(me, HIG
"��ѧ��ѧ�����������ľ���ͻȻ�е�����֮����ӿ��������\n" NOR);
                me->add("con", 1);
		me->unconcious();
        }
}
