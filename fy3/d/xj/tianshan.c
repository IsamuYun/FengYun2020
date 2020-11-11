#include <globals.h>
inherit ROOM;
void create()
{
	object con,item;
        set("short", "天山山脉");
        set("long", @LONG
这是天山东段最高峰博格达峰，为天山第二高峰，山峰终年积雪。
峰顶冰川纵横，景观绮丽。在博格达峰的山腰有一个碧蓝碧蓝的小湖，
池水清澄，看了就叫人感到喜欢。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"gela",
  "northwest" : __DIR__"tianchi",
]));
        set("objects", ([
	__DIR__"obj/snow" : 1,
	__DIR__"obj/lotus" : 1,
       	]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1140);
	set("coor/y",990);
	set("coor/z",0);
	setup();
        con = present("积雪",this_object());
        item= present("天山雪莲", this_object());
        item->move(con);
}
