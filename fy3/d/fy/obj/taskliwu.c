#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY "礼品包" NOR,({"lipin-bao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIR "一个天机老人给的礼品包，似乎可以(cai)打开。\n"NOR);
                set("unit","个");
                      set("no_get",1);
                            set("no_drop",1);
                             }
}
void init()
{
        add_action("open_gongbao","cai");
}
int open_gongbao(string arg)
{
        object goldd;
        object psd;
        object jin;
        if (this_player()->query("add_task_over") != 1){
              message_vision(HIR"不是$N的东西请不要打开。\n"NOR,this_player());
                return 1;
        }
         if (this_player()->query("open_task_over") != 1){
              message_vision(HIR"不是$N的东西请不要打开。\n"NOR,this_player());
                return 1;
        }
      if ( arg == "lipin-bao"){
          psd = new("d/fy/npc/obj/dan");
          jin = new("questobj/obj/hongbao2");
             goldd = new("obj/money/gold");
          goldd->set_amount(500+random(200));
        psd->move(this_player());
        goldd->move(this_player());
        jin->move(this_player());
 this_player()->delete("open_task_over");
             message_vision(HIY"$N打开了天机老人给的礼品包。\n"NOR,this_player());
        tell_object(this_player(),RED"你发现里面装着一堆黄金，一棵叛师丹和一个解迷大红包。\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}


