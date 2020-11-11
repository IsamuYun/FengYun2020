//wdl的小屋
//ROOM: /open/myhome.c
//wdl bye 2000/12/19
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", BLINK HIY"温馨小屋"NOR NOR);
  set ("long",@LONG
这里是罗曼蒂克自己的休息室，只供他自己休息或和朋友
一起聚会。看起来摆设很简单，只有一排书架，一张温暖的小
床，一个写字台和几张椅子。迎面墙上题这一首诗：
    三代探花鸿都客，古道瘦马走秋夜。
    玉盏酒滴楚腰轻，剑气震动平湖月。
    罗衣绣衾沉香雪，桃花乱落如红雨。
    黯然西风出东关，春闺忆君梦寒铁。
    弹铗自饮塞外道，寂寞英雄古原草。
    燕台空散十丈红，中都已绝音尘小。
LONG);

  set("exits",([
  "up":"/d/fy/fysquare",
  "txf":"/d/wiz/fengye/home",
]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);

  set("objects",([
  __DIR__"girl.c":1,
]) );
  setup();
        call_other("/obj/board/wizard_b", "???");
}
void init()
{
object room;
if((this_player())->query("gender") != "女性")
{
if(!room = find_object("/d/wiz/fengye/home"))
room = load_object("/d/wiz/fengye/home");
this_player()->move(room);
}
}
