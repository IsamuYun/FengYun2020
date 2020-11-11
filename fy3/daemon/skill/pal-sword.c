// pal-sword@zip
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N将$w舞成一团剑花，向$n的$l攻去。",
                "dodge":                -20,
                "damage":               60,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N身形一转，反手一剑，$w闪电般刺向$n的$l。",
                "dodge":                -20,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N中宫直进，$w直刺$n$l。",
                "dodge":                -30,
                "damage":               70,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N将$w越舞越急，一团剑光，直冲$n而去。",
                "dodge":                -20,
                "damage":               70,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N错步上前，弧光现处，$w向$n的$l划去。",
                "dodge":                -20,
                "damage":               50,
      "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使出“力劈华山”的力道，不管三七二十一，$w对着$n就是一阵乱砍。",
                "dodge":                -30,
                    "damage":           100,
      "damage_type":  "割伤"
        ]),
//剑气
        ([      "action":               
"$N将$w一划,九道剑气化为三路，分攻$n上，中，下三盘。",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N$w连点，无数剑气绵绵不绝地向$n攻去。",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N将$w朝$n一指，只听“嗤”的一声，一道剑光以迅雷不及掩耳盗铃之势刺向$n的$l。",
                "dodge":                20,
                "damage":               150,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N身形一变，使一招“峰回路转”，$w剑光竟突然一转，以意想不到的方向刺向$n的$l。",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N竖起$w，剑尖上光芒闪处，宛如“泰山日出”，迸出万道金光，将$n照住。",
                "dodge":                20,
                "damage":               180,
                "damage_type":  "刺伤"
        ]),
([      "action":               
"$N大喝一声，$w化作无数剑光，铺天盖地同时向$n刺去，意欲立斩$n于剑下，正是一招“锄魔天地”。",
                "dodge":                20,
                "damage":               320,
                "damage_type":  "刺伤"
        ]),     
});

int valid_learn(object me)
{        object ob;
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
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
        act["action"] = replace_string(act["action"], "$w", "身体");
        return act;}
  else return action[random(11)];
return action[6+random(6)];
}
int practice_skill(object me)
{        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 6 )
                return 
notify_fail("你的内力或气不够，没有办法练习蜀山剑法。\n");
        me->receive_damage("kee", 18);
        me->add("force", -6);
 write("你按著所学练了一遍蜀山剑法。\n");
        return 1;
}
string perform_action_file(string action)
{return CLASS_D("xianlingdao") + "/pal-sword/" + action;
}
int effective_level() { return 18;}
string query_parry_msg(object weapon)
{string *parry_msg = ({
"$n向后急跳，连跃数丈，躲开了$N的攻势。\n",
"$n用$v一格，“当”的一声，架开了$N的$w。\n",
"$n$v一抖，幻出数朵剑花，挡住了$N的$w。\n",
"无数剑气绵绵缠住了$N，将$N缠的动弹不得，举步维艰。正是“蜀道难，难于上青天”。\n",
"$n剑气急收，化作两股，“双龙飞舞”，绞住了$N的$w。\n",
"$n轻轻一跃，一式“御剑乘风”，身随剑飞，早已避在七丈开外。\n",
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
