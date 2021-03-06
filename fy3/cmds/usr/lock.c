// xgchen@zzfy
// lockscreen.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;

        if( me != this_player(1) ) return 0;

        ob = me->query_temp("link_ob");
        if( !ob ) return 0;
        while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

        write("\n\n\n\n\n\n现在封锁频幕\n要恢复请先输入您原来的密码：");
        input_to("get_old_pass", 1, ob,me);
        return 1;
}

private void get_old_pass(string pass, object ob,object me)
{
        string old_pass;

        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("密码错误！\n");
        write("为了安全起见，请输入您的密码：");
                input_to("get_old_pass", 1, ob);
                return;
        }
}

int help(object me)
{
        write(@HELP
指令格式 : lockscreen
 
这个指令锁住屏幕。
 
HELP
    );
    return 1;
}

