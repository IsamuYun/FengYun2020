// ff.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string dest, func, file;
	string * inherit_ob;
	int i,s;

        if( wiz_level(me) < wiz_level("(admin)") )
	return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n"); 

	if(!arg || sscanf(arg, "%s %s", dest, func)!=2 )
		return notify_fail("指令格式：ff <物件> <函数名称>\n");

	if( dest=="me" ) ob = me;
	else if( dest=="here" ) ob = environment(me);
	else ob = present(dest, me);

	if( !ob ) ob = present(dest, environment(me));
	if( !ob ) ob = find_object(resolve_path(me->query("cwd"), dest));
	if( !ob ) return notify_fail("这里没有「" + dest + "」。\n");
	file = function_exists(func, ob);
	if(!file)
		printf("物件 %O 并没有定义 %s 这个函数。\n", ob, func);
	else
		printf("物件 %O 的 %s 函数定义在 %s.c。\n", ob,	func, file );
	inherit_ob=deep_inherit_list(ob);
	s=sizeof(inherit_ob);
	if (s==0) return 1;
	for (i=0;i<s;i++) {
		printf("%s\n",inherit_ob[i]);
		ob=find_object(inherit_ob[i]);
		if (!objectp(ob))	continue;
		file = function_exists(func, ob);
		if(file)
			printf("物件 %O 的 %s 函数定义在 %s.c。\n", ob,	func, file );
	}
	printf("查找结束.\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式：ff <物件> <函数名称>

这个指令可以找出指定物件中的某个函数定义在哪一个档案(包括继承档案)里。
TEXT
	);
	return 1;
}
