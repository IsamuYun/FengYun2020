// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,kee;
	int orforce,hit,damage,lv;
	object weapon;
	lv = (int)me->query("kaitianpidi");
	if (!lv)
		me->set("kaitianpidi",1);
	lv = (int)me->query("kaitianpidi");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
    extra = me->query_skill("pangu-hammer",1);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("str");
    if ( extra < 30) return notify_fail("����̹ž�ʽ��������ʮ����\n");
    if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ۿ���ٵأ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	kee = 0;
	orforce = (int) me->query("force");
	if (orforce < lv*30)
		return notify_fail("����������㡣\n");
    me->add_temp("apply/attack",extra/2 + lv*100);
    me->add_temp("apply/damage",extra/2 + lv*100);
	weapon = me->query_temp("weapon");
	me->add("force", -lv*30);
	msg = HIY  "$N�������е�"+weapon->name()+HIY"�Կջ���һ��ԲȦ,��$N�Ĳ�ͣ�趯��,��Χ�ķ綼��£����һ��.\n$N����$n���һ��:����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack",- extra/2 - lv*100);
    me->add_temp("apply/damage",- extra/2 - lv*100);
	kee =1;
	if (extra > 59 && random(extra*lv)>40 && kee==1)
	{
		orforce = (int) me->query("force");
		if (orforce < lv*60)
			return notify_fail("�����������ʹ�õڶ��С�\n");
	me->add_temp("apply/attack",extra + lv*150);
    me->add_temp("apply/damage",extra + lv*150);
	weapon = me->query_temp("weapon");
	me->add("force", -lv*60);
	msg = HIB  "$N�Ƶ�$n�Ҳ�,"+weapon->name()+HIB"����ͣЪ,��$n���Ͼ���һ��,����$n�������ֲ���.\n�죡" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack",- extra - lv*150 );
    me->add_temp("apply/damage",- extra - lv*150);
	kee =2;
	}
	if (extra > 89 && random(extra*lv)>55 && kee==2)
	{
		orforce = (int) me->query("force");
		if (orforce < lv*90)
			return notify_fail("�����������ʹ�õ����С�\n");
	me->add_temp("apply/attack",extra*2 + lv*200);
    me->add_temp("apply/damage",extra*2 + lv*200);
	weapon = me->query_temp("weapon");
	me->add("force", -lv*90);
	msg = HIC  "$N��ȻһԾ����,�̾����,"+weapon->name()+HIC"����������������ɫ�Ĺ�â,����չ�������$n.\n�٣�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack",- extra*2 - lv*200);
    me->add_temp("apply/damage",- extra*2 - lv*200);
	kee =3;
	}
	if (extra > 119 && random(extra*lv)>70 && kee==3)
	{
		orforce = (int) me->query("force");
		if (orforce < lv*120)
			return notify_fail("�����������ʹ�õ����С�\n");
	me->add_temp("apply/attack",extra*3 + lv*300);
    me->add_temp("apply/damage",extra*3 + lv*300);
	weapon = me->query_temp("weapon");
	me->add("force", -lv*120);
	msg = HIW  "$N��Ȼ����,����"+weapon->name()+HIW"��ÿ�����,��$n�޷�����$N��һ���Ķ���.���ڴ˿�,$N�����һ������ʹ�˳���.\n�أ�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack",- extra*3 - lv*300);
    me->add_temp("apply/damage",- extra*3 - lv*300);
	kee = 4;
	}
	if(me->query("kaitianpidi") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("kaitianpidi_exp",1);
	      tell_object(me, "��ġ�����ٵء������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("kaitianpidi_exp") > (me->query("kaitianpidi")*me->query("kaitianpidi")*100))&&(me->query("kaitianpidi")< MAX_PFMLEVEL))
		{
		me->add("kaitianpidi",1);
		me->set("kaitianpidi_exp",0);

	      tell_object(me, HIW"��ġ�����ٵء��ȼ������ˡ�\n"NOR);
		}
	me->start_busy(kee+1);
	return 1;
}
int help(object me)
{
	int extra,lv;
	extra = me->query_skill("pangu-hammer",1);
	lv = me->query("kaitianpidi");
        write(YEL"\n�̹ž�ʽ֮����ٵأ�"NOR"\n");
	write(@HELP

      �촸ɽׯ���ռ�ɱ�У�������ʽ,��Ҳ��Ҫ���¹�ͨ����ʹ��������
HELP
	);
	write("\t��ǰ״̬�����������˺��ӳɵ�һ��"+(int)(extra/2+100*lv)+"��,�ڶ���"+(int)(extra+150*lv)+"��,������"+(int)(extra*2+200*lv)+"��,������"+(int)(extra*3+300*lv)+"��.\n\n.");
	
	write(@HELP
	  �̹ž�ʽ�ȼ�ÿ����һ��,���Ӵ������������˺�.
      ����ٵصȼ�ÿ����һ����������һ��ʽ�ĳ����ʡ�

HELP
	);
	return 1;
}
