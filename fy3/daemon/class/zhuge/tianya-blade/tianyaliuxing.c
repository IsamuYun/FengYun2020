// written by tiandi
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me,object target)
{
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
HIR "流星卷！\n$N剑斜垂指河，湍流立即水花溅飞，剑尖指处空落了一片树叶！"NOR,
RED "天涯篇－－$N的刀身，“嗖”地逐然遽长，成了扫刀！" NOR,
HIY "流星卷！\n$N剑横指新月，如千军万马，金兵齐呜！" NOR,
YEL "天涯篇－－$N忽然抬头，目光如上，大喝，纵身而上，到了$n身前，一刀斫下去！！" NOR,
HIB "流星卷！\n$N的剑如雪，忽裂为二，左右两片雪光，斜斜地射向$n！" NOR,
BLU "天涯篇－－$N按捺不住，一刀劈出！刀风霎时间布满了狭厌的空间。！" NOR,
HIW "【天涯流星】！！！\n只见$N闭着双跟，手上两道白练，上下游走，迅若游龙，招招都是要害！" NOR,
HIM "【天涯流星】－－$N手中之刀，忽然变成了一支长矛。\n至于刀如何变成矛，则快如电光石火，无法瞧得清楚，一刹那，刀已变矛，矛已发出！"NOR 
});
	string msg;
	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs,weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		  return notify_fail("［天涯流星］只能对战斗中的对手使用。\n");
	if((int)me->query_skill("tianya-blade",1) < 50)
                return notify_fail("你的刀法实在太差了！\n");
	if( me->query("TASK") < 1500  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("以你目前的状况，还没有资格用这一招。\n");
	weapon = me->query_temp("weapon");
	
	if(pointerp(obs=me->query_team()) )
	{
	FLAG=1;
	for(i=0;i<sizeof(obs);i++)
		{
	if(obs[i] == me) continue;
	if(!obs[i]) {FLAG=0; continue;}
	if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
	if(!obs[i]->query_skill("fallingstar-sword")) {FLAG=0; continue;}
	if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
	if(ob->query("skill_type") != "sword"){FLAG=0; continue;}
	if(obs[i]->query_skill_mapped("sword") != "fallingstar-sword") {FLAG=0; continue;}
		}	
	if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("tianya-blade",1);
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/50;
	
	if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	skl_you=(int)you->query_skill("fallingstar-sword",1);
	extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/50;
        me->add_temp("apply/attack",(skl_you+skl_me)/2);
        me->add_temp("apply/damage",(extra_you+extra_me)*6);
        you->add_temp("apply/attack",(skl_you+skl_me)/2);
        you->add_temp("apply/damage",(extra_you+extra_me)*6);
        you->kill_ob(target);
	 msg =HIY"\n白光一闪，$N已拔刀。天下无双的刀，不可思仪的刀法。\n无论多恶毒的兵器，无论多复杂的诡计，遇见了这种刀法，就像是冰雪到了阳光下。\n"HIW"刀光闪，带来一连串金铃般的轻响。\n"NOR;
	 message_vision(msg,me,target);
	for(i=0;i<sizeof(tianyaliuxing);i++)
	if(i%2) COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,tianyaliuxing[i]);
	else    COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR,tianyaliuxing[i]);
        me->add_temp("apply/attack",-(skl_you+skl_me)/2);
        me->add_temp("apply/damage",-(extra_you+extra_me)*6);
        you->add_temp("apply/attack",-(skl_you+skl_me)/2);
        you->add_temp("apply/damage",-(extra_you+extra_me)*6);
	msg = RED"\n\n刀光消失后，才看见血，血是从脸上流下的。$n"RED"的脸。\n一道刀口从$n"RED"眉毛间刻下来，划过鼻尖，这一刀只要多用三分力，$n"RED"的头就要一劈为二了。\n刀已人鞘。鲜血从鼻尖流落，流入嘴唇，$n"RED"却没有感到一丝痛苦。\n"NOR;
	message_vision(msg,me,target);}
	else
	{
        msg =HIY"白光一闪，$N已拔刀。天下无双的刀，不可思仪的刀法。\n无论多恶毒的兵器，无论多复杂的诡计，遇见了这种刀法，就像是冰雪到了阳光下。\n"HIW"刀光闪，带来一连串金铃般的轻响。\n"NOR;
	 message_vision(msg,me,target);
	 me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        for(i=0;i<sizeof(tianya);i++)
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,tianya[i]);
        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
	msg = RED"\n\n刀光消失后，才看见血，血是从脸上流下的。$n"RED"的脸。\n一道刀口从$n"RED"眉毛间刻下来，划过鼻尖，这一刀只要多用三分力，$n"RED"的头就要一劈为二了。\n"RED"刀已人鞘。鲜血从鼻尖流落，流入嘴唇，$n"RED"却没有感到一丝痛苦。\n"NOR;
	message_vision(msg,me,target);
	}	
	me->start_busy(4);
	return 1;
}