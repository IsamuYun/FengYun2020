//txf的小屋
//ROOM: /d/wiz/home.c
//txf bye 2001/1/26
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", BLINK HIY"小枫居"NOR NOR);
  set ("long",@LONG
这里是枫自己的休息室，只供他自己休息或和朋友
一起聚会。看起来摆设很简单，只有一排书架，一张温暖的小
床，一个写字台和几张椅子。迎面墙上题这一首诗：
事了拂衣去，深藏身与名。闲过信陵饮，脱剑膝前横。
救赵挥金锤，邯郸先震惊。纵死侠骨香，不惭世上英。
谁能书阁下，白首太玄经。十步杀一人，千里不留行。
LONG);

  set("exits",([
  "chu":"/d/wiz/fengye/chu",
  "down":"/d/fy/fysquare",
  "nwc":"/d/wiz/fengye/wc1",
  "up":"/d/wiz/jobroom",
  "wdl":"/d/wiz/wdl/myhome",
  "manwc":"/d/wiz/fengye/wc",
]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);

  setup();
}
int valid_leave(object me, string dir)
{
        if(  dir == "nwc" && me->query("gender") != "女性")
        return notify_fail("这是女人厕所，你冲进去作什么，变态啊？\n");
        if(  dir == "manwc" && me->query("gender") != "男性")
        return notify_fail("这是男人厕所，你冲进去作什么，白痴啊，男女不分？\n");
        return 1;
}
