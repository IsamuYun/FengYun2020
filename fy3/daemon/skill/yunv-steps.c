#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "$n���β���,�������ɵ�����$Nת�˸�Ȧ��,ʹ��һ��" + HIC "�������貨��" NOR + "��$N����ʽ������ա�\n",
        "$n��$N΢΢һЦ,$Nһ��֮��,$n�Ѿ��Ƶ���$N�����,�õ�����" + HIW "��һЦ�����" NOR + "��\n",
        "$nʹһ��"+ HIR "��������ơ�" NOR + ",��������һ��,$N��ǰһ��,$n����Ӱ�Ѿ������ټ���\n",
        "$n����һ��,������׵��������,һ��" + HIY "�����ҹ����" NOR + "�õ������޷졣\n",
        "����$nʹһ��"+ HIM "��������Ӱ��" NOR +"������Ʈ��������$N�Ĺ���ʧȥ��׼ͷ��\n",
        "$n����һ��,ͻȻ������׹,һʽ"+ HIG "������׹¥��" NOR + "��$N�Ĺ���ȫ����ա�\n",

});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취ѧϰ��Ů����\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("�������������������������Ů����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

int effective_level() { return 25;}

int learn_bonus()
{
        return -90;
}
int practice_bonus()
{
        return -50;
}
int black_white_ness()
{
        return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("wudujiao") + "/dodge/" + action;
}