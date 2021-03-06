
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N双手一晃，手中的$w如一条银蛇般飞向$n的$l",
                "dodge":                -20,
                "damage":               30,
		"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N右手一抖，$w发出刺耳的破空声直射$n的$l",
                "dodge":                -40,
                "damage":               30,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手指微动，$w斜斜的飞向$n的$l",
                "dodge":                -40,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N力发肩肘，右手一甩，手中的$w化作一道弧光射向$n的$l",
                "dodge":                20,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练唐门暗器。\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("你必须先找一些暗器才能练唐门暗器。\n");

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
notify_fail("你的内力或气不够，没有办法练习暗器。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
write("你按著所学练了一遍唐门暗器。\n");
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
