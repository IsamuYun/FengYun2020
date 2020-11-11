//hongbao.c

#include <ansi.h>


inherit ITEM;

void create()
{
        string *order=({HIC"����", HIY"����", HIG"����", HIW"����",
HIB"����"});
        set_name((order[random(5)]) + HIR "���" NOR, ({ "full-hongbao"}) );

        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIR "һ���ý�˿��ɵĽ��������ƺ�����(open)�򿪡�\n"NOR);
                set("unit","��");
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
        message_vision(HIG"$N���˲���ͷ�ĺ�ˮ���Ȳ��������ò�����˫�ִ��˺����\n"NOR,this_player());
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
        tell_object(this_player(),HIY"�ۣ��������㷢������װ�ţ�\n" +
        chinese_number(exp) + "�㡰ʵս���顱�Ľ�����\n"+
        chinese_number(pot) + "�㡰Ǳ�ܡ��Ľ�����\n" +
        chinese_number(sscore) + "�㡰�ۺ����ۡ��Ľ�����\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}