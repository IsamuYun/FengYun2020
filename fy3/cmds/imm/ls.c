// by xgchen 2001
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        int mark_loaded;
        int i, j, w, col;
        string dir;
        mixed *file;
 
        seteuid(geteuid(me));
         if( wiz_level(me) < wiz_level("wizard") )
        return notify_fail("�����ʦ�ȼ�̫�ͣ�û��ʹ�����ָ���Ȩ����\n"); 
       dir = resolve_path(me->query("cwd"), arg);
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) )
        {if (file_size(dir) == -2) return notify_fail("Ŀ¼�ǿյġ�\n");
                else
                return notify_fail("û�����Ŀ¼��\n");
        }
 
        i = sizeof(file);
        w = 0;
        while(i--) {
                if (file[i][1]==-2) file[i][0] += "/";
                if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
        }
        write("Ŀ¼�s" + dir + "\n");
        col = 70 / (w+6);
        if (sizeof(file))
                for(i=0, j = sizeof(file); i<j; i++) {
                        int mode=0;     // unloaded file
                        
                        if (strsrch(file[i][0], "/") >= 0) mode = 1; // dir
                        else if (find_object(dir+file[i][0])) mode =2; // loaded file
 
                        printf("%4d %-*s%s", file[i][1]/1024 + 1, w+1+
                                (mode>0? 16: 9),
                                (mode==1? HIC: mode==2? HIR: "") +
                                file[i][0] + (mode==2? "*": " ") + NOR,
                                ((i+1)%col)?"  ":"\n");
                }
        else write("    û���κε�����\n");
        write("\n");
        
        return 1;       
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ�sls [<·����>]
 
�г�Ŀ¼�����е���Ŀ¼�������o���û��ָ��Ŀ¼�o���г�����Ŀ¼
�����ݩo���г��ĵ�����ǰ���ʾ * �ŵ����Ѿ�����������
 
����:
'ls /' ���г�����λ춸�Ŀ¼�µĵ�������Ŀ¼��
 
���ָ��scd��pwd��
HELP
        );
        return 1;
}
