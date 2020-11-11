// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "鬼门关");
        set("long",
"猛一惊醒，不觉身在鬼门关，高大的城墙边渭水环绕，阴气森森，\n"
"几个面目狰狞的牛头，马面手持武器把守城门，勾死人手持铁链\n"
"正在拖拽着几个人影走了进去．．．．．．．，城门楼上高悬一\n"
"幅牌匾：[31m鬼门关[37m\n"
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
 
