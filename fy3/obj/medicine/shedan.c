// shedan.c - �ߵ�

inherit COMBINED_ITEM;

void create()
{
    	set_name("�ߵ�", ({ "shedan" }) );
	if( clonep() )	set_default_object(__FILE__);
	set("unit", "Щ");
	set("base_unit","��");
	set("long", "��������ȱ���Ĵ��ߵĵ����̷���use������Իָ����������\n");
	set("value", 50);
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

	message_vision("$N��һ���ߵ������طŵ��������һ��������ȥ��\n",me);
	// me->apply_condition("add_sen", 10);
	increasement = 20;
	if( (int)me->query("sen") + increasement < (int)me->query("eff_sen") ) 
		me->set("sen", (int)me->query("sen") + increasement);
	else 
		me->set("sen", (int)me->query("eff_sen"));

	add_amount(-1);        
	return 1;
}
