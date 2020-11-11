// XXDER@fy
inherit ROOM;
#include <command.h>
#include <ansi.h>
void create()
{
        set("short", "榕树上");
        set("long", @LONG
你发现你现在以经隐身在大榕树上，在这里阳光也透不过茂密的树冠。站在树
上，你视野宽广，看到远处的沼泽正冒着浓烟......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "down" : __DIR__"garden",
   ]));

   set("item_desc", ([
   "tiao" : "一根断掉的藤条，看来已经不能使用了。\n",
   "藤条" : "一根断掉的藤条，看来已经不能使用了。\n",

   ]) );
        set("coor/x",0);
        set("coor/y",-610);
        set("coor/z",50);
        setup();
}

