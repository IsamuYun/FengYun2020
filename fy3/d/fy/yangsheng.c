inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "������");
  set ("long", @LONG
�������ıڽԿգ�Ψǽ��������������У��������ޡ���ɫ��ɫ�������пա�����
Ϊ�У�����Ϊ�ޡ�ɫ��Ϊɫ���ǿ�Ϊ�ա��ռ���ɫ��ɫ����ɫ��ɫ�޶�ɫ��ɫ���ǿա�
���޶��գ��ռ���ɫ��֪�ղ��գ�֪ɫ��ɫ��
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huofe" : 1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : -49,
  "z" : 0,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pusheng",
]));

  setup();
  replace_program(ROOM);
}
