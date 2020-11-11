// written by tiandi
    
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
        string *liuxing = ({
HIR "流星卷！\n$N剑斜垂指河，湍流立即水花溅飞，剑尖指处空落了一片树叶！" NOR,
HIY "流星卷！\n$N剑横指新月，如千军万马，金兵齐呜！" NOR,
HIB "流星卷！\n$N的剑如雪，忽裂为二，左右两片雪光，斜斜地射向$n！" NOR,
HIG "流星卷！\n只见$N闭着双跟，手上两道白练，上下游走，迅若游龙，招招都是要害！" NOR
});
        string *tianya= ({
RED "天涯篇－－$N的刀身，“嗖”地逐然遽长，成了扫刀！" NOR,
YEL "天涯篇－－$N忽然抬头，目光如上，大喝，纵身而上，到了$n身前，一刀斫下去！！" NOR,
BLU "天涯篇－－$N按捺不住，一刀劈出！刀风霎时间布满了狭厌的空间。！" NOR,
HIM "天涯篇－－$N手中之刀，忽然变成了一支长矛。\n至于刀如何变成矛，则快如电光石火，无法瞧得清楚，一刹那，刀已变矛，矛已发出！"NOR 
});
        string *tianyaliuxing= ({
RED "天涯篇－－$N的刀身，“嗖”地逐然遽长，成了扫刀！" NOR,
HIR "流星卷！\n$N剑斜垂指河，湍流立即水花溅飞，剑尖指处空落了一片树叶！" NOR,
YEL "天涯篇－－$N忽然抬头，目光如上，大喝，纵身而上，到了$n身前，一刀斫下去！！" NOR,
HIY "流星卷！\n$N剑横指新月，如千军万马，金兵齐呜！" NOR,
BLU "天涯篇－－$N按捺不住，一刀劈出！刀风霎时间布满了狭厌的空间。！" NOR,
HIB "流星卷！\n$N的剑如雪，忽裂为二，左右两片雪光，斜斜地射向$n！" NOR,
HIM "【天涯流星】－－$N手中之刀，忽然变成了一支长矛。\n至于刀如何变成矛，则快如电光石火，无法瞧得清楚，一刹那，刀已变矛，矛已发出！"NOR 
HIW "【天涯流星】！！！\n只见$N闭着双跟，手上两道白练，上下游走，迅若游龙，招招都是要害！" NOR,
});


	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs,weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［天涯流星］只能对战斗中的对手使用。\n");
	
	if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("以你目前的状况，还没有资格用这一招。\n");
	if((int)me->query_skill("fallingstar-sword",1) < 50)
                return notify_fail("你的剑法实在太差了！\n");
	weapon = me->query_temp("weapon");
	
	if(pointerp(obs=me->query_team()) )
	{
	FLAG=1;
	for(i=0;i<sizeof(obs);i++)
	{
	if(obs[i] == me) continue;
	if(!obs[i]) {FLAG=0; continue;}
	if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
	if(!obs[i]->query_skill("tianya-blade")) {FLAG=0; continue;}
	if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
	if(ob->query("skill_type") != "blade"){FLAG=0; continue;}
	if(obs[i]->query_skill_mapped("blade") != "tianya-blade") {FLAG=0; continue;}
	}	
	if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("fallingstar-sword",1);
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/50;
	
	if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	skl_you=(int)you->query_skill("fallingstar-sword",1);
	extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/50;
        me->add_temp("apply/attack",(skl_you+skl_me));
        me->add_temp("apply/damage",(extra_you+extra_me)*4);
        you->add_temp("apply/attack",(skl_you+skl_me));
        you->add_temp("apply/damage",(extra_you+extra_me)*4);
        you->kill_ob(target);
	msg =HIY"\n$n眼见$N有退意，正要出手，$N陡然顿住，凌厉的剑气咄咄反逼了过来。\n这一下虽无半点声息，但胜过霹雳雷霆，$n在这电光石火的刹那间，徐进的脚步如遇铁壁，犹豫间反退了半步！\n就在这时，$N出手！一剑拦腰反斩，紫电穿云，势所无匹！\n"NOR;
	 message_vision(msg,me,target);
	for(i=0;i<sizeof(tianyaliuxing);i++)
	if(i%2) COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,tianyaliuxing[i]);
	else    COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR,tianyaliuxing[i]);
        me->add_temp("apply/attack",-(skl_you+skl_me));
        me->add_temp("apply/damage",-(extra_you+extra_me)*4);
        you->add_temp("apply/attack",-(skl_you+skl_me));
        you->add_temp("apply/damage",-(extra_you+extra_me)*4);
	}
	else
	{
        msg =HIY"$n眼见$N有退意，正要出手，$N陡然顿住，凌厉的剑气咄咄反逼了过来。\n这一下虽无半点声息，但胜过霹雳雷霆，$n在这电光石火的刹那间，徐进的脚步如遇铁壁，犹豫间反退了半步！\n就在这时，$N出手！一剑拦腰反斩，紫电穿云，势所无匹！\n"NOR;
	 message_vision(msg,me,target);
	 me->add_temp("apply/attack",skl_me/5);
        me->add_temp("apply/damage",extra_me/5);
        for(i=0;i<sizeof(liuxing);i++)
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,liuxing[i]);
        me->add_temp("apply/attack",-skl_me/5);
        me->add_temp("apply/damage",-extra_me/5);
	}	
	me->start_busy(4);
	return 1;
}
