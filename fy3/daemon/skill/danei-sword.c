inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":               
"$Nʹ����ɽʮ��ʽ�е����һʽ----��"HIY"��ӳ��ɽ"NOR"�ݣ����е�$wֱ��$n��$l��",
                "force" :               70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����ɽ����еġ�"HIW"�������"NOR"��������$w����һ�����磬�����Ļ���$n��$l",
                "force":               80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��佻����������е�$w���϶������ֵ�һ��---["HIC"����һ��"NOR"]���羪��֮ʽ����$n��$l",
                "force":               90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����ֽ����еģ�"HIY"���־�"NOR"�ݽ�$w�������֣����죬��������׼����$n�̳���",
                "force":                80,

                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����촵ѩ�����еģ�"HIR"��Ȼһ��"NOR"�ݴ���ǰ�����е�$w����ַɣ���â�������޵���$n��ȥ��",
                "force":               90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��ɱ�˽����еģ�"HIR"ɱ������"NOR"�ݴ���ǰ�����е�$w��籩������$n������",
                "force":               80,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");
        if (me->query("level") < 40)
	 return notify_fail("��ĵȼ���������ʮ����\n");
        return 1;
}

int valid_enable(string usage)
{

        return usage=="sword";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
                return notify_fail("�����ؽ�ֻ��ͨ����ʦ��ѧϰ��������\n");
}


string perform_action_file(string action)
{
        return CLASS_D("official") + "/danei-sword/" + action;
}
 
int effective_level() { return 20;}

string *parry_msg = ({
        "$nʹ����Ե���ǽ����еģ�"CYN"һ����Ե"NOR"�ݣ����������߰��ס$N��$w��\n",
        "$nʹ�����Ž����еġ�"HIG"ճ"NOR"���־���������$n�Ĺ��ƣ�����$v��$N��$w�������⡣\n",
        "$nʹ�����ɽ����еġ�"HIW"�������"NOR"�������е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$n�����ؽ����е�$v��������ǰ��ǿ�ҵĽ��罫$N�Ƶ����˼�����������ˮ�����еġ�"HIC"����һ��"NOR"��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬һ�е����������еġ�"YEL"���ǿ��Ϊ"NOR"����ס��$N�Ĺ��ơ�\n",
        "$nһ�����е�$v��ʹ�����촵ѩ�����еġ�"HIG"����ħ��"NOR"�������е�$v��ס��ȫ��\n",
        "$nʹ���μҽ����е�һ�С�"WHT"�����"NOR"����$vֱ��$N��˫�֡�\n",
        "$n$n�����е�$v�����̳�����ס$N��ȫ�����ơ�\n",
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
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 100;

}
string belong()
{
	return "official";
}
