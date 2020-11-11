//����Ӣ��
//����������  
//����Ѹ�٣�ɱ�����޴󣬵���Ҫ����������֧�֡�
//by lion@hero

inherit SKILL;

mapping *action = ({
([  "action" : "$N����ڿ�Ծ��˫�ֽ���$w��һ�С�����ٵء�����׼$n��ͷ�������϶��µؿ�����ȥ��
ֻ�ڰ��������һ�ž޴�ĺ�Ӱ",
    "damage": 1300,
    "dodge" : -50,
    "parry" : -50,
    "damage_type" : "����",
]),
([  "action" : "$NͻȻ��һ��������ǰ������һ�С�����������������$w���¶��Ϸ���$n����·��$n����
һ������ɫ����Ӱ�����Լ�����֪�����æ�м�",
    "damage": 1325,
    "dodge" : 45,
    "parry" : -30,
    "damage_type" : "����",
]),
([  "action" : "$Nʹ��һ�С���ɨǧ��������Ȼ����һ��������б����ǰ�����һ��������΢�Σ�����$w�ڿ�
�л���һ����Ӱ�����ٺ�ɨ$n���Ҽ磬��������",
    "damage": 1350,
    "dodge" : -40,
    "parry" : 50,
    "damage_type" : "����",
]),
([  "action" : "$NͻȻ�������ҹ������漴���𣬡�����Ϊ���������������һ˲�䣬�ѵ�������$w
����$n�����ߣ����ּȿ��Һ�",
    "damage": 1390,
    "dodge" : 35,
    "parry" : -40,
    "damage_type" : "����",
]),
([  "action" : "$N��һ�С���ײ�ӡ�˫�ֺ��$w��ƽɨ$nǰ�أ���ʽδʹ�Ͼ��Ѵ�ס�Ȼ���У�����ֱ
ײ$n��С����",
    "damage": 1430,
    "dodge" : -40,
     "parry" : -40,
    "damage_type" : "����",
]),
([  "action" : "$N����������ת��΢�ף�$n��$N¶����������æ������ȴͻȻ����$N
��������ת������ʹ��һ�С��ط�ת�ơ�������$w��Ѹ�͵�ɨ���Լ�������",
    "damage": 1480,
    "dodge" : -30,
    "parry" : 54,
    "damage_type" : "����",
]),
([  "action" : "$Nʹ��һ�С��師������������΢��������ͬһʱ�������������ҿ����師��$n�����$w�Ӳ�
ͬ�ķ�λ�����Լ���һʱ�侹��֪������м�",
    "damage": 1540,
    "dodge" : -25,
    "parry" : -66,
    "damage_type" : "����",
]),
([  "action" : "$Nǰ���͵�������һ�٣�һ�С�һ�����ơ������Ҳ΢΢һ�𣬽��ž���ͷ��ͷ����ת
��Ȧ��$w����������֮��ƽֱ�����ȵ�Ϯ��$n��$n������δ����㣬
�ܿ����������Լ�����һ�ߣ����ɴ�ʧɫ",
    "damage": 1600,
    "parry" : -55,
    "dodge" : -65,
    "damage_type" : "����",
]),
([      "action" : "$Nƽ������$w��һ�С������𡹣�������ǰ����$n��$l��ȥ",
        "force" : 100,
        "dodge" : 20,
        "damage" : 410,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����ɽ������һվ,���Ƹ�����$wƽƽ��$n�ľ���Ĩȥ",
        "force" : 150,
        "dodge" : -20,
        "parry" : 30,
        "damage" : 500,
        "damage_type" : "����"
]),
([      "action" : "$N�������츫Ӱ������Ҵ�,һ�С�����ơ��������$n��ȫ��",
        "force" : 200,
        "dodge" : -20,
        "damage" : 400,
        "parry" : -500,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����»���������ʽ��׾,�󿪴��أ��߾�ͷ��,ֱ����$n",
        "force" : 250,
        "dodge" : 30,
        "parry" : -56,
        "damage" : 600,
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ������������,һ�С�����ء���˫�ֻ���$w����$n���ؿ�",
        "force" : 300,
        "dodge" : -10,
        "damage" : 780,
        "damage_type" : "����"
]),

});

string *parry_msg = ({
        "���$nһ�С����־������Ӷ�����$v����$N��$w��\n",
        "���$n����$vһ�֣�һ�С��ƿ���������б��$N��$w��\n",
        "���$n����$v�ն���ɣ�һ�С��쵶���项������$N��$w��\n",
        "���$n����$v������ת��һ�С�������ۡ�����ɨ$N��$w��\n",
});

int valid_enable(string usage) { return usage=="axe" ||  usage=="parry"; }      

int valid_learn(object me)
{
    if ((int)me->query_skill("force") < 100)
   return notify_fail("����ڹ��ķ���򲻹����޷�ѧ��������\n");
    if ((int)me->query("max_force") < 300)
   return notify_fail("���������Ϊ̫�����޷�����������\n");
    if ((int)me->query("force") < 200)
   return notify_fail("�������̫�����޷�����������\n");  
    if ((int)me->query_str() < 30)
   return notify_fail("�������̫С���޷�����������\n");   
   return 1;

}

mapping query_action(object me, object weapon)
{
return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
   return parry_msg[random(sizeof(parry_msg))];
  }

int effective_level() { return 28;}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
   return notify_fail("���������һ�Ѹ�ͷ���������Ƶ�������������������\n");
    if ((int)me->query("kee") < 50)
    return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("force") < 20)
   return notify_fail("���������������������\n");
    me->receive_damage("kee", 50);
    me->add("force",-20);
   return 1;
}

int learn_bonus()
{
        return -2800;
}
int practice_bonus()
{
        return -2800;
}
int black_white_ness()
{
        return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("heimiao") + "/pili-axe/" + action;
}
