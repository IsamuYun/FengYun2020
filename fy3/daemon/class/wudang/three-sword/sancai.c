#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int i,hit,damage;
	string *style = ({
HIY"��ʱ����$N����һ��,�ն�����$w������һ��������$n��$l��"NOR,
HIR"��������$N��ǰһ��������$w������Ӱ���أ���$n����Χס��"NOR,
HIB"�˺ͣ���$N������һ��������$w��Ȼһ����ָ��$n��$l��"NOR,
HIM"����ˣ������и����紩��������˲�佻����λ�ã������ܲ����ִ�$n�ĸ���Ҫ����\n"NOR});
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����Ź�һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("ֻ�ж�������ſ��Է�����ʽ��\n");
            if(sizeof(obs) != 3 )
		return notify_fail("�������Ҫ�����ˣ���\n");
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("����Ҫ������϶��顣\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("������Ա��ȫ������ߡ�\n");
	if(obs[i]->query_skill("three-sword")<20) return notify_fail("��������������Ž����ȼ�̫�͡�\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("��Ķ���������û�б�����\n");
	if(ob->query("skill_type") != "sword") return notify_fail("��Ķ���������û���ý�����\n");
	if(obs[i]->query_skill_mapped("sword") != "three-sword") return notify_fail("��Ķ���������û�������Ž�����\n");
	if(!obs[i]->query("sancai")) obs[i]->set("sancai",1);
	if(obs[i]->query("sancai") *100 > obs[i]->query("force"))  return notify_fail("��Ķ�������������������\n");
	}	
	message_vision(HIM+"\n\n$N�ߺ�һ�����죭���أ����ˣ������Ź�һ������ʱ���������Ž���\n"+style[3],me,target);
	for(i=0;i<3;i++)
        {
	ob=obs[i]->query_temp("weapon");
	msg =  style[i];
	hit = obs[i]->query_skill("literate",1);
	damage = obs[i]->query("sancai");
        obs[i]->add_temp("apply/attack", hit);
        obs[i]->add_temp("apply/damage", 200*damage);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	obs[i]->kill_ob(target);	
	obs[i]->add_temp("apply/attack", -hit);
	obs[i]->add_temp("apply/damage", -200*damage);
       obs[i]->add("force", -100*damage);
	obs[i]->start_busy(2);
	}
	if(me->query("sancai") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("sancai_exp",1);
	      tell_object(me, "��ġ����Ź�һ�������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("sancai_exp") > (me->query("sancai")*me->query("sancai")*100))&&(me->query("sancai")< MAX_PFMLEVEL))
		{
		me->add("sancai",1);
		me->set("sancai_exp",0);

	      tell_object(me, HIW"��ġ����Ź�һ���ȼ������ˡ�\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n���Ž������Ź�һ��"NOR"\n");
	write(@HELP

       ���Ž�������̫��ȭΪ������չ�����ļӷ�����̫��ȭһ�������Ծ��ƶ���
       �����ˣ�ÿһ�ж�����̫��ʽ�������仯�����Ź�һ�����Ž����Ľ���
       ������Ҫ����ͬʱ��ϲ��ܷ��������������������˶���Ҫ�и���Ľ�
       �������һ��ʩչ�������������
	
      ����ʶ�ּ��ܵȼ�ÿ����һ�������Ӵ�������һ�㡣
      ���Ź�һ�ȼ�ÿ����һ�������Ӵ����˺����ٵ㡣
HELP
	);
	return 1;
}
