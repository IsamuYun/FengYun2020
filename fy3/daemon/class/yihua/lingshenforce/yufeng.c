// yufeng.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target)
{
        if(environment(me)->query("no_magic")) 
        {
                return notify_fail("这个地方无法灵神飞行。\n");
        }

        if( me->query_temp("nofly") || me->query("job/sxy") )
                return notify_fail("你有任务在身不能使用这个外功。\n");
        if( me->is_fighting() )
		return notify_fail("战斗中无法灵神飞行！\n");
        if( me->query("force") < 200 )
		return notify_fail("你的内力不够！\n");
        if( me->query("gin") < 100 )
                return notify_fail("你的精不够！\n");
	if( me->is_ghost())
		return notify_fail("鬼魂无法灵神飞行！\n"); 	
        if((int) me->query_skill("lingshenforce",1) < 120)
                return notify_fail("你的灵神诀不够高深！");
		write(BLINK"[1;34m你要灵神到哪儿？[2;37;0m");

	input_to( (: call_other, __FILE__, "select_target", me :));

		return 1;
}


void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("[1;35m中止灵神[1;34m。\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob) || !ob->query("max_force") || !ob->query("force")) {
		write("你无法感受到这个人的内力 ....\n");
		write("你要移动到哪一个人身边？");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;


		}
	if( me->is_fighting() ) {
		write("[1;31m战斗中无法使用驭风飞行[2;37;0m！\n");
		return;
        } else if( me->query("force") < 200 ) {
		write("你的内力不够！\n");
		return;
	}

        me->add("force", -150);
        me->receive_damage("gin", 80);
	
	message_vision( HIC "$N凝神内视，开始施展道家的驭风飞行 ....\n" NOR, me);
        if( random(ob->query("force")) < (int)me->query("force") / 10 ) {
		write("你感受到对方的内力，但是不够强烈。\n");
		return;
	}
  if( random(me->query_skill("lingshenforce")) < (int)ob->query("force") / 500 ) {
		write("你因为不够熟练而失败了。\n");
		return;
	}
        if( random(80) > (int)(me->query_skill("lingshenforce",1))){
                write("你因为不够熟练而失败了。\n");
                return;
        }
	if(environment(ob)->query("no_magic")) {
		write("你想要灵神的地方不可以去！\n");
		return;
	}
	message( "vision", HIM "\n突然间云丝集结,飘向" + me->name() 
		+ "，慢慢的飘上云丝,转眼间已消失无踪！\n\n" NOR, environment(me), ({ me }) );
        me->move(environment(ob));
        me->start_busy(2);
	message( "vision", HIW "\n突然间，天边飘来一丝彩云,云上影约有个人影正在以你无法想象的速度向你飘来！\n\n" NOR,
		environment(ob), ({ me }) );
}

