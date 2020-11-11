// xiandou.c - �ɶ�

inherit COMBINED_ITEM;

void create()
{
    	set_name("�ɶ�", ({ "xian dou", "dou" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "Щ");
	set("base_unit", "��");
	set("long", "���Ϻ�����ʥҩ���̷���use�������ʹ������ȫ�ָ���\n");
	set("value", 20000 );
        set("base_weight", 10);
        set_amount(1);

}

void init()
{
	add_action("do_use", "use");
}

int do_use(string arg)
{
	object me;
	int increasement;

	me = this_player();
	if(!id(arg))  return notify_fail("����Ҫʹ��ʲô������\n");

	if( me->is_fighting() )	return notify_fail("����������ս����\n");

	if( me->is_busy() ) return notify_fail("����æ���أ�\n");
	me->start_busy(1);

	message_vision("$N��һ���ɶ��ŵ����������������ȥ��\n", me );
	me->set("gin", (int)me->query("max_gin"));
	me->set("kee", (int)me->query("max_kee"));
	me->set("sen", (int)me->query("max_sen"));
	me->set("eff_gin", (int)me->query("max_gin"));
	me->set("eff_kee", (int)me->query("max_kee"));
	me->set("eff_sen", (int)me->query("max_sen"));

	me->set("eff_atman", (int)me->query("max_atman"));
	me->set("eff_force", (int)me->query("max_force"));
	me->set("eff_mana", (int)me->query("max_mana"));
	me->set("food", me->max_food_capacity());
	me->set("water", me->max_water_capacity());
	me->set("poison", 0);

	add_amount(-1);        
	return 1;
}
