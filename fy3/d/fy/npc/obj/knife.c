
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("�ɵ�", ({ "feidao" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ�ѳ��̸պõ���Ҷ�ɵ�\n");
		set("unit", "��");
		set("value", 1000);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
		set("limited_lv",1);
		set("abradability",100);
	}
	set_amount(1);
	init_throwing(10);
	setup();
}