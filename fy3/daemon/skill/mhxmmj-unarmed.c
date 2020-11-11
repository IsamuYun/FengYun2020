// ÕâÊÇÍæ¼Ò×Ô´´Îä¹¦³ÌĞò Ô­ÓÉmaxim@nju_fengxue±àĞ´£¬ÏÖÓÉxgchen@zzfyĞŞ¸Ä
// xmmj
// ³¿·ç
// ÃÎ»Ã³Ç¡¡[1;31mµ¶Éñ[2;37;0m
// 7600779
// ÄĞĞÔ
// unarmed
// ÃÎ»Ã·çÎèÈ­





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÈ«Éí°ÎµØ¶øÆğÊ¹³öÒ»ÕĞ»ÃÏëÔÆÂä,$NµÄÈ­¼²ÈçÉÁµç£¬È­·çÎŞ´¦²»ÔÚµØÏò$nµÄ$l¹¥È¥",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "ğöÉË",
"skill_name" : "»ÃÏëÔÆÂä"
]),
// ZHAOSHI :1

([
"action" :"$NÉíĞĞ¶·×ª¡¸»ÃÊÀ¿ñ·ç¡¹ºôĞ¥¶ø³ö£¬Ë²¼ä»¯×÷Áú¾í¿ñ·ç¹¥Ïò$nµÄ$l",
"damage" :80,
"dodge" :-10,
"parry" :-10,
"damage_type": "ğöÉË",
"skill_name" : "»ÃÊÀ¿ñ·ç"
]),
// ZHAOSHI :2

([
"action" :"$NÒ»Éù³¤Ğ¥£¬Ò»ÕĞ¡¸·ç¾í²ĞÔÆ¡¹»÷³ö£¬Ç¿ÁÒµÄÈ­·çÆËÏò$nµÄ$l",
"damage" :100,
"dodge" :-20,
"parry" :-20,
"damage_type": "ğöÉË",
"skill_name" : "·ç¾í²ĞÔÆ"
]),
// ZHAOSHI :3

([
"action" :"$NÉíĞĞÒ»ÉÁ£¬Ò»ÕĞ¡¸¶·×ªĞÇÒÆ¡¹Ë«È­»¯×÷ÂşÌì·±ĞÇÏò$n$l¹¥È¥",
"damage" :130,
"dodge" :-30,
"parry" :-30,
"damage_type": "ğöÉË",
"skill_name" : "¶·×ªĞÇÒÆ"
]),
// ZHAOSHI :4

([
"action" :"$NË«ÍÈÈçĞĞÔÆ°ãÌß³ö£¬Ò»¸ö¿Õ·­£¬Í·³¯ÏÂ£¬Ë«È­Á¬»·»÷³ö¡¸¸²Óê·­ÔÆ¡¹£¬¹¥Ïò$n$l",
"damage" :150,
"dodge" :-50,
"parry" :-40,
"damage_type": "ğöÉË",
"skill_name" : "¸²Óê·­ÔÆ"
]),
// ZHAOSHI :5

([
"action" :"$Nì¬È»Í£×¡£¬ĞÄ¾²Èç¡¸¾®ÖĞÖ®ÔÂ¡¹£¬ÈËÒ»¶¯²»¶¯£¬Õû¸öÈ­·¢³öµÄ¾¢·çÀ©Ïò$n$l",
"damage" :180,
"dodge" :-60,
"parry" :-50,
"damage_type": "ğöÉË",
"skill_name" : "¾®ÖĞÖ®ÔÂ"
]),
// ZHAOSHI :6

([
"action" :"$N·ÉÉí¶øÆğ£¬Ë«È­»¯×ÅÍòÇ§È­Ó°£¬Ò»ÕĞ¡¸»÷ÆæÑ©Ó¿¡¹,È­·çÈç´óÑ©°ã¾íÏò$n$l",
"damage" :200,
"dodge" :-80,
"parry" :-60,
"damage_type": "ğöÉË",
"skill_name" : "»÷ÆæÑ©Ó¿"
]),
// ZHAOSHI :7

([
"action" :"$NÈ«ÉíĞı×ªÆğÀ´£¬Ë²¼ä»¯³ÉÈçÃÎÈç»ÃµÄÉíÓ°£¬¾øÑ§¡¸ÃÎ»Ã·çÎè¡¹ºôĞ¥¶ø³ö£¬Ïò$n$l»÷³öÖÂÃüÒ»È­",
"damage" :220,
"dodge" :-90,
"parry" :-70,
"damage_type": "ğöÉË",
"skill_name" : "ÃÎ»Ã·çÎè"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"ÃÎ»Ã·çÎèÈ­"+"±ØĞë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·"+"ÃÎ»Ã·çÎèÈ­"+"¡£\n");
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
