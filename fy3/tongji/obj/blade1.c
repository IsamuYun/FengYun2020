// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIY"�Ͷ�����"NOR, ({ "blade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500000);
                set("material", "iron");
              set("weapon_prop/weapon_prop", 1);
              set("weapon_prop/personality", 10);
                set("weapon_prop/intelligence",3);
                set("long", "����һ����ʮ��Ư���ı��������Ӳ�,�ֱ��ϻ���Ƕ�˸����鱦,����ȥ��,һ���и��ü�Ǯ��
������д��:
                        ��   ��   ��   �ơ�\n");
                set("wield_msg", "$N������Ƥ�����г��һ�����Ӳӵ�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
        init_blade(125);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("sen",dam/5);
        return HIW "�Ͷ����ưѱ��ϵ���ʯ�����ҫ�۵Ĺ�â�ŵ�$n˫�۴�ʹ��\n" NOR;
}
