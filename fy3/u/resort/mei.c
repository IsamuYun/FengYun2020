// Room: /u/resort/mei
inherit ROOM;

void create ()
{
  set ("short", "梅园");
  set ("long", @LONG
园里种满了精心修剪过的梅花树，雪白而又透着
粉红的梅花竞项开放,清新的梅香味充满整个园子，被
风吹落的梅花四处飘舞着。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/girl2" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"front_yard",
]));
  set("no_magic", 1);

        set("coor/x",-1240);
	set("coor/y",50);
	set("coor/z",-10);
  setup();
  replace_program(ROOM);
}
