// heal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
                if(amount<40) amount=40;
        if( (int)me->query("force") < amount )
                return notify_fail("�������������\n");
        if( (int)me->query_skill("seven-gest") < 40 )
                return notify_fail("����߾�����̫���ˣ�����ʹ�������Ԫ��\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 14 )
                return 
                        notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

    if(target==me){
        write( HIC "��ʹ�������Ԫ���˹����ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + 
                                "ʹ�������Ԫ�������ƣ���ɫ�������ö��ˡ�\n" NOR,
                environment(me), ({ me }));
    }else{
        message_vision( HIR "$Nʹ�������Ԫ��Ϊ$n�˹����ˣ�$n����ɫ�������ö��ˡ�\n" NOR, me, target);
    }

        target->receive_curing("kee", amount + ((int)me->query_skill("force") * amount /70) );
        target->add("kee", (target->query("eff_kee")-target->query("kee"))/4 );
        me->add("force", -amount);
        me->start_busy(1);

        return 1;
}
