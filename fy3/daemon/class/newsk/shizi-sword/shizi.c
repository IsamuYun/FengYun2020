// light@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int level;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill_eff_lvl("shizi-sword");
        level = me->query_skill("shizi-sword",1);
        if ( level < 50) return notify_fail("你的十字剑法还不够纯熟！\n");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［十字剑法］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        me->add_temp("apply/attack", extra*2);  
        me->add_temp("apply/damage", extra*2);
        msg = HIR "$N突然神情有了变化，面目狰狞，状若疯狂，使出师门绝学-疯-狂-十-字-斩-砍向$n ！\n
            ._z@@,
              ~@CL
      @]@@@@~~~@@@~~@@@@@
       @[ ___       __
   ~;@@]@`@@~~~~~~~-@@P
       @[ @[ 4@L ]a@@@
   ;;@@]@ ]@ `~@L@@~@@
  ~'  @[  @@   O@@, @@,
     .d@.d@r._a~~~@_]@@
    @[d_d@@r`~~'   `~ ]@@@zzz,
  ~~~ ~~~`            ~~~~~` 
"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIR  "
        _
     _  `@] ___    ___
     `]@ [@ @@@~~~@@@@ 
       ]@]     [@@@
     @]@[    __ @@__
   _@] ]@`   @@~-@@@P
       @[]      @]
    @]@]@       [@
  _@]  @[  ____ @]  ___
     .d@.  @@@@~~~~~@@@@
    @[d
 

"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);

msg = HIR  "
            ___
             @@
             @@
             @@_z@@@@
     __aaa@@@@@@@~~~~
      ~~ ~~~ @@ 
             @@
             @@
             @@
             @@     
             @@
             %

"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);

msg = HIR  "

           ._z@@,
       ___   ~@CL
       ~@@~~~~~`~~~~@@b
       ~[  ___   __   ]~
           @@~~~~@] 
                @}
       ___     P    __ 
        @@@@~~~@]~~~@@P
                @]
               [@
           ~a [@b
             [@@

"NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);

msg = HIR  "
                   )z_
        `azL      .d@
       __a@@_  _d@
    _z@@@@Lz~ @@   ___ _
      ]@ @@   [@@~~~@@VV
   ._d@~@@@a@v@]   ][   
    ~~~@ @@~ _[@   @] 
      a@@@a@@V@]   @[
    _d@~@@~` d@    @]
         @@_d@     @[
         @@        ],
         ~         %

只见剑光闪闪，劈刺截扫，斩削砍剁，$N越斗越是凌厉！" NOR;
        
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -extra*2);
        me->start_busy(2);
        return 1;
}

