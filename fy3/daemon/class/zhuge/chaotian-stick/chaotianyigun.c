//����һ�� writted by tiandi

#include <ansi.h>
inherit SSERVER;
void remove_effect(object me, int amount);

int perform(object me,object target,int amount)
{
        string msg;
        object weapon;
        int skill, exp,str;
        skill  = me->query_skill("chaotian-stick",1);
 	 str = me->query("str");
	 exp = me->query("combat_exp");
	 
	 if( !target ) target = offensive_target(me);
	 if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                   return notify_fail("��"+HIW"����һ��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	 if ( str < 40 ) return notify_fail("�������������\n");
        if ( exp < 500000 ) return notify_fail("���ʵս���鲻����\n");

        if( me->query("TASK") < 2300  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("����Ŀǰ��״���������ǲ���ʹ����һ���ˡ�\n");
	  if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
            return notify_fail("��ʹ�õ��������ԡ�\n");
	
	 if( (int)me->query_temp("chaotian") ) return notify_fail("���Ѿ����˹����ˡ�\n");

        if( skill < 150)
            return notify_fail("��ĳ�����ȼ�����, ����ʹ�á�"+HIW"����һ��"NOR+"����\n");

        if( me->query("force") < 3000 )
            return notify_fail("��������������޷����á�"+HIW"����һ��"NOR+"����\n");
	
	 if( me->query_temp("five")!=4)
	     return notify_fail("�㻹û���ʸ��������С�\n");

        msg = HIW
    "$N�������˾Ÿ��������趯��"+weapon->name()+HIW"�����˼�Х,ֻ��$Nһ�Ӷ���Խ������ͷ�����ϳ�һ�����£�\n���˲������ƣ�$NҪ��˭�ء�������\n\n"HIB"$n���ܵ�һ���������δ�й��ĸо������ǡ��ס��ĸо���\n------���ס���һ�硰������һ���޿ɵ������޷�ƥ�С����Ծܿ������б���ġ�\n"NOR;


        message_vision(msg, me, target);
        me->set_temp("chaotian", 1);
	 me->set_temp("no_eat",1);
	 me->add("combat_exp",exp*4);
	  me->set_temp("no_quit",1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, exp*4 :), skill/4);

        me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)	 
{
              int kee;
	 object env,room;

	 me->add("combat_exp",-amount);
        me->delete_temp("chaotian");
	 me->set("force",0);
	 me->delete_temp("quit");
	 env = environment(me);
        if ( env->query("no_death_penalty")) 
		{
		room = load_object("/d/death/gate");
  		if(room) me->move(room);
 	 	}//��ֹ���pfm���yaren������
	 tell_object(me, HIR"\n\n�����������һ����������Ҳվ�������ˡ�\n\nϦ����������������ϣ��㲻����ο��Ц�ˣ������ء����������ر�����˫�ۡ�\n"NOR);
	
	me->add("kee",-(me->query("max_kee")+1000));
	me->set_temp("last_damage_from","???");
	me->delete_temp("no_eat");
}
