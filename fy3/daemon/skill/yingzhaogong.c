#include <ansi.h>
// inherit SKILL;
inherit FORCE;

mapping *action = ({
        ([      "action":
"$N����һ�Σ���ָ���ţ�Ĵָ��ʳָ����ָ��ӥצ״������$n����ץ��",
                "force":                500,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N˫��һ�������Ϲ�ע����������һ̽�����$n������",
                "force":                500,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�ڣ�������ָ������׶״����������ֱ��$n��$l",
                "force":                700,
                "damage_type":  "����"
        ]),
        ([      "action":
"$NһԾ��������һֻ��ӥ���Ӹ�����˫������צ�㵱��ץ��$n��$l",
                "force":                900,
                "damage_type":  "ץ��"
        ]),
});

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
        int force;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(3*(me->query_skill("yingzhaogong"))) > (damage_bonus + foo))
 {
                        victim->receive_wound("kee", (damage_bonus + foo));
                        victim->receive_wound("gin", (damage_bonus + foo));
                        victim->receive_wound("sen", (damage_bonus + foo));
                        force = victim->query("force");
                        victim->set("force", force-random(10)-1);
                        victim->set("max_force", 0);
                        return
"$n��ȫ�������$N��ӥצ����÷��飡������\n";
                }
        }
        return foo;
}

int valid_enable(string usage) 
{ 
return  
        usage=="unarmed" ||
        usage=="parry";
        
}

int valid_learn(object me) { return 1; }

// int practice_skill(object me)
// {
//        return 
// notify_fail("ӥצ��ֻ����ѧ�ġ�\n");
// }

 
int effective_level() { return 30;}

string *absorb_msg = ({
        "$n������ת�����˵��˫�ֱ�ü�Ӳ�ޱȡ�\n",
        "$nʩչ������ӥצ�������������纮����\n",
        "$n����΢չ����Ӱ���������ռ䡣\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$n˫��΢����ʩչ����ʮ��·С�����֣��㡢ץ������ɨ��$N�������ɽ���\n",
        "$n˫��һ�֣�ʩչ����ʮ��·�������֣��󿪴�ϣ��������������磬$Nһ������ȴʩչ������\n",
});
string *parry_msg = ({
        "$n˫��΢����ʩչ����ʮ��·С�����֣��㡢ץ������ɨ��$N�������ɽ���\n",
        "$n˫��һ�֣�ʩչ����ʮ��·�������֣��󿪴�ϣ��������������磬$Nһ������ȴʩչ������\n",
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
        return 40;
}

int learn_bonus()
{
        return -50;
}
int practice_bonus()
{
        return -50;
}
int black_white_ness()
{
        return 20;
}

string perform_action_file(string action)
{
        return CLASS_D("newsk") + "/yingzhao/" + action;
}


