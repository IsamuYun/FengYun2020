// by xgchen@zzfy
inherit SKILL;

int valid_enable(string usage) { return usage=="chanting"; }

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("���ɱ��̫�أ��޷����������𷨡�\n");
        if(me->query("family/family_name") != "������")
                return notify_fail("�㲻�����ֺ��У��޷����������𷨡�\n");
return 1;
}
int practice_skill(object me)
{
        return 
notify_fail("�����𷨲�����ϰ��\n");
}
string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/rulai-fofa/" + action;
}
int effective_level() 
{ return 20;}

int learn_bonus()
{
     return -3000;
}
int practice_bonus()
{
        return -5000;
}
int black_white_ness()
{
        return 400;
}

