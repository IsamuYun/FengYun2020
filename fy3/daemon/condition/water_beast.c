//����Ӣ��
//function for water beast
//by lion@hero

#include <ansi.h>

int update_condition(object me, int duration)
{
    object beast;
    me->apply_condition("water_beast", duration - 1);
    if( duration < 1 ){ 
    beast = new("/d/heimiao/npc/waterbeast");
    message_vision(HIG"ˮħ��"HIR"�ָ����ˣ�ҡ����ӷ�׵�������$N���˹�����\n"NOR,me);
    beast->move(environment(me));
    return 0;
     }
    if(!me->query_temp("water_beast")){   //ʹ����ʱ�������������ͻȻ���ߵ������
    me->apply_condition("water_beast", 0);
    return 0;  
     }
    return 1;
}
string query_type() { return "waterbeast"; }
