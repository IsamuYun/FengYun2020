//dan.c

#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIC "��ʦ��" NOR,({"panshidan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "һ���ܹ���������ʦ������������鵤��\n"NOR);
    set("unit","��");
        set("value", 50000000);
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
          if (this_player()->query("eatdans")>4 ) return notify_fail("���Ѿ��Թ������ʦ�����������ٳ���!\n");
          if (this_player()->query("combat_exp")<3500000 ) return notify_fail("�㾭�鲻��3500000�����ܳ���ʦ��!\n");
          if (this_player()->query("betrayer")<1 ) return notify_fail("���Ѿ�û����ʦ��¼�ˣ���Ҫ�˷�!\n");
 if ( arg == "panshidan")
  {
   message_vision(HIC"$NС������ķ���һ����ʦ����һ������ֱ�����ţ�����ʦ����������·𶼳��˹�ȥ��\n"NOR,this_player());
   this_player()->add("betrayer",-1);
   this_player()->add("combat_exp",-2000000);
   this_player()->add("eatdans",1);
   destruct(this_object());
   return 1;
  }
 return 0; 
}
