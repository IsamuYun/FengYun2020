#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) 
{ 
return (usage=="iron-cloth" || usage=="force");
}

int valid_learn(object me) {
     return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("��Ӱ�񹦹���������ֻ�оߴ������߲�����̽�����о����������\n");
}

int effective_level() { return 35;}

string *absorb_msg = ({
        "$n��Ĭ�ˣ����ҵ�����糱ˮ�����ȶ�����\n",
        "$n����˫�֣���̬��Ȼ����$N�Ĺ��Ʋ��ܲ��ã�\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
	return 40;
}

int learn_bonus()
{
	return -5000;
}

int practice_bonus()
{
	return -5000;
}

int black_white_ness()
{
	return 200;
}
string exert_function_file(string func)
{
        return CLASS_D("moon") + "/yueying/" + func;
}


//}

