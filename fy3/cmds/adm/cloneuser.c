#pragma save_binary
inherit F_CLEAN_UP;

void create() {        seteuid(getuid());}
int main(object me, string arg)
{
        object ob;
        if( me != this_player(1) ) return 0;
if(!arg)
        return notify_fail("��Ҫ����ʲô�ˣ�\n");
	ob=find_player(arg);
        ob = new("/obj/usertest");
        ob->set("id",arg);
              ob->setup();
	   ob->move(environment(me));
	   tell_object(me,"�㸴�Ƴ���"+ob->name()+"\n");
	   return 1;
	 
}


int help(object me)
{
        write(@HELP
ָ���ʽ : cloneuser
 
���ָ����Ը�����ҡ�
 
HELP
    );
    return 1;
}
 
