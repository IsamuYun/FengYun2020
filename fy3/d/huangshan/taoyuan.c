// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Դͤ");
        set("long", @LONG
����λ���һ����ϣ���ΧϪ�����ƣ������ɾӣ��ʳ���Դͤ����
�����֮�����ڿ��Ծ������ͻ�ɽ������֮һ�ġ������١���Զ����
ȥ���ٲ���й��ǡ���Ǹ����֣�ɷ����Ȥ��
LONG
        );
        set("exits", ([ 
  "north"  : __DIR__"ciguang",
]));
        set("objects", ([
                __DIR__"obj/ting" : 1,
       ]) );
        set("outdoors", "huangshan");
	set("coor/x",-530);
	set("coor/y",-520);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
