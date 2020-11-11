// yiru@hero 2000.8.5

// 净衣符

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "净衣符" NOR, ({ "cleanning sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("value", 0);
    set("level", 5);
    setup();
}

int attach_function(object ob)
{
    object me = this_player();
    int lvl, bonus;

    bonus = me->query("mana_factor");
    if( bonus < 1 ){
        write("请先使用 encurse 命令指定法力加力点数。\n");
        return 1;
    }
    if( me->query("mana")<me->query("mana_factor") ){
        write("你的法力不够了！\n");
        return 1;
    }
    me->add("mana", -me->query("mana_factor") );

    bonus = bonus + query("level");

    if( me ==ob )
        message_vision("\n$N往自己身上贴了一道"+name()+"。\n",me);
    else
        message_vision("\n$N往$n身上贴了一道"+name()+"。\n",me,ob);

    if ( random(bonus) > ob->query("level") )
    {
        ob->clear_condition();
        message_vision(HIC "\n$N的状态全恢复了！\n\n" NOR, ob);
    }else{
        tell_object(me, "\n但是什么也没有发生，也许是法力不够。\n");
        me->start_busy(3);
    }

    destruct(this_object());
    return 1;
}
