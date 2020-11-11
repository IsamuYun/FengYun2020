#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR "朝廷俸禄" NOR,({"fenglu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIR "一个皇上御赐的俸禄包，似乎可以(open)打开。\n"NOR);
                set("unit","个");
                      set("no_get",1);
                            set("no_drop",1);
                             }
}
void init()
{
        add_action("open_gongbao","open");
}
int open_gongbao(string arg)
{
        object goldd;
        if (this_player()->query("fenglu_open") == 1){
              message_vision(HIR"不是$N的俸请不要打开。\n"NOR,this_player());
                return 1;
        }
       if ( arg == "fenglu"){
   	  goldd = new("obj/money/gold");
	  goldd->set_amount(100+random(300));
	 goldd->set("name",HIY" 朝廷制黄金"NOR);
        goldd->move(this_player());
        this_player()->set("fenglu_open",1);
              message_vision(HIW"$N打开了皇上御赐的俸禄包。\n"NOR,this_player());
        tell_object(this_player(),HIY"你发现里面装着一堆黄金。\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}

