#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "û�����ֵĵط�");
        set("long", @LONG
�����Ǹ�����ֵĵط����ڲ����ط�������ů�紺������ҹ��
����ط����ǹ������硣�����оƣ�ȴ���Ǿ�¥���жģ�ȴ���Ƕĳ���
����ʱ�����������κ��µ�Ů�ˣ�ȴҲ���Ǽ�Ժ����ط�����û����
�֣�ȴ�Ǹ����������������ĵط��������а���ʮ�������ӣ�������
ѡ����һ���������������㶼�������ܵ���õľƲˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beimen",
  "south" : __DIR__"bazha",
]));
        set("objects", ([
                __DIR__"npc/yekai" :1,
                __DIR__"npc/hong" :1,
                __DIR__"npc/hua" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1100);
	set("coor/z",0);
	setup();
}