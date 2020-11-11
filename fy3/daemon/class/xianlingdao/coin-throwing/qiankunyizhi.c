// qiankunyizhi.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
    int amount,lev;
    object coin;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target
      ||        !target->is_character()
      ||        !me->is_fighting(target) )
        return notify_fail("["HIY"Ǭ��һ��"NOR"]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if((int) me->query_skill("coin-throwing",1) < 30)
        return notify_fail("���ͭǮ�ڻ��������������ܷ���"HIY"Ǭ��һ��"NOR"��\n");
    coin=present("coin",me);
    if(!coin)
        return notify_fail("������û��Ǯ,������Ǭ��һ����\n");
    amount=10*(lev=me->query_skill("throwing"));
    if(coin->query_amount()<amount)
        return notify_fail("�����ϵ�Ǯ����"+chinese_number(amount)+"��,���ܷ�Ǭ��һ����\n");
    message_vision(HIY"$NͻȻ�ӻ����ͳ�һ���ͭǮ������������$n��ȥ��������$n��������·\n"
      "�������ˡ�\n"NOR,me,target);
    message_vision("�����ɷǳ����µ������˺���\n",target);
    coin->add_amount(-amount);
    target->receive_damage("kee",5*lev,me);
    COMBAT_D->report_status(target);

    me->start_busy(2);
    return 1;
}
