// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����ͤ");
        set("long", @LONG
һ�������̽ǣ�����������Сͤ�������������Զ�ۻ�ɽ����
����֮һ�ġ�����Ȫ�����ɴ˿�����Ȫ��ֻ����̶�����ƶ����з�Ȫ
��й�����������콵������ʱ������ɴ��������ʱ����ǧƥ������
������ʣ�ʵ������ʤ�ա�
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"wenquan",
]));
        set("objects", ([
                __DIR__"npc/katai" : 1,
       ]) );
        set("outdoors", "huangshan");
	set("coor/x",-520);
	set("coor/y",-500);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
