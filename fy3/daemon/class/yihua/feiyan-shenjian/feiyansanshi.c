// xgchen@fy 2002
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        extra = me->query_skill("feiyan-sword",1);
        if ( extra < 200) return notify_fail("你的［飞燕三式］还不够纯熟！\n");
      if (me->query("family/master_name")!="燕南天") 
          return notify_fail("你的［飞燕三式］还不够纯熟！\n");
         if ( me->query("force") < 500) return notify_fail("你的内力还不够纯熟！\n");
       if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[飞燕三式]只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("[飞燕三式]能是要剑才可以发出绝技！\n");
        if( (string)weapon->query("skill_type") != "sword")
        return notify_fail("[飞燕三式]能是要剑才可以发出绝技！\n");
        if ( (string) me->query_skill_mapped("sword") != "feiyan-sword")
        return notify_fail("[飞燕三式]能是要剑才可以发出绝技！\n");
        me->add_temp("apply/attack", extra*extra);    
        me->add_temp("apply/damage", extra*extra);
       if (target->query("max_kee") >= target->query("kee"))
{               target->add("eff_kee",-target->query("eff_kee")/(random(7)+1));}
       if (me->query("eff_kee")>2000)
{               me->add("eff_kee",-me->query("eff_kee")/8);}
        msg = HIR  "\n$N突然将手中的"+ weapon->name() +HIR"往右手刺去，右手鲜血狂喷！\n\n左手挥剑，卷起血浪使出飞燕绝招击向$n！\n\n"BLINK+"                 飞燕同归\n"NOR"\n$n受到极其严重的伤害。" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra*extra);    
        me->add_temp("apply/damage", -extra*extra);
        me->start_busy(4);
        return 1;
}

int help(object me)
{
        write(WHT"\n飞燕三式："NOR"\n");
        write(@HELP
        飞燕三式，是燕南天创就出来，专门对付移花功的，可惜他还没有练成
        却已经被移花宫猪所伤，此剑法极其难练，但是又厉害无比，能学80级
       就可以发出绝技。此剑法看上去平淡无奇，不懂其中奥妙，决难学成，
       因为燕南天已经残废了，所以就是小鱼儿那么聪明的人，也没有去学
       此剑法据闻尚未有人学会。
        
        绝技要求：      (学）秘密；
                          （用）内力 500 以上；      
                                 等级 80 以上;
HELP
        );
        return 1;
}
