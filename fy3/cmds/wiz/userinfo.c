// whosepet.c  by tiandi for check the owner of pet.   somebody use the pet name as npc name.
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string name,temp;
        object ob,obj;
		int i;
        me = this_player();
        if( !arg || sscanf(arg, "%s %s %d", name,temp,i) != 3 )
                return notify_fail("ָ���ʽ: userinfo <id> <query> <flag>\n");

        if( !objectp(ob = present(name, environment(me))) && !objectp(ob = present(name, me)) )
                return notify_fail("�Ҳ���" + name + "��\n");
		if (i == 1)
		{
			write ("��鿴�Ĳ���query("+temp+")��ֵ��"+ob->query(temp)+"\n");
		}
		else
			write ("��鿴�Ĳ���temp_query("+temp+")��ֵ��"+ob->query_temp(temp)+"\n");
		return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ: userinfo id query flag

�鿴��ҵ�һЩ��������,
queryΪ���query������
flag��ǩΪ��1��ʱ��queryΪtemp_query������.
 
HELP
    );
    return 1;
}
 

