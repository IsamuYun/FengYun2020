#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_AUTOLOAD;
void create()
{
        set_name( RED "��Ҷǡ�ƶ���˪" NOR, ({ "leafsword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
  "һ����ϸ�屡�������Ĵ��������������������������֮һ\n"
);
               set("weapon_prop/intelligence",5);
 set("value", 38000);
        set("no_drop",1);
                set("sxwuqi", 1);
set("no_get",1);
                set("material", "steel");
                set("wield_msg", "$N��������һ���γ�һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

        init_sword(75);
        setup();}
void owner_is_killed(object killer)
{
	message_vision(RED"\n ��Ҷǡ�ƶ���˪ " NOR +"���ڵ��ϣ���$N���ڻ��У�\n\n",killer);
	this_object()->move(killer);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("force");
	victim->receive_damage("gin",dam/5);
	return RED "��Ҷǡ�ƶ���˪" +  NOR"���һ�֣�$nֻ������������һ����\n" NOR;
}
 int query_autoload() { return 1; }




