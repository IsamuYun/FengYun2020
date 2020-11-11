// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("上了年纪的老太婆", ({ "taipo", "po" }) );
        set("long",
                "风云城中最老的老太婆，风云老小都很尊重她\n");

	set("gender","女性");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
		  set_temp("kf_tufei",60);
        set("pursuer", 1);
set("age", 99);
        set("combat_exp", 0);
        setup();
        carry_object("obj/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_work", "work");

}
int do_work(string arg)
{
        object ob;
        object me;
		int exp,pot;
        me = this_player();
if(me->is_busy()) return notify_fail("你的动作还没有完成，不能工作。\n");
        if( me->query("level") < 4 )
              return notify_fail("你的等级不适合在这里打工了。\n");



		if (me->query("longstory") == 2)
		{
			me->set("longstory",3);
			write( YEL"钓鱼钓得怎么样，无聊的话可以换换环境，来这里打工，虽然还是同样的无聊。\n");
			write( "到了五级的话，就可以到各地去拜师啦。游历中如果需要治疗可以找风云城的普生。\n"NOR);
		}
		        if( me->query("workfortaipo") > 100 )
              return notify_fail("够了够了，老太婆不再需要你帮忙了。\n");

message_vision("$N辛苦的工作终于结束了，可人也累的要死\n",me);
me->add("gin",-30);
me->add("sen",-30);
 exp = 30 + random(20);
        pot = exp/7	;
		me->add("combat_exp",exp);
		me->add("potential",pot);
		me->add("workfortaipo",1);
		write("你获得了\n"+chinese_number(exp)+"点经验。\n");
		write(chinese_number(pot)+"点潜能。\n");

ob = new("/obj/money/silver");
ob->move(me);
message_vision("上了年纪的老太婆对$N说：这是你的工钱。\n", me);
me->start_busy(5);
return 1;
}
