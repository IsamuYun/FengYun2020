#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIG "����黨" NOR, ({ "feicui-pin"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ����ˮ��ı����黨��\n");
		set("unit", "ֻ");
		set("value", 200000);
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 5);
                set("armor_prop/intelligence",5);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϣ��ζ������Ĵ��̹⻪����ͫ�׷Ŵ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");


	}
	setup();
}

