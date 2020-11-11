#include <room.h>
inherit CREATE_CHAT_ROOM; 
int is_chat_room() { return 1; } 
#include <ansi.h>
void create()
{
  set ("short", BLINK CYN"谈心居"NOR NOR);
        set("long", @LONG
这里是风云最安全的地方之一，也是一些朋友聚会的好地方。东边有
一个酒柜，上面有琳琅满目的各种各样的酒，有一些江湖侠客正在举
杯痛饮，西边还有几个醉汗喝的大醉。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"yitea2",
]));
        set("objects", ([
        "/d/wiz/xgchen/npc/fang" : 1,
     "/d/fy/npc/gmss.c" : 1,
                        ]) );
  set("no_death_penalty", 1);
        set("no_fight",1);
		set("NONPC",1);
        set("no_sheet",1);
        set("no_beg",1);
        set("no_du",1);
        set("no_exert",1);
        set("no_magic",1);
        set("no_dazuo",1);
        set("coor/x",10);
        set("coor/y",-30);
        set("coor/z",20);
	setup();
}
