//wuyoudan.c

#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIC "���ǵ�" NOR,({"wuyoudan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "һ���ܹ��������н�����Թ���鵤��\n"NOR);
    set("unit","��");
    set("value", 5000000);
   }
}

void init()
{
 add_action("eat_guo","eat");
}

int eat_guo(string arg)
{
 if ( arg == "wuyoudan")
  {
   message_vision(HIC"$NС������ķ���һ�����ǵ���һ������ֱ�����ţ����н�����Թ��������ɢ�ˡ�\n"NOR,this_player());
   this_player()->delete("vendetta");
   destruct(this_object());
   return 1;
  }
 return 0; 
}

