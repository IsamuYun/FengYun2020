// whosepet.c  by tiandi for check the owner of pet.   somebody use the pet name as npc name.
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string name;
        object ob;
        me = this_player();
        if( !arg || sscanf(arg, "%s", name) != 1 )
                return notify_fail("指令格式: whosepet <id>\n");
        if( !objectp(ob = present(name, environment(me))))
                return notify_fail("找不到" + name + "。\n");
          write(ob->query("name")+"是"+ob->query("owner")+"的。\n");
return 1;
}
int help(object me)
{
	write(@Help
 指令格式: whosepet <id>
有些玩家给自己的宠物取一些NPC的名字，造成一些任务出现BUG。
此命令查出该宠物属于哪个玩家。
Help
        );
        return 1;
}
