// TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIW  "�����" NOR, ({ "cang qiong" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��û�н�ͷ�ĳ���\n");
                set("value", 50000);
                set("rigidity",2000);   
                set("material", "steel");
                set("max_enchant",7);
                set("for_create_weapon",1);
        }
        init_sword(50);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        pro = 0 - (int) victim->query_skill("iron-cloth");
        victim->set_temp("apply/iron-cloth",pro);
        return HIR"$N����"HIR"����˿˿������ֱȡ$n�����ţ�\n" NOR;
}

