//dan.c

#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIY "��ԭ��" NOR,({"hydan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "һ���ܹ��������²��볯ͨ͢��������鵤��\n"NOR);
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
                if (this_player()->query("m_success")>4 ) return notify_fail("���Ѿ��Թ���û�ԭ�����������ٳ���!\n");
          if (this_player()->query("m_success")<1 ) return notify_fail("��û�б�Ҫ�Ի�ԭ��!\n");
 if ( arg == "hydan")
  {
   message_vision(HIC"$NС������ķ���һ�Ż�ԭ����һ������ֱ�����ţ����ֿ����泯͢�����ˡ�\n"NOR,this_player());
   this_player()->add("combat_exp",-200000);
   this_player()->set("m_success",0);
   destruct(this_object());
   return 1;
  }
 return 0; 
}
