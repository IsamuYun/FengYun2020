//mouse@wenxin
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "��" + HIG "��" + HIC "��" NOR, ({ "shunv sword", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ�����������â�ķ����������ǵ���ѩ������߽���ʱ���İ��ĵı�����\n"
);
                set("value", 18000);
                set("for_bandit",1);
                set("sxwuqi", 1);
                set("material", "steel");
                set("wield_msg", "$N�����ν����г��һ����â�����$n��\n");
                set("unwield_msg", "$N��$n������У�$n����һ�������������ν����С�\n");
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
        return HIM "���ν���������Ĺ�â����$n�����㱣���Ѫ���ڣ�����\n" NOR;
}
