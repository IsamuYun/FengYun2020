// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
          set_name( HIG "七" HIR "彩" HIB "丝" HIY "缎" HIW "带" NOR , ({ "silk" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long","这条七彩丝缎带在烛光下闪着七种光茫，一看就是不凡之品．\n");
                set("material", "cloth");
		set("realsilk",1);
		set("value",50000);
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", 5);
		set("armor_prop/spirituality",3);
        }
        setup();
}
