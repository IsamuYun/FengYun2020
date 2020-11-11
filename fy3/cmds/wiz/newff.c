// ff.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string dest, func, file;
	string * inherit_ob;
	int i,s;

	if(!arg || sscanf(arg, "%s %s", dest, func)!=2 )
		return notify_fail("ָ���ʽ��ff <���> <��������>\n");

	if( dest=="me" ) ob = me;
	else if( dest=="here" ) ob = environment(me);
	else ob = present(dest, me);

	if( !ob ) ob = present(dest, environment(me));
	if( !ob ) ob = find_object(resolve_path(me->query("cwd"), dest));
	if( !ob ) return notify_fail("����û�С�" + dest + "����\n");
	file = function_exists(func, ob);
	if(!file)
		printf("��� %O ��û�ж��� %s ���������\n", ob, func);
	else
		printf("��� %O �� %s ���������� %s.c��\n", ob,	func, file );
	inherit_ob=deep_inherit_list(ob);
	s=sizeof(inherit_ob);
	if (s==0) return 1;
	for (i=0;i<s;i++) {
		printf("%s\n",inherit_ob[i]);
		ob=find_object(inherit_ob[i]);
		if (!objectp(ob))	continue;
		file = function_exists(func, ob);
		if(file)
			printf("��� %O �� %s ���������� %s.c��\n", ob,	func, file );
	}
	printf("���ҽ���.\n");
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��ff <���> <��������>

���ָ������ҳ�ָ������е�ĳ��������������һ������(�����̳е���)�
TEXT
	);
	return 1;
}
