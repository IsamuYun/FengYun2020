// pal-sword@zip
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N��$w���һ�Ž�������$n��$l��ȥ��",
                "dodge":                -20,
                "damage":               60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һת������һ����$w��������$n��$l��",
                "dodge":                -20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�й�ֱ����$wֱ��$n$l��",
                "dodge":                -30,
                "damage":               70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wԽ��Խ����һ�Ž��⣬ֱ��$n��ȥ��",
                "dodge":                -20,
                "damage":               70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����ǰ�������ִ���$w��$n��$l��ȥ��",
                "dodge":                -20,
                "damage":               50,
      "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����������ɽ�����������������߶�ʮһ��$w����$n����һ���ҿ���",
                "dodge":                -30,
                    "damage":           100,
      "damage_type":  "����"
        ]),
//����
        ([      "action":               
"$N��$wһ��,�ŵ�������Ϊ��·���ֹ�$n�ϣ��У������̡�",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N$w���㣬�����������಻������$n��ȥ��",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w��$nһָ��ֻ�����͡���һ����һ��������Ѹ�ײ����ڶ�����֮�ƴ���$n��$l��",
                "dodge":                20,
                "damage":               150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ�䣬ʹһ�С����·ת����$w���⾹ͻȻһת�������벻���ķ������$n��$l��",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�������Ϲ�â���������硰̩ɽ�ճ������ų������⣬��$n��ס��",
                "dodge":                20,
                "damage":               180,
                "damage_type":  "����"
        ]),
([      "action":               
"$N���һ����$w�����������⣬����ǵ�ͬʱ��$n��ȥ��������ն$n�ڽ��£�����һ�С���ħ��ء���",
                "dodge":                20,
                "damage":               320,
                "damage_type":  "����"
        ]),     
});

int valid_learn(object me)
{        object ob;
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");
        return 1;
}
int valid_enable(string usage)
{        return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{mapping act;
int i;
i=(int)me->query_skill("sword");
if(i<100||me->query_temp("pfm/palswd")==2) return action[random(6)];
if(i<180)
  if(me->query_temp("pfm/palswd")==1)
        {act=action[random(11)];
        act["action"] = replace_string(act["action"], "$w", "����");
        return act;}
  else return action[random(11)];
return action[6+random(6)];
}
int practice_skill(object me)
{        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 6 )
                return 
notify_fail("�����������������û�а취��ϰ��ɽ������\n");
        me->receive_damage("kee", 18);
        me->add("force", -6);
 write("�㰴����ѧ����һ����ɽ������\n");
        return 1;
}
string perform_action_file(string action)
{return CLASS_D("xianlingdao") + "/pal-sword/" + action;
}
int effective_level() { return 18;}
string query_parry_msg(object weapon)
{string *parry_msg = ({
"$n���������Ծ���ɣ��㿪��$N�Ĺ��ơ�\n",
"$n��$vһ�񣬡�������һ�����ܿ���$N��$w��\n",
"$n$vһ�����ó����佣������ס��$N��$w��\n",
"�������������ס��$N����$N���Ķ������ã��ٲ�ά�衣���ǡ�����ѣ����������족��\n",
"$n�������գ��������ɣ���˫�����衱����ס��$N��$w��\n",
"$n����һԾ��һʽ�������˷硱�����潣�ɣ����ѱ������ɿ��⡣\n",
});
if( weapon )
   return parry_msg[random(sizeof(parry_msg))];
else
  return parry_msg[0];
}

int learn_bonus()
{
        return -90;
}
int practice_bonus()
{
        return 18;
}
int black_white_ness()
{
        return 18;
}
