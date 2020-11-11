#include <ansi.h>
#include <weapon.h>
inherit ITEM;
void create()
{
        set_name( HIG "杀人证" NOR, ({ "sr_zheng", "zheng" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
                        "一张能进去杀人比赛的证明。\n");
                set("value", 0);
              set("no_give",1);
//		set("no_get",1);
              set("no_drop",1);
        }
        setup();
}
void init()
{
        add_action("do_open", "si");
}

int do_open(string arg)
{
	object me;
        int exp,pot,score;
        exp=4000+random(4000);
        pot=1000+random(1000);
        score=35+random(20);
    	me = this_player();
          if(query("srname") == me->query("id"))
                  return notify_fail("唉！你有问题呀，想撕掉自己的东西？\n");
 if( !arg || arg=="" ) return 0;
      if( arg=="zheng" || arg =="sr-zheng" ) {
      message_vision(HIW"\n\n$N抹了抹头上的汗水，用沾满鲜血的双手撕开了"+this_object()->name()+"。\n"NOR , me);
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
void owner_is_killed(object killer)
{
       message_vision(HIR"\n \n $N成功的杀死了一个敌人，$N的把杀人证放在怀中！\n\n",killer);
 	this_object()->move(killer);
}
