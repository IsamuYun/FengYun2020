#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�ż�", ({"xin", "letter"}));
        set("long",
               "�����Ų��и�����ż���\n");
        set("unit", "��");
        set("weight", 5);
         set("no_drop", 1);
        set("no_get", 1);

        setup();
}

void init()
{
        add_action("do_sendto","sendto");
}

int do_sendto(string arg)
{
	object ob=this_object(),me=this_player();
	string targ;
	int exp,pot;
       if (!arg||!ob=present(arg,environment(me)))
               return notify_fail("��Ҫ�����͸�˭��\n");
       targ=ob->name(1);
	if ( targ != me->query("quest_letter/quest") ) 
		return notify_fail("�����͸�"+me->query("quest_letter/quest")+"���ţ�����ô������Ҹ��أ�\n");
       if (userp(ob)) 
		return notify_fail("��Ū�����˰ɣ�\n"); //��ҿ�������ͬ��NPC������
       if ( (int) me->query("task_time") < time() )
      	{
      		return notify_fail(targ+"�����˵������������,�������ҵĴ��£��㻹���������ң���\n");
        }
        tell_object(me,"����Ž�����"+targ+"��\n\n\n" NOR );
        exp=me->query("quest_letter/exp_bonus");
        pot=me->query("quest_letter/pot_bonus");
        tell_object(me,targ+"ϲ������л����ʱ���Ÿ��ң�\n\n"
	HIW"�㱻�����ˣ�"+chinese_number(exp)+"�㾭��ֵ��\n"
           "            "+chinese_number(pot)+"��Ǳ�ܡ�\n\n"NOR);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set("quest_letter",0);
        destruct(present("xin",me));
        return 1;
}

void owner_is_killed() { destruct(this_object()); }
