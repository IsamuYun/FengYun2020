
inherit ROOM;

void create()
{
        set("short", "�ص�");
        set("long", @LONG
����һ������������������Ƕ��ͭ�ơ���бб��������£���֪
�ж೤��Ҳ��֪����δ���������ͭ�ƾ㶼���ü�Ϊ�������Լ��˵ؾ�����
�����ߡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"secretpath2",
  "west" : __DIR__"secretpath0",
]));
        set("objects", ([
        __DIR__"npc/redbeast" : 1,
                        ]) );


        set("coor/x",240);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

