// yiru@hero
// iceheart.c

#include <ansi.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
  int force, lvl;

  force =(int) me->query("force") - (int) me->query("max_force");
  lvl = me->query_skill("moon-magic",1);

  if(force<=100)
    return notify_fail("����������㡣\n");

    if(me->query_skill("moon-magic",1)<=120)
        return notify_fail("���ˮ���ɷ�̫���ˣ�\n");

  if( target != me )
  {
    me->start_busy(3);
    if(force<=150)
        return notify_fail("����������㡣\n");
    me->add("force", -150 );
    message_vision(HIB"\n$N��˫������$n����������ľ���һ�ɱ���֮��������$n��ȥ��\n"NOR,me,target);
    if(target->query("force")*2>=me->query("force"))
    { 
        message_vision(HIR"\n����$NͻȻ��һ���ƺ��ܵ�$n��������������һ����Ѫ���ۡ������˳�����\n"NOR,me,target);
        me->receive_damage("kee",target->query("force")%100+1,target);
        COMBAT_D->report_status(me);
    }
    else if(random(lvl)<30)
    { 
        message_vision(HIW"\n$nֻ����һ�ɱ���֮���������ڣ��������ĵĵġ������˶��¡�\n"NOR,me,target);
        write("�˹�����ʧ�ܡ�\n");
    }
    else
    { 
        message_vision(HIB"\n$nֻ����һ�ɱ���֮��ֱ����Ƣ����ʱ����Ŀ���������³�һ������\n"NOR,me,target);
        message_vision("\n$n�еĶ���ʧ�ˣ�\n",me,target);
        target->clear_condition();
    }
    return 1;
  }

    me->start_busy(2);
    if (random(lvl) < 20)
    {           
        me->add("force", -100  );
        message_vision("$N�˹�������ͷ��ð������ĺ�������\n", me);
        write("��ʧ���ˡ�\n");
    }
    else
    {
        me->clear_condition();  
        write("��ɹ��ˣ�\n");
    }
    return 1;
}
