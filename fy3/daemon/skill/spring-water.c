
#include <ansi.h>
inherit SKILL;

int valid_enable(string usage) { return usage=="iron-cloth"; }

int valid_learn(object me) 
{
    if( (string)me->query("gender") != "Ů��" ) {
        return notify_fail("��ˮ������ֻ��Ů�Ӳ��������书��\n");
        }

        return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("��ˮ����ֻ��ͨ��ѧϰ����ߡ�\n");
}

 
int effective_level() { return 28;}

string *absorb_msg = ({
        "$n��ü΢����ʩչ�������������¡�����������Ʈ�裬��Ȼ�ƺ��е��΢�⸡����\n",
        "$nʩչ��ˮ�����ġ��κ�¥̨���������������ܣ����ƺ�������$N�����ڡ�\n",
        "$n΢΢����һʽ���仨�˶���������$N�Ĺ����£��´�ƮƮ����紵���衣\n",
        "$nʩչ����΢����˫�ɡ���˫���չ������$N��һ����\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
	return 10;
}

int learn_bonus()
{
	return -1000;
}
int practice_bonus()
{
	return -5;
}
int black_white_ness()
{
	return 20;
}

