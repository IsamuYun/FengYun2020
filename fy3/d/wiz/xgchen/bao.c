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
        set("long",HIY"����֣�ݷ���Ϊ��л������ҵĺ񰮣�Ϊ������������İ��˺����\n"NOR);
        set("material", "paper");
  set("value", 1);
set("no_drop", 1);
        setup();
}
int do_open()
{
        int  exp, pot, score, money;
        object mon, me, ob;        

        me = this_player();
        
        if(me->query("olympic2")==2)
        {
        message_vision(HIM"���Ѵ򿪹�����˰ɣ���ռ����ѽ��\n"NOR,this_object(), me);
        return 1;
        }
        exp = 10000 + random(10000);
        pot = 2000 + random(10000);
        score = random(200);
        me->add("potential", pot); 
        me->add("combat_exp",exp); 
        me->add("score",score);
        tell_object(me, HIY "�����ˣ�\n" NOR + HIG +
        exp + "  ��ʵս����\n" NOR + HIC +
        pot + "  ��Ǳ��\n" NOR + HIW +
        score + "  ���ۺ�����\n" NOR );
        me->set("olympic2",2);
        if (present("liwu",me)) destruct(present("liwu",me));
        return 1;
}

