#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_launch", "搜");
       add_action("do_stop", "停");
}


void create()
{
       set_name(BLU"神灯"NOR, ({"shen deng", "deng", "light"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
       	       set("long", "一只阿拉伯神灯，可以用它来“搜”人，搜索中可以“停”下来，但只能用三次。\n");
               set("value", 1000000000);
               set("unit", "只");
       }
}

int do_launch(string arg)
{
       object target, where, npc, me;
       me = this_player();
  
       if(!arg) return notify_fail("你这是要搜谁啊？给个名字来。 ( 搜 <id> ) \n");
       if(query("used") >= 3)
          return notify_fail("这只神灯已经用过三遍了，变得黯然无色。\n");
          
       if( me->is_busy() || me->is_fighting())
          return notify_fail("你正忙着呢。\n");

       if (objectp(target = LOGIN_D->find_body(arg))) 
            where = environment(target);
       else return notify_fail("没有这个人耶。。。\n");
       
       if (!where) return notify_fail("这个人在虚无飘藐间，找不到他。\n");
       
       if (wizardp(target)) return notify_fail("从神灯中冒出只幽灵，对着你就是一棒：竟敢偷看我们敬爱的巫师们！不要命啦？\n");

       if (target==me) return notify_fail("从神灯中冒出只幽灵，指着你哈哈大笑：世界上竟然有这么笨的蛋！\n");

       if(objectp(npc = me->query_temp("shendeng_npc")))
          return notify_fail("你正在使用着神灯呢。\n");
          
       message_vision(HIY"\n$N拿起一块破布，在神灯上擦啊擦啊。。。口中还一边念着"+target->name()+HIY"的名字。\n\n" NOR, me);
       npc = new("shendeng_npc");
       npc->do_setup(me, target);
       me->set_temp("shendeng_npc", npc);
       me->start_busy(1);
       me->add("used", 1);
       return 1;
}


int do_stop()
{
	object npc, me;
	me = this_player();
	
	if(!me->query_temp("shendeng_npc"))
          return notify_fail("你又没在使用着神灯，停什么停？\n");

	npc = me->query_temp("shendeng_npc");
        if(objectp(npc))
           npc->do_remove();
	message_vision(HIC"\n$N对着神灯吹了口气，拿个盖子将它盖上了。\n\n" NOR, me);
	me->delete_temp("shendeng_npc");
        me->start_busy(1);
	return 1;
}


