// ɽè(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ����ʯ�̳ɵ�С·�ϣ�С·�ı�����Ǳ��䳡���п�̨��������
���䳡�Ĵ��š������(enter)������䳡��
LONG);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"gate",
	]));
	setup();
}

void init()
{
	add_action ("do_enter","enter");
}

int do_enter(string arg)
{
	object me=this_player();
	string mout=YEL ""+me->query("name")+"�߽��˱��䳡��\n" NOR;
	string min=YEL ""+me->query("name")+"�������˽�����\n" NOR;

	message( "vision", mout, environment(me), ({me}) );
	me->move(__DIR__"kantai2");
	message( "vision", min, environment(me), ({me}) );
	return 1;
}
