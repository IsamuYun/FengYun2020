#include <ansi.h>
inherit FORCE;
mapping *action = ({
        ([      "action":
"$Nʹ��һ�С�������ػ�Ԫ�������־۳�һ�Ż�Ԫһ������$n��$l",
                "force":                500,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�������ػ�Ԫ�������־۳�һ�Ż�Ԫһ������$n��$l",
                "force":                800,
                "damage_type":  "����"
        ]),
	([ 	"action":
"$Nʹ��һ�С�������ػ�Ԫ����˫�־۳�һ�Ż�Ԫһ������$n��$l",
                "force":                1000,
                "damage_type":  "����"
        ]),
	([	"action":
"$Nʹ��һ�С�������ػ�Ԫ����ȫ���ڿն���ȫ����һ�Ż�Ԫһ������$n��$l",
                "force":                1200,
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
                if( random(2 * (me->query_skill("yiqiforce"))) > (damage_bonus + foo))
                {      
                        victim->receive_wound("kee", (damage_bonus + foo));
                        victim->receive_wound("gin", (damage_bonus + foo));
                        victim->receive_wound("sen", (damage_bonus + foo));
			force = victim->query("force");
			victim->set("force", force - random(force) - 1);
			//victim->set("max_force", 0);
                        return "$N�Ļ�Ԫһ�����ݻ���$n����Ԫ��������\n";
                }
        }
        return foo;
}
*/


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    /*
        if(!userp(me) && userp(victim) && me->query("id")=="dadi")
        {
                me->start_call_out( (: call_other, __FILE__, "kill_him", me, victim :), 1);  
        }
    */
    return 0;
}


void kill_him(object me, object victim)
{
        if(userp(victim))
        {
                victim->die();
        }
}

int valid_enable(string usage) 
{ 
return 	usage=="iron-cloth" ||
	usage=="unarmed" ||
	usage=="force";
}

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        if ( (int)me->query("force") < 30 ) {
	        return notify_fail("�����������������û�а취��ϰ��Ԫһ������\n");
        }

	me->add("force", -30);

	write("�㰴����ѧ����һ���Ԫһ������\n");

	return 1;
}

 
int effective_level() { return 100; }

string *absorb_msg = ({
        "$n������ת��˫��΢�����޼᲻�ݵĻ�Ԫһ�������ȶ�����\n",
        "$nʩչ����Ԫһ���������������纮����\n",
        "$n����΢չ����Ԫһ�����������ռ䡣\n",
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
        "$nʩչ������Ԫ���ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
});
string *parry_msg = ({
        "$n�������ȣ��������飬$N�������ɽ���\n",
        "$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",
        "$nʩչ������Ԫ���ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
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
	return 40;
}

int learn_bonus()
{
	return 100;
}
int practice_bonus()
{
	return 50;
}
int black_white_ness()
{
	return 200;
}
string exert_function_file(string func)
{
        return CLASS_D("xianren") + "/yiqiforce/" + func;
}

string perform_action_file(string action)
{
        return CLASS_D("xianren") + "/yiqiforce/" + action;
}
void skill_improved(object me)
{
        /*
        if( (int)me->query_skill("incarnation", 1)  < random(331) ) {
                tell_object(me,
                        HIR "\n��ͻȻȫ���飡�߻���ħ�ˣ���....\n\n" NOR);
		me->skill_death_penalty();
		me->delete_skill("yiqiforce");
		me->unconcious();
        }
        */
}
