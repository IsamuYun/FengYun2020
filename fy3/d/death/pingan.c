// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ƽ����");
        set("long", @LONG
�����Ѿ��ǵظ����ĵ�·�ˣ���Ϊ�˵ض���Ͷ�����˱ؾ�֮·������
ʮ�ְ�������Ϊ�����������������ٴ���ʮ�ꡣ�ɴ���ȥ��ԶԶ��һ
���ţ�ʮ�ֵ���ΰ��
LONG
        );
        set("exits", ([
		"north" : __DIR__"wangsi",
		"south" : __DIR__"aihe",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-80);
	set("coor/z",-290);
	setup();
        replace_program(ROOM);
}
 
