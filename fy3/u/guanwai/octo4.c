
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
  "west" : __DIR__"octo5",
  "east" : __DIR__"octo3",
]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/lama2" : 2,
        ]) );
        set("coor/x",-1220);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",-1220);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

