// TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
	set_name(HIW  "����Ƭ" NOR, ({ "old iron" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������Ƭ������������������������Ķ�����\n");
		set("value", 500);
		set("rigidity",2000);	
		set("material", "steel");
		set("max_enchant",6);
        set("for_create_weapon",1);
	}
	init_dagger(20);
	set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");
	setup();
}
