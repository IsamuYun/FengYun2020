//hongbao.c

#include <ansi.h>


inherit ITEM;

void create()
{
        string *order=({HIC"奖励", HIY"创新", HIG"运气", HIW"辛苦",
HIB"鼓励"});
        set_name((order[random(5)]) + HIR "红包" NOR, ({ "full-hongbao"}) );

        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIR "一个用金丝编成的锦绣红包，似乎可以(open)打开。\n"NOR);
                set("unit","个");
                set("value", 100000);
        }
}
void init()
{
        add_action("open_gongbao","open");
}
int open_gongbao(string arg)
{
        int m_kee;
        int m_sen;
        int m_gin;
        int exp;
        int pot;
        int sscore;
        int m_force;
        if ( arg == "full-hongbao"){
                m_kee = this_player()->query("max_kee");
        m_sen = this_player()->query("max_sen");
        m_gin = this_player()->query("max_gin");
        m_force = this_player()->query("max_force");
        exp = 3000 + random(1000);
        pot = exp / 10  + 50;
        sscore = 20 + random(30);
        message_vision(HIG"$N擦了擦额头的汗水，迫不及待地用颤抖的双手打开了红包。\n"NOR,this_player());
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
        this_player()->add("special_score",1);
        tell_object(this_player(),HIY"哇！！！！你发现里面装着：\n" +
        chinese_number(exp) + "点“实战经验”的奖励。\n"+
        chinese_number(pot) + "点“潜能”的奖励。\n" +
        chinese_number(sscore) + "点“综合评价”的奖励。\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}