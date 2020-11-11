// yufeng.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target)
{
        if(environment(me)->query("no_magic")) 
        {
                return notify_fail("����ط��޷�������С�\n");
        }

        if( me->query_temp("nofly") || me->query("job/sxy") )
                return notify_fail("��������������ʹ������⹦��\n");
        if( me->is_fighting() )
		return notify_fail("ս�����޷�������У�\n");
        if( me->query("force") < 200 )
		return notify_fail("�������������\n");
        if( me->query("gin") < 100 )
                return notify_fail("��ľ�������\n");
	if( me->is_ghost())
		return notify_fail("����޷�������У�\n"); 	
        if((int) me->query_skill("lingshenforce",1) < 120)
                return notify_fail("���������������");
		write(BLINK"[1;34m��Ҫ�����Ķ���[2;37;0m");

	input_to( (: call_other, __FILE__, "select_target", me :));

		return 1;
}


void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("[1;35m��ֹ����[1;34m��\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob) || !ob->query("max_force") || !ob->query("force")) {
		write("���޷����ܵ�����˵����� ....\n");
		write("��Ҫ�ƶ�����һ������ߣ�");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;


		}
	if( me->is_fighting() ) {
		write("[1;31mս�����޷�ʹ��Ԧ�����[2;37;0m��\n");
		return;
        } else if( me->query("force") < 200 ) {
		write("�������������\n");
		return;
	}

        me->add("force", -150);
        me->receive_damage("gin", 80);
	
	message_vision( HIC "$N�������ӣ���ʼʩչ���ҵ�Ԧ����� ....\n" NOR, me);
        if( random(ob->query("force")) < (int)me->query("force") / 10 ) {
		write("����ܵ��Է������������ǲ���ǿ�ҡ�\n");
		return;
	}
  if( random(me->query_skill("lingshenforce")) < (int)ob->query("force") / 500 ) {
		write("����Ϊ����������ʧ���ˡ�\n");
		return;
	}
        if( random(80) > (int)(me->query_skill("lingshenforce",1))){
                write("����Ϊ����������ʧ���ˡ�\n");
                return;
        }
	if(environment(ob)->query("no_magic")) {
		write("����Ҫ����ĵط�������ȥ��\n");
		return;
	}
	message( "vision", HIM "\nͻȻ����˿����,Ʈ��" + me->name() 
		+ "��������Ʈ����˿,ת�ۼ�����ʧ���٣�\n\n" NOR, environment(me), ({ me }) );
        me->move(environment(ob));
        me->start_busy(2);
	message( "vision", HIW "\nͻȻ�䣬���Ʈ��һ˿����,����ӰԼ�и���Ӱ���������޷�������ٶ�����Ʈ����\n\n" NOR,
		environment(ob), ({ me }) );
}

