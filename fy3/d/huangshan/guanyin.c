// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����ʯ");
        set("long", @LONG
�ɰ�ɽ�������������ŵ��춼���£�����һ��ͤͤ������ʯ�ˣ�
����һ���װ��Ů���˳ƹ���ʯ������һ��Сʯ��ǡ����֮ͯ�ӣ�
�⡰С��٪�����á���������ʯ�����ù��ɡ�ͯ�Ӱݹ���������
����㿪ʼ�ˡ��̿�ǧ���������ϵ��ݡ������춼��ؿ����
�͡��ĵǶ����̡�
LONG
        );
        set("exits", ([ 
  "eastdown"  : __DIR__"banshan",
  "westup" : __DIR__"yingke",
  "north" : __DIR__"jiyu",
]));
        set("objects", ([
        __DIR__"obj/guanyin" : 1,
	__DIR__"obj/xiaotong" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-560);
	set("coor/y",-510);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
