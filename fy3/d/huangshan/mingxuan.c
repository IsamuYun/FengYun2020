// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
Ȫˮ�Ը�ɽʯ����Ȼ���£����һ�����ɽ´������ұ��пգ�
״����ٵ���ʯ�������ö����н������������������Թ�ʫ�޵�
��ȴ��������ϸ������ʮ���Ҿ㲻�ڡ���
LONG
        );
        set("exits", ([ 
  "east"	: __DIR__"sandie",
]));
        set("objects", ([
        __DIR__"obj/stone3" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-570);
	set("coor/y",-520);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
