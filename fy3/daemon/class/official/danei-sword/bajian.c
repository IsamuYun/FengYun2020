#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,hit,damage,okee,lv;
        object weapon;
        extra = me->query_skill("danei-sword",1);
        if ( extra < 50) return notify_fail("��Ĵ����ش��������������죡\n");
        if( !target ) target = offensive_target(me);
    hit = me->query_skill("danei-sword",1);
    damage = me->query_skill("leadership",1);
	lv = me->query("bajian");
	if (!lv)
		me->set("bajian",1);
	lv = me->query("bajian");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����°Խ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
if (me->query("force")< lv*100)
			 return notify_fail("�������������\n");

            me->add_temp("apply/attack",hit*2);
            me->add_temp("apply/damage",damage*2);
	weapon = me->query_temp("weapon");
	
	me->add("force", -lv*100);
        msg = HIY  "$N"HIY"ʹ�����ڽ����еģ����°Խ��ݣ����е�"+ weapon->name()+  HIY"�������磬��ʱ$n������˷����ǽ�Ӱ��\n��������ʵʵ����$n������ң�" NOR;

	okee= target->query("kee");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

            me->add_temp("apply/attack",-hit*2);
            me->add_temp("apply/damage",-damage*2);

	if(target->query("kee") < okee)
		{
		message_vision(HIB"$N��$n����Ҫ�������������½��ˣ�\n"NOR,target,me);
		if (!target->query_temp("bajian_minus_dodge"))
			{
       			target->add_temp("apply/dodge", - 100*lv);
        			target->set_temp("bajian_minus_dodge", 1);
			target->remove_call_out("remove_effect");
		        	seteuid(ROOT_UID);
			target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 100*lv :), extra/10);
					seteuid(getuid());
			}
		}
	if(me->query("bajian") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("bajian_exp",1);
	      tell_object(me, "��ġ����°Խ��������һ�㼼�������ȡ�\n"NOR);
		}
	  if(me->query("bajian_exp") > (me->query("bajian")*me->query("bajian")*100)&&(me->query("bajian")<MAX_PFMLEVEL))
		{
		me->add("bajian",1);
		me->set("bajian_exp",0);
	      tell_object(me, HIW"��ġ����°Խ����ȼ������ˡ�\n"NOR);
		}

        me->start_busy(2);
        return 1;
}
void remove_effect(object target, int amount)
{	
        target->add_temp("apply/dodge", amount);
        target->delete_temp("bajian_minus_dodge");
        message_vision(HIG"$N�����������ָ��ˡ�\n"NOR,target);
}
int help(object me)
{
        write(YEL"\n���ڽ���֮���°Խ���"NOR"\n");
	write(@HELP

      ����˵Ҳ֪����ֻ�г�͢����ʹ�õ�������һ��ʹ������������ͨ����Ҫ��һ����
      ������һ�����ʿ��Լ��ͶԷ�������������

      ����֮�����ܵȼ�ÿ����һ�������Ӵ����˺����㡣
      ���ڽ������ܵȼ�ÿ����һ�������Ӵ����������㡣
      ���°Խ��ĵȼ�ÿ����һ�����������ӶԵн�����������һ�ٵ㡣

HELP
	);
	return 1;
}
