#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "地下");
        set("long", @LONG
这里的四周都是泥土，看来是地底下了。
LONG
        );
	set("NONPC",1);

        setup();
}
