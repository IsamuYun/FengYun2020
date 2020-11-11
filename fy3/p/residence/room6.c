#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",YEL"泰安广场"NOR);
  set("long",@LONG
在这里你能享受到城内少有的清净。彩色石块铺成的大道向四方伸延。广场
呈菱形，街面是由碗口大的彩色石块铺成，青兰紫绿，煞是好看。广场旁有个清
水池，池内鱼虾龟虫倒也养了不少，在这四季如春的气候下，荷花睡莲无比妖娆。
LONG
  );
  set("exits",([
          "southwest" :__DIR__"room7",
	  "northwest" :__DIR__"room5",	
               ]));
	set("owner","public");
        set("outdoors", "qianfo");
  	set("coor/x",20);
	set("coor/y",2040);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",2040);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
