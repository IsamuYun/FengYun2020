inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("千年石钟乳" , ({"shi zhongru" }) );
    if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long","由石钟岩经过长时间天然而成的一种非常珍贵的药材，也是武林中人梦寐以求的宝贝。\n");
                set("unit", "滴");
                set("value", 10000);
                }
        setup();
}


void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  int gin, kee, sen, atman ,mana , force ;
  {     object me;
        me = this_player();
       if( !arg || arg=="" ) return 0;
       if( arg=="shi zhongru" || arg =="千年石钟乳" )
     {
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
message_vision(HIW"\n$N迫不急待地把千年石钟乳滴入嘴里，顿时觉浑身一阵透底的凉爽!\n"NOR, me);
        destruct(this_object());
        return 1;
  }
}
}
