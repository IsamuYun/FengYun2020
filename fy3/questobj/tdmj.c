#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL "����ؼ�" NOR, ({ "tdmji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "������õ��书�ؼ���\n");
        	set("value", 0);
			set("skill", ([
			"name": 		"vivienforce",	
			"exp_required":	20000,				
			"sen_cost":		50,				
			"difficulty":	40,		
			"max_skill":	100		
		]) );
  }

    setup();
}
