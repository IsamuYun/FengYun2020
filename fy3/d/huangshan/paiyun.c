// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����ͤ");
        set("long", @LONG
�������Ƶ���Ѵ�����ɽ�ƺ�������֣������ϱ������캣��
���������ƶ�Ϊ��״���������ε��ˣ�����ͤ��Ϊ���ƶ�����Ҳ��
�ƶ�������������Ծ�����ɽ����֮�ƺ������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"shizi",
  "north" : __DIR__"sanhua",
  "east" : __DIR__"feilai",
]));
        set("outdoors", "huangshan");
	set("coor/x",-610);
	set("coor/y",-530);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
