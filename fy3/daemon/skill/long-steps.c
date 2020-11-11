//����̫����  written by tiandi
inherit SKILL;
#include <ansi.h>
#include <combat.h>
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}
string status_msg(int ratio)
{
        if( ratio==100 ) return HIG "���������������������۷�״̬��" NOR;
        if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
        if( ratio > 90 ) return HIY "������������Щ���á�" NOR;
        if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
        if( ratio > 60 ) return HIY "�������꣬��ɫ�Ұס�" NOR;
        if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
        if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
        if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

string *dodge_msg = ({
	"$nһ�С��Ի�������ҡҡ�λεر��˿�ȥ��\n",
	"ֻ��$n��ӰƮ�������Ծ���֮״��һʽ�������������ѱ�������֮�⡣\n",
	"$nʹ�����㾦����������$N����һ�㣬�������Ѿ�����$N����ʽ��\n",
	"$n����һ�㣬һ�С�¡�жԡ��ڿն��𣬵���ײײ�رܹ���$Nһ����\n",
	"$n��Ӱ΢�����Ѿ���һ�С������Ρ����Լ�������Ӳ��Ų�˰�֡�\n",
	 "����$n��̤���Բ����������ţ�һ��"+HIM"��ŤתǬ����"+NOR"��ת��Ϊ����$NϮȥ��\n",
        "$n��������һ�Σ�һ��ת����һ��ת�ۣ����ѽ�$N���˵�����֮�⡣\n",
	 "$n���һ�����ҿ�һ����һʱ����Ӱ�ƺ��������������$N�ε��ۻ����ҡ�\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query_skill("move",1) < 150 || (int)me->query_skill("dodge",1)<150)
		return notify_fail("��Ļ���������û�а취��"+HIC"��"+HIY"��"+HIR"̫"+HIW"��"+HIB"��\n"NOR);
	  if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("����Ŀǰ��״������û���ʸ���"+HIC"��"+HIY"��"+HIR"̫"+HIW"��"+HIB"��\n"NOR);

	return 1;
}

string query_dodge_msg(string limb)
{
	object me=this_player();
	object target = offensive_target(me);
	int i;
//        object weapon = target->query_temp("weapon");
	int lv = target->query_skill("long-steps",1);
	int force=target->query("eff_force");
	int damage=random(force)+100;
	string msg;
	i=random(sizeof(dodge_msg));
	if(i!=5)   return dodge_msg[i];
        if (lv >130)  { 
		msg=dodge_msg[5];
		msg+="$n�������ѣ��·������һ�㣬��������������������$n����ͻȻ����һ������������ת�죬Ѹ����$N�����˹�����\n";
		msg+="$Nʼδ�ϵ�$n��������һɱ�У���æ������������Ӧ������$n����ʵʵ�ػ���Ҫ����\n";
		me->receive_wound("kee",damage);
             	msg+= "( $N"+status_msg((int)me->query("eff_kee")*100/(int)me->query("max_kee"))+")\n";
		return msg;
						}
	return dodge_msg[4];
}
int practice_skill(object me)
{
	if( (int)me->query_skill("move",1) < 250 || (int)me->query_skill("dodge",1)<250)
		return notify_fail("��Ļ���������û�а취��"+HIC"��"+HIY"��"+HIR"̫"+HIW"��"+HIB"��\n"NOR);

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������������"+HIC"��"+HIY"��"+HIR"̫"+HIW"��"+HIB"��\n"NOR);
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 25;}

int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return 20;
}
int black_white_ness()
{
	return 100;
}

string perform_action_file(string action)
{
        return CLASS_D("zhuge") + "/long-steps/" + action;
}
