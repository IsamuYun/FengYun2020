// yiru@hero
// huanhun.c
// ������

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert_to_me(object me, object target,int amount)
{
    me->add("atman", -amount );
    me->add("mana", -amount );
    if (random(me->query_skill("shuiyue-xianfa",1)) < 30)
    {           
        write("��ʧ���ˡ�\n");
        me->start_busy(1);
        return 1;
    } else {
        if(me!=target)
            message_vision("$N��һ���������뵽$n���ڣ�$n����������ö��ˡ�\n", me, target);
        else
            message_vision("$N������һ����������������ö��ˡ�\n", me);
        target->set("gin",(target->query("gin")+target->query("eff_gin"))/2);
        target->set("sen",(target->query("sen")+target->query("eff_sen"))/2);
        me->start_busy(1);
        return 1;
    }
}

int exert(object me, object target, int amount)
{
    int lvl;

    if(amount<60) amount=60;

    if(me->query_skill("shuiyue-xianfa",1)<120)
        return notify_fail("���ˮ���ɷ�̫���ˣ�\n");

    if( (int) me->query("force") < amount) 
        return notify_fail("����������㡣\n");
    if( (int) me->query("atman") < amount) 
        return notify_fail("����������㡣\n");
    if( (int) me->query("mana") < amount) 
        return notify_fail("��ķ������㡣\n");

    if( !target ) {
        exert_to_me(me,target,amount);
        return 1;
    }

    if(!target->query_temp("is_unconcious")){
        exert_to_me(me,target,amount);
        return 1;
    }

    lvl = me->query_skill("shuiyue-xianfa",1);

    me->add("force", -amount );
    if (random(lvl+amount/3) < 60)
    {           
        me->start_busy(3);
        write("��ʧ���ˡ�\n");
    } else {
        me->add("force", amount/3 );
        message_vision("$N��һ���������뵽$n���ڡ�����\n", me, target);
        target->revive();
        write("��ɹ��ˣ�\n");
    }
    if(me->query("force")<60){
        message_vision("$N�������Ĺ��ȣ����˹�ȥ��",me);
        me->unconcious();
    }
    return 1;
}
