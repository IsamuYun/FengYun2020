
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("��֦" , ({ "taozhi", "��֦" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֦");
		set("long", "��֦�Ͽ����˷ۺ�ɫ�Ļ���!\n");
		set("value", 5);
		set("rigidity", 5);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ֦�����˷ۺ�ɫ�����$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(5);
	setup();
}
