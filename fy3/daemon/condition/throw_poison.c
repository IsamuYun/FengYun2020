//xgchen@zzfy
#include <ansi.h>

int update_condition(object me, int duration)
{
       int ban;
        if( duration < 1 ){
       message("vision", "��ͭ�����ĵ��˿��Ѿ�ֹͣ��Ѫ��,������������"+me->query("name")+"�����ϡ�\n", environment(me), me);
             return 0;
       }
       ban = me->query("max_kee");
       me->receive_wound("kee", ban/20);
       me->apply_condition("throw_poison", duration - 1);
       message("vision", "Ѫ��"+me->query("name")+"���ϵļ�һ��һ������˳�����\n", environment(me), me);
       tell_object(me, RED "$N���Ѫ��������������ʹ���Ұ�(drag)��\n" NOR );
       switch(random(4)) {
              case 0:
                       message_vision (YEL"���ĵ���ʹ��$N�ҽ�һ����\n\n"NOR,me);
               break;
              case 1:
                        message_vision (YEL"$N�޺�����˭�ܰ����?\n\n"NOR,me);
               break;
              case 2:
                       message_vision (YEL"$N���˿ڿ�ʼ�����ˡ�\n\n"NOR,me);
                break;

        }
        if( duration < 1 ){
             return 0;
       }
        return 1;
}

