// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�Ƿ��س�");
        set("long", @LONG
��ʯ�ֵ�����Խ��Խ�ӽ�ɽ����ÿ�����������������������
�οͼ��࣬������Ϊ������ɽ�ؾ�֮·�ĵǷ��سǷ�������֣���
·���ߵ�����������ɽ�����һ�У�����Ӧ�о��С�
LONG
        );
        set("exits", ([ 
  "east" : "/d/fy/wgate",
  "west" : "/u/quicksand/huangyie0",
  "northwest" : __DIR__"qimu",
  "southeast" : __DIR__"bupu",
  "southwest" : __DIR__"tiepu",
]));
        set("objects", ([
                __DIR__"npc/waiter" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",-200);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-200);
	set("coor/y",100);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
