#include <ansi.h>
inherit ITEM;

void init()
{
       add_action("do_open","open");
}
void create()
{
      set_name( HIC"奥"HIY"运"HIG"红"HIM"包"NOR, ({ "liwu" }) );
        set_weight(1);
        set("unit", "个");
        set("long",HIY"这是郑州风云为答谢新老完家的厚爱，为大家特意制作的奥运红包！\n"NOR);
        set("material", "paper");
  set("value", 1);
set("no_drop", 1);
        setup();
}
int do_open()
{
        int  exp, pot, score, money;
        object mon, me, ob;        

        me = this_player();
        
        if(me->query("olympic2")==2)
        {
        message_vision(HIM"你已打开过红包了吧，想占便宜呀？\n"NOR,this_object(), me);
        return 1;
        }
        exp = 10000 + random(10000);
        pot = 2000 + random(10000);
        score = random(200);
        me->add("potential", pot); 
        me->add("combat_exp",exp); 
        me->add("score",score);
        tell_object(me, HIY "你获得了：\n" NOR + HIG +
        exp + "  点实战经验\n" NOR + HIC +
        pot + "  点潜能\n" NOR + HIW +
        score + "  点综合评价\n" NOR );
        me->set("olympic2",2);
        if (present("liwu",me)) destruct(present("liwu",me));
        return 1;
}

