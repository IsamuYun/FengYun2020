// jiesheng_room.c
// xgchen@zzfy
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "接生房");
        set("long", @LONG
你现在正站在接生房里，这里是专门替人为生育孩子接生的地方，
城里所有的夫妇都是在这里生孩子的，招牌上写着价钱（ｓｉｇｎ）。
LONG
        );
        set("exits", ([
                "out"          : __DIR__"marry_room", 
         ]) );
             set("no_magic",1);
             set("no_fight",1);
             set("no_beg",1);
             set("no_du",1);
             set("no_perform",1);
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("objects", ([
                __DIR__"npc/jiesheng2" : 1,
        ]) );
 
        set("coor/x",10);
        set("coor/y",-1);
        set("coor/z",10);
        setup();

}

string look_sign(object me)
{
        return "接生价格为(1000两黄金)。\n";
}


