#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( HIG "���̱�ʯ" NOR, ({ "ningbi" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������ˮ�����ر�ʯ��\n");
		set("value", 40000);
		set("material", "stone");
		set("rigidity", 20000);
	}
	setup();
}
