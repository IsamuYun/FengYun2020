
inherit ROOM;

void create()
{
        set("short", "�κ���");
        set("long", @LONG
�ӹ�����ʯ�񣬱�ֱ���У� ֻ��ǰ�澺��һ��Ϫ�����ϼܺ�ʯС�ţ�
���Ϻ�Ȼд���� ���κ��ţ� ���֣� ��Ŀ��ȥ�����κ��ţ��Ǳߣ��ֲ���һ
Ƭ������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"river",
  "north" : __DIR__"stonelin",
  "south" : __DIR__"ghost",
]));
        set("objects", ([
        __DIR__"obj/mirror" : 1,
                        ]) );

        set("outdoors", "palace");

        set("coor/x",160);
	set("coor/y",-30);
	set("coor/z",20);
	set("coor/x",160);
	set("coor/y",-30);
	set("coor/z",20);
	set("coor/x",160);
	set("coor/y",-30);
	set("coor/z",20);
	set("coor/x",160);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}

