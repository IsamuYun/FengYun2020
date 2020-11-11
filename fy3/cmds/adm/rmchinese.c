inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz;
        if( wiz_level(me) < wiz_level("(admin)") )
	return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n"); 
	if( !arg || arg=="" )
		return notify_fail("指令格式：rmchinese <英文>\n");

	if( sscanf(arg, "<%s>", key)==1 ) {
		CHINESE_D->remove_translate(key);
		write( "remove " + key + "\nOk.\n");
		return 1;
	}

	return 0;
}

int help()
{
	write ( @HELP
指令格式：rmchinese <英文>
HELP
	);
	return 1 ;
}
