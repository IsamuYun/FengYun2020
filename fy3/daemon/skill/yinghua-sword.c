// fonxansword.c
inherit SKILL;  
mapping *action = ({         
([      "action":               "$N合掌跌坐，$w自怀中跃出，如疾电般射向$n的$l",                 
	"damage":               50,                 
	"dodge":                -20,                 
	"damage_type":  "刺伤"         ]),         
 ([      "action":               "$N手中$w嗡嗡微振，幻成一条白光刺向$n的$l",                
	 "parry":                             -200,                
	 "damage":                 70,                 
	"force":               200,                 
	"dodge":                -200,                 
	"damage_type":  "刺伤"         ]),        
	 ([      "action":               "$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，刺向$n的$l",                 
	"parry":                             -250,                
	 "damage":                 90,                
	 "dodge":                -250,                
	 "force":               220,                
	 "damage_type":  "刺伤"         ]),        
 ([      "action":               "$N纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",                 
	"parry":                             -200,                 
	"damage":                 50,                 
	"dodge":                -200,                 
	"force":               100,                 
	"damage_type":  "刺伤"         ]),        
 ([      "action":               "$N纵身轻轻跃起，$w光芒如水，一泻千里，洒向$n的$l",                
	 "parry":                             -300,                 
	"damage":                 150,                 
	"dodge":                -200,                 
	"force":               250,                 
	"damage_type":  "刺伤"         ]),         
([      "action":               "$N手中$w斜指苍天，剑芒吞吐，，对准$n的$l斜斜击出",                
	 "parry":                             -100,                 
	"damage":                 50,                 
	"dodge":                -100,                 
	"force":               150,                 
	"damage_type":  "刺伤"         ]), });  
int valid_learn(object me)
 {
           object ob;         
	 if( (int)me->query("max_force") < 50 )                 
		return notify_fail("你的内力不够，没有办法练樱花剑道。\n");          
	if( !(ob = me->query_temp("weapon"))         ||      (string)ob->query("skill_type") != "sword" )                
		 return notify_fail("你必须先找一把剑才能练剑法。\n");          
		return 1;
 }  
int valid_enable(string usage)
 {         
	return usage=="sword" || usage=="parry"; 
}  
mapping query_action(object me, object weapon)
 {         
	return action[random(sizeof(action))];
 }  
int practice_skill(object me) 
{         
	if( (int)me->query("kee") < 30         ||      (int)me->query("force") < 3 )                
		 return  notify_fail("你的内力或气不够，没有办法练习樱花剑道。\n");         
	me->receive_damage("kee", 30);        
	 me->add("force", -3);         
	write("你按著所学练了一遍樱花剑道。\n");        
	 return 1;
 }  
string perform_action_file(string action)
 {         
	return CLASS_D("swordsman") + "/feixian-sword/" + action;
 }   
int effective_level() 
{ 
return 26;
}  
string *parry_msg = ({         "$n随风轻轻飘落，手中$v平指，缓缓拍向$N脸颊。\n",        
			 "$n随意挥洒， 轻而易举的架住了$N的$w。\n",        
			 "$n深吸一口气，手中的$v化作千百剑芒，护住了全身。\n",         
			"$n手中的$v急剧抖动，封住了$N的所有攻势。\n", 
		}); 
 string *unarmed_parry_msg = ({
			"$n身形飞舞，有如樱花飞舞一般，躲过了$N的险险一击。\n",
			"落叶缤纷，红花共舞，$n踩着点点樱花借力打力封住了$N的攻势。\n",
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
	return 0;
 } 
int practice_bonus()
 {
 	return 0; 
} 
int black_white_ness() 
{ 	
	return -10;
 }  