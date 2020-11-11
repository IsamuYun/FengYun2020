// yiru@hero
// iceheart.c

#include <ansi.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
  int force, lvl;

  force =(int) me->query("force") - (int) me->query("max_force");
  lvl = me->query_skill("moon-magic",1);

  if(force<=100)
    return notify_fail("你的真气不足。\n");

    if(me->query_skill("moon-magic",1)<=120)
        return notify_fail("你的水月仙法太差了！\n");

  if( target != me )
  {
    me->start_busy(3);
    if(force<=150)
        return notify_fail("你的真气不足。\n");
    me->add("force", -150 );
    message_vision(HIB"\n$N将双手贴在$n背后，运起冰心诀，一股冰凉之气缓缓向$n输去。\n"NOR,me,target);
    if(target->query("force")*2>=me->query("force"))
    { 
        message_vision(HIR"\n但是$N突然手一震，似乎受到$n体内内力反击，一口鲜血“哇”的喷了出来。\n"NOR,me,target);
        me->receive_damage("kee",target->query("force")%100+1,target);
        COMBAT_D->report_status(me);
    }
    else if(random(lvl)<30)
    { 
        message_vision(HIW"\n$n只觉得一股冰凉之气侵入体内，不禁“的的的”打起了哆嗦。\n"NOR,me,target);
        write("运功冰心失败。\n");
    }
    else
    { 
        message_vision(HIB"\n$n只觉得一股冰凉之气直沁心脾，顿时心清目明，长长吐出一口气。\n"NOR,me,target);
        message_vision("\n$n中的毒消失了！\n",me,target);
        target->clear_condition();
    }
    return 1;
  }

    me->start_busy(2);
    if (random(lvl) < 20)
    {           
        me->add("force", -100  );
        message_vision("$N运功抗毒，头上冒出豆大的汗．．．\n", me);
        write("你失败了。\n");
    }
    else
    {
        me->clear_condition();  
        write("你成功了！\n");
    }
    return 1;
}
