// by xgchen
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIB"玄铁剑"NOR, ({ "xuantie-sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("xuantie",1);
                set("sxwuqi", 1);
            set("long", "一把蓝色宝剑,剑身刻有:神兵镇天下。\n");
                set("wield_msg", HIR"$N「唰」地一声从背后的剑鞘抽出一把$n。\n"NOR);
                set("unwield_msg", HIB"$N将手中的$n"HIB"插入背后的剑鞘。\n"NOR);
                set("armor_prop/armor", 2);
                set("armor_prop/spells", 3);
        }
      init_sword(100);
           setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("sen",dam/5);
        return HIB "玄铁剑卷起的真气发出蓝光,$n心神不定,头昏眼花了。\n" NOR;
}
