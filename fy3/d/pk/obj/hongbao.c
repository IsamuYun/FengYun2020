// hongbao.c
// ken 1999.12.3
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( HIR "ɱ�˺��" NOR, ({ "sr-hongbao", "hongbao" }) );
        set_weight(10);
        set("value", 100000);
        set("unit", "��");
        set("long", "�����ñ������������Ľ���������Դ�(open)������\n");
        setup();
}  

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
	object me;
        int exp,pot,score;
        exp=4000+random(1000);
        pot=1000+random(1000);
        score=35+random(20);
    	me = this_player();
      if( !arg || arg=="" ) return 0;
      if( arg=="sr-hongbao" || arg =="���" ) {
      message_vision("\n\n$NĨ��Ĩͷ�ϵĺ�ˮ���ò�����˫��, �Ȳ������ش���"+this_object()->name()+"��\n"NOR , me);
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

