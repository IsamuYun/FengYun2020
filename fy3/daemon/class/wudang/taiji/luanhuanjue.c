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
                return notify_fail("［乱环决］只能对战斗中的对手使用。\n");
	if (!me->query("luanhuanjue"))
		me->set("luanhuanjue",1);
	lv = me->query("luanhuanjue");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("taiji",1) ;
        if( extra <=20) return notify_fail("你的[太极拳]还不够熟练！\n");
      if( (int)me->query("force") < 100*lv )     return  notify_fail("你的内力不够。\n");
        hit = me->query_skill("literate",1);
        me->add_temp("apply/attack", hit/5);  
        me->add_temp("apply/damage", extra/5);
	me ->add("force",-100*lv);
        msg = HIR  "$N左手连划数圈，逼开$n的攻势，右手突然攻向$n!" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
            if( lv >2) {
            me->add_temp("apply/attack", hit/5);
            me->add_temp("apply/damage", extra/5);
       msg = HIR  "$N不等上一招用老,右手连划数圈，逼开$n的攻势，左手突然攻向$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
            me->add_temp("apply/attack", -hit/5);
           me->add_temp("apply/damage", -extra/5);
            }
            if( lv >4) {
       me->add_temp("apply/attack", hit);
            me->add_temp("apply/damage", extra);
            msg = HIY  "$N身行晃动,左右手同时连划数圈，把$n一带，左肩却猛撞$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -hit);
        me->add_temp("apply/damage", -extra);
       }
            if( lv >6) {
       me->add_temp("apply/attack", hit*2);
            me->add_temp("apply/damage", extra*2);
            msg = HIY  "$N左右手连忙收回来，接着慢慢推出，把$n一带，右肩却猛撞$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -hit*2);
        me->add_temp("apply/damage", -extra*2);
       }
            if( lv >8) {
       me->add_temp("apply/attack", hit*3);
            me->add_temp("apply/damage", extra*3);
 msg = HIB  "$N身影微动，双拳下垂,终极太极无影拳的拳气向$n逼去！" NOR;
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
	      tell_object(me, "你的【乱环诀】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("luanhuanjue_exp") > (me->query("luanhuanjue")*me->query("luanhuanjue")*100))&&(me->query("luanhuanjue")< MAX_PFMLEVEL))
		{
		me->add("luanhuanjue",1);
		me->set("luanhuanjue_exp",0);

	      tell_object(me, HIW"你的【乱环诀】等级上升了。\n"NOR);
		}

	return 1;
}

int help(object me)
{
        write(YEL"\n太极拳乱环诀："NOR"\n");
        write(@HELP

       太极拳为武当派的开山祖师张三丰所首创，跟自来武学之道全然不同，讲
       究以静制动、后发制人，每一招都含着太极式的阴阳变化，精微奥妙，实
       是开辟了武学中从所未有的新天地。
             乱环术法最难通，上下随合妙无穷。
             陷敌深入乱环内，四两能拨千斤动。
             手脚齐进竖找横，掌中乱环落不空。
             欲知环中法何在，发落点对即成功。
        这乱环诀是太极拳的顶级武功，所谓乱环，便是说拳招虽有定型，变化却
        存乎其人。到底发挥多大的威力，就看自己的造化了。
        
            
            读书识字技能影响此招的命中。
            太极拳技能等级影响此招的伤害。
            乱环诀每提升两级，增加出招次数。
HELP
        );
        return 1;
}


