#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "钓鱼亭");
        set("long", @LONG
这是沉香镇的钓鱼亭，这可是个不错的地方，尤其对新手来说
真得很难得，不过你可以在这里通过钓鱼(diao)来获得经验和潜
能，还可以用钓来的鱼换点钱。
LONG
        );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);

        set("exits", ([
"east":__DIR__"cx4",
]));
        setup();
}

void init()
{
        add_action("do_diao","diao");
}

int do_diao(string arg)
{
        object me = this_player();
        int bonus,exp,pot;
        object mon,dan;

        if( me->query("level") < 3 )
              return notify_fail("你的等级还不适合钓鱼。\n");
        if (!arg)
              return notify_fail("你要钓什么？\n");
        if (arg != "fish")
              return notify_fail("这里只能钓鱼。\n");
        if( (int)me->query_temp("fishing") ) 
              return notify_fail("你已经在钓鱼了。\n");
        if ((int)(me->query("sen")) < 16)        
              return notify_fail("再钓当心把小命送掉，你还是休息一下吧。\n");

        message_vision("
$N将鱼饵挂在钩上，轻轻一荡鱼竿，将鱼饵扔进水里。\n\n",me);
        me->set_temp("fishing",1);
        me->add("sen",-15);
		if (me->query("longstory") == 1)
		{
			me->set("longstory",2);
			write( YEL"钓鱼可以获得不少银子，这样的话，省得点花，去拜师学习基础技能应该还是够的。\n");
			write( "到了4级的话，还可以找风云城的老太婆打工来赚钱。\n");
			write( "以后的话，当你等级到达了十级，就可以接受运镖任务了，那样赚钱是很快的。\n"NOR);
		}
		if( me->query("workforfish") > 100 )
              return notify_fail("你现在已经不能钓鱼了。\n");
        call_out("del_fishing", 6, me, mon, bonus, exp, pot);
        return 1;
}

void del_fishing(object me, object mon, int bonus, int exp, int pot)
{
        me->delete_temp("fishing");
        if (random (10) < 2)
{
       message_vision(HIY"
只见浮漂轻轻点了两下，$N赶紧用力提竿，提上来一看，白白的鱼钩上
什么也没有，原来是太心急了。没等鱼儿把钩吃进去就早早提竿了。\n"NOR,me);
        me->start_busy(6);
        return ;
}
        else
{
        exp = 20 + random(8);
        pot = exp/7	;
		message_vision(HIW"
   浮漂在动了，$N屏息静气，死死盯住浮漂，不敢有私毫大意，只
见浮漂猛地往下一沉，$N抓住时机一提竿，$N钓起了一条" + chinese_number(exp) + "斤重的鱼。\n\n"NOR
"$N身旁突然钻出一个鱼贩，一把将$N的手中将鱼夺走，顺手扔给$N一锭银子。\n",me);
        bonus = (int) me->query("combat_exp");
        bonus += exp;
        me->set("combat_exp", bonus);
		write("你获得了\n"+chinese_number(exp)+"点经验。\n");
        bonus = (int) me->query("potential");
        bonus += pot;
		write(chinese_number(pot)+"点潜能。\n");
		me->add("workforfish",1);
        me->set("potential", bonus);
        mon = new("/obj/money/silver");
        mon->set_amount(exp / 4);
		write(chinese_number(exp/4)+"两银子。\n");
        mon->move(me);
        me->start_busy(6);
        return;
}
}
