// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "һ����");
        set("long", @LONG
�춼������Խ���������Ժȥ����С���£������ɣ�����ش�ֱ
��ϵ�绯�ġ�һ���족������ʮ���������ߴ���ʮ���׵�ʯ�ڽ�����
������������ף�խ��ֻ�а��ף��������գ�����һ�ߡ�һ������
����������Ժ�ˡ�
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"wenzhu",
  "eastup" : __DIR__"tiandu",
]));
        set("outdoors", "huangshan");
	set("coor/x",-570);
	set("coor/y",-490);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
