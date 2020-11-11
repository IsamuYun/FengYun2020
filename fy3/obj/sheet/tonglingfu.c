// yiru@hero 2000.8.6

// 通靈符

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "通靈符" NOR, ({ "tong-ling sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("level", 5);
    set("value", 0);
    setup();
}

int burn_function()
{
    object ob, me = this_player();
    int lvl, bonus;

    ob = me;
    bonus = me->query("atman_factor");

        if( me->query_temp("apply/astral_vision") )
        {
                write("你已经具有通灵的能力了。\n");
                return 1;
        }
        
    if( bonus < 1 ){
        write("请先使用 enchant 命令指定灵力加力点数。\n");
        return 1;
    }
    if( me->query("atman")<me->query("atman_factor") ){
        write("你的灵力不够了！\n");
        return 1;
    }
    me->add("atman", -me->query("atman_factor") );

    message_vision("$N祭起一张$n，$n哗的烧了起来！\n",me,this_object());

    // 只有本人亲自烧符才有比较好的效果。
    bonus += query("level");
        if(me->query("family/family_name")!="蜀山剑派")
        {
                bonus = bonus/10;
        }

    ob->add_temp("apply/astral_vision", 1);
    ob->start_call_out( (: call_other, __FILE__, "do_back", ob, this_object() :), bonus/3);

    // 有call_out的函数还未执行，不能destruct
    set("no_get",1);
    move(VOID_OB);

    return 1;
}
 
void do_back(object ob, object sheet)
{
    tell_object(ob,"你的"+name()+"失效了。\n");
    ob->add_temp("apply/astral_vision", -1);
    destruct(sheet);
}

