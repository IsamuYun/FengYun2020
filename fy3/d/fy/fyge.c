// inn.c

#include <room.h>

inherit ROOM;


void create ()
{
  set ("short", "���Ƹ�");
  set ("long", @LONG
���Ƹ�����˾��ǵ�����������������С��ɵ�����̽�������������⣬������
�кܶ����Ľ�������˸�����һ��֮Ե�����д�첨˹��̺�̵أ������û͡����
�Ĵ����������һ��ʯ�̵Ķ�������
[33m
                	һ���߽�ʿ��
                	������̽����
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
