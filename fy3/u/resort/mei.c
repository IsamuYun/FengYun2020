// Room: /u/resort/mei
inherit ROOM;

void create ()
{
  set ("short", "÷԰");
  set ("long", @LONG
԰�������˾����޼�����÷������ѩ�׶���͸��
�ۺ��÷�������,���µ�÷��ζ��������԰�ӣ���
�紵���÷���Ĵ�Ʈ���š�
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
