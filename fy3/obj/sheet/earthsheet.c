// earth-warp sheet.c

inherit SHEET;

#include <ansi.h>
#include <login.h>

void create()
{
    set_name(YEL "阴界传送符" NOR, ({ "earth-warp sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("value", 0);
    setup();
}

int burn_function()
{
    object me = this_player();
    object env;

    env = environment(me);

    if(me->is_fighting())
        return notify_fail("战斗中不能使用阴界传送符！\n");

    me->start_busy(random(3)+1);
    message_vision(
        HIB "$N祭起一张阴界传送符。\n"
        "忽然四周吹起了一阵凉飕飕的阴风，阴风之中彷佛有许多人影在晃动...\n"
        "然後一阵火光突然爆起！\n" NOR, me);

    message("vision", 
        "可是...." + me->name() + "已经不见了。\n"
        , env, ({ me }));

    tell_object(me,
        CYN "你只觉得身子不断下坠，一直下坠，一直下坠，一直下坠，一直下坠 .....\n"
        NOR "不知道什麽时候，你发现你其实一直都站在坚硬的地面上，可是四周的景物\n"
        "却不一样了....\n");

    me->move(DEATH_ROOM);

    destruct(this_object());

    return 1;
}
