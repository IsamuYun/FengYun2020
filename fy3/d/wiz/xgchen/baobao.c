#include <ansi.h>
inherit ITEM;

void init()
{
       add_action("do_open","open");
}
void create()
{
      set_name( HIC"补"HIY"尝"HIG"红"HIM"包"NOR, ({ "liwu" }) );
        set_weight(1);
        set("unit", "个");
        set("long",HIY"这是一世风云为补偿玩家因为意外损失特意制作的奥运红包！\n"NOR);
        set("material", "paper");
set("value", 10);

        setup();
}
int do_open()
{
        int  exp, pot, score, money;
        object mon, me, ob;        

        me = this_player();
        
                exp = 500000;
        pot = 100000;
        score = 2;
        me->add("potential", pot); 
        me->add("combat_exp",exp); 
        me->add("score",score);
 me->add("gongxian",10000);

        tell_object(me, HIY "你获得了：\n" NOR + HIG +
        exp + "  点实战经验\n" NOR + HIC +
        pot + "  点潜能\n" NOR + HIW +
        score + "  点综合评价\n" NOR );
              if (present("liwu",me)) destruct(present("liwu",me));
        return 1;
}

