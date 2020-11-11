// outdoor.c zip@hero 2000.1.27 房子门口
#include <ansi.h>
#define ID 101
inherit ROOM;
void create()
{	string *dir=({"东","西"});
	set("short",HIG"风云街"+chinese_number(ID/100)+"号"+dir[ID%2]+NOR);
	set("long",@LONG
风云街，风云城内风云人物居住的地方，能在这里拥有一间房子是无数人的
梦想。快乐的快乐[2;37;0m就在这里。郁郁葱葱的松林，鸟语花香。
o
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","sku");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"