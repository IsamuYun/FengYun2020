// ÕâÊÇÍæ¼Ò×Ô´´Îä¹¦³ÌĞò Ô­ÓÉmaxim@nju_fengxue±àĞ´£¬ÏÖÓÉxgchen@zzfyĞŞ¸Ä
// skydream
// ÌìÃÎ
// ¶ùÍ¯ÍÅ¡¡[1;37m º¢×Ó[2;37;0m
// 10015579
// Å®ĞÔ
// unarmed
// ¾ÅÌìÃÎ¾³ÉñÈ­





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"y",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "ğöÉË",
"skill_name" : "ÈËÉúÒ»³¡´óÃÎ"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"¾ÅÌìÃÎ¾³ÉñÈ­"+"±ØĞë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·"+"¾ÅÌìÃÎ¾³ÉñÈ­"+"¡£\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
int effective_level() { return 20;}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("force") < 30 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -30);
	return 1;
} 
string *parry_msg = ({
        "$nÀûÓÃÉí·¨ÒıÆ«ÁË$NµÄ$w¡£\n",
});
string *unarmed_parry_msg = ({
        "$nÇáÃèµ­Ğ´µÄ»¯½âÁË$NµÄ¹¥ÊÆ¡£\n",
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
        return 30;
}
int practice_bonus()
{
        return -30;
}
int black_white_ness()
{
        return 320;
}
string perform_action_file(string action)
{
        return CLASS_D("player") + "/"+"unarmed"+"/" + action;
}
