#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_AUTOLOAD;
void create()
{
        set_name( RED "红叶恰似二月霜" NOR, ({ "leafsword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",
                        
  "一柄身细体薄，剑锋颇带红光的名剑－天下三件神兵利器之一\n"
);
               set("weapon_prop/intelligence",5);
 set("value", 38000);
        set("no_drop",1);
                set("sxwuqi", 1);
set("no_get",1);
                set("material", "steel");
                set("wield_msg", "$N「叮」地一声拔出一柄$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

        init_sword(75);
        setup();}
void owner_is_killed(object killer)
{
	message_vision(RED"\n 红叶恰似二月霜 " NOR +"落在地上，被$N拿在怀中！\n\n",killer);
	this_object()->move(killer);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("force");
	victim->receive_damage("gin",dam/5);
	return RED "红叶恰似二月霜" +  NOR"红光一现，$n只觉脸上已着了一剑。\n" NOR;
}
 int query_autoload() { return 1; }




