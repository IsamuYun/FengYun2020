#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,hit,damage,lv;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���һ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!me->query("luanhuanjue"))
		me->set("luanhuanjue",1);
	lv = me->query("luanhuanjue");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("taiji",1) ;
        if( extra <=20) return notify_fail("���[̫��ȭ]������������\n");
      if( (int)me->query("force") < 100*lv )     return  notify_fail("�������������\n");
        hit = me->query_skill("literate",1);
        me->add_temp("apply/attack", hit/5);  
        me->add_temp("apply/damage", extra/5);
	me ->add("force",-100*lv);
        msg = HIR  "$N����������Ȧ���ƿ�$n�Ĺ��ƣ�����ͻȻ����$n!" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
            if( lv >2) {
            me->add_temp("apply/attack", hit/5);
            me->add_temp("apply/damage", extra/5);
       msg = HIR  "$N������һ������,����������Ȧ���ƿ�$n�Ĺ��ƣ�����ͻȻ����$n��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
            me->add_temp("apply/attack", -hit/5);
           me->add_temp("apply/damage", -extra/5);
            }
            if( lv >4) {
       me->add_temp("apply/attack", hit);
            me->add_temp("apply/damage", extra);
            msg = HIY  "$N���лζ�,������ͬʱ������Ȧ����$nһ�������ȴ��ײ$n��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -hit);
        me->add_temp("apply/damage", -extra);
       }
            if( lv >6) {
       me->add_temp("apply/attack", hit*2);
            me->add_temp("apply/damage", extra*2);
            msg = HIY  "$N��������æ�ջ��������������Ƴ�����$nһ�����Ҽ�ȴ��ײ$n��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -hit*2);
        me->add_temp("apply/damage", -extra*2);
       }
            if( lv >8) {
       me->add_temp("apply/attack", hit*3);
            me->add_temp("apply/damage", extra*3);
 msg = HIB  "$N��Ӱ΢����˫ȭ�´�,�ռ�̫����Ӱȭ��ȭ����$n��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -hit*3);
        me->add_temp("apply/damage", -extra*3);
      
}
       me->add_temp("apply/attack", -hit/5);
        me->add_temp("apply/damage", -extra/5);
        me->start_busy(4);
	if(me->query("luanhuanjue") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("luanhuanjue_exp",1);
	      tell_object(me, "��ġ��һ����������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("luanhuanjue_exp") > (me->query("luanhuanjue")*me->query("luanhuanjue")*100))&&(me->query("luanhuanjue")< MAX_PFMLEVEL))
		{
		me->add("luanhuanjue",1);
		me->set("luanhuanjue_exp",0);

	      tell_object(me, HIW"��ġ��һ������ȼ������ˡ�\n"NOR);
		}

	return 1;
}

int help(object me)
{
        write(YEL"\n̫��ȭ�һ�����"NOR"\n");
        write(@HELP

       ̫��ȭΪ�䵱�ɵĿ�ɽ��ʦ���������״�����������ѧ֮��ȫȻ��ͬ����
       ���Ծ��ƶ��������ˣ�ÿһ�ж�����̫��ʽ�������仯����΢���ʵ
       �ǿ�������ѧ�д���δ�е�����ء�
             �һ���������ͨ��������������
             �ݵ������һ��ڣ������ܲ�ǧ�ﶯ��
             �ֽ�������Һᣬ�����һ��䲻�ա�
             ��֪���з����ڣ������Լ��ɹ���
        ���һ�����̫��ȭ�Ķ����书����ν�һ�������˵ȭ�����ж��ͣ��仯ȴ
        ������ˡ����׷��Ӷ����������Ϳ��Լ����컯�ˡ�
        
            
            ����ʶ�ּ���Ӱ����е����С�
            ̫��ȭ���ܵȼ�Ӱ����е��˺���
            �һ���ÿ�������������ӳ��д�����
HELP
        );
        return 1;
}


