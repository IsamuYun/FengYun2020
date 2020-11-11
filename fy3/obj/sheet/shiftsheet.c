// yiru@hero
// cronus-shift sheet.c

inherit SHEET;

#include <ansi.h>
#include <login.h>

void create()
{
    set_name(YEL "遁身符" NOR, ({ "cronushift sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("value", 0);
    setup();
}

object find_env(object ob)
{
    while(ob)
    {
        if(ob->query("coor") ) return ob;
        else ob=environment(ob);
    }
    return ob;
}

int burn_function()
{
    object me = this_player();
    object env;

    if( me->is_fighting() )
        return notify_fail("战斗中不能使用遁身符！\n");

    env = me->query_temp("possheet");
    if(env)
        env = find_env(env);
    if(!env)
        return notify_fail("请先使用定位符确定转移的地点。\n");

    me->start_busy(random(3));
    message_vision(
        HIC "$N祭起一张遁身符。\n\n"
        HIW "忽然四周发出眩目的光亮，几乎使你目不能视物。……\n\n"
        NOR, me);

    if( (!env->query("no_magic")) && (env != environment(me))){
        message("vision", 
            "光亮过后，" + me->name() + "消失了。\n"
            , env, ({ me }));
        tell_object(me, HIC "光亮开始慢慢减弱，你发现你已到了……\n" NOR );
        me->move(env);
    }else{
        message("vision", 
            "光亮过后，什么也没有发生。\n"
            , env, ({ me }));
        tell_object(me, HIC "光亮开始慢慢减弱，你发现你还站在原地……\n" NOR );
    }

    destruct(this_object());

    return 1;
}
