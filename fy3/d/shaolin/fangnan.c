// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������Ժ");
        set("long", @LONG
���������Ѿ�û����ס�ˣ���������ī�ͣ���ѧ̩�����ͷ���֮����
���ڴˣ��������Բ̾��ġ���������Ϊ���ڡ�
LONG
        );
        set("exits", ([ 
  "southup" : __DIR__"changjing",
  "north" : __DIR__"fang",
]));
        set("outdoors", "shaolin");
	set("coor/x",-210);
	set("coor/y",240);
	set("coor/z",40);
	setup();
}
void init()
{
	if(!this_player()->query_temp("see_fangzhang"))
	{
		set("exits/northup",__DIR__"lixue");
		delete("exits/north");
	}
	else 
	{
		set("exits/north", __DIR__"fang");
		delete("exits/northup");
	}
}
