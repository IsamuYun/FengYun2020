// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "¹íÃÅ¹Ø");
        set("long",
"ÃÍÒ»¾ªĞÑ£¬²»¾õÉíÔÚ¹íÃÅ¹Ø£¬¸ß´óµÄ³ÇÇ½±ßÎ¼Ë®»·ÈÆ£¬ÒõÆøÉ­É­£¬\n"
"¼¸¸öÃæÄ¿ÕøÄüµÄÅ£Í·£¬ÂíÃæÊÖ³ÖÎäÆ÷°ÑÊØ³ÇÃÅ£¬¹´ËÀÈËÊÖ³ÖÌúÁ´\n"
"ÕıÔÚÍÏ×§×Å¼¸¸öÈËÓ°×ßÁË½øÈ¥£®£®£®£®£®£®£®£¬³ÇÃÅÂ¥ÉÏ¸ßĞüÒ»\n"
"·ùÅÆØÒ£º[31m¹íÃÅ¹Ø[37m\n"
);
        set("exits", ([
                "south" : __DIR__"naihe",
		"east" : __DIR__"aihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/niutou":1,
		__DIR__"npc/mamian":1,
		__DIR__"npc/panguan" : 1,
        ]) );
        set("no_fight",1);
  set("no_death_penalty", 1);
	set("no_magic",1);
	set("coor/x",-1020);
	set("coor/y",0);
	set("coor/z",-100);
	setup();
        replace_program(ROOM);
}
 
