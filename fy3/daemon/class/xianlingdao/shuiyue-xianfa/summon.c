// yiru@hero

inherit SSERVER;
#include <ansi.h>
#include <condition.h>
#include <combat.h>

int summon_god(object me, object target, int level)
{
    object soldier;
        message_vision(HIW"\n$N��"HIM"ʥ����"HIW"�߾ٹ�ͷ����ʹ�������ٻ���������\n"NOR, me);
        message_vision(HIY"ֻ��һ���������ף����մ󵶵���ʿͻȻ����$n�����\n"NOR, me, target);

        seteuid(geteuid(this_player()));

        soldier = new("/obj/npc/wu_god");

        soldier->move(environment(me));
        soldier->invocation(me, level);
        soldier->set("possessed", me);
        me->remove_all_killer();
        me->set_temp("guards/wu",1);
        me->start_busy(1);
        target->start_busy(3);

    return 1;
}

int conjure(object me, object target)
{
        int lvl, lvl1;
    object zhu;

    lvl = me->query_skill("shuiyue-xianfa",1);
    lvl1 = (lvl + me->query_skill("five-summon",1))/2;

    if( lvl1 > lvl ) lvl = lvl1;

    if(lvl < 250)
                return notify_fail("�㻹ûѧ�������ٻ���������\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ٻ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

  if(userp(me)){
        if( (int)me->query("atman") < lvl)
                return notify_fail("������������ˣ�\n");
        if( (int)me->query("force") < lvl)
                return notify_fail("������������ˣ�\n");
        if( (int)me->query("mana") < lvl)
                return notify_fail("��ķ��������ˣ�\n");
        me->add("atman", -lvl);
        me->add("force", -lvl);
        me->add("mana", -lvl);
  }

        me->start_busy(2);

    notify_fail("�����������ٻ���������ʲôҲû�з�����\n");

    if(random(lvl)<90) return 0;
    if(me->query_temp("guards/wu")) return 0;
    if(!objectp(zhu=present("shengling zhu", me)) ) return 0;
    if(!zhu->query("equipped") ) return 0;

    if( userp(me) )
    {
        return summon_god(me, target, 10*lvl);
    }

        return 0;
}
