// fonxansword.c
inherit SKILL;  
mapping *action = ({         
([      "action":               "$N���Ƶ�����$w�Ի���Ծ�����缲�������$n��$l",                 
	"damage":               50,                 
	"dodge":                -20,                 
	"damage_type":  "����"         ]),         
 ([      "action":               "$N����$w����΢�񣬻ó�һ���׹����$n��$l",                
	 "parry":                             -200,                
	 "damage":                 70,                 
	"force":               200,                 
	"dodge":                -200,                 
	"damage_type":  "����"         ]),        
	 ([      "action":               "$N��ָ�����㣬����$w�Ƴ�����ѩ����â������$n��$l",                 
	"parry":                             -250,                
	 "damage":                 90,                
	 "dodge":                -250,                
	 "force":               220,                
	 "damage_type":  "����"         ]),        
 ([      "action":               "$N����Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",                 
	"parry":                             -200,                 
	"damage":                 50,                 
	"dodge":                -200,                 
	"force":               100,                 
	"damage_type":  "����"         ]),        
 ([      "action":               "$N��������Ծ��$w��â��ˮ��һкǧ�����$n��$l",                
	 "parry":                             -300,                 
	"damage":                 150,                 
	"dodge":                -200,                 
	"force":               250,                 
	"damage_type":  "����"         ]),         
([      "action":               "$N����$wбָ���죬��â���£�����׼$n��$lбб����",                
	 "parry":                             -100,                 
	"damage":                 50,                 
	"dodge":                -100,                 
	"force":               150,                 
	"damage_type":  "����"         ]), });  
int valid_learn(object me)
 {
           object ob;         
	 if( (int)me->query("max_force") < 50 )                 
		return notify_fail("�������������û�а취��ӣ��������\n");          
	if( !(ob = me->query_temp("weapon"))         ||      (string)ob->query("skill_type") != "sword" )                
		 return notify_fail("���������һ�ѽ�������������\n");          
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
		 return  notify_fail("�����������������û�а취��ϰӣ��������\n");         
	me->receive_damage("kee", 30);        
	 me->add("force", -3);         
	write("�㰴����ѧ����һ��ӣ��������\n");        
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
string *parry_msg = ({         "$n�������Ʈ�䣬����$vƽָ����������$N���ա�\n",        
			 "$n��������� ����׾ٵļ�ס��$N��$w��\n",        
			 "$n����һ���������е�$v����ǧ�ٽ�â����ס��ȫ��\n",         
			"$n���е�$v���綶������ס��$N�����й��ơ�\n", 
		}); 
 string *unarmed_parry_msg = ({
			"$n���η��裬����ӣ������һ�㣬�����$N������һ����\n",
			"��Ҷ�ͷף��컨���裬$n���ŵ��ӣ������������ס��$N�Ĺ��ơ�\n",
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