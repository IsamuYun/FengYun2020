// yiru@hero 2000.8.5

// 定位符

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "定位符" NOR, ({ "position sheet", "sheet"}) );
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

    if ( random(bonus) > ob->query("level") )
    {
        if( move(ob) ){
            // 贴符
            set("equipped", "sealed");
            set("no_drop", "这样东西不能丢弃，必须用 detach。\n");
            message_vision("\n$N往$n身上贴了一道"+name()+"。\n",me,ob);
            // 记录定位符的指针，以便瞬间转移时需要。
            me->set_temp("possheet",this_object());
        }else
            tell_object(me, "\n你试图往"+ob->name()+"身上贴"+name()+"，但是失败了。\n");
    }else{
        tell_object(me, "\n你试图往"+ob->name()+"身上贴"+name()+"，但是失败了。\n");
        me->start_busy(3);
        destruct(this_object());
    }

    return 1;
}
