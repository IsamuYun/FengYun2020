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
        set_name("房间坐标编辑器" + RMK_VERSION, ({ "roomediter", "editer" }) );
        set_weight(100);
        set("unit", "个" );
        set("long", @LONG
这是一个用来修改房间坐标的工具，帮助的巫师修改坐标系统：

reset <X> <Y> <Z>

    设定你目前房间的坐标，
        X坐标是东边的比西方的大,
        Y坐标是北边的比南方的大,
        Z坐标是高边的比低方的大,

chkxyz 

    取得你目前所在房间的坐标，如 short，long 等。

LONG
        );
}

int query_autoload() { return 1; }

void init()
{
        if( wizardp(environment()) ) {
                seteuid(getuid(environment()));
                add_action("do_reset", "xyz");
        }
}

int do_saveroom(object room,int x,int y,int z);
int do_reset(string arg)
{
        int x,y,z,*coor;
        if( !arg || sscanf(arg, "%d %d %d", x, y, z)!=3 )
                return notify_fail("指令格式：reset <X> <Y> <Z>\n");
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
        int i,j,k,f;

        env = room;
        file = file_name(env) + ".c";
                if(!stringp(str=read_file(file,0))) 
                        return 0;
                i=strsrch(str,"create(");
                j=strsrch(str[i..],"setup(");
                if(i<0||j<0||f<0) return 0;
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
        write("存档 " + file + "....");
        if( write_file(file, str) ) {
                write("Ok.\n");
                return 1;
        } else
                return notify_fail("你没有写入这个档案(" + file + ")的权利。\n");
}

void owner_is_killed() { destruct(this_object()); }

