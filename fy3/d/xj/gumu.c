#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "��˹����");
        set("long", @LONG
��˹������ά������˼�ǡ��׸�����Ĺ�ᰴ���������ÿһ��
����й̶���Ĺ�أ�����ʯΪ�磬ÿ��Ĺ���������б��Ĺ������Ĺ�ҡ�
Ĺ����Ĺ�Ҷ�������һ�㶼�Ѱ���ʯ��ƽ��ʡ��ס����Ρ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"emin",
]));
        set("objects", ([
                __DIR__"npc/ghost" :2,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1050);
	set("coor/y",1020);
	set("coor/z",0);
	setup();
}
