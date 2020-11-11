// yiru@hero 2000.8.5

// 灵心符

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "灵心符" NOR, ({ "ling-xin sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("value", 0);
    set("level", 5);
    setup();
}

int attach_function(object ob)
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
    me->add("atman", -me->query("atman_factor") );

    if( me ==ob )
        message_vision("\n$N往自己身上贴了一道"+name()+"。\n",me);
    else
        message_vision("\n$N往$n身上贴了一道"+name()+"。\n",me,ob);

    bonus += query("level");
        if(ob->query("family/family_name")!="蜀山剑派")
        {
                bonus = bonus/10;
        }

    // 解定身
    ob->delete_temp("no_move");
    // 解晕眩
    if( ob->query_temp("is_unconcious") )
    {
        ob->revive();
    }
    // 解混乱
    if( ob->query("bellicosity") > bonus )
    {
        ob->add("bellicosity", -bonus);
    }
    else
    {
        ob->set("bellicosity", 0);
    }
    
    // 解咒封
    if( environment(ob)->query("magic_protect") ) 
    {
        environment(ob)->delete("magic_protect");
        environment(ob)->delete("no_magic");
        message_vision(HIY"\n周围的魔法禁制被解除了！\n"NOR,me);
    }

    me->start_busy(1);

    destruct(this_object());

    return 1;
}

