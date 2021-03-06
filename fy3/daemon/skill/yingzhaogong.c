#include <ansi.h>
// inherit SKILL;
inherit FORCE;

mapping *action = ({
        ([      "action":
"$N右手一晃，五指齐张，拇指、食指、中指成鹰爪状，对着$n当胸抓下",
                "force":                500,
                "damage_type":  "抓伤"
        ]),
        ([      "action":
"$N双手一翻，手上灌注真力，向外一探，便扣$n的脉门",
                "force":                500,
                "damage_type":  "挫伤"
        ]),
        ([      "action":
"$N左手一摆，右手五指弯曲成锥状，暗运真力直击$n的$l",
                "force":                700,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N一跃而起，宛若一只苍鹰，居高临下双手如利爪般当空抓向$n的$l",
                "force":                900,
                "damage_type":  "抓伤"
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
"$n的全身骨骼被$N的鹰爪功捏得粉碎！！！！\n";
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
// notify_fail("鹰爪功只能用学的。\n");
// }

 
int effective_level() { return 30;}

string *absorb_msg = ({
        "$n身体虚转，气运丹田，双手变得坚硬无比。\n",
        "$n施展出大力鹰爪功，浑身肌肤坚如寒铁。\n",
        "$n身型微展，掌影充斥了丈许空间。\n",
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
        "$n双手微划，施展出七十二路小擒拿手，点、抓、戳、扫，$N根本不可近身。\n",
        "$n双手一分，施展出三十六路大擒拿手，大开大合，劈、砍、削、剁，$N一身武艺却施展不开。\n",
});
string *parry_msg = ({
        "$n双手微划，施展出七十二路小擒拿手，点、抓、戳、扫，$N根本不可近身。\n",
        "$n双手一分，施展出三十六路大擒拿手，大开大合，劈、砍、削、剁，$N一身武艺却施展不开。\n",
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


