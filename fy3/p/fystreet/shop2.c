#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"�Ҿ߳�"NOR);
	set("long",@LONG
�����Ƿ��ƽ��̳���¥��
LONG	);
	set("exits",([
	"down" : __DIR__"shop",
	]));
	set("objects",([
	__DIR__"npc/seller":1,
	__DIR__"npc/obj/jiaju":3,
	__DIR__"npc/obj/jiaju1":3,
	]));
	set("coor/x",60);
	set("coor/y",20);
	set("coor/z",10);
	set("no_fight",1);
	setup();
}