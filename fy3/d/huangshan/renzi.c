// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��ɽ������֮һ��λ�����ƣ���ɰ������ɽ��֮�У�������й
����ɽ֮ʱ�����о�ʯ��ɽ��б����������԰�;һ��Ϊ�����γ�һ
�����֣���������������������ֵ�����ֱ�����¡�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"qingluan",
]));
        set("objects", ([
                __DIR__"npc/xiangke" : 3,
       ]) );
	set("resources/water",1);
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-520);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
