// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ɹ���");
        set("long", @LONG
������ʯ�ף���;����ï��������֦�Ϲ�������ݣ�Խ��������
�����ľ��ĸо�����ǰ����վ���Ȼ��ͬ������ʯ�ױ����ɹ��֣�����
һ�������ĵ��ۣ���ǰ�����纣����̶��������ɫ�����������������
����̶�����ء�

                  [42;41m����������������������[0m
                  [42;41m��[33m   �� �� �� �� [42;41m   ��[0m
                  [42;41m����������������������[0m
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"feicui",
  "northup" : __DIR__"caishi",
  "east" : __DIR__"diezhang",
]));
        set("objects", ([
        __DIR__"npc/master" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-650);
	set("coor/y",-540);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
