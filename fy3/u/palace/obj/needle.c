// tea_leaf.c

#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name( HIC "��Ӱ����" NOR, ({ "needle", "magic needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"��ǿ��ɱ�����ľ޶��ޱȵ���Ӱ����\n");
		set("unit", "��");
		set("value", 10);
		set("base_unit", "֧");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(5);
	init_throwing(2);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	victim->apply_condition("no_shadow",random(10)+10);
	message_vision("$N������Ӱ�����ϵĶ���\n", victim);
}

