// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ɹ�Ϫ�ߣ������岼��������̶��ƽʱ̶ˮ�峺ƽ����ÿ��΢�紵����
����΢�����������ۣ����Խ���̶������ˮɫ��Ϊ�࣬�࣬�ڣ��ף��ϣ�����
һ̶��ˮ�����������Ա���Ϊ���ء�����ʯ����ʯ����������̣�Ӧ�о��У�
���з�ζ����˵�������µ�����������������̶�����Ҳ��֪��١�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"songgu",
]));
        set("objects", ([
        __DIR__"obj/pond1" : 1,
        __DIR__"obj/pond2" : 1,
        __DIR__"obj/pond3" : 1,
        __DIR__"obj/pond4" : 1,
        __DIR__"obj/pond5" : 1,
        __DIR__"obj/pond6" : 1,
                        ]) );

        set("outdoors", "huangshan");
	set("coor/x",-660);
	set("coor/y",-540);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
