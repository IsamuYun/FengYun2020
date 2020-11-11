// blade.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIY"惩恶扬善"NOR, ({ "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500000);
                set("material", "iron");
                set("long", "这是一样子十分漂亮的宝剑，金光灿灿,手柄上还镶嵌了各种珠宝,如拿去卖,一定有个好价钱。
剑脊上写着：
                        惩   恶   扬   善。\n");
                set("wield_msg", "$N从鲨皮剑鞘中抽出一柄金光灿灿的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon_prop/weapon", 1);
                set("weapon_prop/personality", 10);
                set("weapon_prop/intelligence",3);
        }
        init_sword(125);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("sen",dam/5);
        return HIW "惩恶扬善把柄上的钻石反射出耀眼的光芒扰的$n双眼刺痛。\n" NOR;
}
