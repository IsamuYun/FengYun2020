// ��������Դ��书���� ԭ��maxim@nju_fengxue��д������xgchen@zzfy�޸�
// pltd
// �����쵶
// ����Сѧ��ǰ��У��
// 9801914
// Ů��
// unarmed
// ��ϯȭ��





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nһ����,һ��[��ɽ��˶ཿ],��ȭ����$n��$l",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "����",
"skill_name" : "��ɽ��˶ཿ"
]),
// ZHAOSHI :1

([
"action" :"$Nһ���֣�һ��[����Ӣ�۾�����]�����ƿ���$n��$l",
"damage" :80,
"dodge" : 10,
"parry" :-10,
"damage_type": "����",
"skill_name" : "����Ӣ������"
]),
// ZHAOSHI :2

([
"action" :"$Nһ���֣�һ��[�غ������Ĳ�]�����ƿ���$n��$l",
"damage" :100,
"dodge" : 10,
"parry" :-20,
"damage_type": "����",
"skill_name" : "�غ������Ĳ�"
]),
// ZHAOSHI :3

([
"action" :"$Nһ���֣�һ��[����������ѷ��ɧ�ݣ����ƴ���$n��$l",
"damage" :130,
"dodge" :25,
"parry" :30,
"damage_type": "����",
"skill_name" : "������ѷ��ɧ"
]),
// ZHAOSHI :4

([
"action" :"$N����������һ����һ��ˣ�����$n��$l---��",
"damage" :150,
"dodge" :30,
"parry" :40,
"damage_type": "����",
"skill_name" : "˼���乭���"
]),
// ZHAOSHI :5

([
"action" :"$N��˫��һ� һ��ʣ� ����ľ�����$n��$l�����",
"damage" :180,
"dodge" :40,
"parry" :50,
"damage_type": "����",
"skill_name" : "����������"
]),
// ZHAOSHI :6

([
"action" :"$N����ָ��ǰ����һ�л�����������������$n��$l��",
"damage" :200,
"dodge" :50,
"parry" :60,
"damage_type": "����",
"skill_name" : "���������쵶"
]),
// ZHAOSHI :7

([
"action" :"$N���������һ�һ��ͣ�$n��$l��˼�������ˣ�",
"damage" :220,
"dodge" :80,
"parry" :70,
"damage_type": "����",
"skill_name" : "ͬ־��������"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"��ϯȭ��"+"������֡�\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������̫�����޷���"+"��ϯȭ��"+"��\n");
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
