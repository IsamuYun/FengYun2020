#include <combat.h>
#include <ansi.h>
#define SYNTAX  "ָ���ʽ��gq <dir>\n"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        int i,j,k,m,flag=0;
        string *top = ({"/d/","/u/","/p/"});
        string direc,*dir, roomname, location;
        string *file;
        string status;
        object room;
        if(!me->query("env/yesiknow")) return notify_fail("���ָ���Ѿ����ϳ��ˣ�\n");
        status = wizhood(me);
        if( me!=this_player(1)
        || wiz_level(me) < wiz_level(status) )
                return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
        seteuid(getuid());
        for(i=0; i<sizeof(top); i++) 
        {
        dir = get_dir(top[i]);
//      write(top[i]+"\n");
        for(j=0; j<sizeof(dir); j++)
        {
//      write(top[i]+dir[j]+"/"+"\n");
        file = get_dir(top[i]+dir[j]+"/");
        for(k=0; k<sizeof(file); k++)
        {
        if( sscanf(file[k],"%s.c", roomname) != 1) continue;
//              write( "working on:" +file[k]+"\n");
        reset_eval_cost();

        location = top[i]+dir[j]+"/"+file[k];
        room = find_object(location);
        if(!room) room=load_object(location);
        }}}


        return 1;
}


