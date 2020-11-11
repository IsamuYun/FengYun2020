// gaoyao.c - ��Ƥ��ҩ

inherit COMBINED_ITEM;

void create()
{
	set_name("��Ƥ��ҩ", ({ "gaoyao" }) );
	if( clonep() )	set_default_object(__FILE__);
	set("unit", "Щ");
	set("base_unit","��");
	set("long","���Ƶ���Ĺ�Ƥ��ҩ������㱻������ˣ�������һ����use�����ԡ�\n");
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
	if(!id(arg))  return notify_fail("����Ҫ��ʲô������\n");

	if( me->is_fighting() )	return notify_fail("����������ս����\n");

	if( me->is_busy() ) return notify_fail("����æ���أ�\n");
	me->start_busy(1);

	message_vision("$N��һ����Ƥ��ҩ��ž����һ�������Ϻ��׵Ĳ�λ������ȥ��\n",me);
	// me->apply_condition("add_kee", 10);
	increasement = 20;
	if( (int)me->query("kee") + increasement < (int)me->query("eff_kee") ) 
		me->set("kee", (int)me->query("kee") + increasement);
	else 
		me->set("kee", (int)me->query("eff_kee"));

	add_amount(-1);        

	return 1;
}
