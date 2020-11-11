// animate.c
#include <ansi.h>
inherit F_CLEAN_UP;

int cast(object me, object target)
{
	  int lv;
	 lv = (int)me->query("animate");
	if (!lv)   me->set("animate",1);
	lv = (int)me->query("animate");

        if( me->is_fighting() ) 
		return notify_fail("������ս���У�\n");
        
        if( (int)me->query_skill("spells") < 100)
		return notify_fail("��ķ��������ߣ�\n");

        if( !target || !target->is_corpse() ) 
        	return notify_fail("��Ҫ������һ��ʬ�壿\n");
        
        if( (int)me->query("mana") < 100*lv)
		return notify_fail("��ķ��������ˣ�\n");

        message_vision(
	"$N�������ϵ�$n�૵����˼������$n�鴤�˼��¾�վ��������\n", me, target);

        target->animate(me, (int)me->query_skill("spells")+(int)me->query_skill("spells")/10*lv);
        me->add("mana", -100*lv);
        me->receive_damage("sen", 10);
				if(me->query("animate") < (me->query("level")/10) && userp(me))
	{
        me->add("animate_exp",1);
	      tell_object(me,"��ġ���ʬ�䡿�����һ�㼼�������ȡ�\n"NOR);
	  if(me->query("animate_exp") > (me->query("animate")*me->query("animate")*100)&&(me->query("animate")<10))
		{
		me->add("animate",1);
		me->set("animate_exp",0);
	      tell_object(me, HIW"��ġ���ʬ�䡿���������ˡ�\n"NOR);
		}
	}
        return 1;
}
 int help(object me)
{
        write(YEL"\n�������֮��ʬ��"NOR"\n");
	write(@HELP

     ������ʬ���Ϊ��ʬ����ʬ�������ߵ�����Ϊʳ��

     ��ʬ��ÿ����һ�������ӽ�ʬ�ĸ�������1/10��

HELP
	);
	return 1;
}
 
