#include <ansi.h>
#include <weapon.h>
 inherit SWORD;
void create()
{
        set_name( HIR "��Ѫ���콣" NOR, ({ "tiesword" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"������ƽ�,���⾧Ө��Ŀ�����ɷ��������ħ,�Խ�����!---������ʮ�����������֮һ\n");
                set("value", 28000);
		set("for_bandit",1);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

          init_sword(75);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("force");
        victim->receive_damage("gin",dam/20);
return HIR "��Ѫ���콣�ƺ�͸�Ű߰�Ѫ������ɫ����֮��$n���ɱ���������롣\n" NOR;
}
 
