// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ");
        set("long", @LONG
�������������ߵ���ʯ��ʯ��һ������ϡ�ɼ���������״ǡ��
����������ʯ������ʯ���֣������پ������������Ʒ�һ����������
�����ֽ��ڴ˴�������ʯ�������б����Խ�ʯ��
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"shijian",
  "northup" : __DIR__"banshan",
  "northeast" : __DIR__"qingluan",
  "westdown" : __DIR__"sandie",
]));
        set("objects", ([
        __DIR__"obj/stone2" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-550);
	set("coor/y",-520);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
