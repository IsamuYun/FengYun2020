#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR "��͢ٺ»" NOR,({"fenglu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIR "һ���������͵�ٺ»�����ƺ�����(open)�򿪡�\n"NOR);
                set("unit","��");
                      set("no_get",1);
                            set("no_drop",1);
                             }
}
void init()
{
        add_action("open_gongbao","open");
}
int open_gongbao(string arg)
{
        object goldd;
        if (this_player()->query("fenglu_open") == 1){
              message_vision(HIR"����$N��ٺ�벻Ҫ�򿪡�\n"NOR,this_player());
                return 1;
        }
       if ( arg == "fenglu"){
   	  goldd = new("obj/money/gold");
	  goldd->set_amount(100+random(300));
	 goldd->set("name",HIY" ��͢�ƻƽ�"NOR);
        goldd->move(this_player());
        this_player()->set("fenglu_open",1);
              message_vision(HIW"$N���˻������͵�ٺ»����\n"NOR,this_player());
        tell_object(this_player(),HIY"�㷢������װ��һ�ѻƽ�\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}

