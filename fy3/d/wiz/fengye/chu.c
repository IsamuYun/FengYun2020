#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", BLINK BLU"厨房"NOR NOR);
  set ("long",@LONG
这是枫家的厨房，好香的气味从里面飘出来。
有一口大锅，还再冒着烟，看了就想吃。
LONG);

  set("valid_startroom", 1);
  set("exits",([
  "home":"/d/wiz/fengye/home",
]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);

  setup();
}
void init()
{
       add_action("do_ponder","chi");
}
int do_ponder(string arg)
{
       object who;

       who = this_player();
        if((int) who->query("sen") <=10)
        return notify_fail("你的命都快没了，还吃个屁。\n");
       message_vision("$N嘟囔着:肚子又饿了，偷点吃的把。n" ,who);
       who->receive_damage("sen",10);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 15 ) );
       message_vision("$N嘟囔着:偷的东西就是好吃。 \n" , who);
    return 1;
}
