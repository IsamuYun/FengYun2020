// force_book.c

inherit ITEM;

void create()
{
	set_name("���ʮ��ʽ", ({ "qing feng book","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"���ǻ�ɽ����ʧ���Ծõ�һ�����ס�\n");
		set("value", 50000);
		set("material", "paper");
		set("skill", ([
			"name": 		"sword",		// name of the skill
			"exp_required":	0,				// minimum combat experience required
											// to learn this skill.
			"sen_cost":		30,				// gin cost every time study this
			"difficulty":	20,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	51				// the maximum level you can learn
											// from this object.
		]) );
	}
}
