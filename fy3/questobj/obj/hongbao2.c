// hongbao.c
// ken 1999.12.3
#include <ansi.h>
inherit ITEM;

void create()
{
        string *names = ({
               MAG "���Խ������"NOR, HIG "���Խ������"NOR, HIY "���Խ������"NOR, HIC "���Խ������"NOR
        });
        set_name( names[random(sizeof(names))], ({ "ackbao" }));
        set_weight(600);
        set("no_dropall",1);
        set("unit", "��");
        set("long", "���Ｋ�����Ψ�н⿪���������߲��ܻ�ã�����Դ�(open)������\n");
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
        exp=12000+random(2000);
        pot=exp/7;
        score=80+random(400);
    	me = this_player();
      if( !arg || arg=="" ) return 0;
      if( arg=="ackbao" || arg =="���" ) {
message_vision(HIG"\n\n$N�����������ˣ�͵͵�ͳ�������������ò�����˫��, �Ȳ������ش���.....\n"NOR , me);
      message_vision(HIW"\n$N����һ�������˴��һ������\n\n"NOR, me);
      me->add("combat_exp",exp);
      me->add("potential",pot);
      me->add("score",score);
      me->add("STASK",1); 
tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+chinese_number(pot) + "��Ǳ��\n"+
         chinese_number(score) + "������\n"+
         NOR);
       tell_object(me,HIR"\n\n       ��ϵع�ϲ��!        ������ȫ����ʦ\n\n"NOR);
       destruct(this_object());
       return 1;
}
         return 1;
}

//}
