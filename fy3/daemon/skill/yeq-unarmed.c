// ��������Դ��书���� ԭ��maxim@nju_fengxue��д������xgchen@zzfy�޸�
// xgchen
// ��������
// ��Ǯ�����������
// 13720000
// ����
// unarmed
// Ұ��ȭ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ������ʽ��������ֱ��������$n��$l",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "����",
"skill_name" : "����ʽ"
]),
// ZHAOSHI :1

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ʽ�𡹣�����ֱ��������$n��$l",
"damage" :80,
"dodge" :-10,
"parry" :-10,
"damage_type": "����",
"skill_name" : "��ʽ��"
]),
// ZHAOSHI :2

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n��$l",
"damage" :100,
"dodge" :-20,
"parry" :-20,
"damage_type": "����",
"skill_name" : "���Ƚ�"
]),
// ZHAOSHI :3

([
"action" :"��������������$N����һԾ����������һ�С����к�ء���׼��$lбб�̳�һ��",
"damage" :130,
"dodge" :-30,
"parry" :-30,
"damage_type": "����",
"skill_name" : "���볤��"
]),
// ZHAOSHI :4

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ��������������ֱ��������$n��$l",
"damage" :150,
"dodge" :-50,
"parry" :-40,
"damage_type": "����",
"skill_name" : "Ұ��"
]),
// ZHAOSHI :5

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ��������������ֱ��������$n��$l",
"damage" :180,
"dodge" :-60,
"parry" :-50,
"damage_type": "����",
"skill_name" : "��������"
]),
// ZHAOSHI :6

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ��������������ֱ��������$n��$l7",
"damage" :200,
"dodge" :-80,
"parry" :-60,
"damage_type": "����",
"skill_name" : "����"
]),
// ZHAOSHI :7

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ��������������ֱ��������$n��$l8",
"damage" :220,
"dodge" :-90,
"parry" :-70,
"damage_type": "����",
"skill_name" : "������"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"Ұ��ȭ"+"������֡�\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������̫�����޷���"+"Ұ��ȭ"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
int effective_level() { return 20;}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 30);
	me->add("force", -30);
	return 1;
} 
string *parry_msg = ({
        "$n��������ƫ��$N��$w��\n",
});
string *unarmed_parry_msg = ({
        "$n���赭д�Ļ�����$N�Ĺ��ơ�\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus()
{
        return 30;
}
int practice_bonus()
{
        return -30;
}
int black_white_ness()
{
        return 320;
}
string perform_action_file(string action)
{
        return CLASS_D("player") + "/"+"unarmed"+"/" + action;
}
