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

        write("\n\n\n\n\n\n���ڷ���ƵĻ\nҪ�ָ�����������ԭ�������룺");
        input_to("get_old_pass", 1, ob,me);
        return 1;
}

private void get_old_pass(string pass, object ob,object me)
{
        string old_pass;

        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("�������\n");
        write("Ϊ�˰�ȫ������������������룺");
                input_to("get_old_pass", 1, ob);
                return;
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ : lockscreen
 
���ָ����ס��Ļ��
 
HELP
    );
    return 1;
}

