#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"酒吧"NOR);
	set("long",@LONG
这里是风云街商场酒吧。
LONG	);
	set("exits",([
	"up" : __DIR__"shop",
	]));
	set("objects",([
	__DIR__"npc/waitress":1,
	__DIR__"npc/obj/kalaok":1,
	__DIR__"npc/obj/table":1,
	]));
	set("coor/x",60);
	set("coor/y",20);
	set("coor/z",-10);
	set("no_fight",1);
	setup();
}
int valid_leave(object me, string dir)
{ object ob,*user;
  int i,j;
  if(!objectp(ob=present("bar waitress",this_object()))) return 1;
  if(ob->query("cost")==0) return 1;
  user=all_inventory(this_object());
  for(i=0;i<sizeof(user);i++) if(userp(user[i])) j++;
  if(random(j)>2) return 1;
  message_vision("$N微笑着说道：您还没付账呢。\n啊，",ob);
return 0;}
   