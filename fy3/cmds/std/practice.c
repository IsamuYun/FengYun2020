// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string skillname;
	int skill, skill_basic;
	int amount;

	seteuid(getuid());
	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

	skill_basic = me->query_skill_eff_lvl(arg) * 1 + 1;
	skill = me->query_skill_eff_lvl(skillname)  + 1;

	if( skill < 1 )
		return notify_fail("�����û��ѧ�᡹����ܰɣ������ȥ��̱��ˡ�\n");
	if( skill_basic < 1 )
		return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");

	notify_fail("�����ڲ�����ϰ����ܡ�\n");

 
        if( me->query_skill(skill,1) >= me->query("level")*5 )
        
			return notify_fail("��Ĺ�����ͨ�����ַ�������ˡ�\n");
       

	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
	if( SKILL_D(skillname)->practice_skill(me) ) {
		amount = (skill - 75) * SKILL_D(skillname)->black_white_ness()/100;
		if((amount < -25) && (skill < 75)) amount = -25;
		amount += SKILL_D(skillname)->practice_bonus() + skill_basic/5 + 1;
		if( amount < 1) amount = 1;
		me->improve_skill(skillname, amount, skill_basic > skill? 0: 1);
		write( HIY "���" + to_chinese(skillname) + "�����ˣ�\n" NOR);
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@TEXT
ָ���ʽ��practice <��������>

���ָ��������ϰĳ������ļ��ܣ�������ܱ����Ǿ��� enable ��רҵ���ܡ�

�������ⷽ��Ļ������ܹ��ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ��������ʤ�����
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
TEXT
	);
	return 1;
}
