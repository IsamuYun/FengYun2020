#pragma save_binary
inherit F_CLEAN_UP;

void create() {        seteuid(getuid());}
int main(object me, string arg)
{
        object ob;
        if( me != this_player(1) ) return 0;
if(!arg)
        return notify_fail("你要复制什么人？\n");
	ob=find_player(arg);
        ob = new("/obj/usertest");
        ob->set("id",arg);
              ob->setup();
	   ob->move(environment(me));
	   tell_object(me,"你复制出了"+ob->name()+"\n");
	   return 1;
	 
}


int help(object me)
{
        write(@HELP
指令格式 : cloneuser
 
这个指令可以复制玩家。
 
HELP
    );
    return 1;
}
 
