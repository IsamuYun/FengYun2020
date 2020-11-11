// hongbao.c
// ken 1999.12.3
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( HIR "杀人红包" NOR, ({ "sr-hongbao", "hongbao" }) );
        set_weight(10);
        set("value", 100000);
        set("unit", "个");
        set("long", "这是用别人生命换来的奖励，你可以打开(open)看看。\n");
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
        exp=4000+random(1000);
        pot=1000+random(1000);
        score=35+random(20);
    	me = this_player();
      if( !arg || arg=="" ) return 0;
      if( arg=="sr-hongbao" || arg =="红包" ) {
      message_vision("\n\n$N抹了抹头上的汗水，用颤抖的双手, 迫不急待地打开了"+this_object()->name()+"。\n"NOR , me);
      message_vision(HIW"\n$N不带一点的伤心，仿佛不知道这是用别人生命换来的。\n\n"NOR, me);
      me->add("combat_exp",exp);
      me->add("potential",pot);
      me->add("score",score);
      me->add("newpk",1); 
tell_object(me,HIY"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+chinese_number(pot) + "点潜能\n"+
         chinese_number(score) + "点评价\n"+
         NOR);
       tell_object(me,HIW"\n恭喜你!\n"NOR);
       destruct(this_object());
       return 1;
}
         return 1;
}

