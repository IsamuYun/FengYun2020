// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
���˻�ɽ���ճ������ڣ�ÿ���峿�����˵���������յ�Σ����
����Զ����ֻ�������Ƶ�����ƽ�̣��������ʱ���ޡ���Ρ���Ⱥ��
����û���ƺ�֮�С�������ʵ���ǰױ������ʹ����ĳ�ϼ����
��������ĺ��Խ��Խ����ֱ�����ֻ�������ƺ����ڿն������þ�
�����˻�ζ��
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"diezhang",
  "northwest" : __DIR__"feilong",
  "east" : __DIR__"shizi",
]));
        set("outdoors", "huangshan");
	set("coor/x",-630);
	set("coor/y",-530);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
