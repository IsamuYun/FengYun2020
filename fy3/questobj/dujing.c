#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"毒经"NOR, ({ "dujing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "stone");
            set("long", "这本破旧的书是周济一生的心血，记载了大量制毒和用毒的方法。\n");
            set("value", 200);
            set("material", "paper");
		set("skill", ([
			"name": 		"toxin",	
			"exp_required":	0,				
			"sen_cost":		20,				
			"difficulty":	20,		
			"max_skill":	50		
		]) );
          }

    setup();
}
