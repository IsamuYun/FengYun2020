#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "�Ϲ�Ǯׯ");
        set("long", @LONG
��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����˼�Ǯׯ���Һ��֣������Ϲ���ҵ֮
һ���Ϲ�Ǯׯ����Ʊ�������ã����ϱ����ɶ��֡����Ǹ��ɵй��Ľ�Ǯ�Ҳ����
�����Ǯׯ������һ��ľ��̨�����˶�ߣ������ƣ�����һ�顣
[31m
                        �Ϲ�Ǯׯ
[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"bazha",
  "east" : __DIR__"bazha1",
  "southeast" : __DIR__"bazha3",
]));
        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ�ҡ�
withdraw    ��ȡ��
deposit     ����Ǯ�ҡ�
balance     ��Ѱ��
loan        ��Ǯׯ��Ǯ��

TEXT
        ]) );
        set("objects", ([
                __DIR__"npc/bankowner" :1,
                __DIR__"npc/swaiter7" :1,
                __DIR__"npc/swaiter8" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1130);
	set("coor/y",1080);
	set("coor/z",0);
	setup();
}
