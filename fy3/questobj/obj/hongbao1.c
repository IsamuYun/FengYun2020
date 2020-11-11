// hongbao.c
// ken 1999.12.3
#include <ansi.h>
inherit ITEM;

void create()
{
        string *names = ({
               HIG "��������"NOR, HIM "��ȡ����"NOR, HIW "���´���"NOR, HIY "��������"NOR, HIR "��������"NOR
        });

        set_name( names[random(sizeof(names))], ({ "full-hongbao" }));
        set_weight(10);
        set("value", 100000);
        set("unit", "��");
        set("long", "�����������ʹ����Ľ���������Դ�(open)������\n");
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
        exp=4000+random(300);
        pot=exp/7;
        score=35+random(20);
    	me = this_player();
      if( !arg || arg=="" ) return 0;
      if( arg=="full-hongbao" || arg =="���" ) {
      message_vision("\n\n$NĨ��Ĩͷ�ϵĺ�ˮ���ò�����˫��, �Ȳ������ش���"+this_object()->name()+"��\n"NOR , me);
      message_vision(HIW"\n$N����ص��˵�ͷ���Ǻǵ�ɵЦ��������\n\n"NOR, me);
      me->add("combat_exp",exp);
      me->add("potential",pot);
      me->add("score",score);
      me->add("TTASK",1); 
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

//}
