#pragma save_binary
// roommaker.c
// xgchen@zzfy
#include <ansi.h>
#define RMK_VERSION "(v0.11)"

inherit ITEM;
inherit F_AUTOLOAD;

string *special_props = ({
        "short", "long" });

int save_room_file(string yn, string file, string str);

void create()
{
        set_name("��������༭��" + RMK_VERSION, ({ "roomediter", "editer" }) );
        set_weight(100);
        set("unit", "��" );
        set("long", @LONG
����һ�������޸ķ�������Ĺ��ߣ���������ʦ�޸�����ϵͳ��

reset <X> <Y> <Z>

    �趨��Ŀǰ��������꣬
        X�����Ƕ��ߵı������Ĵ�,
        Y�����Ǳ��ߵı��Ϸ��Ĵ�,
        Z�����Ǹ߱ߵıȵͷ��Ĵ�,

chkxyz 

    ȡ����Ŀǰ���ڷ�������꣬�� short��long �ȡ�

LONG
        );
}

int query_autoload() { return 1; }

void init()
{
        if( wizardp(environment()) ) {
                seteuid(getuid(environment()));
                add_action("do_check", "chkxyz");
                add_action("do_reset", "reset");
        }
}

int do_check(string arg)
{
                int *coor;
                if((coor=environment(this_player())->query("coor"))==0)coor=({0,0,0});
                tell_object(this_player(),sprintf("��ǰ����: X=%d\tY=%d\tZ=%d\n",
                                coor[0],coor[1],coor[2]));
                return 1;
}
int do_saveroom(object room,int x,int y,int z);
int do_reset(string arg)
{
        int x,y,z,*coor;
        if( !arg || sscanf(arg, "%d %d %d", x, y, z)!=3 )
                return notify_fail("ָ���ʽ��reset <X> <Y> <Z>\n");
                coor=({x,y,z});
        environment(this_player())->set("coor", coor);
                do_saveroom(environment(this_player()),x,y,z);
        write("Ok.\n");
        return 1;
}


int do_saveroom(object room,int x,int y,int z)
{
        object env;
        string str,file,all,head;
        int i,j,k;

        env = room;
        file = file_name(env) + ".c";
                if(!stringp(str=read_file(file,0))) 
                        return 0;
                i=strsrch(str,"create(");
                j=strsrch(str[i..],"set(");
                if(i<0||j<0) return 0;
                head=str[0..i+j-1];
                if(strsrch(str[i+j..],"set(\"coor\",")==0){
                        k=strsrch(str[i+j..],"\n\t");
                        if(k>0)j+=k+2;
                        }
                if(strsrch(str[i+j..],"set(\"coor\",")==0){
                        k=strsrch(str[i+j..],"\n\tset(");
                        if(k>0)j+=k+2;
                        }
all=head+sprintf("set(\"coor/x\",%d);\n\t"+"set(\"coor/y\",%d);\n\t"+"set(\"coor/z\",%d);\n\t",x,y,z);
                all+=str[i+j..];

        return save_room_file("y", file, all);
}

int save_room_file(string yn, string file, string str)
{
        if( strlen(yn)<1 || yn[0]!='y' ) return 1;

        rm(file);
        write("�浵 " + file + "....");
        if( write_file(file, str) ) {
                write("Ok.\n");
                return 1;
        } else
                return notify_fail("��û��д���������(" + file + ")��Ȩ����\n");
}

void owner_is_killed() { destruct(this_object()); }

