// TIE@FY3
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object obj;
	string id, verb,replace;
	string tmp;
	if( !arg ) 
		return notify_fail("ָ���ʽ : alter <���ĵĶ���> <���ĵĿ���> <�ı������>\n");
	

	if( sscanf(arg, "%s %s %s", id, verb, replace)!=3 )
		return notify_fail("ָ���ʽ : alter <���ĵĶ���> <���ĵĿ���> <�ı������>\n");
	if( !objectp(obj = present(id, me)) )
		return notify_fail("������û������������\n");
	if(obj->query("owner") != me->query("id"))
		return notify_fail("�ⲻ����˽�˵Ķ�����\n");
	switch(verb) {
		case "desc":
			if(!CHINESE_D->check_chinese(replace)) return notify_fail("�������������ġ�\n");
			obj->set("long",replace+"\n");
			break;
		case "wield_msg" :
			if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
			return notify_fail("�������뺬��$N��$n��\n");
			tmp = replace_string(replace,"$N","");
			tmp = replace_string(tmp,"$n", "");
			if(!CHINESE_D->check_chinese(tmp)) return notify_fail("�������������ġ�\n");		
			obj->set("wield_msg",replace+"\n");
			break;
		case "unwield_msg" :
			if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("�������뺬��$N��$n��\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("�������������ġ�\n");
                        obj->set("unwield_msg",replace+"\n");
                        break;
		case "wear_msg" :
                        if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("�������뺬��$N��$n��\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("�������������ġ�\n");
                        obj->set("wear_msg",replace+"\n");
                        break;
		case "remove_msg" :
                        if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("�������뺬��$N��$n��\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("�������������ġ�\n");
                        obj->set("unequip_msg",replace+"\n");
                        break;
		default: 
			return notify_fail("ָ���ʽ : alter <���ĵĶ���> <���ĵĿ���> <�ı������>\n");
		
	}
	obj->save();
	write("�ı�ɹ���\n");
	me->add("sen",-10);
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ : alter <���ĵĶ���> <���ĵĿ���> <�ı������>
	������ԸĵĶ���ֻ�������Լ�����Ķ�����
	���ԸĵĿ��������
		desc  		��Ʒ������
		wield_msg 	װ������������
		unwield_msg	���±���������
		wear_msg	���Ͽ��׵�����
		remove_msg	���¿��׵�����

��������һ��Ѫ��(redsword)��
	alter redsword wield_msg ֻ�����һ�֣�$N�Ѱ�$n��������	

	�Ժ�ÿ����װ��redsword(wield redsword)����Ҷ��ῴ����
	��ֻ�����һ�֣������Ѱ�Ѫ���������У�	
HELP
);
        return 1;
}
