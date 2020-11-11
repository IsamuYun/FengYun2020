#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_AUTOLOAD;
void create()
{
        set_name( HIR "妖神火刃" NOR, ({ "yaoshen-blade" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"一把刀身极厚，刀边散发出一股与众不同的热气,刃口朝里，显然这是一把反刃刀－－天下三件妖器之一。\n"
);
              set("value", 38000);
		set("no_get",1);
                set("material", "steel");
                set("wield_msg", "$N大喝一声：“妖神何在？”只听见天边传来一声“吾在！”$N的兵器似乎发生了异样的变化。\n");
                set("unwieldmsg", "$N手中的妖神之火渐渐消失了。。。。。。\n");
        }

        init_blade(10);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query_skill("spells")*2;
	victim->receive_damage("kee",dam);
	return HIR "妖神火刃" +  NOR"骤然又一亮，火势又猛了起来，"+victim->name()+"闪躲不及，被烧伤了一大片。\n" NOR;
}
 int query_autoload() { return 1; }




