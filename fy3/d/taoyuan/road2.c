inherit ROOM;
void create()
{
        set("short", "����ʯ��·");
        set("long", @LONG
����ʯ��·��ɽ�ּ�ı������ʪ���������͵����Ź⣻ʯ������
̦���ܵ������˷�϶������������Ь���Ž�Ѿ���������ܣ����һ�������
���е�������ʯ��·�ı��������ɢ���ż���ũ�ҡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "west" : __DIR__"road1",
   "east" : __DIR__"road3",
   "south" : __DIR__"linjian",
]));

   	set("outdoors","taoyuan");
        set("coor/x",200);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}


