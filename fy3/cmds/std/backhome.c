// goto.c

inherit F_CLEAN_UP;

int main(object me)
{
	if (!me->query("class"))
			return notify_fail("入了门派后才可以使用该命令。\n");
	if (me->is_ghost())
			return notify_fail("鬼魂不可以使用。\n");
	if( me->is_fighting() )
			return notify_fail("战斗中不可以使用回门术。\n");
	if (me->query("level")> 49)
	{
		if( me->query("lifetili")<2 )
			return notify_fail("你的活力不够。\n");
		if( me->query("force")<50 )
			return notify_fail("你的内力不够。\n");
		me->add("lifetili",-2);
		me->add("force",-50);
	}
			
	if (me->query("class")=="baiyun" || me->query("class")=="official" )
	{
		message_vision("$N使用了回门术。瞬间消失在众人的眼前。\n", me);
		me->move("/d/fy/fqkhotel");
		message_vision("$N使用了回门术，又出现在众人的眼前。\n", me);
		return 1;
	}
	if (me->query("class")=="dazhao" )
	{
		message_vision("$N使用了回门术。瞬间消失在众人的眼前。\n", me);
		me->move("/u/guanwai/inn");
		message_vision("$N使用了回门术，又出现在众人的眼前。\n", me);
		return 1;
	}
		if (me->query("class")=="sanqing" )
	{
		message_vision("$N使用了回门术。瞬间消失在众人的眼前。\n", me);
		me->move("/u/taoguan/road5");
		message_vision("$N使用了回门术，又出现在众人的眼前。\n", me);
		return 1;
	}
		if (me->query("class")=="wudang" )
	{
		message_vision("$N使用了回门术。瞬间消失在众人的眼前。\n", me);
		me->move("/u/wudang/road1");
		message_vision("$N使用了回门术，又出现在众人的眼前。\n", me);
		return 1;
	}
		if (me->query("class")=="tieflag" )
	{
		message_vision("$N使用了回门术。瞬间消失在众人的眼前。\n", me);
		me->move("/d/tieflag/island");
		message_vision("$N使用了回门术，又出现在众人的眼前。\n", me);
		return 1;
	}
		if (me->query("class")=="tianchui" )
	{
		message_vision("$N使用了回门术。瞬间消失在众人的眼前。\n", me);
		me->move("/u/palace/palace_palace");
		message_vision("$N使用了回门术，又出现在众人的眼前。\n", me);
		return 1;
	}
		if (me->query("class")=="mojiao" )
	{
		message_vision("$N使用了回门术。瞬间消失在众人的眼前。\n", me);
		me->move("/d/daimiao/tongting");
		message_vision("$N使用了回门术，又出现在众人的眼前。\n", me);
		return 1;
	}
		if (me->query("class")=="xingguo" )
	{
		message_vision("$N使用了回门术。瞬间消失在众人的眼前。\n", me);
		me->move("/d/qianfo/chansi");
		message_vision("$N使用了回门术，又出现在众人的眼前。\n", me);
		return 1;
	}


	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : backhome
 
拜师之后可以使用该命令回到师傅所在附近的地点。
 
HELP
    );
    return 1;
}
