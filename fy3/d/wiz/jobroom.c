// Tie@fy3
inherit ROOM;
void create ()
{
  set ("short", "�����");
  set ("long", @LONG
���µĵ�ɢ������͵Ĺ⣬��ľ��̨����Χ���˼���
���ӡ���������Ĳ�������ô�ĺ�г��������볨�����
���飬ʹʹ���ؽ����е�ʵ��ʹ�ҷ�����������Ϣ
�ң������Ƿ�Ժ���������Ǽ�����
LONG);

  set("coor", ([ /* sizeof() == 3 */
  "y" : 0,
  "z" : 10,
  "x" : 0,
]));
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"hall",
  "north" : __DIR__"courthouse",
  "down" : "/d/fy/fysquare",
  "west" : __DIR__"outjail",
  "east" : __DIR__"jail",
]));
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);

  setup();
  replace_program(ROOM);
}

