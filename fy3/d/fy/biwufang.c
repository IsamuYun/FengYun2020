// xgchen@zzfy
inherit ROOM;
void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是比武选手的休息室．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"biwukantai",
  "down" : __DIR__"poemp"
]));
        set("no_magic",1);
        set("no_exert",1);
        setup();
}

void init()
{
object room;
if(this_player()->query("gender")=="女性")
{
if(!room = find_object("/d/fy/biwufang2"))
room = load_object("/d/fy/biwufang2");
this_player()->move(room);
}
}
