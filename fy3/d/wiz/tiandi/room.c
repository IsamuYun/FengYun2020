inherit ROOM;
void create()
{
set("short", "�����");
set("long", @LONG
tiandi�ķ���
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
