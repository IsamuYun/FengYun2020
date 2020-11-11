#include <ansi.h>
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
        object cash;
        string c_name;     
        string *dir,file,temp;
        int i;
        seteuid(getuid());
        if(!arg || sscanf(arg,"%s",c_name) != 1)
      	  return notify_fail("指令格式：　buildgroup 白虎团。\n");
        if((int)me->query("score") < 10000)
       	 return notify_fail("你的评价点不够"+chinese_number(10000)+"点。\n");
        cash = present("ttcash",me);
        if(!cash) return notify_fail("你身上没有一万两银票(tenthousand-cash)。\n");
        if((int) cash->query_amount() < 10)
        return notify_fail("你身上没有"+chinese_number(10)+"张一万两银票(tenthousand-cash)。\n");
        if(!check_legal_name(c_name) )
        return 1;
        dir = get_dir(DATA_DIR+"group/");
        for(i=0; i<sizeof(dir); i++) 
        if(dir[i] == c_name)
      	  return notify_fail("你想创立的社团名字已经被别人占用了！\n"); 
	file = "/data/group/"+c_name;
	temp = me->query("name");
          write_file(file,"level 1\nmember 1\n"+ temp);

        me->set("group",c_name);
        me->add("score",-10000);
	me->set("grouptitle",1);
	me->set("groups",1);
	me->set("grouplv",1);
	me->set("groupscore",100);
        cash->add_amount(-10);
        message("system",HIC"\n【快乐风云】社团消息："HIY+ me->query("name")+"建立了社团，社团名为『"HIC+c_name+HIY"』！请大家一起祝贺该社团越办越强大。\n\n"NOR, users() );
    return 1;
}
 
int help(object me)
{
    write(@HELP
让你在快乐风云中建立自己的社团
指令格式: 
buildgroup 社团中文名

此指令让你创立一个新的社团。
社团是进行城战的前提，只有社团的团长才可以发起城战。

HELP
    );
        return 1;
}
 
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 4) || (strlen(name) > 20 ) ) {
                write("对不起，中文名字必须是三到十个中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("对不起，中文名字不能用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，名字必需是中文。\n");
                        return 0;
                }
        }
        return 1;
}

