#include <armor.h>
inherit HEAD;
void create()
{
	set_name("ά�����ñ", ({ "cotton hat"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��������ɫ���ֺܺÿ���ñ�ӡ�");
		set("unit", "��");
		set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 1);
	}
	setup();
}
