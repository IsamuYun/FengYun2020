inherit SKILL;

string *parry_msg = ({
        "$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ������������������¡�\n",
        "$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
        "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
        "$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
        "$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
        "$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

string *dodge_msg = ({
        "$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ������������������¡�\n",
        "$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
        "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
        "$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
        "$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
        "$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}

string query_parry_msg(string limb)
{
       return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
	if( (int)me->query("kee") < 3000
	||	(int)me->query("force") < 300 )
		return notify_fail("������������������������ƻ���ľ��\n");
	me->receive_damage("kee", 1000);
	me->add("force", -100);
	return 1;
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("yihua-jimu", 1);

        if ( !wizardp(this_player()) && (me->query("family/family_name") != "�ƻ���"))
                return notify_fail("�㲻���ƻ������Ӳ���ʹ���ƻ���ľ.\n
                                    �ƻ���ľ������, ���ƻ������Ӳ���, �治֪��������ôѧ���!\n
                                    Ҫ������λ����֪������ɲ���.\n");
        if ( me->query("gender") != "Ů��")
                return notify_fail("�ƻ���ľ���ƻ�����������,�����������ӡ�\n");

if ((int)me->query_skill("mingyu-shengong", 1) < 50)
                return notify_fail("��������񹦻���������ô��ѧ�ƻ���ľ�أ�\n");

if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("����ô������ڹ�����ѧ�ƻ���ľ��\n");

    if ((int)me->query("max_force", 1) < 800)
                return notify_fail("����ô����������ѧ�ƻ���ľ��\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��\n");

        return 1;
}
int effective_level() { return 30;}

int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/yihua-jiemu/" + action;
}
