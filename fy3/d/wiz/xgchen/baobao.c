#include <ansi.h>
inherit ITEM;

void init()
{
       add_action("do_open","open");
}
void create()
{
      set_name( HIC"��"HIY"��"HIG"��"HIM"��"NOR, ({ "liwu" }) );
        set_weight(1);
        set("unit", "��");
        set("long",HIY"����һ������Ϊ���������Ϊ������ʧ���������İ��˺����\n"NOR);
        set("material", "paper");
set("value", 10);

        setup();
}
int do_open()
{
        int  exp, pot, score, money;
        object mon, me, ob;        

        me = this_player();
        
                exp = 500000;
        pot = 100000;
        score = 2;
        me->add("potential", pot); 
        me->add("combat_exp",exp); 
        me->add("score",score);
 me->add("gongxian",10000);

        tell_object(me, HIY "�����ˣ�\n" NOR + HIG +
        exp + "  ��ʵս����\n" NOR + HIC +
        pot + "  ��Ǳ��\n" NOR + HIW +
        score + "  ���ۺ�����\n" NOR );
              if (present("liwu",me)) destruct(present("liwu",me));
        return 1;
}

