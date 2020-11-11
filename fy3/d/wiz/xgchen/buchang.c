//hongbao.c

#include <ansi.h>


inherit ITEM;

void create()
{
        set_name(HIR "补偿丹" NOR, ({ "buchangdan" }));

        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIR "一个补偿丹，似乎可以(eat)打开。\n"NOR);
              set("unit","个");
                set("value", 1);
                set("no_drop", 1);
                set("no_get",1);
                set("no_give",1);
            }
}
void init()
{
        add_action("open_gongbao","eat");
}
int open_gongbao(string arg)
{
        int m_kee;
        int m_sen;
        int m_gin;
        int exp;
        int pot;
        int gold;
        int m_force;
              int sscore;
        if( this_player()->query("id") != query("player_id") ) 
        {
                return 0;
        }

       if (this_player()->query("buchang_over") == 1){
              message_vision(HIR"$N已经吃过了，怎么会还有的。\n"NOR,this_player());
                return 1;
        }
    if (( arg == "buchangdan")){
                m_kee = this_player()->query("max_kee");
        m_sen = this_player()->query("max_sen");
        m_gin = this_player()->query("max_gin");
        m_force = this_player()->query("max_force");
        exp = 100000 + random(10000);
        pot = exp / 2  + 2000;
        sscore = 50 + random(30);
              message_vision(HIR"$N擦了擦补偿丹上的尘土，一口气吞了下去。\n"NOR,this_player());
        this_player()->set("eff_kee",m_kee);
        this_player()->set("kee",m_kee);
        this_player()->set("eff_gin",m_gin);
        this_player()->set("gin",m_gin);
        this_player()->set("eff_sen",m_sen);
        this_player()->set("sen",m_sen);
        this_player()->set("force",m_force);
        this_player()->add("combat_exp",exp);
        this_player()->add("potential",pot); 
        this_player()->add("score",sscore);
        this_player()->set("hongbao_over",1);
        this_player()->add("special_score",1);
        tell_object(this_player(),HIY"哇！！！！你被奖励了：\n" +
        chinese_number(exp) + "点“实战经验”的奖励。\n"+
        chinese_number(pot) + "点“潜能”的奖励。\n" +
        chinese_number(sscore) + "点“综合评价”的奖励。\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}
void owner_is_killed(object killer)
{
	   destruct(this_object());
}
     
