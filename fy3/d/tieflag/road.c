// road.c
// QC'ed by Tie@fy2
inherit ROOM;
void create ()
{
  set ("short", "С·");
  set ("long", @LONG
���￿�������ɽǧ�𶴣���������ɽ��ɽ�µıؾ�֮·��
��·����һƬСС���֣�һ��ʯ��������ʯ�ʡ�һ��С���ڴ�
��������������Ϊ��¡��
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
