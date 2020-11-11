// shouwu.c - ������

inherit COMBINED_ITEM;

void create()
{
    	set_name("������", ({ "shouwu" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "Щ");
	set("base_unit", "��");
	set("long", "�Զ�����ͷ���������ɰױ�ڵ�ҩ���̷���use������Իָ�������\n");
	set("value", 100 );
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

	message_vision("$N��һ������������طŵ����������ζ�س�����ȥ��\n",me );
	// me->apply_condition("add_eff_gin",2);
	increasement = 5;
	if( (int)me->query("eff_gin") + increasement < (int)me->query("max_gin") ) 
		me->set("eff_gin", (int)me->query("eff_gin") + increasement);
	else 
		me->set("eff_gin", (int)me->query("max_gin"));

	add_amount(-1);        
	return 1;
}
