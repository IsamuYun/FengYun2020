// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��¶̨");
        set("long", @LONG
��˵�����뾭���콵��¶��������Ϊ��¶̨��̨������Űأ�̨��
���ù������Ѹ�¶̨���Ű�ס��
LONG
        );
        set("exits", ([ 
  "eastdown" : __DIR__"tayuan",
]));
        set("objects", ([
                __DIR__"npc/master_21" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-230);
	set("coor/y",260);
	set("coor/z",60);
	setup();
	create_door("eastdown", "ľ��", "westup", DOOR_CLOSED);
}
