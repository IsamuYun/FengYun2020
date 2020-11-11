#include <ansi.h>
inherit ITEM;

void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIR "还魂丹" NOR, ({ "huanhun dan" , "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗还魂丹，是恢复功夫的灵药！\n");
                set("no_get", "这样东西不能离开那儿。\n");
                }
        setup();
}
int do_eat(string arg)
{
        object me = this_player();

        object *inv;
        mapping hp_status, skill_status;
        string *sname;
        int i;

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        skill_status = me->query_skills();
        if (!skill_status)
        return notify_fail("你用不着吃还魂丹。\n");

        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
                me->set_skill(sname[i], skill_status[sname[i]]+7);
        }

        hp_status = me->query_entire_dbase();
        me->set("combat_exp",hp_status["combat_exp"]*50/49);
        me->set("potential",hp_status["potential"]*2-1);
        
        me->save();
        message_vision(HIR "$N吃下一颗还魂丹，只觉得一阵肚痛．顿时又好转起来．\n" NOR, me);
        destruct(this_object());
        return 1;
        
}
