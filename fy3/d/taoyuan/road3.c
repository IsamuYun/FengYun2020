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
   "north" : __DIR__"anju",
   "west" : __DIR__"road2",
]));
//set("objects",([
//__DIR__"npc/cxq": 1, ]));
  	set("outdoors","taoyuan");
        set("coor/x",210);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	

}


