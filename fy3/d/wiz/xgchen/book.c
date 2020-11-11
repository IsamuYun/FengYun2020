// force_book.c

inherit ITEM;

void create()
{
	set_name("三才剑法", ({ "threesword-book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这本旧书的纸张都已经泛黄了，上面只有一些字迹模糊的字句，似乎\n"
			"好象有个人影在挥动着一把剑,这本剑谱没有一般的经验是学不好的。\n");
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
