// big-bag.c

inherit ITEM;

void create()
{
	set_name("���", ({ "big bag", "bag" }) );
	set_weight(1000);
	set_max_encumbrance(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��Ѱ�����������������װһЩ���\n");
		set("value", 100);
    };
}

int is_container() { return 1; }
