// xgchen@zzfy
inherit ROOM;
void create ()
{
  set ("short", "业务室");
  set ("long", @LONG
这里是郑州风云巫师的业务室这里将会开放给巫师使用功能
具体请MORE HERE!
LONG);
  set("coor", ([ /* sizeof() == 3 */
  "y" : 0,
  "z" : 10,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"hall",
  "enter" : __DIR__"outjail",
]));
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);
  setup();
  replace_program(ROOM);
}
