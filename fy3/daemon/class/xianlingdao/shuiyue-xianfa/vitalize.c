// yiru@hero
// vitalize.c
// ������Ԫ

#include <ansi.h>

int exert(object me, object target, int amount)
{
                if(amount<90) amount=90;

        if( (int)me->query("force") < amount )
                return notify_fail("�������������\n");
        if( (int)me->query("atman") < amount )
                return notify_fail("�������������\n");
        if( (int)me->query("mana") < amount )
                return notify_fail("��ķ���������\n");

        if( (int)me->query_skill("shuiyue-xianfa",1) < 120 )
                return notify_fail("���ˮ���ɷ�̫���ˣ�����ʹ��������Ԫ��\n");

        if( (int)me->query("gin") < (int)me->query("eff_gin") / 12 
         || (int)me->query("kee") < (int)me->query("eff_kee") / 12 
         || (int)me->query("sen") < (int)me->query("eff_sen") / 12 
        )
                return 
                        notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

    if(target==me){
        write( HIW "��ʹ��������Ԫ���˹����ˡ�\n" NOR);
        message("vision",
                HIC + me->name() + 
                                "ʹ��������Ԫ����ɫ�;��񶼺ö��ˡ�\n" NOR,
                environment(me), ({ me }));
    }else{
        message_vision( HIW "$Nʹ��������Ԫ��Ϊ$n�˹��˹����ˣ�$n����ɫ�������ö��ˡ�\n" NOR, me, target);
    }

        target->receive_curing("gin", amount + ((int)me->query_skill("magic") * amount /120) );
        target->set("gin", (target->query("gin")*2+target->query("eff_gin"))/3 );
        target->receive_curing("kee", amount + ((int)me->query_skill("force") * amount /120) );
        target->set("kee", (target->query("kee")*2+target->query("eff_kee"))/3 );
        target->receive_curing("sen", amount + ((int)me->query_skill("spells") * amount /120) );
        target->set("sen", (target->query("sen")*2+target->query("eff_sen"))/3 );

        me->add("atman", -amount);
        me->add("force", -amount);
        me->add("mana", -amount);
        me->start_busy(1);

        return 1;
}
