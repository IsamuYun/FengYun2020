#include <ansi.h>
inherit FORCE;
mapping *action = ({
        ([      "action":
"$Nʹ��һ�С����ִ��š����ֽŲ��ú��һ���$n��$l",
                "force":        30,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С���ͷ���ԡ���ͷһ�ڱ�ֱײ��$n��$l",
                "force":        40,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�����ʮ�㡹���������������ͦ������$n��$l",
                "force":        50,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С����ϰ��١���ȫ��������أ�����ɷ���ѿ���ӲҪ������$n��˫��",
                "force":         60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С��������ס���˫�ֱ���$n��$l",
                "force":        40,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�����������������һ�죬���һ�ţ�ҧ��$n��$l",
                "force":        50,
                "damage_type":  "����"
        ]),
});

int valid_enable(string usage) 
{ 
return  usage=="unarmed" ||
        usage=="force";
}

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("������ֻ��Ҫ�����Ϳ����ˡ�\n");
}

 
int effective_level() { return 30;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$n�Ż����ţ��͵��ҹ�������ײײ�Ķ㿪��$N�Ĺ�����\n",
        "$n���Ų��ѣ�˫���һӣ����յ�ס��$N�Ĺ��ơ�\n",
});
string *parry_msg = ({
        "$n�Ż����ţ��͵��ҹ�������ײײ�Ķ㿪��$N�Ĺ�����\n",
        "$n���Ų��ѣ�˫���һӣ����յ�ס��$N�Ĺ��ơ�\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int bounce_ratio()
{
        return 10;
}

int learn_bonus()
{
        return -50000;
}
int practice_bonus()
{
        return 0;
}

int black_white_ness()
{
        return 0;
}

string exert_function_file(string func)
{
        return CLASS_D("player") + "/idle-force/" + func;
}
string perform_action_file(string action)
{
        return CLASS_D("player") + "/idle-force/" + action;
}


void skill_improved(object me)
{
        if( (int)me->query_skill("idle-force", 1)  > 1000 ) 
        {
                tell_object(me, HIW "\n��ķ�������Ҳ�޷������ˣ�\n\n" NOR);
                                me->set_skill("idle-force", 1000);
        } 
}
string belong()
{
	return "common";
}
