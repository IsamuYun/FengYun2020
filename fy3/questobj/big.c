// jin-nang by zzfy
#include <ansi.h>
inherit ITEM;
void create()
{
        string *order=({HIB"��ɫ����"NOR, HIR"��ɫ����"NOR, HIY"��ɫ����"NOR,HIW"��ɫ����"NOR,HIM"��ɫ����"NOR,HIC"��ɫ����"NOR});
        set_name((order[random(6)]) , ({ "jin-nang", "jin","nang"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIY "һ���ý�˿��ɵĽ��ң��ƺ�����(open)�򿪡�\n"NOR);
                set("unit","��");
                set("value", 0);
        }
        }
void init()
{
        add_action("open_gongbao","open");
}
int open_gongbao(string arg)
{
        int exp;
        int pot;
        int sscore;
        int extra;
        if ( arg == "jin-nang")
        {
extra = 1+(((int)this_player()->query("TASK"))/3000)+(((int)this_player()->query("bigtasks"))/1500);
        exp = (2000 + random(2000))*extra;
        if( exp > 5000) exp = 5000;
        pot = (300 + random(300))*extra;
        if(pot > 800) pot = 800;
        sscore = (30 + random(20))*extra;
        if(sscore > 100) sscore = 100;
        message_vision(HIM"$N���˲���ͷ�ĺ�ˮ���Ȳ��������ò�����˫�ִ��˽��ҡ�\n"NOR,this_player());
        this_player()->add("combat_exp",exp);
        this_player()->add("potential",pot); 
        this_player()->add("score",sscore);
        tell_object(this_player(),HIR"�ۣ��������㱻�����ˣ�\n\n" +
        chinese_number(exp) + "��ʵս���顣\n"+
        chinese_number(pot) + "��Ǳ�ܡ�\n" +
        chinese_number(sscore) + "���ۺ����ۡ������Ŭ��������\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}
