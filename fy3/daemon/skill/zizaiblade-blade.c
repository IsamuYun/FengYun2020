// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改
// zyzz
// 自由自在
// 自在门　门主[1;33m【实习捕快】[2;37;0m
// 10565729
// 男性
// blade
// 自在刀法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N微微一笑，凭空划下，使出一招「自由自在」，手中$w如梦似幻般地直劈$n的$l！",
"damage" :50,
"dodge" :20,
"parry" :20,
"damage_type": "割伤",
"skill_name" : "自由自在"
]),
// ZHAOSHI :1

([
"action" :"$N拿起大刀向鬼子砍去，$n躲闪不级，$l中了一下",
"damage" :80,
"dodge" :10,
"parry" :20,
"damage_type": "割伤",
"skill_name" : "自己自在"
]),
// ZHAOSHI :2

([
"action" :"$N对着$n的$l，闭着眼睛，一刀劈了下去，只听哧的一声，裤管被撕破了",
"damage" :100,
"dodge" :10,
"parry" :10,
"damage_type": "割伤",
"skill_name" : "自在刀法三招"
]),
// ZHAOSHI :3

([
"action" :"$N撒出一把黄金，$n眼花缭乱，被一刀砍在$l",
"damage" :130,
"dodge" :5,
"parry" :10,
"damage_type": "割伤",
"skill_name" : "自在大法四招"
]),
// ZHAOSHI :4

([
"action" :"$N大喊一声，ＳＨＵＴ　ＵＰ，$n被口水喷了一脸，脚下一慢，$l被砍了下来",
"damage" :150,
"dodge" :-5,
"parry" :5,
"damage_type": "割伤",
"skill_name" : "自在大法五招"
]),
// ZHAOSHI :5

([
"action" :"$N全力一挥，谁知手中$w断成两块，前半部分直奔$n$l而去",
"damage" :180,
"dodge" :-5,
"parry" :5,
"damage_type": "割伤",
"skill_name" : "自在大法六"
]),
// ZHAOSHI :6

([
"action" :"$N一口把碗中剩下的酒喝干，意犹未尽地用袖子搽搽嘴，把$w递给$n，说道，再换一碗来",
"damage" :200,
"dodge" :-10,
"parry" :5,
"damage_type": "割伤",
"skill_name" : "自在大法七"
]),
// ZHAOSHI :7

([
"action" :"$N手持$w，仔细地一刀刀地修着脚趾甲，全然不把$n放在眼里",
"damage" :220,
"dodge" :-10,
"parry" :5,
"damage_type": "割伤",
"skill_name" : "自在大法八"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力太弱，无法练"+"自在刀法"+"。\n");
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
