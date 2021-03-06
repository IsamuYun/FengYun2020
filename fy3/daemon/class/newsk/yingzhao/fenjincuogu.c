//light@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int level;
        int orforce;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill_eff_lvl("yingzhaogong");
        level = me->query_skill("yingzhaogong",1);
        if ( level < 50) return notify_fail("你的大力鹰爪功还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［分筋挫骨手］只能对战斗中的对手使用。\n");
        me->add("force_factor",extra);
        orforce = (int) me->query("force");
        me->add("force",extra*2);
        me->add_temp("apply/attack",extra*2);
        me->add_temp("apply/damage",extra*2);
        weapon = me->query_temp("weapon");
        msg = HIR  "$N使出鹰爪功的绝技［分筋挫骨手］，一招连环四式向$n攻出！\n" NOR;
        message_vision(msg,me,target);
        msg = HIY  "[ 巧扣连环 ! ] \n$N左手一缩，右掌横劈便来拿$n的手腕，五指伸进$n身边，突然上翻，抓向$n的喉头！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "[ 笑语解颐 ! ] \n$N凝神不动，待到$n袭到胸口，身子略偏，左手拿敌手臂，右手暴起，抓向敌肋，搭上脸颊，向外急拉$n下颚关节！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "[ 壮士断腕 ! ] \n$N双手抖送，斜身一闪，伸手猛抓$n手腕，左手拿向$n肘部，前一送，下一扭，喀嚓一声，$n右腕关节立时脱出!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "[ 白蟒锁喉! ] \n$N右手在$n右肘上急拨，抢身上步，左臂已自$n右腑下穿入，左手反钩上来，同时右手拿向$n咽喉!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "$N身子微侧，左掌在右掌上一拍，右掌斜飞而出，一招[阴阳归一]，啪的一声重重的击向$n的小腹!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(2);
        me->set("force_factor",0);
        me->set("force", orforce);
        me->add_temp("apply/attack",-extra*2);
        me->add_temp("apply/damage",-extra*2);
return 1;
}

