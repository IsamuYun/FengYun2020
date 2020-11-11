#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( HIG "大风刀" NOR, ({ "windblade" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"一把身宽体厚，刀背一溜儿钢环的宝刀－海内十三件神兵利器之一\n"
);
                set("value", 18000);
		set("for_bandit",1);
                set("material", "steel");
                set("sxwuqi", 1);
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }

        init_blade(75);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("force");
        victim->receive_damage("sen",dam/20);
	return HIG "大风刀发出的呼啸声扰得$n心神不宁。\n" NOR;
}
 
