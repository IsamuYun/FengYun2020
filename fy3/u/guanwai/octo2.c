
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
  "north" : __DIR__"octo1",
  "west" : __DIR__"octo3",
]));
        set("outdoors", "guanwai");
        set("coor/x",-1200);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",-1200);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

