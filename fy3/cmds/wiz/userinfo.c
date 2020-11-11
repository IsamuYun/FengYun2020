// whosepet.c  by tiandi for check the owner of pet.   somebody use the pet name as npc name.
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string name,temp;
        object ob,obj;
		int i;
        me = this_player();
        if( !arg || sscanf(arg, "%s %s %d", name,temp,i) != 3 )
                return notify_fail("指令格式: userinfo <id> <query> <flag>\n");

        if( !objectp(ob = present(name, environment(me))) && !objectp(ob = present(name, me)) )
                return notify_fail("找不到" + name + "。\n");
		if (i == 1)
		{
			write ("你查看的参数query("+temp+")的值＝"+ob->query(temp)+"\n");
		}
		else
			write ("你查看的参数temp_query("+temp+")的值＝"+ob->query_temp(temp)+"\n");
		return 1;
}
int help(object me)
{
	write(@HELP
指令格式: userinfo id query flag

查看玩家的一些数据资料,
query为玩家query的内容
flag标签为非1的时候query为temp_query的内容.
 
HELP
    );
    return 1;
}
 

