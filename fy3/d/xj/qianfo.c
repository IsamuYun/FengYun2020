#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "���ο����ǧ��");
        set("long", @LONG
ʼ���ڹ�Ԫ���������ϸ߲���ʱ�ڣ�һֱ�Ǹ߲������ķ���صء�
�ڻ��󲿷ֲл٣��д沿�������Դ�����Ϊ�����С�������ʿ�䡱��
���ٰ�ͼ�����������䡱����С���ס��ȡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huoyan",
]));
        set("objects", ([
                __DIR__"npc/youke" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1030);
	set("coor/y",1030);
	set("coor/z",0);
	setup();
}