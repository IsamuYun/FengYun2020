#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�������Ǽ��е���˼���������ġ����������ڶ���ǰ���ǡ�˿��֮·�����������ĵط���
ÿ��ϡ�������ʱ���������ز�Ʒ���ֹ���Ʒ���Ϲ��߲˵�һ���򡰰�����ӿ������ʱ���
�����Կ���ͷ����ñ������Сë¿��������ʢװ�䡰���������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"bazha2",
  "north" : __DIR__"wuming",
  "southeast" : __DIR__"bazha1",
]));
        set("objects", ([
                __DIR__"npc/swaiter11" :1,
                __DIR__"npc/swaiter4" :1,
                __DIR__"npc/swaiter5" :1,
                __DIR__"npc/swaiter6" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1090);
	set("coor/z",0);
	setup();
}
