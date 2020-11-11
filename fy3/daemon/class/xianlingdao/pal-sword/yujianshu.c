// yiru@hero

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int do_one_attack(object me, object target, int lvl, int extra, int busy);
int do_another_attack(object me, object target, int lvl, int extra, int busy);

int perform(object me, object target)
{
    int extra, lvl, busy;
    object weapon;

    if ( !target )
        target = offensive_target(me);
    if ( !target
      || !target->is_character()
      || !me->is_fighting(target) )
        return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    weapon = me->query_temp("weapon");
    lvl = me->query_skill("pal-sword",1);
    extra = lvl / 18 + ((lvl % 18) > 0);
    message_vision(HIC "\n$N"HIC"�������������Ǳ������������$n" HIC
      "���ֶ�����\n" NOR, me, weapon);
    if ( userp(me) && ( random(lvl-18) + me->query_agi()<36 ) )
    {
        message_vision(HIW  "$N����������ָ��"+ weapon->name() + HIW
          "��$n" HIW "��ȥ��\n"
          HIY "���Ϻ����˰��죬"+ weapon->name() + HIY
          "������ž����һ���������£�" NOR, me, target);

        write(HIY "\n����������ɽ�������������졣\n" NOR);
        if( weapon->query("owner") )
            message_vision(HIW "����$N����һ�������ȵİ�$n"HIW
              "�������С�\n"NOR, me, weapon);
        else
            weapon->move(environment(me));
        return 1;
    }

    busy = lvl/40+1;

    me->do_attack_perform(target, extra, busy, lvl/9, lvl/3,
        HIW  "$N" HIW "����������"
        + weapon->name() + HIW "�������۾���ֱ��$n"HIW"��" NOR,
        "\n" HIG + weapon->name() + HIG "�ɻ�$N" HIG "���У�"
        "$N" HIG "����һ�������Ƚ�ס��\n" NOR);

    return 1;
}
