#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
        if( me->query_temp("nofly") || me->query("job/sxy"))
                return notify_fail("����Ҫ�����������������ܣ�\n");
        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ�û�������\n");
        if( me->query("atman") < 100 )
                return notify_fail("�������������\n");
        if( me->query("atman") < 100 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 100 )
                return notify_fail("��ľ�������\n");
        if( me->is_ghost())
                return notify_fail("����޷�����������\n");     
        if((int) me->query_skill("huanlong",1) < 151)
                return notify_fail("��Ļ��������������죡");

        if( target )
                return notify_fail("������ֻ�ܶ��Լ�ʹ�ã�\n");
        write("��Ҫ��������һ������ߣ�");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
}

void select_target(object me, string name)
{
        object ob;

        if( !name || name=="" ) {
                write("��ֹ����������\n");
                return;
        }

        ob = find_player(name);
        if( !ob || !me->visible(ob) || wizardp(ob) )
                ob = find_living(name);
        if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)

        || !ob->query("max_force") || !ob->query("force")) {
                write("���޷����ܵ�����˵����� ....\n");
                write("��Ҫ��������һ������ߣ�");
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
        if( me->is_fighting() ) {
                write("ս�����޷�ʹ�û�������\n");
                return;
        } else if( me->query("atman") < 100 ) {
                write("��������������޷��ٻ�������\n");
                return;
        }

        me->add("atman", -75);
        me->receive_damage("gin", 30);
        
        message_vision( HIG "$N����һ����ֵ����䣬��ʼ��������....\n" NOR, me);
        if( random(me->query_skill("magic")) < (int)ob->query("atman") / 50 ) {
                write("�ĺ�������Ч��������������Ϊ����������\n");

                return;
        }
        if( random(50) > 
        (int)(me->query_skill("huanlong",1))){
                write("�ĺ�������Ч��������������Ϊ����������\n");
                return;
        }
        if(environment(ob)->query("no_magic")) {
              write("����Ҫ����ȥ�ĵط��������û�������\n");
              return;
        }
                message( "vision", HIC "\nһ�����۾����������������������" + me->name() + "�����������������\n\n" NOR, environment(me), ({ me }) );
        me->move(environment(ob));
        me->start_busy(random(2));
        message( "vision", HIC "\n����Ͽ�ͻȻ����һ�����۾�����������������Լվ�Ÿ��ˣ�
����ȥ�������"+me->name()+"��\n\n" NOR,
                environment(ob), ({ me }) );
}
