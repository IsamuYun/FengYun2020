inherit ROOM;
void create()
{
        set("short", "皇宫");
        set("long", @LONG
这里是当今皇上休息的地方，四周辉煌膨碧，龙床附近有一个雕像，不
知是谁的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
    "south" : __DIR__"poemp",
  
]));
	
			set("no_magic",1);
        set("outdoors", "fengyun");
  set("coor", ([ /* sizeof() == 3 */
  "y" : 2,
  "z" : 0,
  "x" : -10,
]));
        set("objects", ([
       ]) );
setup();
        replace_program(ROOM);


}

