// five-poison.c

#include <ansi.h>
inherit FORCE;

mapping *action = ({
        ([      "action":               "$N往$n的$l狠狠的一抓",
        "force":        500,
                "damage_type":  "抓伤",
        ]),
});

int valid_learn(object me)
{
      if ((string)me->query("class") != "diabloist" && (string)me->query("class") != "baimiao")
        return notify_fail("您的体质不适合于学这项功夫。\n");
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
 return HIY "$n中了$N身上的毒！\n" NOR;
  }
  skill = (int)me->query_skill("five-poison",1);
force = (int)victim->query_skill("force");
 if( random(2*skill+force) > force) {
                victim->apply_condition(poisons[random(sizeof(poisons))], skill / 50);
skill = 5000 / skill;
 victim->receive_wound("gin", (int)victim->query("gin")/skill);
 victim->receive_wound("kee", (int)victim->query("kee")/skill);
 victim->receive_wound("sen", (int)victim->query("sen")/skill);
return HIY "$n中了$N身上的毒！\n" NOR;
  }
    return skill+damage_bonus+factor;
}

string *parry_msg = ({
        "但是被$n格开了。\n",
        "结果被$n挡开了。\n",
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
