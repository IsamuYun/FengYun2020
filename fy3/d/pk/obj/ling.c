#include <ansi.h>
#include <weapon.h>
inherit ITEM;
void create()
{
        set_name( HIG "ɱ��֤" NOR, ({ "sr_zheng", "zheng" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ���ܽ�ȥɱ�˱�����֤����\n");
                set("value", 0);
              set("no_give",1);
//		set("no_get",1);
              set("no_drop",1);
        }
        setup();
}
void init()
{
        add_action("do_open", "si");
}

int do_open(string arg)
{
	object me;
        int exp,pot,score;
        exp=4000+random(4000);
        pot=1000+random(1000);
        score=35+random(20);
    	me = this_player();
          if(query("srname") == me->query("id"))
                  return notify_fail("������������ѽ����˺���Լ��Ķ�����\n");
 if( !arg || arg=="" ) return 0;
      if( arg=="zheng" || arg =="sr-zheng" ) {
      message_vision(HIW"\n\n$NĨ��Ĩͷ�ϵĺ�ˮ����մ����Ѫ��˫��˺����"+this_object()->name()+"��\n"NOR , me);
      message_vision(HIW"\n$N����һ������ģ��·�֪�������ñ������������ġ�\n\n"NOR, me);
      me->add("combat_exp",exp);
      me->add("potential",pot);
      me->add("score",score);
      me->add("newpk",1); 
tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+chinese_number(pot) + "��Ǳ��\n"+
         chinese_number(score) + "������\n"+
         NOR);
       tell_object(me,HIW"\n��ϲ��!\n"NOR);
       destruct(this_object());
       return 1;
}
         return 1;
}
void owner_is_killed(object killer)
{
       message_vision(HIR"\n \n $N�ɹ���ɱ����һ�����ˣ�$N�İ�ɱ��֤���ڻ��У�\n\n",killer);
 	this_object()->move(killer);
}
