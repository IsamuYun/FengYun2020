
#include <ansi.h>

int update_condition(object me, int duration)
{
       int ban;
        if( duration < 1 ){
             me->set("kf_working",0);
             if (present("ling pai",me)) destruct(present("ling pai",me));
//       message("vision", "衙役举起大板对着"+me->name() + "的屁股狠狠的打下最后一板。\n", environment(me), me);
       tell_object(me, HIG "衙役举起大板对着你狠狠的打下最后的一板！\n" NOR );
             return 0;
       }
       ban = me->query("max_kee");
       if(environment(me)!=find_object("/d/fy/zt")) return 0;
       me->receive_wound("kee", ban/100);
       me->apply_condition("kf_stop", duration - 1);
       message("vision", "衙役举起大板对着"+me->name() + "的屁股狠狠的打了下去。\n", environment(me), me);
       tell_object(me, HIG "衙役举起大板对着你的屁股就是狠狠的一下！\n" NOR );
       switch(random(4)) {
              case 0:
		       message_vision (RED"$N发出一阵杀猪般的惨叫。\n\n"NOR,me);
       	       break;
              case 1:
                        message_vision (RED"$N哭嚎道：林大人，饶命啊！饶命啊！！\n\n"NOR,me);
       	       break;
              case 2:
		       message_vision (RED"$N的屁股绽开了花。\n\n"NOR,me);
              	break;

        }
        if( duration < 1 ){
             me->set("kf_working",0);
             if (present("ling pai",me)) destruct(present("ling pai",me));
             return 0;
       }
        return 1;
}
