#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( RED "��Ҷǡ�ƶ���˪" NOR, ({ "leafsword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ����ϸ�屡�������Ĵ���������������ʮ�����������֮һ\n"
);
                set("value", 38000);
		set("for_bandit",1);
                set("material", "steel");
                set("sxwuqi", 1);
                set("wield_msg", "$N��������һ���γ�һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
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
        return RED "��Ҷǡ�ƶ���˪�����ĺ�Х���ŵ�$n�����ɢ��\n" NOR;
}
