//txf的wc
//ROOM: /d/wiz/fengye/wc.c
//txf bye 2001/1/26
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", BLINK BLU"男厕所"NOR NOR);
  set ("long",@LONG
这是枫家的厕所，主要给大家方便用的。但是要收费的啊。1gold一次。
有一个白玉小马桶。还有一个浴盆，好象很舒服啊。
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
       add_action("do_ponder","poop");
}
int do_ponder(string arg)
{
       object who;

       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("你的神不够。\n");
       message_vision("$N嘟囔着:肚子疼不是病，一泡稀屎没拉净。一屁股坐在马桶上。n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 15 ) );
       message_vision("$N似乎感觉神清气爽，@#$%#$%朴哩朴拉。。好臭。 \n" , who);
    return 1;
}
