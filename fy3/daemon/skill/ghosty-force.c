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
notify_fail("�޿�����ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("bandit") + "/ghosty-force/" + func;
}
 
int effective_level() { return 10;}

int learn_bonus()
{
	return -110;
}
int practice_bonus()
{
	return -110;
}
int black_white_ness()
{
	return -20;
}

void skill_improved(object me)
{
        int s,diff;
        object hb;

        s = me->query_skill("ghosty-force", 1);
	diff = (s-100)/10;
        if((int)me->query("age_modify") < diff && diff > 0 && (int)me->query("age")>10) {
                tell_object(me, HIG "����޿�������פ����Ч�����Եø��������ˣ�\n" NOR);
		me->set("age_modify",-diff);
		me->update_age();
        }
        if( (int)me->query_skill("ghosty-force", 1)  > 299              &&  me->query("gender") != "Ů��" ) {
                tell_object(me,
HIR "\n��ͻȻ��ֻ�����Լ�������˸����Ƶ�,ԭ�����޿�����ʹ������Ա�Ϊ��Ů�ԣ���....\n\n" NOR);
                me->set("gender","Ů��");
                me->add("max_force",200);
                hb=new("/questobj/obj/hongbao2");
                hb->move(me);
                me->unconcious();
                }
}
