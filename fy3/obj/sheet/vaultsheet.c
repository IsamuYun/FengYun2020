// yiru@hero 2000.8.5

// 定位符

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "天罡符" NOR, ({ "sky-vault sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("value", 0);
    set("level", 5);
    setup();
}

int burn_function()
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

    lvl = query("level");

    if ( random(bonus + lvl) > lvl )
    {
        me->start_busy(1);
    }else{
        me->start_busy(2);
    }

    if( (int)me->query_temp("vault")>0 ) return 1;
    message_vision("$N祭起一张$n，$n哗的烧了起来！\n",me,this_object());

    me->add_temp("apply/courage", 10);
    me->add_temp("apply/attack", bonus/2);
    me->add_temp("apply/damage", lvl);
    me->add_temp("vault",1);
    me->start_call_out( (: call_other, __FILE__, "do_back", me, bonus,
            this_object() :), bonus/2);

    // 有call_out的函数还未执行，不能destruct
    set("no_get",1);
    move(VOID_OB);

    return 1;
}
 
void do_back(object ob, int bonus, object sheet)
{
    tell_object(ob,"你的"+name()+"失效了。\n");
    ob->add_temp("apply/damage", -sheet->query("level"));
    ob->add_temp("apply/attack", -bonus/2);
    ob->add_temp("apply/courage", -10);
    ob->add_temp("vault",-1);
    destruct(sheet);
}
