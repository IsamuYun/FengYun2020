#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "�������ϳ���");
        set("long", @LONG
����������Ԫ�����������������ֵĳ�������İ�����������ʷ�ƾ�
�������������������й�ǧ�����ʷ���������ν��ʮ�ﳤ�֣������Ƽ�����
�������Ǵ�������������ͳ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"bazha3",
  "south" : __DIR__"tulu2",
]));
        set("objects", ([
                __DIR__"npc/police2" :1,
                __DIR__"npc/wall_solider" :2,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1060);
	set("coor/z",0);
	setup();
}