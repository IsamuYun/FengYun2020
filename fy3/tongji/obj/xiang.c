#include <ansi.h>


inherit ITEM;

void create()
{
        set_name(HIR "��ľ���" NOR,({"mugui"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIR "Ư���ĺ�ľ����ƺ�����(open)�򿪡�\n"NOR);
                set("unit","��");
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
        message_vision(HIW"$N�ڴ��ź��˵ĵ���������˫Ŀ��ĬĬ���� .... Ȼ���ò�����˫�ִ��˺�ľ���\n"NOR,this_player());
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
        tell_object(this_player(),HIY"�ۣ��������㷢������װ�ţ�\n" +
        chinese_number(exp) + "�㡰ʵս���顱��\n"+
      chinese_number(pot) + "�㡰Ǳ�ܡ���\n"+
          chinese_number(score) + "�㡰���ۡ���\n"+
           chinese_number(count) + "�š�һǧ������Ʊ����\n"NOR
);
        destruct(this_object());
        return 1;
     }
     return 0; 
}
