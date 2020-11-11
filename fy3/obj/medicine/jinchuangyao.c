// jinchuangyao.c - ��ҩ

inherit COMBINED_ITEM;

void create()
{
	set_name("��ҩ", ({ "jinchuang yao", "yao" }) );
	if( clonep() )	set_default_object(__FILE__);
	set("unit", "Щ");
	set("base_unit","��");
	set("long", "������ʿ����ر���ҽ�ε���֮�˵�ҩ�����ã�use��֮������ƻ���һ����Ч����\n");
	set("value", 100);
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
	if(!id(arg) ) return notify_fail("����Ҫ��ʲô������\n");

	if( me->is_fighting() )	return notify_fail("����������ս����\n");

	if( me->is_busy() ) return notify_fail("����æ���أ�\n");
	me->start_busy(1);

	message_vision("$N����ҩ�������飬С�ĵؾ����˿ڷ�����ȥ��\n",me);
	// me->apply_condition("add_eff_kee", 2);
	increasement = 5;
	if( (int)me->query("eff_kee") + increasement < (int)me->query("max_kee") ) 
		me->set("eff_kee", (int)me->query("eff_kee") + increasement);
	else 
		me->set("eff_kee", (int)me->query("max_kee"));

	add_amount(-1);        
	return 1;
}
