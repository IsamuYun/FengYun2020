#include <ansi.h>
#include <weapon.h>
 inherit SWORD;
void create()
{
        set_name( HIR "铁血大旗剑" NOR, ({ "tiesword" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"大旗风云剑,剑光晶莹夺目，不可方物。带剑入魔,以剑清心!---－海内十三件神兵利器之一\n");
                set("value", 28000);
		set("for_bandit",1);
                set("material", "steel");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

          init_sword(75);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("force");
        victim->receive_damage("gin",dam/20);
return HIR "铁血大旗剑似乎透着斑斑血迹，红色剑光之中$n不由变得神情迷离。\n" NOR;
}
 
