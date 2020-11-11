inherit ROOM;
void create()
{
set("short", "会客厅");
set("long", @LONG
tiandi的房间
LONG
);
set("exits", ([ 
  "south" : "/u/wiz/dating",
]));
   set("objects", ([
                "/cmds/usr/news" : 1,
       ]) );
setup();
replace_program(ROOM);
}
