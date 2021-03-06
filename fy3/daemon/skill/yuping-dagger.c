
inherit SKILL;

mapping *action = ({
	([	"action":	"$N手中$w斜指，一招「停车问路」，反身一顿，一刀向$n的$l撩去",

		"damage":		70,
		"dodge":		70,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
		"damage":		40,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
		"damage":		20,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口",
		"damage":		70,
		"damage_type":	"割伤"
	]),
	([	"action":	 "$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n",
		"damage":		30,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
		"damage":		50,
		"damage_type":	"割伤"
	]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("你的内功心法不够，没有办法练玉平短兵刃。\n");

        if( (string)me->query_skill_mapped("force")!= "wuchenforce")
                return notify_fail("玉平短兵刃必须配合无尘心法才能练。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "dagger" )
                return notify_fail("你必须先找一把匕首才能练刀法。\n");
        return 1;
}

int valid_enable(string usage)
{
	return (usage=="dagger") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "dagger" )
		return notify_fail("你必须先找一把匕首，才能练刀法。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
        me->receive_damage("kee", 40);
	return 1;
}
int effective_level() { return 20;}

string *parry_msg = ({
        "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，反向$n的全身涌去。\n",
	"$N使出一招「白佛光度」，左臂回收，右掌引内力直刺$n的$l,避得$n连连后退。\n",
	
});

string *unarmed_parry_msg = ({
        "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，反向$n的全身涌去。\n",
	"$N使出一招「白佛光度」，左臂回收，右掌引内力直刺$n的$l,避得$n连连后退。\n",
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
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return CLASS_D("quanli") + "/yuping-dagger/" + action;
}

