// ��ħ��  written by tiandi
#include <ansi.h>
inherit F_CLEAN_UP;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int exert(object me, object target,int amount)
{
       int skill,myexp,urexp,force,getforce;
	string msg;
	if( !me->is_fighting() )
		return notify_fail("����ħ���ֻ����ս����ʹ�á�\n");
	skill = (int)me->query_skill("moshen-force",1);
	if( skill < 50 )
		return notify_fail("�����ħ��������\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("��Ҫ��˭ʩչ����ħ��ݣ�\n");
	}
	myexp = (int)me->query("combat_exp");
	urexp = (int)target->query("combat_exp");
	force = (int)target->query("force");
	if( me->query("TASK") < 1300  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("����Ŀǰ��״������û���ʸ�����һ�С�\n");
	if ( force < 50) force = 50;
	msg = BLU"ʹ����ħ���еģ���ħ���һʽ��˫�ڿ���$n�ľ�������ͼ��$n��������Ϊ���á�\n"NOR;
	message_vision(msg,me,target);
	if ( random(myexp)*skill/50 < urexp ) 
		{
		msg = "$n��ʶԨ������$N������ˣ�����һ�����˹�ȥ��\n";
		me->start_busy(2);
		}
	else 	{
		getforce = force / 5;
		if ( getforce > 500 ) getforce =500;
		target->add("force",-getforce);
		me->add("force",getforce);
		if ( me->query("force") > me->query("max_force")*3)
			me->set("force",me->query("max_force"));
		msg = "$Nץ��$n�����Ų��ţ�$nֻ����һ������������й���������Կ��ƣ�\n";
		me->start_busy(2);
		}
	message_vision(msg,me,target);
	return 1;
}
