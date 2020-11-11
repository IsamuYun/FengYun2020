// snake_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int a1 = 0;
	int a2 = 0;
	int exp = 0;
	
	me->receive_wound("kee", 550);
    me->receive_wound("sen", 350);
    if(!random(8) && userp(me))
    {
		a1 = (int)me->query("int");
		a2 = (int)me->query("spi");
		exp = (int)me->query("combat_exp");
		if(a1 > 1)
		{
			me->set("int" , a1-1);
		}
		if(a2 > 1)
		{
			me->set("spi" , a2-1);
		}		
		if(exp > 100000)
		{
			me->set("combat_exp" , exp-3000);
		}				
		me->skill_death_penalty();
	}	
	me->apply_condition("demon", duration - 1);
    if( duration < 1 )
    {
		tell_object(me, HIW "�������Լ�ǿ�ޱȵ���־�˷���������ħ��\n" NOR );
		return 0;
	}
	else
	{
		tell_object(me, HIC "ħӰ���أ�����׳ʣ������ħ�������������ˣ�\n" NOR );
	}

	return CND_CONTINUE;
}
