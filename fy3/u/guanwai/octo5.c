
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
  "east" : __DIR__"octo4",
  "west" : __DIR__"octo6",
  "south" : __DIR__"work",
]));
        set("outdoors", "guanwai");
        set("coor/x",-1230);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",-1230);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

