// ken 1999.12.7

#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIW"��Ƥ��"NOR, ({ "piao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����Ƥ�����ڱ���ѩ���ﴩ�ţ������ٺò����ˡ�\n");
		set("material", "cloth");
		set("armor_prop/intelligence",3);
	}
	setup();
}
