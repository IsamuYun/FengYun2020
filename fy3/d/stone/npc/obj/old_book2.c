// force_book.c

inherit ITEM;

void create()
{
	set_name("����", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ������Ȼ������������ڣ������񹦡�\n"+
			"��˵����һ�ż�Ϊ�������ڹ���������Ϊֹ��ȴ�����ܹ����ɡ�\n"+
			"�����ǡ�Ϊ�����ޡ���jiayi����ֻ��ʩչ��������֪����ʲô�ô���\n"
		);
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"jiayiforce",		// name of the skill
			"exp_required":	0,				// minimum combat experience required
											// to learn this skill.
			"sen_cost":		60,				// gin cost every time study this
			"difficulty":	50,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	45				// the maximum level you can learn
											// from this object.
		]) );
	}
}
