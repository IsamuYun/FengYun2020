// jingqiwan.c - ������

inherit COMBINED_ITEM;

void create()
{
    	set_name("������", ({ "jingqi wan", "wan" }) );
	if( clonep() )	set_default_object(__FILE__);
	set("unit", "Щ");
	set("base_unit","��");
	set("long", "���ƾ���ȱ�����鵤��ҩ���̷���use������Իָ���ľ�����\n");
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

	message_vision("$N��һ�þ����������طŵ��������һ��������ȥ��\n",me);
	// me->apply_condition("add_gin", 10);
	increasement = 20;
	if( (int)me->query("gin") + increasement < (int)me->query("eff_gin") ) 
		me->set("gin", (int)me->query("gin") + increasement);
	else 
		me->set("gin", (int)me->query("eff_gin"));

	add_amount(-1);        
	return 1;
}
