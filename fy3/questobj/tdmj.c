#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL "天地秘籍" NOR, ({ "tdmji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "天地无用的武功秘籍。\n");
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
