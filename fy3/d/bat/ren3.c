//3290,0,10
inherit ROOM;
void create()
{
        set("short", "孤峰绝顶");
        set("long", @LONG
   海风劲吹。天下尽在眼底，这才是人间的绝顶。
只有举世无匹的高手才能登上这里，但是高处不胜寒！
LONG      );
        set("exits", ([ 
		 
		  "southdown" : __DIR__"ren2",
		]));         
		set("objects",([
                __DIR__"npc/baiyiren" : 1,
       	]) );
    set("outdoors", "bat");
    set("coor/x",3290);
	set("coor/y",50);
	set("coor/z",60);
	set("no_magic",1);
	set("no_dazuo",1);

	setup();
}
