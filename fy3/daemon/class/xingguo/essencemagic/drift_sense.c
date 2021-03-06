// drift_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
    if( me->query_temp("nofly")  )
        return notify_fail("你有重要的任务在身，不能乱跑！\n");
	if( me->is_fighting() )
		return notify_fail("战斗中无法使用游识神通！\n");
	if( me->query("atman") < 75 )
		return notify_fail("你的灵力不够！\n");
        if( me->query("atman") < 75 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 35 )
                return notify_fail("你的精不够！\n");
	if( me->is_ghost())
		return notify_fail("鬼魂无法使用游识神通！\n"); 	
        if((int) me->query_skill("essencemagic",1) < 60)
                return notify_fail("你的八识神通不够高深！");
	if( target )
		return notify_fail("游识神通只能对自己使用！\n");
	write("你要移动到哪一个人身边？");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("中止施法。\n");
		return;
	}

	ob = find_player(name);
	if( !ob || wizardp(ob) )
		ob = find_living(name);
	if( !ob || wizardp(ob) || !environment(ob)
	|| !ob->query("level")*10 > me->query_skill("essencemagic",1) || ob->query("is_jobnpc")) {
		write("你无法感受到这个人的灵力 ....\n");
		write("你要移动到哪一个人身边？");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	if( me->is_fighting() ) {
		write("战斗中无法使用游识神通！\n");
		return;
	} else if( me->query("atman") < 75 ) {
		write("你的灵力不够！\n");
		return;
	}

	me->add("atman", -75);
	me->receive_damage("gin", 30);
	
	message_vision( HIY "$N低头闭目，开始施展游识神通 ....\n" NOR, me);
	if( random(me->query_skill("essencemagic",1)) < ob->query("level")*5 ) {
		write("你感受到对方的灵力，但是不够强烈。\n");
		return;
	}
/*  by tiandi 不需要那么多限制
	if( random(me->query_skill("magic")) < (int)ob->query("atman") / 50 ) {
		write("你因为不够熟练而失败了。\n");
		return;
	
        if( random(50) > 
	(int)(me->query_skill("essencemagic",1))){
                write("你因为不够熟练而失败了。\n");
                return;
        }
		*/ 
	if(environment(ob)->query("no_magic")) {
		write("你想要游识的地方不可以用神通！\n");
		return;
	}
	message( "vision", HIY "\n一道耀眼的光芒忽然罩住" + me->name() 
		+ "，几秒钟後，光芒和人一齐消失得无影无踪！\n\n" NOR, environment(me), ({ me }) );
	me->move(environment(ob));
	message( "vision", HIY "\n你的眼前突然出现一团耀眼的光芒，光芒中浮现出一个人影！\n\n" NOR,
		environment(ob), ({ me }) );
}
int help(object me)
{
        write(YEL"\n八识神通之游识："NOR"\n");
	write(@HELP

         八识神通之经典招数，可以根据自己的意念瞬间飞行到目标处。
		 八识神通每上升十级，增加可以飞行的目标等级限制一级。
     

HELP
	);
	return 1;
}

