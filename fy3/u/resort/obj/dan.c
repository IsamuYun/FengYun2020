inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("ǧ��ʯ����" , ({"shi zhongru" }) );
    if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long","��ʯ���Ҿ�����ʱ����Ȼ���ɵ�һ�ַǳ�����ҩ�ģ�Ҳ������������������ı�����\n");
                set("unit", "��");
                set("value", 10000);
                }
        setup();
}


void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  int gin, kee, sen, atman ,mana , force ;
  {     object me;
        me = this_player();
       if( !arg || arg=="" ) return 0;
       if( arg=="shi zhongru" || arg =="ǧ��ʯ����" )
     {
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
message_vision(HIW"\n$N�Ȳ������ذ�ǧ��ʯ������������ʱ������һ��͸�׵���ˬ!\n"NOR, me);
        destruct(this_object());
        return 1;
  }
}
}
