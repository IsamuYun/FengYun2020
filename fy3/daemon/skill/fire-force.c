// �����ڹ�
// fire-force ��Ѫ����

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage)
{
    return     (usage=="iron-cloth") || (usage=="force");
}

int valid_learn(object me)
{
   
    if( me->query("max_force") < me->query_skill("force",1)*5 )
        return notify_fail("�������̫���ˣ�ǿ�����棡\n");

    if( me->query("max_force") < me->query_skill("fire-force",1)*15 )
        tell_object(me,
        HIY "�������Ĺ����У����Ѿ���ʼ�е��������㣬�ƺ�������ȥ�����߻���ħ��\n" NOR);
    return 1;
}

int practice_skill(object me)
{
    return 0;
}

int effective_level() { return 20;}

string *absorb_msg = ({
        HIC"$n������ת��˫��΢����ȫ���ھ��綾������ȶ�����\n"NOR,
        HIC"$n����΢չ��ȫ���죬������������˵Ķ��档\n"NOR,
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
    return 20;
}

int learn_bonus()
{
    return -5300;
}
int practice_bonus()
{
    return -5300;
}
int black_white_ness()
{
    return 200;
}
string exert_function_file(string func)
{
    return CLASS_D("heimiao") + "/fire-force/" + func;
}

string perform_action_file(string action)
{
    return CLASS_D("heimiao") + "/fire-force/" + action;
}

void skill_improved(object me)
{
    int force;
    if( me->query("max_force") > me->query_skill("force",1)*5+me->query_skill("force")*3/2 ) {
        tell_object(me, HIY "\n�㷢���������ǵñﲻ������������Ҫ�������Ƴ���\n\n" NOR);
        me->add("max_force",-me->query_skill("force",1));
        me->unconcious();
    }
    if( me->query("max_force") < random(me->query_skill("fire-force",1)*15) ) {
        tell_object(me, HIR "\n��ͻȻȫ���飡�߻���ħ�ˣ���....\n\n" NOR);
        me->skill_death_penalty();
        me->delete_skill("fire-force");
        me->unconcious();
    }
}
