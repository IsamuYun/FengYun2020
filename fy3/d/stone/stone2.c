// Tie@fengyun
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "ʯ�ﾡͷ");
        set("long", @LONG
ʯ��ľ�ͷ��һ�¸�ǽ��ǽ����һ��խ�ţ�ǽ����һ������
һ����ϡϡ��С�ӹ��ӹ�����������ʱ����ʱ�ģ�һ��������Ѫ
ˮ�ı����ӹ�����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"stone1",
  "north" : __DIR__"sroom",
]));

        set("outdoors", "fengyun");
        set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
       create_door("north", "խ��", "south", DOOR_CLOSED);

}
