// ��������Դ��书���� ԭ��maxim@nju_fengxue��д������xgchen@zzfy�޸�
// xiaoliu
// ���ѩ��
// �·��ǰ��������ư����
// 13367281
// Ů��
// unarmed
// �·���ȭ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N���⹥�ģ��������һȭ����$n���Ŀ�",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "����",
"skill_name" : "�������"
]),
// ZHAOSHI :1

([
"action" :"$Nһ�����飬���ߵߣ�һʽ��С��ä��š���ȫ�������$n���",
"damage" :80,
"dodge" :15,
"parry" :15,
"damage_type": "����",
"skill_name" : "С��ä���"
]),
// ZHAOSHI :2

([
"action" :"$Nһ�����飬���ߵߣ�һʽ��С��ä��š���ȫ�������$n���",
"damage" :100,
"dodge" :20,
"parry" :20,
"damage_type": "����",
"skill_name" : "С��ä���"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"�·���ȭ"+"������֡�\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������̫�����޷���"+"�·���ȭ"+"��\n");
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
