// lingzhi.c - ��֥

inherit COMBINED_ITEM;

void create()
{
    	set_name("��֥", ({ "lingzhi" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "Щ");
	set("base_unit", "��");
	set("long", "��֮Ʒ���̷���use������Իָ�������\n");
	set("value", 500 );
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

	me=this_player();
	if(!id(arg))  return notify_fail("����Ҫʹ��ʲô������\n");

	if( me->is_fighting() )	return notify_fail("����������ս����\n");

	if( me->is_busy() ) return notify_fail("����æ���أ�\n");
	me->start_busy(1);

	message_vision("$N��һ����֥�����طŵ����������ζ�س�����ȥ��\n", me );
	// me->apply_condition("add_eff_sen", 10);
	increasement = 20;
	if( (int)me->query("eff_sen") + increasement < (int)me->query("max_sen") ) 
		me->set("eff_sen", (int)me->query("eff_sen") + increasement);
	else 
		me->set("eff_sen", (int)me->query("max_sen"));

	add_amount(-1);        
	return 1;
}
