#include <weapon.h>
inherit THROWING;
void create()
{
	set_name("÷������", ({ "tree", "plum tree" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","������������磬Ҳ������������죨����壩Щ������\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10000);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(20);
	setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_make","make");

}

int do_make()
{
	object boat;
	if(query_amount() < 15)
	return notify_fail("��"+chinese_number(query_amount())+
	"��÷�����磬ʲôҲ�첻��ѽ������\n");
	boat = new(__DIR__"boat");
	if(boat->move(this_player()))
	write("�������ɵ�˫�������һֻСľ�ۡ�\n");
	destruct(this_object());
	return 1;
			
}
