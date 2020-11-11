// testsheet.c

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "²âÊÔ·û" NOR, ({ "test sheet", "sheet"}) );
    set_weight(5);
    set("unit", "ÕÅ");
    set("value", 0);
    setup();
}

int burn_function()
{
    object me = this_player();

    message_vision("testsheet->burn_funciton called ok.\n",me);

    return 1;
}
 
int attach_function(object ob)
{
    object me = this_player();

    message_vision("testsheet->attach_function called ok with ob ¡º$n¡».\n",me,ob);

    return 1;
}
 
int write_function(object ob)
{
    object me = this_player();

    message_vision("testsheet->write_function called ok with ob ¡º$n¡».\n",me,ob);

    return 1;
}
