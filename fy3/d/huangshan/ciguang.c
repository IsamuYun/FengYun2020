// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ȹ��");
        set("long", @LONG
�����һ��嶥�����������Ȫ����ſ����飬ǶӳȺ�壬ǰ���
������ţ����˵���һ�㶼Ҫ����ЪϢ�����Ǳ����������ȹ��
LONG
        );
        set("exits", ([ 
  "eastdown" : __DIR__"wenquan",
  "south"  : __DIR__"taoyuan",
  "westdown" : __DIR__"qingluan",
]));
        set("objects", ([
                __DIR__"npc/feng" : 1,
		__DIR__"npc/jin" : 1,
       ]) );

        set("outdoors", "huangshan");
	set("coor/x",-530);
	set("coor/y",-510);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
