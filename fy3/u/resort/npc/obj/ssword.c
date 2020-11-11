//mouse@wenxin
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "月" + HIG "形" + HIC "剑" NOR, ({ "shunv sword", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",
                        
"一把闪着奇异光芒的锋利宝剑，是当年雪蕊儿行走江湖时最心爱的的兵器。\n"
);
                set("value", 18000);
                set("for_bandit",1);
                set("sxwuqi", 1);
                set("material", "steel");
                set("wield_msg", "$N从月形剑鞘中抽出一柄神芒四射的$n。\n");
                set("unwield_msg", "$N将$n抛向空中，$n化作一轮新月落入月形剑鞘中。\n");
        }
        init_sword(100);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("gin",dam/10);
        victim->receive_damage("sen",dam/10);
        victim->receive_damage("kee",dam/10);
        return HIM "月形剑发出奇异的光芒，让$n精神恍惚，气血翻腾！！！\n" NOR;
}
