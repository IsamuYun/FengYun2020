#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( RED "红叶恰似二月霜" NOR, ({ "leafsword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",
                        
"一柄身细体薄，剑锋颇带红光的名剑－海内十三件神兵利器之一\n"
);
                set("value", 38000);
		set("for_bandit",1);
                set("material", "steel");
                set("sxwuqi", 1);
                set("wield_msg", "$N「叮」地一声拔出一柄$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

        init_sword(105);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("gin",dam/10);
        return RED "红叶恰似二月霜发出的呼啸声扰得$n精神涣散。\n" NOR;
}
