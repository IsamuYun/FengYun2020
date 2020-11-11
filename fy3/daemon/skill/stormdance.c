// sttormdance.c

inherit SKILL;

string *dodge_msg = ({
	"����$n�����飬�����Ʈ�˿�ȥ��\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (string)me->query("gender") != "Ů��" )
		return notify_fail("�߱������ֻ��Ů�Բ�������\n");
	if( (int)me->query("spi") < 20 )
		return notify_fail("������Բ�����û�а취���߱�����衣\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("��ľ���̫���ˣ��������߱�����衣\n");
	me->receive_damage("sen", 30);
	return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}

