// by snowcat 6/21/1997
// whohave.c

inherit F_CLEAN_UP;

mixed main(object me, string arg, int remote)
{
	object *ulist, *ilist;
	int i, j;

	if (! arg)
		return notify_fail ("ָ���ʽ whohave <id>\n");
        if( wiz_level(me) < wiz_level("(admin)") )
		return notify_fail("�����ʦ�ȼ�̫�ͣ�û��ʹ�����ָ���Ȩ����\n");
	//ulist = users();
        ulist = livings();
	i = sizeof(ulist);
	while (i--) {
		if (! present (arg,ulist[i]))
			continue;
		write ("  "+ulist[i]->query("name")+":");
		ilist = all_inventory(ulist[i]);
		j = sizeof(ilist);
		while (j--) {
			object ob = ilist[j];
			string *ids = ob->parse_command_id_list();
			if (member_array(arg, ids) == -1)
				continue;
			write (" "+ob->short());
		}
		write ("\n");
	}
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ : whohave <id>
 
���г�ĿǰЯ��ĳ����Ʒ����ҡ�
 
 
HELP
);
        return 1;
}
