//guo.c

#include <ansi.h>


inherit ITEM;

void create()
{
        set_name(HIC "无忧丹" NOR,({"dan"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIC "一颗能够忘记所有忧愁的灵丹妙药。\n"NOR);
                set("unit","颗");
                set("value", 40000);
        }
}
void init()
{
        add_action("eat_guo","eat");
}
int eat_guo(string arg)
{
        int m_kee;
        int m_sen;
        int m_gin;
        int m_force;
        if ( arg == "dan"){
                m_kee = this_player()->query("max_kee");
        m_sen = this_player()->query("max_sen");
        m_gin = this_player()->query("max_gin");
        m_force = this_player()->query("max_force");
        message_vision(HIC"$N小心翼翼的服下一颗无忧丹，一股清香直冲面门，仿佛一切烦恼都烟消云散了。\n"NOR,this_player());
        this_player()->set("eff_kee",m_kee);
        this_player()->set("kee",m_kee);
        this_player()->set("eff_gin",m_gin);
        this_player()->set("gin",m_gin);
        this_player()->set("eff_sen",m_sen);
        this_player()->set("sen",m_sen);
        this_player()->set("force",m_force);
        this_player()->set("food",400);
        this_player()->set("water",400);
        this_player()->add("betrayer",-1);
        destruct(this_object());
        return 1;
     }
     return 0; 
}

