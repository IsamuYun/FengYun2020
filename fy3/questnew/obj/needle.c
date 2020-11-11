// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <weapon.h>
inherit DAGGER;
void create()
{
//         string *order=({"红色的", "绿色的", "黄色的", "白色的","黑色的",});
        set_name("银针", ({ "needle"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "一根细长的银针，头上有个小孔。\n");
                set("value", 50);
                set("material", "steel");
        }
        init_dagger(10);
        set("wield_msg", "$N从怀中摸出一支$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n藏入怀中。\n");
        setup();
}