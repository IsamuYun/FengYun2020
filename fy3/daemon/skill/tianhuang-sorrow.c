inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N����������$w�����̶����ƿ���ֱ��$n��$l",
                "dodge":                -10,
                "damage":               50,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 500 )
                return notify_fail("�������������û�а취����ʹ���\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("name") != "�������" )
                return notify_fail("��������ҵ��������������ʹ���\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sorrow" ;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 100
        ||      (int)me->query("force") < 500 )
                return 
notify_fail("�����������������û�а취��ϰ��ʹ���\n");
        me->receive_damage("kee", 100);
        me->add("force", -500);
        write("�㰴����ѧ����һ����ʹ���\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("longxing") + "/sorrow/" + action;
}
 
int effective_level() { return 25;}

int learn_bonus()
{
        return -2220;
}
int practice_bonus()
{
        return -1110;
}
int black_white_ness()
{
        return 15;
}
