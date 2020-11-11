// tuwu.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
    int skill;
    string msg;
    object weapon;

    if( !target ) target = offensive_target(me);
    if (me->query_temp("jinshe/tuwu"))
        return notify_fail("����õĶ�������û�����žͳ��С�\n");

    if( !target
      || !target->is_character()
      || !me->is_fighting(target) )
        return notify_fail("��������ֻ����ս����ʹ�á�\n");

    if ( !objectp(weapon = me->query_temp("weapon"))
      || (string)weapon->query("skill_type") != "throwing" )
           return notify_fail("��û�ð���������ʹ�þ��У�\n");

    if( (int)me->query_skill("dulong-zhui", 1) < 100 )
        return notify_fail("��Ķ���׶������죬����ʹ�ö�������\n");

    if( (int)me->query("force") < 300 )
        return notify_fail("�����������ˡ�\n");

    skill = me->query_skill("throwing");

    me->add("force", -100);
    target->receive_damage("kee", (int)skill, me);

    message_vision(
        HIY "ֻ��һ����ɨҶ��������У�$N���е�"YEL"��׶"
        HIY"������Ŀ�Ĺ�â����ҫ��\n"
        "$n��ð�𻨣�������������"
        "������ǰһ���ص������⣬$nɶҲ�������ˣ�\n" NOR,
            me, target);
    me->set_temp("jinshe/tuwu", 1);
    target->set_temp("block_msg/all",1);

    if ( random(2) )
        target->set_temp("no_move",1);
    else
        me->add_temp("spi_protect", 1);

    target->apply_condition("unknown", random(skill/12) + 1 +
            target->query_condition("unknown"));
    call_out("tuwu_end", (int) skill/20, me, target);

    return 1;
}

void tuwu_end(object me, object target)
{
    if( objectp(target) )
    {
        target->enable_player();
        message_vision("$NĨ��Ĩ������"HIR"��Ѫ"NOR"�������������ۡ�\n", target);
        target->set_temp("block_msg/all", 0);
        target->set_temp("no_move",0);
    }
    // write(HIR"������Ĩ������������Ѫ����������Χ���龰��\n"NOR);
    me->add_temp("spi_protect", -1);
    me->delete_temp("jinshe/tuwu");

    return;
}
