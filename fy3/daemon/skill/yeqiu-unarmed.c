// ��������Դ��书���� ԭ��maxim@nju_fengxue��д������xgchen@zzfy�޸�
// xgchen
// ��������
// ��ͨ����
// 14000000
// ����
// unarmed
// Ұ��ȭ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nǰ���߳������Ƚż���,һʽ����ȭ���衹��˫ȭֱ��������$n��$l",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "��ȭ����"
]),
// ZHAOSHI :1



([
"action" :"$Nһ�С�Ұ�������������Ʈ�������̣�������$n��$lһ����",
"damage" :80,
"dodge" :-10,
"parry" :-10,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "Ұ�����"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"Ұ��ȭ"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
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
	if( (int)me->query("kee") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
} 
string *parry_msg = ({
        "$n��ƫ��$N��$w��\n",
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
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -10;
}
