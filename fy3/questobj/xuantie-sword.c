// by xgchen
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIB"������"NOR, ({ "xuantie-sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("xuantie",1);
                set("sxwuqi", 1);
            set("long", "һ����ɫ����,�������:��������¡�\n");
                set("wield_msg", HIR"$N��ৡ���һ���ӱ���Ľ��ʳ��һ��$n��\n"NOR);
                set("unwield_msg", HIB"$N�����е�$n"HIB"���뱳��Ľ��ʡ�\n"NOR);
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
        return HIB "�����������������������,$n���񲻶�,ͷ���ۻ��ˡ�\n" NOR;
}
