//dan.c

#include <ansi.h>
inherit ITEM;

void create()
{
set_name(HIC "���е�" NOR,({"xiaopandan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "һ���ܹ���������ʦ������������鵤,�Ǹ��Թ�5����ʦ�������õ�,
  ʹ�ú��������4m�ľ���,һ��һ��ֻ�ܳ�2��,���á�\n"NOR);
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
          if (this_player()->query("eatxpd")>2 ) return notify_fail("���Ѿ��Թ�2��
���ѵ����������ٳ���!\n");
  if (this_player()->query("eatwqd")>1 ) return notify_fail("���Ѿ��Թ����鵤���ٳ��������������Σ��!\n");
  if (this_player()->query("combat_exp")<8000000 ) return notify_fail("�㾭�鲻��8000000�����ܳ����ѵ�!\n");
          if (this_player()->query("betrayer")<1 ) return notify_fail("���Ѿ�û����ʦ��¼�ˣ���Ҫ�˷�!\n");
  if ( arg == "xiaopandan")
  {
   message_vision(HIC"$NС������ķ���һ����ʦ����һ������ֱ�����ţ�����ʦ����������·𶼳��˹�ȥ��\n"NOR,this_player());
   this_player()->add("betrayer",-1);
     this_player()->add("combat_exp",-4000000);
     this_player()->add("eatxpd",1);
   destruct(this_object());
   return 1;
  }
 return 0; 
}
