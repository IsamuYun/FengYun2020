// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���Ź�");
        set("long",
"��һ���ѣ��������ڹ��Źأ��ߴ�ĳ�ǽ��μˮ���ƣ�����ɭɭ��\n"
"������Ŀ������ţͷ�������ֳ��������س��ţ��������ֳ�����\n"
"������ק�ż�����Ӱ���˽�ȥ��������������������¥�ϸ���һ\n"
"�����ң�[31m���Ź�[37m\n"
);
        set("exits", ([
                "south" : __DIR__"naihe",
		"east" : __DIR__"aihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/niutou":1,
		__DIR__"npc/mamian":1,
		__DIR__"npc/panguan" : 1,
        ]) );
        set("no_fight",1);
  set("no_death_penalty", 1);
	set("no_magic",1);
	set("coor/x",-1020);
	set("coor/y",0);
	set("coor/z",-100);
	setup();
        replace_program(ROOM);
}
 
