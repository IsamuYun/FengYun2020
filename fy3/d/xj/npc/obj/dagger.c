#include <weapon.h>
inherit DAGGER;
void create()
{
	set_name("Ӣ��ɳС��", ({ "small blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ܷ�����С���������ر��Ư����\n");
		set("material", "iron");
		set("value", 500);
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
	}
	init_dagger(20);
	setup();
}
