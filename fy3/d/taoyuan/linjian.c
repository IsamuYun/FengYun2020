inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ɽ��ï�ܣ�����µ�����ϸ��ǡ��û�㣬��������������������Ż���
���㣬͸���ּ䣬��Լ�ɼ�����ũ�ҵĴ��̣�ԶԶ�ĺ�������ʮ��ֻ������ּ�
��Ծ��Ϸ������һƬ�˼��ɾ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"road2",
]));

   	set("outdoors","taoyuan");
        set("coor/x",200);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}


