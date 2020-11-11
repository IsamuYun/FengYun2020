inherit ROOM;
void create ()
{
  set ("short", "风云蜡像馆");
  set ("long", @LONG
这里是郑州风云玩家的蜡像馆。这里的蜡像有大侠，也有魔头，也有
不是大侠不是魔头的玩家。无论是哪一位，都曾冠绝一时，都有一个长长
而惊心动魄的故事，每一个故事都曾很深远地影响了一代甚至两三代玩家
。虽然他们都曾经轰轰烈烈掀起满江湖的风雨，如今，他们再也不会在江
湖出现了。他们都已经退出江湖，但他们的侠影魔踪很长时间以后仍是一
个传说。为了记念这里人物,长孙无情特意建造这个蜡像馆纪念前人。
LONG);

  set("no_death_penalty", 1);
  set("watch_fight_room2", 1);
  set("watch_fight_room", 1);
  set("no_perform", 1);
  set("no_exert", 1);
  set("no_du", 1);
  set("no_fight", 1);
  set("no_beg", 1);
  set("no_magic", 1);
  set("objects", ([ /* sizeof() == 3 */
//   "/d/shaolin/npc/baixiaoshen" : 1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : 0,
  "z" : 20,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wenroom",
]));
  setup();
}


