// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ�����");
        set("long", @LONG
�����ѵ�ڤ������ģ�·��������ڤ����˾���ƹ������ֻأ�
��Ϊ�ң�Т���ڣ��壬���ƳͶ�����ѭ�������˱�Ӧ����������
�޲�ǰ��һ�ã��Ծ�����
LONG
        );
        set("exits", ([
                "north" : __DIR__"naihe",
		"south" : __DIR__"yanluo",
		"northwest" : __DIR__"zong",
		"southwest" : __DIR__"jie",
		"northeast" : __DIR__"xiao",
		"southeast" : __DIR__"yi",
        ]) );

	set("coor/x",-1020);
	set("coor/y",-20);
	set("coor/z",-100);
	setup();
        replace_program(ROOM);
}
 
