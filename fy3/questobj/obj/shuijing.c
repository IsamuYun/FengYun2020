#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( HIW "ˮ��" NOR, ({ "shuijing" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǵ�龧Ө��ˮ������˵���������ɵĹײĿ��Ա�֤ʬ��ܳ�ʱ�䲻���á�\n");
		set("value", 40000);
		set("material", "stone");
		set("rigidity", 20000);
	}
	setup();
}
