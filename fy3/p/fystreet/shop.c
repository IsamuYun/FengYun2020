#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"�����̳�"NOR);
	set("long",@LONG
�����Ƿ��ƽ��̳���
LONG	);
	set("exits",([
	"east" : __DIR__"street0",
	"up" : __DIR__"shop2",
	"down" : __DIR__"bar",
	]));
	set("coor/x",60);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}