//hongbao.c

#include <ansi.h>


inherit ITEM;

void create()
{
        set_name(HIY"��"HIC"��"HIG"��"GRN"��"HIM"��"NOR, ({ "gqlb" }));

        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIR "һ���ý�˿��ɵĳ������������������ȥ����ͦ�ص�,�ƺ�����(open)������\n"NOR);
                set("unit","��");
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
 object silk;
object silk2;
        int m_gin;
        int exp;
        int pot;
        int gold;
        int m_force;
              int sscore;
       if (this_player()->query("libaoo_over") == 1){
              message_vision(HIR"$N�Ѿ��򿪹����ˣ���ô�ỹ�еġ�\n"NOR,this_player());
                return 1;
        }
    if (( arg == "gqlb")){
                m_kee = this_player()->query("max_kee");
        m_sen = this_player()->query("max_sen");
        m_gin = this_player()->query("max_gin");
        m_force = this_player()->query("max_force");
        silk = new("/d/linjiabao/npc/tianjia/liwu.c");
        silk2 = new("/d/wiz/xgchen/book3.c");

        exp = 50000 + random(1);
        pot = exp / 10  + 100000;
        sscore = 50 + random(300);
              message_vision(HIR"$N��ϲ�����Ȳ������Ĵ��˴�������\n"NOR,this_player());
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
        silk->move(this_player());
        silk2->move(this_player());

        this_player()->set("libao_over",1);
        this_player()->add("special_score",1);
        tell_object(this_player(),HIY"�ۣ��������㷢������װ�ţ�\n" +
        chinese_number(exp) + "�㡰ʵս���顱�Ľ�����\n"+
        chinese_number(pot) + "�㡰Ǳ�ܡ��Ľ�����\n" +
        chinese_number(sscore) + "�㡰�ۺ����ۡ��Ľ���! ��������һ�Ѿ����������书�ؼ�,����������Ȼ�����ֽ�����!\n"NOR);
                destruct(this_object());
        return 1;
     }
     return 0; 
}
void owner_is_killed(object killer)
{
	   destruct(this_object());
}
     
