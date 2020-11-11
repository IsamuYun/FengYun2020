// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(WHT"狼毫笔"NOR, ({ "maobi" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("jungle",1);
		set("material", "iron");
		set("long", "这是一支做工精细的狼毫毛笔。\n");
		set("wield_msg", "$N拿出一支$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n放入怀中。\n");
	}
	init_blade(5);
	setup();
}
