#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
 object obj;

 if (!arg) return notify_fail("��Ҫ��ʲô?\n");
 if( !objectp(obj = present(arg, me)) )
        return notify_fail("������û������������\n");
 if (!obj->query("prick") && obj->query("prick")!=me)
        return notify_fail("��������û�в��������ϣ�\n");
 if(me->is_busy())
        return notify_fail("����һ��������û����ɣ�\n");

 
message_vision(HIR "$N��ס$nҧ������һ�Σ�\n" NOR, me, obj);
obj->move(environment(me));
message_vision(HIR "$N���һ����$n���˳�����һ��Ѫ�����˳�����\n" NOR, me, obj);
me->receive_wound("kee", 200);
me->receive_wound("sen", 200);
me->apply_condition("throw_poison", 0);

obj->delete("prick");
obj->delete_temp("prick");
obj->delete_temp("pricked");
obj->set("name",(string)me->query_temp("prick"));
me->delete_temp("prick");
return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : drag_out <��Ʒ����> 
���㱻��һ���������֮��,�ñ����������������,����,����Ҫ�γ�����.
���ָ���ǽ�����ı��������ڰγ�.���ǰγ�ʱ��������������˺�.
��������������������,һ��������Ӹ���,��һ����,������Խ��Խ��ʱ,
һ�ΰγ����ܻ��������˹���ʹ��ɥ��.
HELP
    );
    return 1;
}

