// hat.c

inherit EQUIP;

void create()
{
	set_name("�Ͻ��", ({ "gold hat", "hat" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 7000);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 10);
	}
}
