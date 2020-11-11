// inn.c

#include <room.h>

inherit ROOM;


void create ()
{
  set ("short", "风云阁");
  set ("long", @LONG
风云阁的主人就是当今天下侠名鼎鼎的小李飞刀。李探花长年行侠在外，但还是
有很多客人慕名来到此阁，以求一面之缘。阁中大红波斯地毯铺地，富丽堂煌。朱红
的大门两侧各挂一幅石刻的对联儿：
[33m
                	一门七进士，
                	父子三探花。
[37m
LONG);

  set("valid_startroom", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fywaiter" : 1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : 10,
  "z" : 0,
  "x" : 10,
]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nwind1",
  "up" : __DIR__"fyyage",
]));

  setup();
  replace_program(ROOM);
}
