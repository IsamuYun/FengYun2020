inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "养生舍");
  set ("long", @LONG
养生舍四壁皆空，唯墙上书道：不有中有，不无中无。不色中色，不空中空。非有
为有，非无为无。色非为色，非空为空。空即是色，色即是色。色无定色，色即是空。
空无定空，空即是色。知空不空，知色不色。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huofe" : 1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : -49,
  "z" : 0,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pusheng",
]));

  setup();
  replace_program(ROOM);
}
