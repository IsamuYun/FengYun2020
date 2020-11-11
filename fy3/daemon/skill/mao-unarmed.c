// ÕâÊÇÍæ¼Ò×Ô´´Îä¹¦³ÌĞò Ô­ÓÉmaxim@nju_fengxue±àĞ´£¬ÏÖÓÉxgchen@zzfyĞŞ¸Ä
// pltd
// Åùö¨Ììµ¶
// ·çÔÆĞ¡Ñ§¡¡Ç°ÈÎĞ£³¤
// 9801914
// Å®ĞÔ
// unarmed
// Ö÷Ï¯È­·¨





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÒ»»ÓÊÖ,Ò»ÕĞ[½­É½Èç´Ë¶à½¿],ÉñÈ­»÷Ïò$nµÄ$l",
"damage" :50,
"dodge" :10,
"parry" :10,
"damage_type": "ğöÉË",
"skill_name" : "½­É½Èç´Ë¶à½¿"
]),
// ZHAOSHI :1

([
"action" :"$NÒ»°ÚÊÖ£¬Ò»ÕĞ[ÎŞÊıÓ¢ĞÛ¾ºÕÛÑü]£¬ÉñÕÆ¿³Ïò$nµÄ$l",
"damage" :80,
"dodge" : 10,
"parry" :-10,
"damage_type": "ğöÉË",
"skill_name" : "ÎŞÊıÓ¢ĞÛÕÛÑü"
]),
// ZHAOSHI :2

([
"action" :"$NÒ»°ÚÊÖ£¬Ò»ÕĞ[ÇØººÂÔÊäÎÄ²É]£¬ÉñÕÆ¿³Ïò$nµÄ$l",
"damage" :100,
"dodge" : 10,
"parry" :-20,
"damage_type": "ğöÉË",
"skill_name" : "ÇØººÂÔÊäÎÄ²É"
]),
// ZHAOSHI :3

([
"action" :"$NÒ»¾ÙÊÖ£¬Ò»ÕĞ[ÌÆ×ÚËÎ×æÉÔÑ··çÉ§£İ£¬ÊÖÕÆ´ÌÏò$nµÄ$l",
"damage" :130,
"dodge" :25,
"parry" :30,
"damage_type": "ğöÉË",
"skill_name" : "ÌÆËÎÉÔÑ··çÉ§"
]),
// ZHAOSHI :4

([
"action" :"$NµÄÊÖÏñÀû¼ıÒ»Ñù£¬Ò»ÕĞË£¬´ÌÏò$nµÄ$l---¡µ",
"damage" :150,
"dodge" :30,
"parry" :40,
"damage_type": "ğöÉË",
"skill_name" : "Ë¼º¹Íä¹­Éäµñ"
]),
// ZHAOSHI :5

([
"action" :"$N°ÑË«ÊÖÒ»Ñï£¬ Ò»ÕĞÊ£¬ ÎŞÇîµÄ¾¢Á¦Ïò$nµÄ$l³å»÷£¡",
"damage" :180,
"dodge" :40,
"parry" :50,
"damage_type": "ğöÉË",
"skill_name" : "Êı·çÁ÷ÈËÎï"
]),
// ZHAOSHI :6

([
"action" :"$N°ÑÊÖÖ¸ÏòÇ°·½£¬Ò»ÕĞ»£¬ÓîÖæµÄÁ¦Á¿´©¹ıÁË$nµÄ$l£¡",
"damage" :200,
"dodge" :50,
"parry" :60,
"damage_type": "ğöÉË",
"skill_name" : "»¹¿´Åùö¨Ììµ¶"
]),
// ZHAOSHI :7

([
"action" :"$N°ÑÓÒÊÖÏòºóÒ»Ñï£¬Ò»ÕĞÍ£¬$nµÄ$l±»Ë¼ÏëÕ÷·şÁË£¡",
"damage" :220,
"dodge" :80,
"parry" :70,
"damage_type": "ğöÉË",
"skill_name" : "Í¬Ö¾ÃÇĞÁ¿àÁË"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"Ö÷Ï¯È­·¨"+"±ØĞë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·"+"Ö÷Ï¯È­·¨"+"¡£\n");
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
