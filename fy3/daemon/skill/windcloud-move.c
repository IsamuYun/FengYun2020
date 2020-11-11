// yiru@hero
// windcloud-move.c
// �ɷ�������

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "����$n����Ʈ��������һ�ݣ�һ�С��ɷ���ơ�������׾ٵıܿ���һ����\n",
        "$n����ͻת��һʽ������ѿǡ�������ܿ������ߡ�\n",
        "$n�������ϰ���һ�С��������ɡ���һ��ת����������֮�⡣\n",
            "$nһ�С������·����������籡��һ�㣬$N�����޴�ʹ��\n",
            "ֻ��$n��Ӱһ�Σ�һʽ���������������ѱ����߳�֮�⡣\n",
                "����$nʹһ�С��ƾ����᡹����������Ʈ�˿�ȥ��\n"
});

int valid_enable(string usage)
{
    return (usage=="dodge") || (usage=="move") || (usage=="magic");
}

void skill_improved(object me)
{
    int sk=me->query_skill("windcloud-move", 1);
        if( sk >= 120) {
        if ( (string) me->query_skill_mapped("dodge") == "windcloud-move") return;
                tell_object(me, 
             HIW "�������ɷ��������Ľ�������ѧ���������ɷ����������㣡\n" NOR );
            me->map_skill("dodge","windcloud-move");
        }
}

int valid_learn(object me)
{
    object ob;
    int sk = me->query_skill("windcloud-move", 1);

        if( (int)me->query_skill("incarnation",1) < sk )
                return notify_fail("���������Ϊ������û�а취���ɷ���������\n");

        if( (string)me->query_skill_mapped("force")!= "incarnate-body")
                return notify_fail("�ɷ���������������ɷ������Ϊ�ڹ���������\n");

    if( me->query("family/family_name")!="��ɽ����" )
        return notify_fail("�ɷ�������ֻ���Դ��ڸ����ŵ��ӡ�\n");
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    int sk = me->query_skill("windcloud-move", 1);
        if( (sk >= 120) && ( (string)me->query_skill_mapped("dodge") != "windcloud-move") ){
                tell_object(me, 
             HIW "�������ɷ��������Ľ�������ѧ���˽��ɷ��������������㣡\n" NOR );
            me->map_skill("dodge","windcloud-move");
        }

    if(me->query_skill("windcloud-move")>=120)
            return notify_fail("�ɷ���������������ز�ֻ�ܴ�ѧϰ����ߡ�\n");

        if( (int)me->query("atman") < 12 )
                return notify_fail("������������ˣ��������ɷ���������\n");
        me->add("atman", -12);
        return 1;
}

int effective_level() { return 21;}

int learn_bonus()
{
        return 120;
}
int practice_bonus()
{
        return 12;
}
int black_white_ness()
{
        return 12;
}

string perform_action_file(string action)
{
        return CLASS_D("xianren") + "/pal-steps/" + action;
}

string conjure_magic_file(string action)
{
        return CLASS_D("xianren") + "/pal-steps/" + action;
}
