
#include <ansi.h>

int update_condition(object me, int duration)
{
       int ban;
        if( duration < 1 ){
             me->set("kf_working",0);
             if (present("ling pai",me)) destruct(present("ling pai",me));
//       message("vision", "���۾��������"+me->name() + "��ƨ�ɺݺݵĴ������һ�塣\n", environment(me), me);
       tell_object(me, HIG "���۾����������ݺݵĴ�������һ�壡\n" NOR );
             return 0;
       }
       ban = me->query("max_kee");
       if(environment(me)!=find_object("/d/fy/zt")) return 0;
       me->receive_wound("kee", ban/100);
       me->apply_condition("kf_stop", duration - 1);
       message("vision", "���۾��������"+me->name() + "��ƨ�ɺݺݵĴ�����ȥ��\n", environment(me), me);
       tell_object(me, HIG "���۾�����������ƨ�ɾ��Ǻݺݵ�һ�£�\n" NOR );
       switch(random(4)) {
              case 0:
		       message_vision (RED"$N����һ��ɱ���ĲҽС�\n\n"NOR,me);
       	       break;
              case 1:
                        message_vision (RED"$N�޺������ִ��ˣ�������������������\n\n"NOR,me);
       	       break;
              case 2:
		       message_vision (RED"$N��ƨ�������˻���\n\n"NOR,me);
              	break;

        }
        if( duration < 1 ){
             me->set("kf_working",0);
             if (present("ling pai",me)) destruct(present("ling pai",me));
             return 0;
       }
        return 1;
}
