// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
˵������ţ�ȷ�е�Ӧ������ɽ�ƿ���ȥ���ţ�ʵ������һ��ʯ
����Զ��ȥ��������ڿգ����Ͽ������ˣ�ʯ�������С���𽡱��
�֣���ȥ���ǻ�ɽ������֮������Ȫ�������б��ǰ�ɽ���ˡ�
LONG
        );
        set("exits", ([ 
  "eastup"  : __DIR__"ciguang",
  "south" : __DIR__"renzi",
  "southwest" : __DIR__"zuishi",
  "north" : __DIR__"baizhang",
  "westup" : __DIR__"banshan",
]));
        set("objects", ([
                __DIR__"obj/stone" : 1,
       ]) );
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-510);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
