inherit ROOM;
void create ()
{
  set ("short", "���������");
  set ("long", @LONG
������֣�ݷ�����ҵ�����ݡ��ϱ��з��Ƶ���������
LONG);

  set("no_death_penalty", 1);
  set("watch_fight_room2", 1);
  set("watch_fight_room", 1);
  set("no_perform", 1);
  set("no_exert", 1);
  set("no_du", 1);
  set("no_fight", 1);
  set("no_beg", 1);
  set("no_magic", 1);
  set("objects", ([ /* sizeof() == 3 */
    "/d/shaolin/npc/baixiaoshen" : 1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : 1,
  "z" : 20,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"poemp",
  "south" : __DIR__"wenroom2",
]));
  setup();
}


