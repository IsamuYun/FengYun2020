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
   "north" : __DIR__"nongjia",
   "west" : __DIR__"taovillage",
   "south" : __DIR__"teaplace",
   "east" : __DIR__"road2",
]));

   	set("outdoors","taoyuan");
        set("coor/x",190);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}
