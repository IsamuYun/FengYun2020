// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���㱳");
        set("long", @LONG
����̽���ɣ��������㱳�ˣ�һ�γ�Լʮ���ɣ�������ɣ�����
��գ�������Ԩ��ʯ���м���ǰ����ν���춼����·��ͨ��ָ�ľ���
��һ�Σ�ֱ��������һ·�����ſ������ɵ��춼���������㱳����
����ǰ��ġ����˰Ѷ��š��������춼���ˡ�
LONG
        );
        set("exits", ([ 
  "northup"  : __DIR__"tiandu",
  "south" : __DIR__"guanyin",
  "west" : __DIR__"erxian",

]));
        set("outdoors", "huangshan");
	set("coor/x",-560);
	set("coor/y",-500);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
