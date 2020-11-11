// road.c
// QC'ed by Tie@fy2
inherit ROOM;
void create ()
{
  set ("short", "小路");
  set ("long", @LONG
这里靠近佛教名山千佛洞，又是往来山上山下的必经之路。
在路边有一片小小树林，一张石桌，几张石凳。一个小贩在大
声叫卖，生意颇为兴隆。
LONG);

  set("outdoors", "tieflag");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaofan" : 1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : 2000,
  "z" : 0,
  "x" : 40,
]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/qianfo/tanghuai",
  "east" : "/d/qingping/gate",
  "eastup" : __DIR__"road0",
]));

  setup();
  replace_program(ROOM);
}
