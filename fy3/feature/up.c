// Room: /feature/up
inherit ROOM;

void create()
{
  set ("short", "饭店");
  set ("long", @LONG
$HIR$这是一个豪华无比的饭店，由于它太豪华了，所以我想我不用多加形容了吧？
LONG);

  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/wanmei/center",
]));
  set("no_fight", 1);
  set("no_clean_up", 1);
  setup();
  replace_program(ROOM);
}
