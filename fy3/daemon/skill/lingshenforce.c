// iceforce.c2

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("�����ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("yihua") + "/lingshenforce/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(me->query_skill("lingshenforce")) > (damage_bonus + 
foo) ) {
                        victim->receive_wound("kee", (damage_bonus + foo));
                        victim->apply_condition("iceshock", factor/3);
                        return 
"$N����ʽЮ��һ�������ޱȵľ���ʹ��$n�������˸����䡣\n";
                }
        }
        return foo;
}
 
int effective_level() { return 25;}

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
	return 0;
}

