// yiru@hero 2000.8.6

// 金刚符

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "金刚符" NOR, ({ "jin-gang sheet", "sheet"}) );
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

    if(undefinedp(query("targetname")))
        set("targetname",this_object());

    ob = query("targetname");
    if(!objectp(ob))
    {
        write("请先用write指令把要保护的人写到符上。\n");
        return 1;
    }

        if((int)ob->query_temp("jingangfu") > 0)
        {
                message_vision("$N已经受到金刚符的保护了！\n",ob);
                return 1;       
        }

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

    message_vision("$N祭起一张$n，$n哗的烧了起来！\n",me,this_object());

    lvl = query("level")+bonus;
        if(ob->query("family/family_name")!="蜀山剑派")
        {
                lvl = lvl/5;
        }
    ob->add_temp("apply/iron-cloth", lvl/3);
    ob->add_temp("apply/extra_fle", lvl/8);
    ob->add_temp("jingangfu", lvl);

    ob->start_call_out( (: call_other, __FILE__, "do_back", ob, lvl, this_object() :), lvl/6);

    // 有call_out的函数还未执行，不能destruct
    set("no_get",1);
    move(VOID_OB);
    return 1;
}
 
void do_back(object ob, int lvl, object sheet)
{
    message_vision(HIY"保护$N的金刚符失效了！\n"NOR,ob);
    ob->add_temp("apply/iron-cloth", -lvl/3);
    ob->add_temp("apply/extra_fle", -lvl/8);
    ob->add_temp("jingangfu",-lvl);
    destruct(sheet);
}

