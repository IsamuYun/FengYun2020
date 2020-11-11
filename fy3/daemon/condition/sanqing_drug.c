// drunk.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") / 20) +1;

	if( duration > limit
	&&	living(me) ) {
		me->delete("statusnow");
		me->unconcious();
		return 0;
	} else if( duration > limit/2 ) {
		tell_object(me, "你觉得脑中昏昏沉沉，心中空荡荡的，直想躺下来睡一觉。\n");
		message("vision", me->name() + "摇头晃脑地站都站不稳，显然是身上被人种下的法力发作了。\n",
			environment(me), me);
	}

	me->apply_condition("sanqing_drug", duration + 1);
	if( duration > 60) 
		{
		me->delete("statusnow");
		return 0;
		}
	return 1;
}
