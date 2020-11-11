inherit ITEM;

void create()
{
	set_name("尸体", ({ "shiti" }));
	set_weight(80000+random(300000));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
             set("for_ok",1);
		set("long",
			"狂人帮第一任老帮主燕狂徒的尸体，不知道为什么会死在这里\n");
		set("value", 0);
	}
}
