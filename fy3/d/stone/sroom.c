// Tie@fengyun
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����ﳱʪ�����������Ӳ���ʮ��խС����ֻ��һ����һ����
һ�ʣ����Ե��ı���Ȼ���ն���į��Ҳ�ĵ���һյ�µƸ���ư�����
���ϵĻ���δ���������ϻ�����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"stone2",
]));
        set("objects", ([
                __DIR__"npc/master": 1, 
]) );
        set("valid_startroom", 1);

        set("coor/x",9);
	set("coor/y",30);
	set("coor/z",0);
	setup();
       create_door("south", "խ��", "north", DOOR_CLOSED);

}
