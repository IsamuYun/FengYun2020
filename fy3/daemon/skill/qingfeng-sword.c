// fonxansword.c
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N���ֺ�ü��$wб�������������������ޣ������ƿ���������·��ʵ���飬��ʽ����δ�䡣�������ʮ��ʽ�еĵ�һʽ����-��-��-����",
                "dodge":                100,
                "damage":               133,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����ʮ��ʽ�еڰ�ʽ����-��-ǧ-�塹����������������������˷���ȴ�ֲ��嵽����һ�����졣",
                "dodge":                120,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����ʮ��ʽ�еڶ�ʽ����-��-ө-�𡹣��ؽ�������Ʈ��Ľ����������ͬҹ������ө���裬Ϯ��$n$l��",
                "dodge":                100,
                "damage":               150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����ᶶ�ὣ������ֻ������������Ʈҡ������ȴ�����ʮ��ʽ�е���ʽ����-��-ɽ-ᰡ�",
                "dodge":                270,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���ӣ��ƺ���̬���У�ͣ�в�����Ȼ�����Ʋ�����ı��֮���ѷ���$n$l���������ʮ��ʽ�е���ʽ����-��-��-�᡹",
                "dodge":                150,
                "damage":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ӻ���һ���뻡������$w���㣬ʹ�����ʮ��ʽ�е���ʽ����-Ѩ-��-�硹�������Ľ�����Ȼ������˷�����$n��",
                "dodge":                100,
                "damage":               110,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w�������ǰ������б�Ӷ��£�����һת��$wƽƽ�Ƴ���˿˿����ƮȻ�������������ʮ��ʽ�е���ʽ��˪-��-��-����",
                "dodge":                195,
                "damage":               170,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���ƺ�����ң�������ǰƮ�������˷ֲ��巽��Ȼ������ȴ���������紺���Ⱦ���֡��������ʮ��ʽ�еھ�ʽ����-��-��-�硹",
                "dodge":                110,
                "damage":               130,
                "damage_type":  "����"
        ]),                       
        ([      "action":               
"$Nʹ�����ʮ��ʽ�е�ʮʽ����-÷-��-ѩ����ֻ���������裬�������䣬������÷�ڷ���Ʈ��$n$l��",
                "dodge":                195,
                "damage":               220,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w��ת��һ�����̶̵Ļ��⸡����ǰ���������ʮ��ʽ�е�ʮ��ʽ����-��-��-Ƽ����ֻ������Ʈ��������$n$l��",
                "dodge":                260,
                "damage":               230,
                "damage_type":  "����"
        ]),  
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 300 )
                return notify_fail("�������������û�а취�����ʮ��ʽ��\n");

        if ((int)me->query_skill("force", 1) < 100) 
        {
                return notify_fail("��Ļ����ڹ����̫ǳ��\n");
        }

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ����������ʮ��ʽ��\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int attack_act;        
        attack_act=random(sizeof(action));
        me->set_temp("qingfeng-act",attack_act); 
        return action[attack_act];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 10 )
                return 
notify_fail("�����������������û�а취��ϰ���ʮ��ʽ��\n");
        me->receive_damage("kee", 50);
        me->add("force", -10);
        if(random(10))
        {
        	return notify_fail("�㰴����ѧ����һ�����ʮ��ʽ�����Ǹо�һ������\n");;	
        }
        write("�㰴����ѧ����һ�����ʮ��ʽ��\n");
        return 1;
}
 
int effective_level() { return 28;}

string *parry_msg = ({
	"$n����$v�������𣬽���Ʈ�����������������������ʮ��ʽ�е���ʽ����-��-��-�ʹ������������֯��һ��������\n",
	"$n���$v�������������޼�бƮ������ʹ�����ʮ��ʽ�е�ʮһʽ����-��-ƫ-��������$N���ƻ������Ρ�\n",
	"$n��紵������΢΢�������ֻӳ�$v��������ƬƬ��ϼƮ���������ʮ��ʽ�е�ʮ��ʽ����-ϼ-��-ɢ����$N������⡣\n",
});

string *unarmed_parry_msg = ({
	"$n����$v�������𣬽���Ʈ�����������������������ʮ��ʽ�е���ʽ����-��-��-�ʹ������������֯��һ��������\n",
	"$n���$v�������������޼�бƮ������ʹ�����ʮ��ʽ�е�ʮһʽ����-��-ƫ-��������$N���ƻ������Ρ�\n",
	"$n��紵������΢΢�������ֻӳ�$v��������ƬƬ��ϼƮ���������ʮ��ʽ�е�ʮ��ʽ����-ϼ-��-ɢ����$N������⡣\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/qingfeng-sword/" + action;
}

mixed hit_ob(object me, object victim)
{       
	int act;
	int pro;
    int dam;
    int level_bonus;       
    string damtype;
        
    if (me->query_skill_mapped("force") != "wuzheng-force")
    {
    	return ("");   
	}
    
    level_bonus = me->query_skill("qingfeng-sword",1);
    act=me->query_temp("qingfeng-act");     
    
    pro = 0;    
        switch(act) {
                case 0:
                        if (level_bonus < 30) break;
                        damtype="kee";
                        pro = 1;
                        break;
                case 7:
                        if (me->query("combat_exp")<600000 || level_bonus < 50) break;
                        damtype="sen";
                        pro = 1;
                        break;
                case 2:
                        if (me->query("combat_exp")<400000  || level_bonus < 40) break;
                        damtype="kee";
                        pro = 2;
                        break;
                case 5:
                        if (me->query("combat_exp")<800000  || level_bonus < 60) break;
                        damtype="gin";
                        pro = 1;
                        break;
                case 8:
                        if (me->query("combat_exp")<1600000  || level_bonus < 80) break;
                        damtype="kee";
                        pro = 3;
                        break;
                case 9:
                        if (me->query("combat_exp")<1200000  || level_bonus < 70) break;
                        damtype="sen";
                        pro = 2;
                        break;
                case 1:
                        if (me->query("combat_exp")<1500000  || level_bonus < 100) break;
                        damtype="kee";
                        pro = 4;
                        break;
                case 3:
                   		if (me->query("combat_exp")<2000000  || level_bonus < 120) break;
                        damtype="gin";
                        pro = 2;
                        break;
                case 4:
                        if (me->query("combat_exp")<3000000  || level_bonus < 140) break;
                        damtype="kee";
                        pro = 5;
                        break;
                case 6:
                        if (me->query("combat_exp")<4000000  || level_bonus < 160) break;
                        damtype="sen";
                        pro = 3;
                        break;
                case 10:
                   		if (me->query("combat_exp")<4500000  || level_bonus < 240) break;
                        damtype="gin";
                        pro = 3;
                        break;
                case 11:
                        if (me->query("combat_exp")<5000000  || level_bonus < 260) break;
                        damtype="kee";
                        pro = 6;
                        break;
                case 12:
                        if (me->query("combat_exp")<5500000  || level_bonus < 280) break;
                        damtype="sen";
                        pro = 4;
                        break;
                }
        if(damtype)
        {
                dam = (4+pro) * (int) me->query("force_factor");
                dam += (1+pro)*level_bonus;
                victim->receive_damage(damtype,dam,me);
                return (HIC"$n"NOR+HIC"���û���һ�飬�ƺ��ѱ�$N���ھ����ˡ�\n" NOR);
        }            
	
	return ("");
} 

int learn_bonus()
{
	return -3000;
}
int practice_bonus()
{
	return -3000;
}
int black_white_ness()
{
	return 200;
}

