//dan.c

#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIG "���鵤" NOR,({"wangqingdan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "һ���ܹ���������ʦ������������鵤��\n"NOR);
    set("unit","��");
        set("value", 100000000);
   }
}

void init()
{
 add_action("eat_guo","eat");
}

int eat_guo(string arg)
{
         object me;
        me = this_player();
                if (this_player()->query("eatdans")>0 ) return notify_fail("���Ѿ��Թ���ʦ�����ٳ��������������Σ��!\n");
 if (this_player()->query("eatwqd")>1 ) return notify_fail("���Ѿ��Թ����е����ٳ��������������Σ��!\n");

          if (this_player()->query("betrayer")<1 ) return notify_fail("���Ѿ�û����ʦ��¼�ˣ���Ҫ�˷�!\n");
 if ( arg == "wangqingdan")
  {
   message_vision(HIC"$N����һ�����鵤,����ʦ����������·𶼳��˹�ȥ��\n"NOR,this_player());
   this_player()->delete("betrayer");
   this_player()->add("eatdans",5);
   this_player()->add("eatwqd",1);
   destruct(this_object());
   return 1;
  }
 return 0; 
}
