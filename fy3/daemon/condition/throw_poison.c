//xgchen@zzfy
#include <ansi.h>

int update_condition(object me, int duration)
{
       int ban;
        if( duration < 1 ){
       message("vision", "受铜箭穿心的伤口已经停止流血了,但是它还留在"+me->query("name")+"的身上。\n", environment(me), me);
             return 0;
       }
       ban = me->query("max_kee");
       me->receive_wound("kee", ban/20);
       me->apply_condition("throw_poison", duration - 1);
       message("vision", "血从"+me->query("name")+"身上的箭一点一点的流了出来。\n", environment(me), me);
       tell_object(me, RED "$N想把血箭拨出来可是怕痛不敢拔(drag)！\n" NOR );
       switch(random(4)) {
              case 0:
                       message_vision (YEL"穿心的伤痛让$N惨叫一声。\n\n"NOR,me);
               break;
              case 1:
                        message_vision (YEL"$N哭嚎道：谁能帮帮我?\n\n"NOR,me);
               break;
              case 2:
                       message_vision (YEL"$N的伤口开始严重了。\n\n"NOR,me);
                break;

        }
        if( duration < 1 ){
             return 0;
       }
        return 1;
}

