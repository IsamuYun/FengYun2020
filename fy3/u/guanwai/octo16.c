
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
  "north" : __DIR__"octo15",
  "south" : __DIR__"octostreet",
]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/lama2" : 5,
        ]) );
        set("coor/x",-1200);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-1200);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
