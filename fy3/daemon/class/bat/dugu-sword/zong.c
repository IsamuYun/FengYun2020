// po.c 「总诀式」
 
#include <ansi.h>
inherit SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon;
	int skill, jing_cost;

	skill = me->query_skill("dugu-sword",1);
	jing_cost = (int)me->query("int") - 45;

        if((string) me->query("class") != "huashan" )
		return notify_fail("你不是华山派的弟子，不能使用「总诀式」。\n");

	if( me->is_fighting() )
		return notify_fail("「总诀式」不能在战斗中演练。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须先去找一把剑。\n");

	if( !skill || (skill < 20))
		return notify_fail("你的独孤九剑等级不够, 不能演练「总诀式」！\n");
	if( !skill || (skill > 1000))
		return notify_fail("你的独孤九剑等级已经到了极限了, 不能演练「总诀式」！\n");

	if( me->query("force") < 50 )
		return notify_fail("你的内力不够，没有力气演练「总诀式」！\n");
 
	if( me->query("gin") < -jing_cost )
		return notify_fail("你现在太累了，无法集中精神演练「总诀式」！\n");

	msg = HIC "$N使出独孤九剑之「总诀式」，将手中" + weapon->name() + "随意挥舞击刺。\n";
	message_vision(msg, me);

	me->add("force", -50);
	me->add("gin", jing_cost);

	if ( skill < 60)
		me->improve_skill("dugu-sword", 10);
	else if (skill < 90)
		me->improve_skill("dugu-sword", 10 + random((int)me->query("int") - 9));
	else if (skill < 140)
		me->improve_skill("dugu-sword", 10 + random((int)me->query("int") * 2 - 9));
	else if (skill < 200)
		me->improve_skill("dugu-sword", 10 + random((int)me->query("int") * 4 - 9));
	else
		me->improve_skill("dugu-sword", 10 + random((int)me->query("int") * 8 - 9));

	msg = MAG"$P的「独孤九剑」进步了！\n"NOR;
	me->start_busy(3+random(3));

	message_vision(msg, me);

	return 1;
}
