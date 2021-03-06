// mouse@skills
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        extra = me->query_skill("dragon-blade",1);
        if ( extra < 40) return notify_fail("你的［伏龙刀法］还不够纯熟！\n");
        extra = me->query_skill("dragon-steps",1);
        if ( extra < 40) return notify_fail("你的［御龙幻步］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[ 幻世金龙 ]只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("幻世金龙只能和伏龙刀法配和！\n");
        if( (string)weapon->query("skill_type") != "blade" )
        return notify_fail("[ 幻世金龙 ]只能和伏龙刀法配和！\n");
        if ( (string) me->query_skill_mapped("blade") != "dragon-blade")
        return notify_fail("[ 幻世金龙 ]只能和伏龙刀法配和！\n");
        extra = me->query_skill("dragon-blade",1) / 10;
        extra += me->query_skill("dragon-steps",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIY  "$N脚踩［御龙幻步］，施展［伏龙刀法］中的绝技－－幻世金龙，手中的"+ weapon->name() +"化作一道金龙砍向$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "刀光霍霍，摄人心志．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIG "$N以刀化龙，人龙共舞！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);

        msg =  HIW "刀光霍霍，摄人心志．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIC "$N翻刀伏龙，人御龙去！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "刀光霍霍，摄人心志．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIY "$N御龙回刀，人龙共现！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -extra);   
        me->add_temp("apply/damage", -extra);
        me->start_busy(4);
        return 1;
}