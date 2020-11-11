// yiru@hero 2000.8.5

// 醉仙封魔符

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "醉仙封魔符" NOR, ({ "no-magic sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("value", 0);
    set("level", 5);
    setup();
}

int burn_function()
{
    object me = this_player();
    int bonus;

    bonus = me->query("atman_factor");
    if( bonus < 1 ){
        write("请先使用 enchant 命令指定灵力加力点数。\n");
        return 1;
    }
    if( me->query("atman")<me->query("atman_factor") ){
        write("你的灵力不够了！\n");
        return 1;
    }
    if( !me->query_condition("drunk") ){
        write("你现在好象一点醉意也没有耶！\n");
        return 1;
    }

    me->add("atman", -me->query("atman_factor") );

    message_vision("\n$N祭起一道"+name()+"。\n",me);

    bonus += query("level");
        if(me->query("family/family_name")!="蜀山剑派")
        {
                bonus = bonus/5;
        }

    // 随机成功率。
    if( random(bonus) > query("level") )
    {
        environment(me)->set("no_magic",1);
        environment(me)->set("magic_protect",1);
        message_vision(HIY"\n紧跟着$N元神出窍，把周围的魔法禁制了！\n"NOR,me);
        // 醉仙封魔需要元神出窍，呵呵
        me->unconcious();
        me->be_full();
    }
    else
    {
        message_vision("\n但是$N失败了！\n",me);
        }
        me->start_busy(1);
    destruct(this_object());

    return 1;
}

