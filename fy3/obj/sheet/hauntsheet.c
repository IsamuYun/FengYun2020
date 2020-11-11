// yiru@hero 2000.8.5

// 僵尸追魂符

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "僵尸追魂符" NOR, ({ "haunting sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("value", 0);
    set("level", 5);
    setup();
}

int attach_function(object who)
{ 
    // string target;
    object dest, owner;

    if( !who->is_zombie() )
        return notify_fail( name() + "只能用在僵尸身上。\n");

    owner = who->query("possessed");
    if( objectp(owner) && owner!=this_player() )
        return notify_fail( "你必须先用法力镇住" + who->name() + 
                            "才能使用这道符。\n");

    if( !objectp(query("targetname")) )
        return notify_fail( "你想用这道符追谁的魂？\n");

    // target = query("targetname");
    // dest = present(target, environment(who));
    // if( !dest ) dest = find_player(target);
    // if( !dest ) dest = find_living(target);
    
    dest = query("targetname");
    if( objectp(dest) ) {
        who->set("haunttar", dest);
        if( environment(dest)==environment(who) ) {
            who->kill_ob(dest);
                   message_vision("$N眼睛忽然睁开，喃喃地说道：" RED 
"杀....死....$n....\n" NOR,
            who, dest);
            who->set_leader(dest);
            dest->fight_ob(who);
        }
         else {
            who->set("haunt", 1);
           }
    } else {
       message_vision("$N眼睛忽然睁开，喃喃地说道：" RED 
"杀....杀....杀....\n" NOR,
            who);
        if( this_player() ) {
            who->kill_ob(this_player());
            who->set_leader(this_player());
            this_player()->fight_ob(who);
        }
    }
    this_object()->move(who);
    message_vision("$N将一张"YEL"僵尸追魂符"NOR"贴在$n身上。\n",this_player(),who);
    set("no_drop", 1);
    set("no_get", 1);
    set("equipped", "seal");
    return 1;
}
