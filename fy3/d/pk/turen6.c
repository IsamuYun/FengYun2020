#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR "毒人场" NOR);
        set("long", @LONG
这里阴森恐怖，地上到处是残肢碎尸，无处不是暗红色的血滴。你心中
忐忑不安，万分警惕，不知道从哪里就会窜出一个黑影。
LONG
        );
        set("exits", ([
                "south" : __DIR__"turen10",
                "west"  : __DIR__"turen5",
                "northwest" : __DIR__"turen2",
        ]));
        set("no_magic",1);
        set("no_dazuo",1);
  set("pk_room", 1);
        setup();
        replace_program(ROOM);
}
