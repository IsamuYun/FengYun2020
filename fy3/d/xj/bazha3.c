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
  "northwest" : __DIR__"bazha2",
  "south" : __DIR__"nanmen",
  "northeast" : __DIR__"bazha1",
]));
        set("objects", ([
                __DIR__"npc/swaiter1" :1,
                __DIR__"npc/swaiter2" :1,
                __DIR__"npc/swaiter3" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1070);
	set("coor/z",0);
	setup();
}
