// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɢ����");
        set("long", @LONG
ɢ������һ��ȣ����з��Ͳβ�ʼܷ壬����ʯ�ȴ�����䣬
Զ�۷��͵��֣����˹�ʯ���ɡ�ÿ������֮��������ʢ�������Ƿ�
���ƽ�������Ůɢ�����γ�һƬ����ȵء�������������Ĺ�ʯ��
��������
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"paiyun",
  "northwest" : __DIR__"shisun",
  "north" : __DIR__"mengbi",
]));
        set("outdoors", "huangshan");
	set("coor/x",-610);
	set("coor/y",-520);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
