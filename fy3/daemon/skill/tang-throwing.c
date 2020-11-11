
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N˫��һ�Σ����е�$w��һ�����߰����$n��$l",
                "dodge":                -20,
                "damage":               30,
		"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ����$w�����̶����ƿ���ֱ��$n��$l",
                "dodge":                -40,
                "damage":               30,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ָ΢����$wбб�ķ���$n��$l",
                "dodge":                -40,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������⣬����һ˦�����е�$w����һ����������$n��$l",
                "dodge":                20,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage":               40,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취�����Ű�����\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("���������һЩ�������������Ű�����\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
          ||      (int)me->query("force") < 3 )
       return 
notify_fail("�����������������û�а취��ϰ������\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
write("�㰴����ѧ����һ�����Ű�����\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("tangmen") + "/tang-throwing/" + action;
}
 
int effective_level() { return 18;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return -5;
}
int black_white_ness()
{
	return 0;
}
