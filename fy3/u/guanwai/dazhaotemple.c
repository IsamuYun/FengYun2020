
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������ʮ�ɣ���һ�ٶ�ʮ�ɡ��������ѵ���ܦ��������ɽ���ϵĳǱ���
���ϵ���Ժ�����������١�¥���㲻��Ĵ��������������������ͣ���
�����ξ����������񻰡�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"octostreet",
  "west" : __DIR__"templeyard",
]));
 set("objects", ([
      //          __DIR__"npc/kazuya" : 1,
        ]) );

        set("outdoors", "guanwai");
        set("coor/x",-1210);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-1210);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

