// fonxansword.c
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N左手横眉，$w斜削而出，剑光似有似无，出手似快似慢，剑路似实似虚，招式将变未变。正是清风十三式中的第一式「清-风-徐-来」",
                "dodge":                100,
                "damage":               133,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使出清风十三式中第八式「风-动-千-铃」。剑光点点流动，如风铃此起彼伏，却分不清到底哪一处在响。",
                "dodge":                120,
                "damage":               140,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出清风十三式中第二式「流-空-萤-火」，回剑轻削，飘渺的剑光点点飞来如同夜空中流萤飞舞，袭向$n$l。",
                "dodge":                100,
                "damage":               150,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手腕轻抖横剑削来，只见剑意萧萧，飘摇不定，却是清风十三式中第三式「竹-外-山-岚」",
                "dodge":                270,
                "damage":               140,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w回掠，似乎意态优闲，停招不发，然而剑势不经意的变幻之间已拂向$n$l，正是清风十三式中第四式「云-淡-风-轻」",
                "dodge":                150,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N左手轻掠划了一个半弧，右手$w连点，使出清风十三式中第五式「空-穴-来-风」，淡淡的剑气忽然从四面八方掩向$n。",
                "dodge":                100,
                "damage":               110,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N将$w横持在面前，左手斜挥而下，右手一转将$w平平推出，丝丝剑气飘然而至。正是清风十三式中第七式「霜-笛-清-晓」",
                "dodge":                195,
                "damage":               170,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w剑势忽左忽右，不断向前飘动，让人分不清方向，然而剑光却渐渐涨起，如春风点染绿林。正是清风十三式中第九式「绿-涨-春-风」",
                "dodge":                110,
                "damage":               130,
                "damage_type":  "刺伤"
        ]),                       
        ([      "action":               
"$N使出清风十三式中第十式「寒-梅-落-雪」，只见剑势萧疏，剑光清冷，如点点落梅在风中飘向$n$l。",
                "dodge":                195,
                "damage":               220,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w轻转，一道道短短的弧光浮现身前，正是清风十三式中第十二式「风-送-浮-萍」，只见弧光飘动，浮向$n$l。",
                "dodge":                260,
                "damage":               230,
                "damage_type":  "割伤"
        ]),  
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够，没有办法练清风十三式。\n");

        if ((int)me->query_skill("force", 1) < 100) 
        {
                return notify_fail("你的基本内功火候太浅。\n");
        }

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练清风十三式。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int attack_act;        
        attack_act=random(sizeof(action));
        me->set_temp("qingfeng-act",attack_act); 
        return action[attack_act];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 10 )
                return 
notify_fail("你的内力或气不够，没有办法练习清风十三式。\n");
        me->receive_damage("kee", 50);
        me->add("force", -10);
        if(random(10))
        {
        	return notify_fail("你按著所学练了一遍清风十三式，但是感觉一无所获。\n");;	
        }
        write("你按著所学练了一遍清风十三式。\n");
        return 1;
}
 
int effective_level() { return 28;}

string *parry_msg = ({
	"$n手中$v慢慢挑起，剑势飘动间如团团落絮随风而起，清风十三式中第六式「落-絮-轻-扬」使出，悠悠漫漫织成一道剑网。\n",
	"$n轻摆$v，剑光若有若无间斜飘而至，使出清风十三式中第十一式「雁-阵-偏-吹」，将$N攻势化于无形。\n",
	"$n如风吹弱柳，微微侧身，反手挥出$v，剑光似片片落霞飘来，以清风十三式中第十三式「落-霞-流-散」将$N封出丈外。\n",
});

string *unarmed_parry_msg = ({
	"$n手中$v慢慢挑起，剑势飘动间如团团落絮随风而起，清风十三式中第六式「落-絮-轻-扬」使出，悠悠漫漫织成一道剑网。\n",
	"$n轻摆$v，剑光若有若无间斜飘而至，使出清风十三式中第十一式「雁-阵-偏-吹」，将$N攻势化于无形。\n",
	"$n如风吹弱柳，微微侧身，反手挥出$v，剑光似片片落霞飘来，以清风十三式中第十三式「落-霞-流-散」将$N封出丈外。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/qingfeng-sword/" + action;
}

mixed hit_ob(object me, object victim)
{       
	int act;
	int pro;
    int dam;
    int level_bonus;       
    string damtype;
        
    if (me->query_skill_mapped("force") != "wuzheng-force")
    {
    	return ("");   
	}
    
    level_bonus = me->query_skill("qingfeng-sword",1);
    act=me->query_temp("qingfeng-act");     
    
    pro = 0;    
        switch(act) {
                case 0:
                        if (level_bonus < 30) break;
                        damtype="kee";
                        pro = 1;
                        break;
                case 7:
                        if (me->query("combat_exp")<600000 || level_bonus < 50) break;
                        damtype="sen";
                        pro = 1;
                        break;
                case 2:
                        if (me->query("combat_exp")<400000  || level_bonus < 40) break;
                        damtype="kee";
                        pro = 2;
                        break;
                case 5:
                        if (me->query("combat_exp")<800000  || level_bonus < 60) break;
                        damtype="gin";
                        pro = 1;
                        break;
                case 8:
                        if (me->query("combat_exp")<1600000  || level_bonus < 80) break;
                        damtype="kee";
                        pro = 3;
                        break;
                case 9:
                        if (me->query("combat_exp")<1200000  || level_bonus < 70) break;
                        damtype="sen";
                        pro = 2;
                        break;
                case 1:
                        if (me->query("combat_exp")<1500000  || level_bonus < 100) break;
                        damtype="kee";
                        pro = 4;
                        break;
                case 3:
                   		if (me->query("combat_exp")<2000000  || level_bonus < 120) break;
                        damtype="gin";
                        pro = 2;
                        break;
                case 4:
                        if (me->query("combat_exp")<3000000  || level_bonus < 140) break;
                        damtype="kee";
                        pro = 5;
                        break;
                case 6:
                        if (me->query("combat_exp")<4000000  || level_bonus < 160) break;
                        damtype="sen";
                        pro = 3;
                        break;
                case 10:
                   		if (me->query("combat_exp")<4500000  || level_bonus < 240) break;
                        damtype="gin";
                        pro = 3;
                        break;
                case 11:
                        if (me->query("combat_exp")<5000000  || level_bonus < 260) break;
                        damtype="kee";
                        pro = 6;
                        break;
                case 12:
                        if (me->query("combat_exp")<5500000  || level_bonus < 280) break;
                        damtype="sen";
                        pro = 4;
                        break;
                }
        if(damtype)
        {
                dam = (4+pro) * (int) me->query("force_factor");
                dam += (1+pro)*level_bonus;
                victim->receive_damage(damtype,dam,me);
                return (HIC"$n"NOR+HIC"觉得浑身一麻，似乎已被$N的内劲所伤。\n" NOR);
        }            
	
	return ("");
} 

int learn_bonus()
{
	return -3000;
}
int practice_bonus()
{
	return -3000;
}
int black_white_ness()
{
	return 200;
}

