// sppearl.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY "ËãÅÌÖé" NOR, ({ "sppearl"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
         else { 
        set("long",
                "Ò»¿Å½ğ»ÆÉ«µÄËãÅÌÖé¡£\n");
        set("unit", "¿Å");
        set("value", 10000);
               }
}



