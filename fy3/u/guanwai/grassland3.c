
inherit ROOM;

void create()
{
        set("short", "��ԭ");
        set("long", @LONG
������һ���޼ʵĴ��ԭ����ɫ�Ĳݵ������þ������ʵ����졣��ԭ��
������������Ⱥ����������Ʈ���Ķ����ơ�Զ���Ĳ��������ڽ����¿���
���紿��������Ϧ������ʱ�ֱ�ò�����ƽ���Ҳ����û�뵽���������
����֮�ؾ����������ĵط������ûԻͶ����أ����������Ի���������
�����ˡ�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"grassland4",
  "east" : __DIR__"grassland2",
]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/sheepgirl3" : 3,
		__DIR__"npc/sheep2" : 6,
              ]) );
 set("coor/x",-1170);
	set("coor/y",-10);
	set("coor/z",0);
        set("coor/x",-1170);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
