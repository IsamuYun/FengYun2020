
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
  "west" : __DIR__"octo14",
  "south" : __DIR__"octo16",
  "east" : __DIR__"shop",
]));
        set("outdoors", "guanwai");
        set("coor/x",-1200);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-1200);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
