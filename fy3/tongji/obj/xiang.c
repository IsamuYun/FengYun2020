#include <ansi.h>


inherit ITEM;

void create()
{
        set_name(HIR "红木大柜" NOR,({"mugui"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIR "漂亮的红木大柜，似乎可以(open)打开。\n"NOR);
                set("unit","个");
                set("value", 100);
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
        int score,count,i;
        int m_force;
        object silver;
        if ( arg == "mugui"){
                m_kee = this_player()->query("max_kee");
        m_sen = this_player()->query("max_sen");
        m_gin = this_player()->query("max_gin");
        m_force = this_player()->query("max_force");
        exp = 2000 + random(1000);
        pot = exp / 10 + 20;
        count=random(3)+3;
         score= pot /5 + 10;
//        intpot = 2 + 2 * random(2);
        message_vision(HIW"$N期待着好运的到来！紧闭双目，默默祷告 .... 然后用颤抖的双手打开了红木大柜。\n"NOR,this_player());
        this_player()->set("eff_kee",m_kee);
        this_player()->set("kee",m_kee);
        this_player()->set("eff_gin",m_gin);
        this_player()->set("gin",m_gin);
        this_player()->set("eff_sen",m_sen);
        this_player()->set("sen",m_sen);
        this_player()->set("force",m_force);
        this_player()->add("combat_exp",exp);
        this_player()->add("potential",pot); 
        this_player()->add("score",score);
        for(i=0;i<count;i++)
        {silver=new("/obj/money/thousand-cash");
        silver->move(this_player());
        }
        tell_object(this_player(),HIY"哇！！！！你发现里面装着：\n" +
        chinese_number(exp) + "点“实战经验”。\n"+
      chinese_number(pot) + "点“潜能”。\n"+
          chinese_number(score) + "点“评价”。\n"+
           chinese_number(count) + "张“一千两的银票”。\n"NOR
);
        destruct(this_object());
        return 1;
     }
     return 0; 
}
