// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
��ͷ���������������ǻ�ɽ����Ȫ�е�һ������Ϊ��ɽ��й��Ȫ
ˮ�������������γ����۶���������Զ�۽�����������Χ���ĵ�ɽ�֣�
���������ױȵ�ʤ��������Ȫ��Զ������Ȫ��
LONG
        );
        set("exits", ([ 
  "eastup"  : __DIR__"zuishi",
  "west"	: __DIR__"mingxuan",
]));
        set("objects", ([
                __DIR__"npc/3que" : 1,
       ]) );
        set("outdoors", "huangshan");
	set("coor/x",-560);
	set("coor/y",-520);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
