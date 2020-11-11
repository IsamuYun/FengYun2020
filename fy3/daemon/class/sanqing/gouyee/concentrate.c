// concentrate.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
        int mana_gain,lv;

        if( target && target!=me )
                return notify_fail("���������ֻ�������ָ��Լ��ķ�����\n");

	lv = (int)me->query("concentrate");
	if (!lv)   me->set("concentrate",1);
	lv = (int)me->query("concentrate");

        if(amount == -1) amount = 100;
        else if(amount < 100 ) 
                return notify_fail("������һ�ٵ�������\n");

        if( (int)me->query("force") < amount )
                return notify_fail("�������������\n");

        	if ( random(100)+lv*5 >= 70) 
	{
        mana_gain =  (10 + (int)me->query_skill("gouyee",1))*amount/20;
        if( mana_gain + (int)me->query("mana") > (int)me->query("max_mana") )
                me->set("mana", (int)me->query("max_mana"));
        else
                me->add("mana", mana_gain);
        me->add("force", -amount);
        me->receive_damage("sen", 10);

        message_vision(
                HIY "$N��Ŀ�����ù����ķ���������ת��һ�Ρ��������...\n"
                "һ��������$N����ɢ���������$P�Ķ��ģ�Ȼ�Ỻ����ȥ��\n" NOR, me);
			if(me->query("concentrate") < (me->query("level")/10) && userp(me))
		{
		  me->add("concentrate_exp",1);
	      tell_object(me, "��ġ�������������һ�㼼�������ȡ�\n"NOR);
		  if(me->query("concentrate_exp") > (me->query("concentrate")*me->query("concentrate")*100)&&(me->query("concentrate")<10))
			{
			me->add("concentrate",1);
			me->set("concentrate_exp",0);
			tell_object(me, HIW"��ġ�����������������ˡ�\n"NOR);
			}
		}
	}
	else
		 tell_object(me, "���ڲ�����������ʩ�ŵ������ʧ���ˡ�\n"NOR);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}
 int help(object me)
{
        write(YEL"\n�����ķ�֮�������"NOR"\n");
	write(@HELP

      ����������幬�����ķ���ʹ�ú���Իָ���������

      �����ķ����ܵȼ�ÿ�������������ӻָ�������㡣
      ������ȼ�ÿ����һ�������Ӵ��еĳɹ���5%��

HELP
	);
	return 1;
}


