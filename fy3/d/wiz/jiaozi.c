//jiaozi.c
#include <ansi.h>
void rling( object ob ) ;

inherit ITEM;

void init()
{
        add_action("do_enter", "enter");
}

void create()
{
        set_name(BLU "�󻨽�" NOR, ({"jiao zi", "jiao"}));
    set_weight(200000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
           set("no_get",1);
                set("long", "һ����ֵĴ󻨽Σ��������(enter)��ȥ���ԡ�\n");
}
        setup();
}

int do_enter(string arg)
{
        object ob ;
        string dir;
        if( !arg || arg != "jiao" ) 
       {
                tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
                return 1 ;
     }
         ob = this_player();
      message_vision( WHT "\n\n$N����������ȥ........ \n\n" NOR,this_player());
    message_vision( BLU "ͻȻһ�����������ˡ���������\n" NOR,this_player());
        call_out("rling", 20 , ob );
        return 1;
     }

void rling( object ob )
{
        message_vision("ͻȻ����ͣ��������\n", ob);
        ob->move(__DIR__"door");
}
