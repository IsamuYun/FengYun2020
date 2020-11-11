#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR "碎尸场" NOR);
        set("long", @LONG
这里阴森恐怖，地上到处是残肢碎尸，无处不是暗红色的血滴。你心中
忐忑不安，万分警惕，不知道从哪里就会窜出一个黑影。
LONG
        );
        set("exits", ([
                "east"  : __DIR__"turen5",
                "south" : __DIR__"turen8",
                "west"  : __DIR__"turen3",
                "north" : __DIR__"turen1",
        ]));
        set("no_magic",1);
        set("no_dazuo",1);
  set("pk_room", 1);
        setup();
        replace_program(ROOM);
}
