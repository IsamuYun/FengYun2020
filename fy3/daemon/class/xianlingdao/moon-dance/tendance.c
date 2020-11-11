// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg,type;
	int extra,extra2;
	int lev;
	int dam1;
	int dam2;
	int dam3;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("moon-dance",1);
	if ( extra < 30) return notify_fail("���ˮ�����軹�������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ʮ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    weapon = me->query_temp("weapon");
    if (!weapon) 
        type = "unarmed";
    else
        type = weapon->query("skill_type");

    if ( type!="whip" || (string) me->query_skill_mapped(type) != "moon-dance")
        return notify_fail("��Ŀǰʹ�õ��⹦����ˮ�����裡\n");

    if ( (string) me->query_skill_mapped("force") != "moon-dance")
        return notify_fail("��Ŀǰʹ�õ��ڹ�����ˮ�����裡\n");

	me->add_temp("apply/attack",extra*5);
	me->add_temp("apply/damage",extra*10);

	msg = HIR  "$N���췢��һ����Ц��ʹ��ˮ�������еģ�����ʮ���\n\n" NOR;
	msg += HIG   "���ƺ���ޱȵ�ˮ�²�������ǰ����ʱ�������Ϊ֮��ɫ��\n" NOR;
	message_vision(msg,me,target);
    
    lev = extra/30;
    extra2 = me->query_skill("moon-dance");
    dam1 = (int) me->query("max_force");
    dam2 = (int) me->query("max_mana");
    dam3 = (int) me->query("max_atman");

	me->add("str",3*extra);
    
    if(lev > 0)
    {
        msg =  HIC  "\n����һ�辪���\n" NOR;
		message_vision(msg,me,target);
        if(1*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIW "$N��ʧɫ���仯������\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)/10+extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)/10+extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)/10+extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");

    }
    
    if(lev > 1)
    {
        msg = HIY  "\n ���������ħ��\n" NOR;
        message_vision(msg,me,target);
        if(2*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIG "$N�Ӳ���ǧ�ع���þ�����ʽ���ң�\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)/8+2*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)/8+2*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)/8+2*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }
    
    if(lev > 2)
    {
    	target->start_busy(3);
        msg = HIW  "\n  �������������\n" NOR;
        message_vision(msg,me,target);
        if(3*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIC "$N�ƺ�������Χ���ǹ���񺿣�������Ҳ�����\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)/6+3*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)/6+3*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)/6+3*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }
    
    if(lev > 3)
    {
        msg = HIR  "\n   �������跭����\n" NOR;
        message_vision(msg,me,target);
        if(4*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIC "$Nֱ����Ѫ���ڣ�����Ż�£�\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)/4+4*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)/4+4*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)/4+4*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }
    
    if(lev > 4)
    {
        msg = HIB  "\n    �����������°�\n" NOR;
        message_vision(msg,me,target);
        if(5*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIY "$N�ٸ������޹⣬���ذ����ƺ�����Ҳ���ߵ���ͷ��\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)/2+5*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)/2+5*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)/2+5*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
  	}

    if(lev > 5)
    {
        msg =  HIC  "\n     �������軻���\n" NOR;
        message_vision(msg,me,target);
        if(6*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIW "�����ֻأ����컻��, $N�ٸд粽���У�\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)+6*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)+6*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)+6*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }

    if(lev > 6)
    {
    	target->add_temp("is_unconcious",1);
        msg = HIY  "\n      ��������Ѫ����\n" NOR;
        message_vision(msg,me,target);
        if(7*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIR "$Nɱ�����ǣ�Ѫɫ���죡\n" NOR,me);
			message_vision( HIR "$N�ľ��������ε����ѣ�\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)*2+7*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)*2+7*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)*2+7*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }

    if(lev > 7)
    {
        msg = HIW  "\n       ������������\n" NOR;
        message_vision(msg,me,target);
        if(8*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIC "$N��̬��ת��������죡\n" NOR,me);
			message_vision( HIG "$Nս��ȫ������ʶ������\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)*3+8*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)*3+8*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)*3+8*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }

    if(lev > 8)
    {
        msg = HIB  "\n        �����������\n" NOR;
        message_vision(msg,me,target);
        if(9*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIY "$N�����Ԫ�����ƾ����죡\n" NOR,me);
			message_vision( HIG "$N�������ޣ���������ս��\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)*4+9*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)*4+9*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)*4+9*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
  	}

    if(lev > 9)
    {
        msg = HIR  "\n         ����ʮ���񷿪\n" NOR;
        message_vision(msg,me,target);
        if(10*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIW "$N���쳤Х����嫲�񷣬Ϊ������, ���绽�꣬ˮ�����裡\n" NOR,me);
			message_vision( HIG "$N�������ܵ����ص����ˣ�����������\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)*5+10*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)*5+10*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)*5+10*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }
  	
  	me->add("str",-3*extra);
  	
  	if(lev > 6)
  	{
		target->add_temp("is_unconcious",-1);
  	}
  	
  	if(lev > 5)
  	{
  		lev = 5;	
  	}
  	
  	lev = lev - (me->query_skill("incarnation",1)+me->query_skill("literate",1))/300;
  	if(lev < 1)
  	{
  		lev = 1;	
  	}
  	
  	me->start_busy(lev);
  	
    me->add_temp("apply/attack",-extra*5);
    me->add_temp("apply/damage",-extra*10);
	return 1;
}
