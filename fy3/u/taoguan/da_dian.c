#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���幬����");
	set("long", @LONG
����������Ľ�����������ǰ�������ϰ��Ÿ�ʽˮ��
��һ��Сͭ¯��ͭ¯�������֧�����˵��㡣������ǽ�϶�
û���κζ�����ȴ��ˢ�úܰס�����������һ������¯��
һλò�����˵ĵ�ʿ����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : "/u/taoguan/da_yuan",
		"northwest" : __DIR__"stoneroad",
]));
        set("valid_startroom", 1);
	set("objects", ([
                "/u/taoguan/npc/up_taoist" : 2,
                "/u/taoguan/npc/taolord2" : 1,

 ]) );
	set("coor/x",-20);
	set("coor/y",2110);
	set("coor/z",80);
	setup();
}

