// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
string *dodge_msg = ({
        "$nһ�С�ħ����Ӱ����ȫ������ǧ�ٸ���Ӱ��������$N��һ�С�\n",
        "$n���۵��һ�С�����ħ�¡������μ������㿪$N������һ����\n",
        "$n������������Х������һ�С�ħ�����¡����������⡣\n",
        "$n˫����̤������һ�С�ħ���컡��������ޱ�����ص������ߡ�\n",
        "$nʹ��������ħ�����˲��еġ�ħӰ��á������λ�ʵΪ��ض㿪��$N��һ�С�\n",
        "$n�ڿ�һԾ��˫�������̤��һ�С�ħ�����������㿪���ߡ�\n",
        "$n���λζ���һ�С�ħ���¡����ȫ������������Ӱ�ӳ����⡣\n",
        "$n����һ������һ�С���ħ���Ρ���������һ���ޱȹ��������Ť���ŵ������ߡ�\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	 if( (int)me->query_skill("demon-force", 1) < (int) me->query_skill("demon-steps",1) )
                return notify_fail("��������ħ�ķ�����㣬�޷��������ħ�����˲���\n");
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	return notify_fail("������ħ�����˲�ֻ��ͨ��ѧϰ��������\n");
	return 1;
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("mojiao") + "/demon-steps/" + action;
}
string belong()
{
	return "mojiao";
}
