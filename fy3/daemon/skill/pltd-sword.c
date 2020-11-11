// ÕâÊÇÍæ¼Ò×Ô´´Îä¹¦³ÌĞò Ô­ÓÉmaxim@nju_fengxue±àĞ´£¬ÏÖÓÉxgchen@zzfyĞŞ¸Ä
// pltd
// Åùö¨Ììµ¶
// [1;35mÑãÓğÃÅ¾ø´úÌì½¾[2;37;0m
// 14645300
// Å®ĞÔ
// sword
// Åùö¨¼ı·¨





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÊÖÖĞ$wÒ»ÕĞÇ´ÌÏò$nµÄ$l",
"damage" :50,
"dodge" :20,
"parry" :20,
"damage_type": "´ÌÉË",
"skill_name" : "Çà"
]),
// ZHAOSHI :1

([
"action" :"$NÊÖÖĞµÄ$wÒ»ÕĞº¿³Ïò$nµÄ$l",
"damage" :80,
"dodge" :10,
"parry" :20,
"damage_type": "´ÌÉË",
"skill_name" : "ºì"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·"+"Åùö¨¼ı·¨"+"¡£\n");
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
                      return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");	
if( (int)me->query("kee") < 40 )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("force") < 40 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	me->receive_damage("kee", 40);
	me->add("force", -40);
	return 1;
} 
string *parry_msg = ({
	"$nÊ¹³öÒ»ÕĞĞéÕĞ£¬ÊÖÖĞ$vĞéµãÒ»ÕĞ£¬Í»È»»ØÕĞ»»Ê½£¬»¤×¡$nµÄÈ«Éí¡£\n",
});
string *unarmed_parry_msg = ({
"$nÒ»ÕĞ·´¹¥£¬ÓÃÊÖÖĞµÄ$vµ´¿ªÁË$NµÄÕĞÊ½¡£\n",
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
