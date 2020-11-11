// ÕâÊÇÍæ¼Ò×Ô´´Îä¹¦³ÌĞò Ô­ÓÉmaxim@nju_fengxue±àĞ´£¬ÏÖÓÉxgchen@zzfyĞŞ¸Ä
// zyzz
// ×ÔÓÉ×ÔÔÚ
// ×ÔÔÚÃÅ¡¡ÃÅÖ÷[1;33m¡¾ÊµÏ°²¶¿ì¡¿[2;37;0m
// 10565729
// ÄĞĞÔ
// blade
// ×ÔÔÚµ¶·¨





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÎ¢Î¢Ò»Ğ¦£¬Æ¾¿Õ»®ÏÂ£¬Ê¹³öÒ»ÕĞ¡¸×ÔÓÉ×ÔÔÚ¡¹£¬ÊÖÖĞ$wÈçÃÎËÆ»Ã°ãµØÖ±Åü$nµÄ$l£¡",
"damage" :50,
"dodge" :20,
"parry" :20,
"damage_type": "¸îÉË",
"skill_name" : "×ÔÓÉ×ÔÔÚ"
]),
// ZHAOSHI :1

([
"action" :"$NÄÃÆğ´óµ¶Ïò¹í×Ó¿³È¥£¬$n¶ãÉÁ²»¼¶£¬$lÖĞÁËÒ»ÏÂ",
"damage" :80,
"dodge" :10,
"parry" :20,
"damage_type": "¸îÉË",
"skill_name" : "×Ô¼º×ÔÔÚ"
]),
// ZHAOSHI :2

([
"action" :"$N¶Ô×Å$nµÄ$l£¬±Õ×ÅÑÛ¾¦£¬Ò»µ¶ÅüÁËÏÂÈ¥£¬Ö»ÌıßêµÄÒ»Éù£¬¿ã¹Ü±»ËºÆÆÁË",
"damage" :100,
"dodge" :10,
"parry" :10,
"damage_type": "¸îÉË",
"skill_name" : "×ÔÔÚµ¶·¨ÈıÕĞ"
]),
// ZHAOSHI :3

([
"action" :"$NÈö³öÒ»°Ñ»Æ½ğ£¬$nÑÛ»¨çÔÂÒ£¬±»Ò»µ¶¿³ÔÚ$l",
"damage" :130,
"dodge" :5,
"parry" :10,
"damage_type": "¸îÉË",
"skill_name" : "×ÔÔÚ´ó·¨ËÄÕĞ"
]),
// ZHAOSHI :4

([
"action" :"$N´óº°Ò»Éù£¬£Ó£È£Õ£Ô¡¡£Õ£Ğ£¬$n±»¿ÚË®ÅçÁËÒ»Á³£¬½ÅÏÂÒ»Âı£¬$l±»¿³ÁËÏÂÀ´",
"damage" :150,
"dodge" :-5,
"parry" :5,
"damage_type": "¸îÉË",
"skill_name" : "×ÔÔÚ´ó·¨ÎåÕĞ"
]),
// ZHAOSHI :5

([
"action" :"$NÈ«Á¦Ò»»Ó£¬Ë­ÖªÊÖÖĞ$w¶Ï³ÉÁ½¿é£¬Ç°°ë²¿·ÖÖ±±¼$n$l¶øÈ¥",
"damage" :180,
"dodge" :-5,
"parry" :5,
"damage_type": "¸îÉË",
"skill_name" : "×ÔÔÚ´ó·¨Áù"
]),
// ZHAOSHI :6

([
"action" :"$NÒ»¿Ú°ÑÍëÖĞÊ£ÏÂµÄ¾ÆºÈ¸É£¬ÒâÓÌÎ´¾¡µØÓÃĞä×Ó²ë²ë×ì£¬°Ñ$wµİ¸ø$n£¬ËµµÀ£¬ÔÙ»»Ò»ÍëÀ´",
"damage" :200,
"dodge" :-10,
"parry" :5,
"damage_type": "¸îÉË",
"skill_name" : "×ÔÔÚ´ó·¨Æß"
]),
// ZHAOSHI :7

([
"action" :"$NÊÖ³Ö$w£¬×ĞÏ¸µØÒ»µ¶µ¶µØĞŞ×Å½ÅÖº¼×£¬È«È»²»°Ñ$n·ÅÔÚÑÛÀï",
"damage" :220,
"dodge" :-10,
"parry" :5,
"damage_type": "¸îÉË",
"skill_name" : "×ÔÔÚ´ó·¨°Ë"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·"+"×ÔÔÚµ¶·¨"+"¡£\n");
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
