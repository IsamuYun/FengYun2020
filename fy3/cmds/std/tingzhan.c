#include <ansi.h>
inherit SKILL;
int main(object me, string arg)
{
        string who;
      	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	seteuid(getuid());

    if ( (!(myfam = me->query("family")) || myfam["family_name"] != "少林寺") )
        return notify_fail("只有少林寺的人才能用停战！\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里没有人打斗！\n");

	if( me->query_temp("tianzhan") )
		return notify_fail("你已经在劝人家罢斗了！\n");
        if ((int)me->query_skill("chanting",1) < 60 ) 
		return notify_fail("你的诵经等级不够！\n");
	if( !arg || sscanf(arg, "%s halt", who)!=1 ) return
		notify_fail("指令格式：tingzhan <人物> halt\n");

	victim = present(who, environment(me));

	if( !victim || victim == me) return notify_fail("你想找的对象不在这里。\n");

	if( !living(victim) || !objectp(victim))
		return notify_fail("你要劝谁停战？\n");

    if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "少林寺" )
        return notify_fail("你不能向本派的使用停战！\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("玩家不能劝巫师停战。\n");
       if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能使用停战。\n");
	if( me->is_fighting() )
                return notify_fail("一边打架一边劝别人停战？你真是虚伪到家了！\n");


	sp = (int)me->query_skill("chanting") * 15 + (int)me->query("kar") * 5;
	if( sp < 1 ) sp = 1;
	dp = (int)victim->query("gin");

	tell_object(me, "你向" + victim->name() + "走过去，双手合十，开始念诵佛经"
			+ "...\n\n");
	tell_object(victim, me->name() + "向你走过来，双手合十，说道：我佛慈悲, 还请" + RANK_D->query_respect(victim) + "停手,放下屠刀，立地成佛吧 ...！\n\n");

	message("vision", "只见" + me->name() + "向" 
		+ victim->name() + "走过去，\n出双手合十，说道: 请"
		+ RANK_D->query_respect(victim) + "，停手吧，放下屠刀，立地成佛吧  ...！\n\n", environment(me), ({ me, victim }) );

	call_out( "compelete_dushi", 3, me, victim, ob, sp, dp);

	return 1;
}

void compelete_dushi(object me, object victim, object ob, int sp, int dp)
{
	me->delete_temp("tingzhan");

	if( environment(victim) != environment(me) ) {
		tell_object(me, "太可惜了，你要找的人已经走了。\n");
		return;
	}

	if( living(victim) && (random(sp+dp) > dp) ) 
	{
		victim ->remove_all_enemy();
		tell_object(me, victim->name() + "低头想了一会，又看了看你，好象被你打动，停止了打斗。\n");
		tell_object(victim, "你听了之后，心中升起一股祥和之气，不再想继续打下去了。\n");

		me->improve_skill("chanting", random(me->query("int")));
		if(((int)me->query("learned_points") + 120) > (int)me->query("potential"))
			me->add("potential",1);
		me->add("combat_exp",2);
		me->add("gin",50);
		me->start_busy(3);
	} 
	else 
	{
		if( random(sp) > dp/2 ) {
			message_vision(victim->name() + "狠狠地瞪了$N一眼，喝道：我都快让人给打死了，能停战吗! $N转身不听你的了。\n", me);
			
			return;
		}
	
		tell_object(me, victim->name() + "一心在战斗，对你理都不理。\n");
		tell_object(victim, "你在生死关头，对" + me->name() + "理都不理。\n");
		message("vision", victim->name() + "一心在战斗，对" + me->name() + "理都不理。\n", 
			environment(me), ({ me, victim }) );

	}
}

int help(object me)
{
write(@HELP
指令格式 : tingzhan <某人> halt
可以让对手停止战斗，但是你不可以在战斗中使用。
HELP
    );
    return 1;
}
