inherit SKILL;
string *dodge_msg = ({
        "$nһ�����Ʋ����еġ�����ʽ�����������죬����Ʈ����$N����ʽ��ա�\n",
        "ֻ��$n���񲻶�����Ȼһ��ӥ�����գ�ʹ�����Ʋ����еġ�����ʽ�������ɵض���һ�ԡ�\n",
        "$nʹ�����Ʋ����еġ�����ʽ��������һԾ��\n",
        "$n����һ�㣬һ�����Ʋ����еġ�̤��ʽ���ڿն��𣬱��˿�ȥ��\n",
        "����$nʹһ�����Ʋ����еġ�����ʽ��������Ʈ��������$N�Ĺ���ʧȥ��׼ͷ��\n",
        "$n����һ�����Ʋ����еġ�����ʽ��������Ʈ�ˣ�����������\n",
        "����$nһ�����Ʋ����еġ�����ʽ��ʹ�������λζ����ó�������Ӱ���Լ�����Ʈ�����ɿ��⣡\n",
});
int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move") ;
}
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취�����Ʋ�����\n");
        return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        return notify_fail("���Ʋ���ֻ�ܿ���ʦ��ѧϰ��������\n"); 
}
int effective_level()
 {
 return 10;
}
int learn_bonus()
{
        return -100;
}
int practice_bonus()
{
        return -50;
}
int black_white_ness()
{
        return 100;
}
string perform_action_file(string action)
{
        return CLASS_D("official") + "/liuyun-steps/" + action;
}
string belong()
{
	return "official";
}