// force_book.c

inherit ITEM;

void create()
{
	set_name("���Ž���", ({ "threesword-book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
			"�����и���Ӱ�ڻӶ���һ�ѽ�,�Ȿ����û��һ��ľ�����ѧ���õġ�\n");
		set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name": 		"three-sword",		// name of the skill
			"exp_required":	0,				// minimum combat experience required
											// to learn this skill.
			"sen_cost":		300,				// gin cost every time study this
			"difficulty":	200,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	10				// the maximum level you can learn
											// from this object.
		]) );
	}
}
