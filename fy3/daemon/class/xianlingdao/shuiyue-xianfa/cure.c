// yiru@hero
// heal.c
// ������

#include <ansi.h>

int exert(object me, object target, int amount)
{
                if(amount<60) amount=60;
        if( (int)me->query("force") < amount )
                return notify_fail("�������������\n");
        if( (int)me->query("sen") < amount )
                return notify_fail("��������������ǿ�˹�������º�Σ�գ�\n");
        if( (int)me->query_skill("shuiyue-xianfa",1) < 60 )
                return notify_fail("���ˮ���ɷ�̫���ˣ�����ʹ�ù����䡣\n");

        if( (int)me->query("kee") < (int)me->query("eff_kee") / 10 )
                return 
                        notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

    if(target==me){
        write( HIW "��ʹ�ù����䣬�˹�������\n" NOR);
        message("vision",
                HIC + me->name() + 
                                "ʹ�ù�������������ʱ����Ŀ���ﵽ�����һ�ľ��硣����\n" NOR,
                environment(me), ({ me }));
    }else{
        message_vision( HIW "$N��������ʩ��$n���ϡ�����$n��ʱƽ����������\n" NOR, me, target);
    }

        target->set("kee", (target->query("eff_kee")+target->query("kee")*2)/3);
        me->add("force", -amount);
        if(me->query("bellicosity") > me->query_skill("force") ){
            me->add("bellicosity", - me->query_skill("force") );
            me->receive_damage("sen", amount);
        }

        me->start_busy(1);

        return 1;
}
