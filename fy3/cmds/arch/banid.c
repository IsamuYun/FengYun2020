// banid.c
// writed by mouse
void create()
{
	seteuid(getuid());
}
int main(object me, string arg)
{
        string banname;
	int i;
	if (!arg)
	{
		if ( file_size(CONFIG_DIR + "banned_id") >=0 )
			me->start_more(read_file(CONFIG_DIR + "banned_id"));
		else
			write("û�н�ֹ��Ӣ�����֡�\n");
		return 1;
	}
	else if (sscanf(arg, "+ %s", banname) == 1)
	{
		i = strlen(banname);

		while(i--)
		{
			if ( (strlen(banname) < 2) || (strlen(banname) > 8 ) )
			{
				write("���ܽ�ֹ " + banname + "��Ӣ�����ֱ����� 2 �� 8 ����ĸ��\n");
				return 1;
			}
			if ( banname[i]<=' ' )
			{
				write("���ܽ�ֹ " + banname + "��Ӣ�����ֲ����ÿ�����Ԫ��\n");
				return 1;
			}
		}
		write_file(CONFIG_DIR + "banned_id", banname + "\n" );
		write("OK.\n");
	}
	else if (sscanf(arg, "- %s", banname) == 1)
	{
		write("���޸� " + CONFIG_DIR + "banned_id" + " �����\n");
	}
	else write("ָ���ʽ��banid [+|- idname]\n");

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��banid [+|- idname]

����������������ֹ������������Ӣ�����֡�
HELP
	);
	return 1;
}
