//sku@00-11-19 
inherit ROOM;
void create ()
{
  set ("short", "密道");
  set ("long", @LONG
这是快乐为了偷懒，自己修的秘密通道：
     [45m天机 A  沉香 B  三清 C  大理 D  关外 E  黄山 F[0m
     [42m魔教 G  万梅 H  武当 I  神水 J  常春 K  少林 L[0m
     [43m神剑 M  清风 N  嵩山 O  兴国 P  蝙蝠 Q  幽灵 R[0m
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : "/d/fy/fysquare",
  "west" : __DIR__"workroom",
]));
  set("coor", ([ /* sizeof() == 3 */
  "z" : 1000000,
  "x" : 0,
  "y" : 0,
]));
  set("no_magic", 1);

  setup();
  replace_program(ROOM);
}
