//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(HIR "��������" NOR, ({ "fulong blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѷ����ı�������Ƥ�ĵ�����׭����һ��С��--���з�����\n");
		set("material", "steel");
		set("wield_msg", "$N��ָ΢����$n����������ĺ�Х���Ƴ��գ�ƮȻԾ��$N���У�\n");
		set("unwield_msg", "$N��$n����Ȼ���ʡ�\n");
	}
	init_blade(80);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	pro = (int) victim->query_temp("apply/armor_vs_fire");
	dam = (int) me->query("force");
	if(dam > pro)
	{
	victim->receive_wound("kee",5);
	return HIB "���������ĵ������һ����ɫ�Ļ��棬�ǿ���$n��ȫ��\n" NOR;
	}
}