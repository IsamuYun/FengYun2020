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
			write("没有禁止的英文名字。\n");
		return 1;
	}
	else if (sscanf(arg, "+ %s", banname) == 1)
	{
		i = strlen(banname);

		while(i--)
		{
			if ( (strlen(banname) < 2) || (strlen(banname) > 8 ) )
			{
				write("不能禁止 " + banname + "，英文名字必须是 2 到 8 个字母。\n");
				return 1;
			}
			if ( banname[i]<=' ' )
			{
				write("不能禁止 " + banname + "，英文名字不能用控制字元。\n");
				return 1;
			}
		}
		write_file(CONFIG_DIR + "banned_id", banname + "\n" );
		write("OK.\n");
	}
	else if (sscanf(arg, "- %s", banname) == 1)
	{
		write("请修改 " + CONFIG_DIR + "banned_id" + " 解禁。\n");
	}
	else write("指令格式：banid [+|- idname]\n");

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：banid [+|- idname]

这条命令是用来防止有人蓄意乱起英文名字。
HELP
	);
	return 1;
}
