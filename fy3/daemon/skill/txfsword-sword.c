// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改
// txf
// 枫
// 移花宫第三代宫主
// 200003144
// 女性
// sword
// 风卷残云





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N一啸冲天，闪电般的冲向$n，手中$w一招「金光泻地」对准的$l斜斜刺出一剑",
"damage" :50,
"dodge" :20,
"parry" :20,
"damage_type": "刺伤",
"skill_name" : "飞仙剑"
]),
// ZHAOSHI :1

([
"action" :"$N身行加快，天地巨变，左手中$w一招「狂风暴雨」对准的$l直直刺出一剑",
"damage" :80,
"dodge" :10,
"parry" :20,
"damage_type": "刺伤",
"skill_name" : "左手剑"
]),
// ZHAOSHI :2

([
"action" :"$N脚踏［段家步］，同时使出［段家剑］中的精髓－［化蝶］，手中的$w划出彩蝶般的曲线击向$n的$l",
"damage" :100,
"dodge" :10,
"parry" :10,
"damage_type": "刺伤",
"skill_name" : "段家剑"
]),
// ZHAOSHI :3

([
"action" :"$N流漏出惋惜的目光，手中$w一招「无情」对准的$l慢慢的直削一剑",
"damage" :130,
"dodge" :5,
"parry" :10,
"damage_type": "刺伤",
"skill_name" : "忘情剑"
]),
// ZHAOSHI :4

([
"action" :"$N手中$w剑光暴长，一招「鬼影憧憧」往$n$l刺去！",
"damage" :150,
"dodge" :-5,
"parry" :5,
"damage_type": "刺伤",
"skill_name" : "吹雪剑"
]),
 });
// ZHAOSHI :5
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力太弱，无法练"+"风卷残云"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int effective_level() { return 30;}
int practice_skill(object me)
{
object weapon; 
if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
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
        return CLASS_D("player") + "/"+"风卷残云"+"/" + action;
}
