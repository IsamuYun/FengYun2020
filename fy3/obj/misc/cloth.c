// cloth.c
// From ES2
// This is the basic equip for players just login.
// �޸ģ���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("����", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������ͨͨ�Ĳ��¡�");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
