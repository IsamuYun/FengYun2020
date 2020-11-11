#include <ansi.h>

inherit F_CLEAN_UP;
int rmhirdir(string dir);
int main(object me, string arg)
{
        if( me->is_busy() )
                return notify_fail("����һ��������û��ɡ�\n");

        if( !arg ) {
                write("You commit suicide.\n");
                return 1;
        }

        if( arg!="-f" ) 
                return notify_fail("��ɱ�����֣�����Ҫ��Զ������������Ͷ̥��\n");

        write(
                "�����ѡ����Զ��������ɱ��ʽ��������Ͼ���Զɾ���ˣ�һ��\n"
                "���������򲻿��ٺ���ˣ�");
        input_to("check_password", 1, me, 1);
        return 1;
}

private void check_password(string passwd, object me, int forever)
{
        object link_ob;
        string old_pass;
        string name;
        link_ob = me->query_temp("link_ob");
        old_pass = link_ob->query("password");
        if( crypt(passwd, old_pass)!=old_pass ) {
                write("�������\n");
                return;
        }

        if (forever) {
                tell_object( me,
                        HIR "\n\n�����ˣ�ϣ�����ڷ�����ÿ���...��\n\n\n" NOR);
        link_ob = me->query_temp("link_ob");
        if( !link_ob ) return 0;

        log_file("static/SUICIDE",
                sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

        seteuid(getuid());
        name = me->query("id");
       LOGIN_D->cphirdir(DATA_DIR + "login/" + name[0..0] + "/" + name, "/suicide/login/"+name+time());
       LOGIN_D->cphirdir(DATA_DIR + "user/" + name[0..0] + "/" + name, "/suicide/user/"+name+time());
      rmhirdir(DATA_DIR + "login/" + name[0..0] + "/" + name );
      rmhirdir(DATA_DIR + "user/" + name[0..0] + "/" + name );

            // by Tiandi to display player 's info
 message("system",HIC "\n�����ַ��ơ���ɱ��Ϣ��"+me->query("name")+"("+ name + ")���ڿ��ƺ쳾��["+query_ip_name(me)+"]����ȡ����ɱ��Ϊ��\n" NOR,users());
        tell_room(environment(me), me->name() +
                "��ɱ�ˣ���������Ҳ������������ˡ�\n", ({me}));
        destruct(me);
        return 0;

        }
}
int rmhirdir(string dirstr)
{
string *dir;
int i;
dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
                if(file_size(dirstr+"/"+dir[i]) == -2 ) {
                                rmhirdir( dirstr +"/"+dir[i]);
                                rmdir(dirstr+"/"+dir[i]);
                                                }
                rm(dirstr+"/"+dir[i]);
        }
rmdir(dirstr);

return 1;

}
int help (object me)
{
        write(@HELP
ָ���ʽ: suicide [-f]
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ.
��ɱ������:
 
suicide    : ����Ͷ̥
suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ����������ȷ�����.
 
������ѡ�� :)
 
HELP
);
        return 1;
}
