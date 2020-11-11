// xiaohuandan.c - С����

inherit COMBINED_ITEM;

void create()
{
    	set_name("С����", ({ "xiaohuan dan", "dan" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "Щ");
	set("base_unit", "��");
	set("long", "�Ѽ���ʥҩ���̷���use�������ʹ����ָ���\n");
	set("value", 3000 );
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

	message_vision("$N��һ��С�����ŵ����������������ȥ��\n", me );
/*
	me->apply_condition("add_gin", 20);
	me->apply_condition("add_eff_gin", 20);
	me->apply_condition("add_kee", 20);
	me->apply_condition("add_eff_kee", 20);
	me->apply_condition("add_sen", 20);
	me->apply_condition("add_eff_sen", 20);
*/
	increasement = 50;
	if( (int)me->query("gin") + increasement < (int)me->query("eff_gin") ) 
		me->set("gin", (int)me->query("gin") + increasement);
	else 
		me->set("gin", (int)me->query("eff_gin"));
	if( (int)me->query("eff_gin") + increasement < (int)me->query("max_gin") ) 
		me->set("eff_gin", (int)me->query("eff_gin") + increasement);
	else 
		me->set("eff_gin", (int)me->query("max_gin"));
	if( (int)me->query("kee") + increasement < (int)me->query("eff_kee") ) 
		me->set("kee", (int)me->query("kee") + increasement);
	else 
		me->set("kee", (int)me->query("eff_kee"));
	if( (int)me->query("eff_kee") + increasement < (int)me->query("max_kee") ) 
		me->set("eff_kee", (int)me->query("eff_kee") + increasement);
	else 
		me->set("eff_kee", (int)me->query("max_kee"));
	if( (int)me->query("sen") + increasement < (int)me->query("eff_sen") ) 
		me->set("sen", (int)me->query("sen") + increasement);
	else 
		me->set("sen", (int)me->query("eff_sen"));
	if( (int)me->query("eff_sen") + increasement < (int)me->query("max_sen") ) 
		me->set("eff_sen", (int)me->query("eff_sen") + increasement);
	else 
		me->set("eff_sen", (int)me->query("max_sen"));

	add_amount(-1);        
	return 1;
}
