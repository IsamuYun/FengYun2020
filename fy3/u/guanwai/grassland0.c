
inherit ROOM;

void create()
{
        set("short", "��ԭ");
        set("long", @LONG
������һ���޼ʵĴ��ԭ����ɫ�Ĳݵ������þ������ʵ����졣��ԭ��
������������Ⱥ����������Ʈ���Ķ����ơ�Զ���Ĳ��������ڽ����¿���
���紿��������Ϧ������ʱ�ֱ�ò�����ƽ���Ҳ���û�뵽���������
����֮�ؾ����������ĵط������ûԻͶ����أ����������Ի���������
�����ˡ�
LONG
        );
        set("exits", ([ 
  "east" : "/u/quicksand/mroad2",
  "west" : __DIR__"grassland1",
]));
        set("outdoors", "guanwai");

        set("coor/x",-1140);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-1140);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

