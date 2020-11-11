// yiru@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg, type;
    int extra, str;
    int force, force_factor, flag;
    object weapon;

    if( !target ) target = offensive_target(me);

    if( !target 
      || !target->is_character()
      || !me->is_fighting(target) )
        return notify_fail(HIC"七决剑气"NOR"只能对战斗中的对手使用。\n");

    weapon = me->query_temp("weapon");
    if (!weapon) 
        type = "unarmed";
    else
        type = weapon->query("skill_type");

    if ( (string) me->query_skill_mapped(type) != "seven-gest")
        return notify_fail("你目前使用的外功不是七决剑气！\n");

    if ( (string) me->query_skill_mapped("force") != "seven-gest")
        return notify_fail("你目前使用的内功不是七决剑气！\n");

    force = me->query("force");
    force_factor = me->query("force_factor");
    if( force < 700+force_factor )
        return notify_fail("你的内力不够了，无法使出"HIC"七决剑气"NOR"！\n");

    extra = me->query_skill("seven-gest",1);
    if( extra < 140 )
        return notify_fail("你的七决剑气还不够纯熟！\n");

    msg = HIW "\n$N使出林家堡武功的精髓，指尖聚起一股内力，将七决剑气一气呵成！\n" NOR;

    // 检测步伐
    flag = me->query_skill("tiannan-step",1);
    if (me->query_skill_mapped("dodge") != "tiannan-step" )
    {
        flag=0;
        }
        
    if( flag > 250)
    {
        msg = HIR "$N脚踏林家堡独有的天南步法，同时使出林家堡武功的精髓，\n"
        "指尖聚起一股内力，将七决剑气一气呵成！\n" NOR;
        target->start_busy( flag/250 );
    }

    message_vision(msg, me, target);
    
    str = extra/3;
    
    if(type == "unarmed")
    {
        me->add("str",str);
    }
    else
    {
        me->add_temp("apply/damage", extra*2);
        me->add_temp("apply/attack", extra*2);
    }

    msg = HIC "「直劈」！\n$N手腕急振，指尖内力如枪直击，攻向$n的胸膛。" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"瘀伤");
    
    msg = HIY "「剑气」！\n$N单臂一挥，一道剑气自左而右划向$n的腿部。" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"瘀伤");

    msg = HIM "「气剑指」！\n$N振臂一举，数道剑气从四面八方袭来，$n几乎都辩不明方向。" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"瘀伤");

    msg = HIB "「气剑斩」！\n$N双手急舞，双手聚出一股内劲破土而过，排山倒海般扫向$n下盘。" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"瘀伤");
    
    msg = HIC "「半月斩」！\n$N忽的向前一跃，以不可思意的角度划向$n前方。" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"瘀伤");

    me->add("str",str);

    msg = HIY "「弦月斩」！\n$N力贯指尖，气出无形, 突然从$n身后袭来, 锐不可当, 防不胜防。" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"瘀伤");

    me->add("str",str);
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);

    msg = HIW "「横扫千军」！\n$N如山而立，以地裂天崩之势凌空扫向$n。" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"瘀伤");

        me->add("str",-2*str);
        me->add_temp("apply/damage", -extra);
        me->add_temp("apply/attack", -extra);

    if(type == "unarmed")
    {
                me->add("str",-str);
    }
    else
    {
        me->add_temp("apply/damage", -extra*2);
        me->add_temp("apply/attack", -extra*2);
    }

    me->set("force",force-700);

    if( flag > 250 )
    {
        me->start_busy(1);
        }
        else if( flag > 150 )
        {
                me->start_busy(3);
        }
        else
        {
                me->start_busy(5);
        }
        
    return 1;
}

