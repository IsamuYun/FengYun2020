// heal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
                if(amount<50) amount=50;
        if( (int)me->query("force") < amount )
                return notify_fail("�������������\n");
        if( (int)me->query_skill("force") < 50 )
                return notify_fail("����ڹ�̫���ˣ�����ʹ��Ԫ���������\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 10 )
                return 
                        notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

    if(target==me){
        write( HIR "��ʹ��Ԫ����������˹����ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + 
                                "ʹ��Ԫ��������������ƣ���ɫ�������ö��ˡ�\n" NOR,
                environment(me), ({ me }));
    }else{
        message_vision( HIC "$Nʹ��Ԫ���������Ϊ$n�˹����ˣ�$n����ɫ�������ö��ˡ�\n" NOR, me, target);
    }

        target->receive_curing("kee", amount + ((int)me->query_skill("force") * amount /50) );
        target->set("kee", (target->query("eff_kee")+target->query("kee"))/2 );
        me->add("force", -amount);

        return 1;
}
