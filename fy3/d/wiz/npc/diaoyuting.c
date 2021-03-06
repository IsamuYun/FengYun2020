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
"east":"/d/chenxiang/cx4",
]));
        setup();
}

void init()
{
        add_action("do_diao","diao");
        add_action("do_ban","dazuo");
        add_action("do_ban","tuna");
        add_action("do_ban","exercise");
        add_action("do_ban","du");
        add_action("do_ban","study");
        add_action("do_ban","lingwu");
}

int do_diao(string arg)
{
        object me = this_player();
        int bonus,exp,pot;
        object mon;

        if((int)(me->query("combat_exp")) > 50000)
              return notify_fail("你的经验太高了，这里不适合你。\n");
        if((me->query("class")) == "dali")
              return notify_fail("你是大理官员，这里不适合你。\n");
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
        exp = 2 + random(8);
        pot = 1 + random(4);
        message_vision(HIW"
   浮漂在动了，$N屏息静气，死死盯住浮漂，不敢有私毫大意，只
见浮漂猛地往下一沉，$N抓住时机一提竿，$N钓起了一条" + chinese_number(exp) + "斤重的鱼。\n\n"NOR
"$N身旁突然钻出一个鱼贩，一把将$N的手中将鱼夺走，顺手扔给$N一锭银子。\n",me);
        bonus = (int) me->query("combat_exp");
        bonus += exp;
        me->set("combat_exp", bonus);
        bonus = (int) me->query("potential");
        bonus += exp;
        me->set("potential", bonus);
        mon = new("/obj/money/silver");
        mon->set_amount(exp);
        mon->move(me);
        me->start_busy(6);
        return;
}
}
