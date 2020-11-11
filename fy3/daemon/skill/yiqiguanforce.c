#include <ansi.h>
inherit FORCE;
mapping *action = ({
        ([      "action":
"$Nʹ��һ�С����ڳ��졹�����־۳�һ�����»���$n��$l",
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�����ɽ�⡹�����־۳�һ�����»���$n��$l",
                "force":                250,
                "damage_type":  "����"
        ]),
	([ 	"action":
"$Nʹ��һ�С��������ա���˫�־۳�һ�����»���$n��$l",
                "force":                350,
                "damage_type":  "����"
        ]),
	([	"action":
"$Nʹ��һ�С����ھ��졹��ȫ���ڿն���ȫ����һ�����»���$n��$l",
                "force":                450,
                "damage_type":  "����"
        ]),
});
/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
	int force;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(2*(me->query_skill("yiqiguanforce"))) > (damage_bonus + foo))
 {
                        victim->receive_wound("kee", (damage_bonus + foo));
                        victim->receive_wound("gin", (damage_bonus + foo));
                        victim->receive_wound("sen", (damage_bonus + foo));
			force = victim->query("force");
			victim->set("force", force-random(10)-1);
			victim->set("max_force", 0);
                        return
"$N�������񹦴ݻ���$n���������Σ�������\n";
                }
        }
        return foo;
}
*/
int valid_enable(string usage) 
{ 
return 	usage=="iron-cloth" ||
	usage=="unarmed" ||
       usage=="force"; 
}

int valid_learn(object me) 
{
if ( me->query_skill("bolomiduo",1)
	|| me->query_skill("cloudforce",1)
	|| me->query_skill("cloudsforce",1)
	|| me->query_skill("dachengforce",1)
	|| me->query_skill("damoforce",1)
	|| me->query_skill("demon-force",1)
	|| me->query_skill("doomforce",1)
	|| me->query_skill("ghost-force",1)
	|| me->query_skill("gouyee",1)
	|| me->query_skill("huntunforce",1)
	|| me->query_skill("iceforce",1)
	|| me->query_skill("iceheart",1)
	|| me->query_skill("jiayiforce",1) 
       || me->query_skill("jingxing",1)
	|| me->query_skill("jingyiforce",1)
	|| me->query_skill("lotusforce",1)
	|| me->query_skill("manjianghong",1)
	|| me->query_skill("mystforce",1)
	|| me->query_skill("nine-moon-force",1)
	|| me->query_skill("noloveforce",1)
	|| me->query_skill("qidaoforce",1)
	|| me->query_skill("taijiforce",1)
	|| me->query_skill("tangforce",1)
	|| me->query_skill("vivienforce",1)
	|| me->query_skill("wuchenforce",1)
|| me->query_skill("xiaochengforce",1)
	|| me->query_skill("yiqiforce",1)
	
	|| me->query_skill("zixia-shengong",1))
	

		return notify_fail("�㲻�ȷ��˱����ڹ�������ѧ�����񹦣���\n");
 return 1; }

int practice_skill(object me)
{
        return 
notify_fail("������ֻ����ѧ�ġ�\n");
}

 
int effective_level() { return 50;}

string *absorb_msg = ({
        "$n������ת��˫��΢�����޼᲻�ݵ����¹����ȶ�����\n",
        "$nʩչ�����¹������������纮����\n",
        "$n����΢չ�����³��������ռ䡣\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$n�������ȣ��������飬$N�������ɽ���\n",
        "$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",
        "$nʩչ��������Ϊ�项�����赭д�Ļ�����$N�Ĺ��ơ�\n",
});
string *parry_msg = ({
        "$n�������ȣ��������飬$N�������ɽ���\n",
        "$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",
        "$nʩչ��������Ϊ�项�����赭д�Ļ�����$N�Ĺ��ơ�\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int bounce_ratio()
{
        return 20;
}

int learn_bonus()
{
	return -5000;
}
int practice_bonus()
{
	return -5000;
}
int black_white_ness()
{
	return 200;
}
string exert_function_file(string func)
{
        return CLASS_D("xianren") + "/yiqiguanforce/" + func;
}

string perform_action_file(string action)
{
        return CLASS_D("xianren") + "/yiqiguanforce/" + action;
}
