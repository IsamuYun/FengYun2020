// ��������Դ��书���� ԭ��maxim@nju_fengxue��д������xgchen@zzfy�޸�
// zyzz
// ��������
// �����š�����[1;33m��ʵϰ���졿[2;37;0m
// 10565729
// ����
// blade
// ���ڵ���





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N΢΢һЦ��ƾ�ջ��£�ʹ��һ�С��������ڡ�������$w�����ƻð��ֱ��$n��$l��",
"damage" :50,
"dodge" :20,
"parry" :20,
"damage_type": "����",
"skill_name" : "��������"
]),
// ZHAOSHI :1

([
"action" :"$N���������ӿ�ȥ��$n����������$l����һ��",
"damage" :80,
"dodge" :10,
"parry" :20,
"damage_type": "����",
"skill_name" : "�Լ�����"
]),
// ZHAOSHI :2

([
"action" :"$N����$n��$l�������۾���һ��������ȥ��ֻ�����һ������ܱ�˺����",
"damage" :100,
"dodge" :10,
"parry" :10,
"damage_type": "����",
"skill_name" : "���ڵ�������"
]),
// ZHAOSHI :3

([
"action" :"$N����һ�ѻƽ�$n�ۻ����ң���һ������$l",
"damage" :130,
"dodge" :5,
"parry" :10,
"damage_type": "����",
"skill_name" : "���ڴ�����"
]),
// ZHAOSHI :4

([
"action" :"$N��һ�����ӣȣգԡ��գУ�$n����ˮ����һ��������һ����$l����������",
"damage" :150,
"dodge" :-5,
"parry" :5,
"damage_type": "����",
"skill_name" : "���ڴ�����"
]),
// ZHAOSHI :5

([
"action" :"$Nȫ��һ�ӣ�˭֪����$w�ϳ����飬ǰ�벿��ֱ��$n$l��ȥ",
"damage" :180,
"dodge" :-5,
"parry" :5,
"damage_type": "����",
"skill_name" : "���ڴ���"
]),
// ZHAOSHI :6

([
"action" :"$Nһ�ڰ�����ʣ�µľƺȸɣ�����δ���������Ӳ���죬��$w�ݸ�$n��˵�����ٻ�һ����",
"damage" :200,
"dodge" :-10,
"parry" :5,
"damage_type": "����",
"skill_name" : "���ڴ���"
]),
// ZHAOSHI :7

([
"action" :"$N�ֳ�$w����ϸ��һ���������Ž�ֺ�ף�ȫȻ����$n��������",
"damage" :220,
"dodge" :-10,
"parry" :5,
"damage_type": "����",
"skill_name" : "���ڴ󷨰�"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������̫�����޷���"+"���ڵ���"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int effective_level() { return 30;}
int practice_skill(object me)
{
object weapon; 
if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
                      return notify_fail("��ʹ�õ��������ԡ�\n");	
if( (int)me->query("kee") < 40 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 40 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 40);
	me->add("force", -40);
	return 1;
} 
string *parry_msg = ({
	"$nʹ��һ�����У�����$v���һ�У�ͻȻ���л�ʽ����ס$n��ȫ��\n",
});
string *unarmed_parry_msg = ({
"$nһ�з����������е�$v������$N����ʽ��\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus()
{	return -150;
}
int practice_bonus()
{	return -150;
}
int black_white_ness()
{	return 30;
}
string perform_action_file(string action)
{
        return CLASS_D("player") + "/"+"weapon"+"/" + action;
}
