// ��������Դ��书���� ԭ��maxim@nju_fengxue��д������xgchen@zzfy�޸�
// everhave
// ӵ��
// �����µڶ�ʮ�Ĵ�����
// 20002087
// ����
// blade
// ��įʮ����





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N����¶��һ�ּ�į֮ɫ������$wһ�С��ߴ���ʤ�� ��������������������ϵ�һϮ���£�����Ʈ�����$nϮȥ��",
"damage" :50,
"dodge" :20,
"parry" :20,
"damage_type": "����",
"skill_name" : "�ߴ���ʤ��"
]),
// ZHAOSHI :1

([
"action" :"$N������������������������졹��$w��������ɫ�ĵ��⣬ն�Ƴ�����һ���ϰ����ƿ���$n��ȥ��",
"damage" :80,
"dodge" :10,
"parry" :20,
"damage_type": "����",
"skill_name" : "��������"
]),
// ZHAOSHI :2

([
"action" :"$N������������Х���������ҡ�,����$w��ͬ������ذ�����$n���������Ҳ�𵴳�һ�����ˡ�����磡",
"damage" :100,
"dodge" :10,
"parry" :10,
"damage_type": "����",
"skill_name" : "��������"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������̫�����޷���"+"��įʮ����"+"��\n");
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
