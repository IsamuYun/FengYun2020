// far-vision sheet.c

#include <ansi.h>
#define MAX_GUARD 4

inherit SHEET;

void create()
{
    set_name(YEL "天通眼符" NOR, ({ "far-vision sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("value", 0);
    setup();
}

int burn_function()
{ 
    object me=this_player();
    object obj;

    if( !objectp(query("targetname")) )
        return notify_fail("你想用这道符看哪里？\n");
    message_vision(
        "$N集中精神，祭起三味真火，唿的一声" + name() +"着了起来！\n", me);
    me->receive_damage("sen", 5);
    obj = query("targetname");

    if(!environment(obj)) {
        message("vision", "你感到眼睛酸酸的，却什么也没看到！\n", me);
    } else
    {
        message("vision", "在闪烁的火光中，你看到：\n", me);
        "/cmds/std/look"->look_room(me, environment(obj));
        message("vision", "你感到脖子发凉，黑暗处好像有双眼睛盯着你！\n", obj);
        message("vision", "你仔细地看了一下四周，却什么也没有！\n", obj);
    }
    destruct(this_object());
    return 1;
}
