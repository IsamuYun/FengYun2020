	// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill,lv;
		lv = (int)me->query("daoqiangburu");
		if (!lv)
			me->set("daoqiangburu",1);
		lv = (int)me->query("daoqiangburu");

        if( target != me ) return 
	notify_fail("��ֻ�ܽ��۵�ǹ����������Լ������ϡ�\n");
        if( (int)me->query("force") < 50*lv )     return
        notify_fail("�������������\n");
        if( (int)me->query_temp("daoqian") ) return 
	notify_fail("���Ѿ���ʩչ�۵�ǹ������ˡ�\n");
	skill = me->query_skill_eff_lvl("jin-gang");
	if(skill < 100) return notify_fail("��Ľ�ղ�����̫���ˣ�\n");
	skill = random(skill/2)+skill/2;
	me->add("force", -100*lv);
        message_vision( HIR
"$N�������ظ����߽��ţ�����ǹ���룡��ǹ���룡��ǹ���룡��������\n" NOR, me);
		write ("����ʱ������"+skill/10*(lv+1)+"���������ȼ���\n");
        me->add_temp("apply/iron-cloth", skill/10*(lv+1));
        me->set_temp("daoqian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/10*(lv+1) :), lv*20);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/iron-cloth", - amount);
        me->delete_temp("daoqian");
        tell_object(me, "��ģ۵�ǹ����ݵĹ�Чɢ���ˡ�\n");
		me->add("daoqiangburu_exp",1);
	    tell_object(me, "��ġ���ǹ���롿�����һ�㼼�������ȡ�\n"NOR);
	    if(me->query("daoqiangburu_exp") > (me->query("daoqiangburu")*me->query("daoqiangburu")*100)&&(me->query("daoqiangburu")<10))
		{
		me->add("daoqiangburu",1);
		me->set("daoqiangburu_exp",0);
	      tell_object(me, HIW"��ġ���ǹ���롿���������ˡ�\n"NOR);
		}
}
 int help(object me)
{
        write(YEL"\n��ղ�����֮��ǹ���룺"NOR"\n");
	write(@HELP

      ����ʹ�ú��ڲ��Ʒ�������¿�����ɷ����˺���

      ��ǹ����ȼ�ÿ����һ�������Ӵ���Ӳ���ӳ�һ�ɣ��ӳ�����ʱ���ʮ�롣

HELP
	);
	return 1;
}

