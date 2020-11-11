// hongbao.c
// ken 1999.12.3
#include <ansi.h>
inherit ITEM;

void create()
{
        string *names = ({
               MAG "解迷奖励红包"NOR, HIG "解迷奖励红包"NOR, HIY "解迷奖励红包"NOR, HIC "解迷奖励红包"NOR
        });
        set_name( names[random(sizeof(names))], ({ "ackbao" }));
        set_weight(600);
        set("no_dropall",1);
        set("unit", "个");
        set("long", "此物极其珍贵，唯有解开极难迷题者才能获得，你可以打开(open)看看。\n");
       setup();
}  

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
	object me;
        int exp,pot,score;
        exp=12000+random(2000);
        pot=exp/7;
        score=80+random(400);
    	me = this_player();
      if( !arg || arg=="" ) return 0;
      if( arg=="ackbao" || arg =="红包" ) {
message_vision(HIG"\n\n$N见四下里无人，偷偷掏出个超级红包，用颤抖的双手, 迫不急待地打开了.....\n"NOR , me);
      message_vision(HIW"\n$N惊叫一声，吓了大家一大跳！\n\n"NOR, me);
      me->add("combat_exp",exp);
      me->add("potential",pot);
      me->add("score",score);
      me->add("STASK",1); 
tell_object(me,HIY"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+chinese_number(pot) + "点潜能\n"+
         chinese_number(score) + "点评价\n"+
         NOR);
       tell_object(me,HIR"\n\n       真诚地恭喜你!        本风云全体巫师\n\n"NOR);
       destruct(this_object());
       return 1;
}
         return 1;
}

//}
