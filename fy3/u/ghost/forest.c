#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ԭʼ����");
	set("long", @LONG
������һƬ�ڰ����ڰ��г����˸�ʽ������Σ�գ�ÿһ�ֶ�����
�����������ڴ�������ʧ�˷��򣬼��ʾ�����������
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest7",
		"south" : __DIR__"forest1",
		"east" : __DIR__"forest5",
		"west" : __DIR__"forest6",
	]));
	set("outdoors", "ghost");
        set("NONPC",1);
	set("coor/x",-1190);
	set("coor/y",-50);
	set("coor/z",-10);
	set("coor/x",-1190);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();

}
void init()
{
	if (this_player()->query("marks/enterghost"))
	{
		this_player()->move("/u/ghost/dating");
		message_vision("\n\n"+HIY"һ����ι�����$N����������Ʈ���˺þ������ص������˵��ϡ�\n"NOR,this_player());
	}
}