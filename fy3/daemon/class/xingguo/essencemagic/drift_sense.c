// drift_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
    if( me->query_temp("nofly")  )
        return notify_fail("������Ҫ�������������������ܣ�\n");
	if( me->is_fighting() )
		return notify_fail("ս�����޷�ʹ����ʶ��ͨ��\n");
	if( me->query("atman") < 75 )
		return notify_fail("�������������\n");
        if( me->query("atman") < 75 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 35 )
                return notify_fail("��ľ�������\n");
	if( me->is_ghost())
		return notify_fail("�����޷�ʹ����ʶ��ͨ��\n"); 	
        if((int) me->query_skill("essencemagic",1) < 60)
                return notify_fail("��İ�ʶ��ͨ�������");
	if( target )
		return notify_fail("��ʶ��ֻͨ�ܶ��Լ�ʹ�ã�\n");
	write("��Ҫ�ƶ�����һ�������ߣ�");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("��ֹʩ����\n");
		return;
	}

	ob = find_player(name);
	if( !ob || wizardp(ob) )
		ob = find_living(name);
	if( !ob || wizardp(ob) || !environment(ob)
	|| !ob->query("level")*10 > me->query_skill("essencemagic",1) || ob->query("is_jobnpc")) {
		write("���޷����ܵ�����˵����� ....\n");
		write("��Ҫ�ƶ�����һ�������ߣ�");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	if( me->is_fighting() ) {
		write("ս�����޷�ʹ����ʶ��ͨ��\n");
		return;
	} else if( me->query("atman") < 75 ) {
		write("�������������\n");
		return;
	}

	me->add("atman", -75);
	me->receive_damage("gin", 30);
	
	message_vision( HIY "$N��ͷ��Ŀ����ʼʩչ��ʶ��ͨ ....\n" NOR, me);
	if( random(me->query_skill("essencemagic",1)) < ob->query("level")*5 ) {
		write("����ܵ��Է������������ǲ���ǿ�ҡ�\n");
		return;
	}
/*  by tiandi ����Ҫ��ô������
	if( random(me->query_skill("magic")) < (int)ob->query("atman") / 50 ) {
		write("����Ϊ����������ʧ���ˡ�\n");
		return;
	
        if( random(50) > 
	(int)(me->query_skill("essencemagic",1))){
                write("����Ϊ����������ʧ���ˡ�\n");
                return;
        }
		*/ 
	if(environment(ob)->query("no_magic")) {
		write("����Ҫ��ʶ�ĵط�����������ͨ��\n");
		return;
	}
	message( "vision", HIY "\nһ��ҫ�۵Ĺ�â��Ȼ��ס" + me->name() 
		+ "���������ᣬ��â����һ����ʧ����Ӱ���٣�\n\n" NOR, environment(me), ({ me }) );
	me->move(environment(ob));
	message( "vision", HIY "\n�����ǰͻȻ����һ��ҫ�۵Ĺ�â����â�и��ֳ�һ����Ӱ��\n\n" NOR,
		environment(ob), ({ me }) );
}
int help(object me)
{
        write(YEL"\n��ʶ��֮ͨ��ʶ��"NOR"\n");
	write(@HELP

         ��ʶ��֮ͨ�������������Ը����Լ�������˲����е�Ŀ�괦��
		 ��ʶ��ͨÿ����ʮ�������ӿ��Է��е�Ŀ��ȼ�����һ����
     

HELP
	);
	return 1;
}
