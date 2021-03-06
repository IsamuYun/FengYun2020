// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改
// everhave
// 拥有
// 少林寺第二十四代弟子
// 20002087
// 男性
// blade
// 寂寞十三刀





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N脸上露出一种寂寞之色，手中$w一招「高处不胜寒 」，刀光就像披在他身上的一袭舞衣，虚无飘渺的向$n袭去！",
"damage" :50,
"dodge" :20,
"parry" :20,
"damage_type": "割伤",
"skill_name" : "高处不胜寒"
]),
// ZHAOSHI :1

([
"action" :"$N对着中天青月喃喃自语「宿命由天」，$w发出厉青色的刀光，斩破尘世间一切障碍，破空向$n飞去！",
"damage" :80,
"dodge" :10,
"parry" :20,
"damage_type": "割伤",
"skill_name" : "宿命由天"
]),
// ZHAOSHI :2

([
"action" :"$N腾身而起，仰天狂啸「天命由我」,手中$w如同划破天地般劈向$n，甚至苍穹也震荡出一股嗡嗡、宏宏的罡风！",
"damage" :100,
"dodge" :10,
"parry" :10,
"damage_type": "割伤",
"skill_name" : "天命由我"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力太弱，无法练"+"寂寞十三刀"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int effective_level() { return 30;}
int practice_skill(object me)
{
object weapon; 
if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
                      return notify_fail("你使用的武器不对。\n");	
if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("force") < 40 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 40);
	me->add("force", -40);
	return 1;
} 
string *parry_msg = ({
	"$n使出一招虚招，手中$v虚点一招，突然回招换式，护住$n的全身。\n",
});
string *unarmed_parry_msg = ({
"$n一招反攻，用手中的$v荡开了$N的招式。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus()
{	return -150;
}
int practice_bonus()
{	return -150;
}
int black_white_ness()
{	return 30;
}
string perform_action_file(string action)
{
        return CLASS_D("player") + "/"+"weapon"+"/" + action;
}
