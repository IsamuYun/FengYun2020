// TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
	set_name(HIG  "����" NOR, ({ "zhfan" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ǧ�˻�����͵����,�������˻ָ����幦��������!(heal)\n");
		set("max_heal",2);
                set("material", "hammer");
	}
	init_hammer(10);
	setup();
}
void init()
{
	if(environment()==this_player())
	add_action("do_heal","heal");

}


int do_heal()
{
    object mme;
    mme=this_player();
    if(query("max_heal") <=0)        return notify_fail("��ᦵĹ�Ч�Ѿ����ù��ˣ�\n");
    mme->set("mana",mme->query("max_mana"));
    mme->set("force",mme->query("max_force")*2);
    mme->set("atman",mme->query("max_atman"));
    mme->set("sen",mme->query("max_sen"));
    mme->set("eff_sen",mme->query("max_sen"));
    mme->set("food",mme->max_food_capacity());
    mme->set("water",mme->max_water_capacity());
      add("max_heal",-1);
      tell_object(mme,HIW"���ᦷ�������׹�,�������ָ���.\n");
    return 1;
}

