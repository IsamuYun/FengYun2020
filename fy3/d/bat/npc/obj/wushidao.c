#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIR"ӳ����ʿ��"NOR, ({ "wushidao" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 400000);
		set("material", "steel");
		set("long", "����һ���ƽ��Ķ����ʿ����\n");
		set("wield_msg", "$N�ӵ����г��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
        init_blade(140);
	setup();
}
