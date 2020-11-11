// unarmed.c

#include <ansi.h>

inherit SKILL;



string *unarmed_parry_msg = ({
        "���Ǳ�$p���ˡ�\n",
        "�����$p�����ˡ�\n",
});

string *parry_msg = ({
        "ֻ�������ϡ�һ������$p���ˡ�\n",
        "�����������һ����$p�����ˡ�\n",
        "���Ǳ�$n�����б��мܿ���\n",
        "����$n����һ�࣬�����б��и񿪡�\n",
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
	return 5;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

int effective_level() { return 5;}
string belong()
{
	return "common";
}