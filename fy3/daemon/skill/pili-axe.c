//欢乐英雄
//霹雳斧法。  
//进招迅速，杀伤力巨大，但需要大量内力做支持。
//by lion@hero

inherit SKILL;

mapping *action = ({
([  "action" : "$N蓦地腾空跃起，双手紧握$w，一招「开天辟地」，对准$n的头顶，自上而下地砍了下去，
只在半空中留下一团巨大的黑影",
    "damage": 1300,
    "dodge" : -50,
    "parry" : -50,
    "damage_type" : "砍伤",
]),
([  "action" : "$N突然发一声喊，冲前两步，一招「气冲霄汉」，手中$w由下而上反撩$n下三路，$n见到
一道淡黄色的气影逼向自己，情知不妙，急忙招架",
    "damage": 1325,
    "dodge" : 45,
    "parry" : -30,
    "damage_type" : "割伤",
]),
([  "action" : "$N使出一招「横扫千军」，忽然虎吼一声，闪身斜向左前方冲出一步，身体微晃，手中$w在空
中划出一道淡影，急速横扫$n的右肩，气势迫人",
    "damage": 1350,
    "dodge" : -40,
    "parry" : 50,
    "damage_type" : "砍伤",
]),
([  "action" : "$N突然抽身向右滚倒，随即跳起，「以退为进」，就在跳起的一瞬间，已单臂握着$w
砸向$n的左肋，出手既快且狠",
    "damage": 1390,
    "dodge" : 35,
    "parry" : -40,
    "damage_type" : "砸伤",
]),
([  "action" : "$N用一招「金斧撞钟」双手横举$w，平扫$n前胸，招式未使老就已打住猝然变招，斧尖直
撞$n的小腹，",
    "damage": 1430,
    "dodge" : -40,
     "parry" : -40,
    "damage_type" : "内伤",
]),
([  "action" : "$N不急不缓地转身微蹲，$n见$N露出破绽，急忙抢攻，却突然发现$N
的身体已转过来，使出一招「回风转云」，手中$w正迅猛地扫向自己的下盘",
    "damage": 1480,
    "dodge" : -30,
    "parry" : 54,
    "damage_type" : "割伤",
]),
([  "action" : "$N使出一招「五斧夺命」，身形微动，就在同一时间自上中下左右砍出五斧，$n见五把$w从不
同的方位砍向自己，一时间竟不知该如何招架",
    "damage": 1540,
    "dodge" : -25,
    "parry" : -66,
    "damage_type" : "砍伤",
]),
([  "action" : "$N前脚猛地往地上一顿，一招「一斧断云」，大地也微微一震，接着举起斧头在头顶急转
数圈，$w就隐含风云之声平直而沉稳地袭向$n，$n无论向何处闪躲，
总看见斧尖离自己不到一尺，不由大惊失色",
    "damage": 1600,
    "parry" : -55,
    "dodge" : -65,
    "damage_type" : "砍伤",
]),
([      "action" : "$N平举手中$w，一招「风云起」，欺身向前，向$n的$l撩去",
        "force" : 100,
        "dodge" : 20,
        "damage" : 410,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「力推山」，马步一站,手推斧背，$w平平向$n的颈部抹去",
        "force" : 150,
        "dodge" : -20,
        "parry" : 30,
        "damage" : 500,
        "damage_type" : "割伤"
]),
([      "action" : "$N掀起漫天斧影，狂冲乱打,一招「狂风破」，罡风笼罩$n的全身",
        "force" : 200,
        "dodge" : -20,
        "damage" : 400,
        "parry" : -500,
        "damage_type" : "内伤"
]),
([      "action" : "$N一招「日月晦明」，招式重拙,大开大阖，高举头顶,直劈向$n",
        "force" : 250,
        "dodge" : 30,
        "parry" : -56,
        "damage" : 600,
        "damage_type" : "劈伤"
]),
([      "action" : "$N手中$w一沉，气凝斧上,一招「震天地」，双手挥起$w砍向$n的胸口",
        "force" : 300,
        "dodge" : -10,
        "damage" : 780,
        "damage_type" : "震伤"
]),

});

string *parry_msg = ({
        "结果$n一招「搁字诀」，挥动手中$v格开了$N的$w。\n",
        "结果$n手中$v一分，一招「云开月明」，斜劈$N的$w。\n",
        "结果$n手中$v抡动如飞，一招「快刀乱麻」，荡开$N的$w。\n",
        "结果$n手中$v飞速旋转，一招「不解成舟」，反扫$N的$w。\n",
});

int valid_enable(string usage) { return usage=="axe" ||  usage=="parry"; }      

int valid_learn(object me)
{
    if ((int)me->query_skill("force") < 100)
   return notify_fail("你的内功心法火候不够，无法学霹雳斧。\n");
    if ((int)me->query("max_force") < 300)
   return notify_fail("你的内力修为太弱，无法练霹雳斧。\n");
    if ((int)me->query("force") < 200)
   return notify_fail("你的内力太弱，无法练霹雳斧。\n");  
    if ((int)me->query_str() < 30)
   return notify_fail("你的力气太小，无法练霹雳斧。\n");   
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
   return notify_fail("你必须先找一把斧头或者是类似的武器，才能练斧法。\n");
    if ((int)me->query("kee") < 50)
    return notify_fail("你的体力太低了。\n");
    if ((int)me->query("force") < 20)
   return notify_fail("你的内力不够练霹雳斧。\n");
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
