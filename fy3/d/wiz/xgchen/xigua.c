// TIE @ FY3

inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("西瓜", ({ "xigua" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一个圆圆的，硬邦邦的大西瓜\n");
		set("unit", "个");
                set("value", 100);
		set("food_remaining", 3);
                set("food_supply", 600);
	}
}
int digest(object me)
{
	if(objectp(me)) me->set_temp("can_pass_wall",1);
	return 1;
}
int do_eat(string arg)
{
   int foo;
   foo=::do_eat(arg);
   if (!foo) return foo;
	call_out("digest",random(20)+5,this_player());
  return 1;
}

