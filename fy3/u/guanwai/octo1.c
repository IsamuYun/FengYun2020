
inherit ROOM;

void create()
{
        set("short", "�˽ǽ�");
        set("long", @LONG
�������⣬Χ������Ժ�İ˽ǽ��ǲ���������������ֵĵط�������
���Ŀ�ջ���̺Ŷ����������ϡ�Զ��������ʱ��������һ���������Ʈ
���������ļⶥ��̫�������Ž�⣬��������ʥׯ�����µľ���
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"octostreet",
  "south" : __DIR__"octo2",
  "east" : __DIR__"inn",
]));
        set("outdoors", "guanwai");
        set("coor/x",-1200);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-1200);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}
