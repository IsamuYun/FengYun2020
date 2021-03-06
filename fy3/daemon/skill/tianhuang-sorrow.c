inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N右手拉弓，$w发出刺耳的破空声直射$n的$l",
                "dodge":                -10,
                "damage":               50,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够，没有办法练天皇弓。\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("name") != "白羽神箭" )
                return notify_fail("你必须先找到白羽神箭才能天皇弓。\n");

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
notify_fail("你的内力或气不够，没有办法练习天皇弓。\n");
        me->receive_damage("kee", 100);
        me->add("force", -500);
        write("你按着所学练了一遍天皇弓。\n");
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
