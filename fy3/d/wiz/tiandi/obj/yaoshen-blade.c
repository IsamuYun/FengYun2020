#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_AUTOLOAD;
void create()
{
        set_name( HIR "�������" NOR, ({ "yaoshen-blade" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ�ѵ����񣬵���ɢ����һ�����ڲ�ͬ������,�пڳ����Ȼ����һ�ѷ��е�����������������֮һ��\n"
);
              set("value", 38000);
		set("no_get",1);
                set("material", "steel");
                set("wield_msg", "$N���һ������������ڣ���ֻ������ߴ���һ�������ڣ���$N�ı����ƺ������������ı仯��\n");
                set("unwieldmsg", "$N���е�����֮�𽥽���ʧ�ˡ�����������\n");
        }

        init_blade(10);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query_skill("spells")*2;
	victim->receive_damage("kee",dam);
	return HIR "�������" +  NOR"��Ȼ��һ��������������������"+victim->name()+"���㲻������������һ��Ƭ��\n" NOR;
}
 int query_autoload() { return 1; }




