
inherit ROOM;

void create()
{
        set("short", "ɳ��С��");
        set("long",
"����ĵ�����һ�ֻƺ�ɫ�����ɫ��ʯ����Ƕ��ϸϸ�Ļ�ɳ֮�У�\n"
"�����Լ������ĸо������������������ԭ���м�ش�������\n"
"�����Ǳ�����\n"
);
        set("exits", ([ 
  "east" : __DIR__"huangyie1",
  "west" : __DIR__"saikou",
]));
        set("outdoors", "quicksand");

        set("coor/x",-1020);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-1020);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

