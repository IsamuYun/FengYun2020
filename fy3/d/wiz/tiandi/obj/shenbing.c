#include <ansi.h>
#include <weapon.h>
inherit	RING;
void create()
{
	set_name( HIY "����ȭ��" NOR, ({ "ring" })	);
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "������װ֮һ������ȭ�������ֱر��Ķ�����������Ч�ذ������ֳɳ���\n\n");
                set("material", "steel");
	  set("no_get",1);
       				set("limited_lv",1);
              set("abradability",500);
	}
	init_ring(50);
	setup();
}


int query_autoload() { return 1; }


