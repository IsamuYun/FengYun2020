// jin-nang by zzfy
#include <ansi.h>
inherit ITEM;
void create()
{
        string *order=({HIB"����ʤ����ɫ����"NOR, HIR"����ʤ����ɫ����"NOR, HIY"����ʤ����ɫ����"NOR,HIW"����ʤ����ɫ����"NOR,HIM"����ʤ����ɫ����"NOR,HIC"����ʤ����ɫ����"NOR});
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
       if (this_player()->query("gender") != "����"){
              message_vision(HIR"$N��û��Ȩ��������\n"NOR,this_player());
                return 1;
        }
       if (this_player()->query("biwuhongbao") == 1){
              message_vision(HIR"$Nû��Ȩ��������\n"NOR,this_player());
                return 1;
}
        if ( arg == "jin-nang"){
        exp = 2000 + random(2000);
        pot = 300 + random(300);
        sscore = 100;
        message_vision(HIM"$N���˲���ͷ�ĺ�ˮ���Ȳ��������ò�����˫�ִ��˽��ҡ�\n"NOR,this_player());
        this_player()->add("deposit",sscore);
        this_player()->set("biwuhongbao",1);
        tell_object(this_player(),HIR"�ۣ��������㱻�����ˣ�\n\n" +
        chinese_number(sscore) + "���ƽ�Ǯ�Զ��������У�\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}
