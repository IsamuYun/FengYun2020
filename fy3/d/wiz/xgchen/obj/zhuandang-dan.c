//ת�����ר�ã�������;�����ԣ�����admin����clone ��co copy
//Υ�ߴ���
#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIR "ת����" NOR,({"zhuandang-dan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "һ��ʹ���ܵ��������ת�����񵤡�\n"NOR);
    set("unit","��");
        set("value", 1000);
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
                if (this_player()->query("eatzddan")>0 ) return notify_fail("���Ѿ��Թ��ˣ��������ٳ���!\n");
 if ( arg == "zhuandang-dan")
  {
   message_vision(HIC"$NС������ķ���һ��ת������һ������ֱ�����š�\n"NOR,this_player());
   this_player()->set("combat_exp",1000000);
     this_player()->set("int",30);
   this_player()->set("str",30);
   this_player()->set("spi",20);
   this_player()->set("con",30);
  this_player()->set("dur",30);
   this_player()->set("fle",20);
   this_player()->set("agi",30);
   this_player()->set("max_force",800);
   this_player()->set("max_atman",225);
   this_player()->set_skill("force",150);
   this_player()->set_skill("iron-cloth",100);
   this_player()->set_skill("jin-gang",50);
   this_player()->set_skill("magic",51);
   this_player()->set("max_mana",225);
   this_player()->set_skill("move",150);
   this_player()->set_skill("parry",150);
   this_player()->set_skill("dodge",150);
   this_player()->set_skill("essencemagic",61);
   this_player()->set("mud_age",110000);
   this_player()->set_skill("unarmed",150);
   this_player()->set_skill("yoga",150);
   this_player()->set_skill("literate",150);
   this_player()->add("potential",50000);
this_player()->add("eatzddan",1);
   destruct(this_object());
   return 1;
  }
 return 0; 
}
//ת�����ר�ã�������;�����ԣ�����admin����clone ��co copy
//Υ�ߴ���

