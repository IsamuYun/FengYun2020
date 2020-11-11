inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":               
"$N使出寒山十八式中的最后一式----［"HIY"月映寒山"NOR"］，手中的$w直刺$n的$l！",
                "force" :               70,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出飞仙剑法中的「"HIW"天外飞仙"NOR"」，手中$w划出一道长虹，闪电般的击向$n的$l",
                "force":               80,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使出浣花剑法，手中的$w自上而下武林第一剑---["HIC"惊天一剑"NOR"]犹如惊天之式刺向$n的$l",
                "force":               90,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使出左手剑法中的［"HIY"右手诀"NOR"］将$w换到右手，更快，更毒，更准地向$n刺出！",
                "force":                80,

                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出寒天吹雪剑法中的［"HIR"混然一剑"NOR"］错步上前，手中的$w剑光分飞，剑芒若有若无地向$n挥去！",
                "force":               90,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使出杀人剑法中的［"HIR"杀人如麻"NOR"］错步上前，手中的$w狂风暴雨般地向$n卷来！",
                "force":               80,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        if (me->query("level") < 40)
	 return notify_fail("你的等级还不够四十级。\n");
        return 1;
}

int valid_enable(string usage)
{

        return usage=="sword";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
                return notify_fail("大内秘剑只能通过向师傅学习来提升。\n");
}


string perform_action_file(string action)
{
        return CLASS_D("official") + "/danei-sword/" + action;
}
 
int effective_level() { return 20;}

string *parry_msg = ({
        "$n使出随缘无忧剑法中的［"CYN"一切随缘"NOR"］，剑身似灵蛇般缠住$N的$w。\n",
        "$n使出三才剑法中的「"HIG"粘"NOR"」字诀，减缓了$n的攻势，手中$v将$N的$w封于丈外。\n",
        "$n使出飞仙剑法中的「"HIW"凤舞九天"NOR"」，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n慢慢地将手中的$v横立于身前，强烈的剑风将$N逼得连退几步，正是秋水剑法中的「"HIC"海天一线"NOR"」\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，一招蝶恋花剑法中的「"YEL"拟对强衣为"NOR"」封住了$N的攻势。\n",
        "$n一抖手中的$v，使出寒天吹雪剑法中的「"HIG"碧灵魔遁"NOR"」，手中的$v护住了全身。\n",
        "$n使出段家剑法中的一招「"WHT"雨后春笋"NOR"」，$v直刺$N的双手。\n",
        "$n$n将手中的$v连续刺出，挡住$N的全部攻势。\n",
});


string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 100;

}
string belong()
{
	return "official";
}
