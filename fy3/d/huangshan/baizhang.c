// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
��ɽ��������֮һ�������ֱ�¶������ɹ���ͤԶ����Ϊ׳�ۣ�
���˽��ۣ��������齦��ˮ��������һ������֮���������������
һ�����ķ��顣����ľ����ٸ��Ǿ��ѡ�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"qingluan",
  "northup" : __DIR__"jiulong",
]));
        set("objects", ([
                __DIR__"npc/shui" : 1,
       ]) );
	set("resources/water",1);
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-500);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
