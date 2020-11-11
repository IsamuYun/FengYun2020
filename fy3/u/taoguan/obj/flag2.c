
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY "黄色飞行符" NOR, ({ "yellow"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
	   set("long","一件飞行符咒。你如果有能力完全可以标记(makehere)它，使它可以记住你现在的位置。\n");
	   set("value",500000);
        }
        setup();
}
void init()
{
        add_action("do_mark", "makehere");
        add_action("do_fly", "use");
}

int do_mark(string arg)
{
        object ob,me;
        string where;
        me = this_player();
        if (!arg) return notify_fail("请使用makehere <符咒ID>。\n");

        ob = present(arg, me);
        if( !ob ) return notify_fail("你身上没有这张符咒。\n");
        if(ob->query_temp("place")) 
		return notify_fail("这张符咒已经被标记了。\n");
        if(environment(me)->query("no_fight"))
		return notify_fail("这里不适合下标记。\n");
       if(me->query("class") != "sanqing")
		return notify_fail("只有三清宫的弟子才可以标记地点。\n");
       if(me->query("lifetili") < 50)
		return notify_fail("你的活力不够五十点。\n");
        where = file_name(environment(me));
        ob->set_temp("place",where);
        ob->set_temp("times",20);
       me->add("lifetili",50);

        ob->set("long","一件已经被标记过的飞行符，标记地点为"+environment(me)->query("short")+"。还可以使用"+ob->query_temp("times")+"次。\n");
        message_vision("$N取出了早已准备好的$n，在地上插了一下，只见一股黄芒渗透进了地底下。\n",me,ob);
        write("\n你用"+ob->query("name")+"在【"+environment(me)->query("short")+"】做了标记，以后你可以用use <符咒ID>方便的回来这里。\n");
        return 1;
}
int do_fly(string arg)
{
        object ob,me,where;
        int i;
        me = this_player();
        if (!arg) return notify_fail("请使用use <符咒ID>。\n");

        ob = present(arg, me);
        if( !ob ) return notify_fail("你身上没有这张符咒。\n");
        if(!ob->query_temp("place")) 
		return notify_fail("这张符咒还未被标记。\n");
        if( me->is_fighting() )
                return notify_fail("你正在战斗中，请先结束战斗吧！\n");
        me->move(ob->query_temp("place"));
        i = ob->query_temp("times");
        ob->set_temp("times",i - 1);
        me->start_busy(2);
        ob->set("long","一件已经被标记过的飞行符，标记地点为"+environment(me)->query("short")+"。还可以使用"+ob->query_temp("times")+"次。\n");
        message_vision("周围黄光一闪，$N骤然出现在"+environment(me)->query("short")+"。\n",me);
        if(ob->query_temp("times") < 1)
		destruct(ob);
        return 1;
}
