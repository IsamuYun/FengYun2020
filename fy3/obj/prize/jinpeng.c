// yiru@hero

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY "金鹏" NOR, ({ "gold peng", "peng", "goose_money" }) );
	set("unit", "只");
	set("value", 0);
	set("long", HIC"一只金光闪闪、栩栩如生的金鹏。\n
	你可以每天检查(checkpeng)一下它是否能下蛋。\n
	记住每天(指游戏中的一天)只能下一次蛋，下过五次蛋以后就不能再下了。\n\n"NOR);
	set_weight(10000);
	set("no_drop", 1);
	set("no_get", 1);
	set("check_numc",0);
}

void init()
{
    add_action("do_check", "checkpeng");
}

int do_check(string arg)
{
	object gold;
    object me = this_player();
    
        if( this_player()->query("id") != query("player_id") ) 
        {
                return 0;
        }

    if( query("check_numc") >= 5 )
    {
    	write("这只金鹏的魔力已经丧失了。\n");
    	destruct(this_object());
        return 1;
    }
        
    if( !arg || arg == "" ) 
        return notify_fail("格式：checkpeng <pot/gold/exp>\n");
    
    if( time()-query("last_check") < 60*15*6 )
        return notify_fail("金鹏刚产过蛋不久,它需要休息。\n");
            
    if( arg=="pot" )
    {
        set("last_check", time());
        add("check_numc",1);
        me->add("potential", 1000+random(80000));
        tell_object(me, HIC"你的潜能增加了。\n"NOR);

	}
	else if( arg=="gold" )
	{
        set("last_check", time());
        add("check_numc",1);
        gold = new("/obj/money/gold");
        gold->set_amount(100+random(7));
		gold->move(me);
        tell_object(me,
            HIY"只见一道金光闪过，金鹏产出了许多黄金！\n"NOR);
        
    }
    else if( arg=="exp" )
    {
        set("last_check", time());
        add("check_numc",1);
        me->add("combat_exp", 1000+random(100000));
        tell_object(me, HIM"你的经验增加了。\n"NOR);
        
    }
    else
    {
        return notify_fail("格式：checkgoose <pot/gold/exp>\n");
    }
       
    return 1;
    
}
