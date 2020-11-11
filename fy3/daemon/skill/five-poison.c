// five-poison.c

#include <ansi.h>
inherit FORCE;

mapping *action = ({
        ([      "action":               "$N��$n��$l�ݺݵ�һץ",
        "force":        500,
                "damage_type":  "ץ��",
        ]),
});

int valid_learn(object me)
{
      if ((string)me->query("class") != "diabloist" && (string)me->query("class") != "baimiao")
        return notify_fail("�������ʲ��ʺ���ѧ�����\n");
        return 1;
}

int valid_enable(string usage) { return usage=="force" || usage=="unarmed"; }

string exert_function_file(string func)
{
        return CLASS_D("baimiao") + "/five-poison/" + func;
}

string perform_action_file(string action)
{
        return CLASS_D("baimiao") + "/five-poison/" + action;
}

string *poisons=({
    "unknown",
    "green_blood",
    "red_blood",
    "rose_poison",
    "zang_poison",
    "snake_poison",
    "red_poison",
    "beast_poison",
});

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
int force, skill;
if(victim->query("gin")<0 || victim->query("kee")<0 || victim->query("sen")<0)
{
 return HIY "$n����$N���ϵĶ���\n" NOR;
  }
  skill = (int)me->query_skill("five-poison",1);
force = (int)victim->query_skill("force");
 if( random(2*skill+force) > force) {
                victim->apply_condition(poisons[random(sizeof(poisons))], skill / 50);
skill = 5000 / skill;
 victim->receive_wound("gin", (int)victim->query("gin")/skill);
 victim->receive_wound("kee", (int)victim->query("kee")/skill);
 victim->receive_wound("sen", (int)victim->query("sen")/skill);
return HIY "$n����$N���ϵĶ���\n" NOR;
  }
    return skill+damage_bonus+factor;
}

string *parry_msg = ({
        "���Ǳ�$n���ˡ�\n",
        "�����$n�����ˡ�\n",
});

string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int effective_level() { return 12;}

int learn_bonus()
{
        return -50;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return -200;
}
