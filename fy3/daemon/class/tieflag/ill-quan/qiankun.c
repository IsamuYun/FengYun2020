#include <ansi.h>
#include <combat.h>
inherit SSERVER;
static object *enemy = ({});
int perform(object me, object target1,object target2)
{
      	string msg;                                
        int extra,lv;
	object weapon;
	lv = me->query("qiankun");
	if (!lv)  me->set("qiankun",1);
	lv = me->query("qiankun");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("ill-quan",1);
	if ( extra < 50) return notify_fail("��Ĳ�άĦȭ���������죡\n");
	enemy=me->query_enemy();
        if (sizeof(enemy)<2) return notify_fail("�����ͬʱ���������ϵĵ���ս������ʹ��Ǭ��Ų�ƣ�\n");
        if( !target1 && target2) return notify_fail("�����ͬʱָ����������\n");
        if( !target2 && target1) return notify_fail("�����ͬʱָ����������\n");
	if(!target1 && !target2)
        {
           target1=enemy[0];
           target2=enemy[1];
         }
        if( !target1 || !target2
	||	!target1->is_character() || !target2->is_character()
	||	!me->is_fighting(target1) || !me->is_fighting(target2))
		return notify_fail("��Ǭ��Ų�ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (me->query("force")<=100*lv) return notify_fail("����������㣬�޷��������˹��ƣ�\n");
        me->add("force",-100*lv);
        message_vision(HIY"\n$Nʹ����άĦȭ�Ĳ���֮�ء�Ǭ��Ų�ơ�,��ͼʹ���ֻ�����ɱ��\n"NOR,me);
        me->start_busy(2);
        weapon = target1->query_temp("weapon");
        if (random(extra/10)+lv>target1->query("level")/2)
        {
          message_vision(HIY "$N���ִ���$n�Ĺ��ƣ�ʹ֮����"+target2->name()+"��\n" NOR,me,target1);
          COMBAT_D->do_attack(target1,target2, weapon);  
          target1->receive_damage("kee",0,me);
          target1->start_busy(1);
        }
        else
        {
          message_vision("��$n����$N����ͼ�����Ʒ���������\n",me,target1);
          COMBAT_D->do_attack(target1,me,weapon);
        }
        weapon = target2->query_temp("weapon");
        if (random(extra/10)+lv>target2->query("level")/2)
        {
          message_vision(HIY "\n$N���ִ���$n�Ĺ��ƣ�ʹ֮����"+target1->name()+"��\n" NOR,me,target2);
          COMBAT_D->do_attack(target2,target1, weapon);  
          target2->receive_damage("kee",0,me);
          target2->start_busy(1);
        }
        else
        {
          message_vision("\n��$n����$N����ͼ�����Ʒ���������\n",me,target2);
          COMBAT_D->do_attack(target2,me,weapon);
        }

	 	 me->add("qiankun_exp",1);
	      tell_object(me, "��ġ�Ǭ��Ų�ơ������һ�㼼�������ȡ�\n"NOR);
	  if((me->query("qiankun_exp") > (me->query("qiankun")*me->query("qiankun")*100))&&(me->query("qiankun")< MAX_PFMLEVEL))
		{
		me->add("qiankun",1);
		me->set("qiankun_exp",0);

	      tell_object(me, HIW"��ġ�Ǭ��Ų�ơ��ȼ������ˡ�\n"NOR);
		}

     	return 1;
}
int help(object me)
{
        write(YEL"\n��άĦȭ֮Ǭ��Ų�ƣ�"NOR"\n");
	write(@HELP
      Ǭ��Ų�ƿ��Խ���Ŀǰ��Ŀ��һ�Ĺ�������Ŀ�����
      
     ��άĦȭ�ĵȼ�ÿ����һ�������Ӵ��еĳɹ��ʡ�
     Ǭ��Ų��ÿ����һ�������Ӵ��еĳɹ��ʡ�

HELP
	);
	return 1;
}

