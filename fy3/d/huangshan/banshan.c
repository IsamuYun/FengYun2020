// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
��ɽ�վ�����ȥ�������̣����������߶�Ϊ���ҿ��޵�ɮ�ˣ���
�Ի�ɽ֮���������ࡣ��ɽ����Ϊ����һλ�ó�ɽˮ�Ĵ󻭼ҡ�ѩׯ
���С�������������֮�ס����������������漣�������ɰ�ɽ������
��ɽ������ʯ������������ȥ�춼�塣
LONG
        );
        set("exits", ([ 
  "westup"  : __DIR__"guanyin",
  "eastdown" : __DIR__"qingluan",
  "southdown" : __DIR__"zuishi",
]));
        set("outdoors", "huangshan");
	set("coor/x",-550);
	set("coor/y",-510);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
