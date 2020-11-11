// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("vivien-steps",1);
	if ( extra < 90) return notify_fail("你的［忘情步法］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［情却千里］只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	message_vision( HIY "$N心不在焉，" + HIW "天下第一轻功--情却千里" + HIY "使了出去！\n" NOR ,me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
	message_vision("结果$N慢上一步，被扰得忙乱出错，不知闪躲！\n",target);
	target->start_busy(5);
	}
	else{
	msg = "可惜$N看出了$n的身法中的一处破绽，向你迅然攻击！";
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
	return 1;
}
