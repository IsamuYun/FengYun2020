#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("信件", ({"xin", "letter"}));
        set("long",
               "这是信差托付你的信件。\n");
        set("unit", "封");
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
               return notify_fail("你要把信送给谁？\n");
       targ=ob->name(1);
	if ( targ != me->query("quest_letter/quest") ) 
		return notify_fail("这是送给"+me->query("quest_letter/quest")+"的信，你怎么能随便乱给呢？\n");
       if (userp(ob)) 
		return notify_fail("你弄错人了吧？\n"); //玩家可能有相同于NPC的名字
       if ( (int) me->query("task_time") < time() )
      	{
      		return notify_fail(targ+"冷冷地说：“你来晚了,耽误了我的大事，你还有脸来见我！”\n");
        }
        tell_object(me,"你把信交给了"+targ+"。\n\n\n" NOR );
        exp=me->query("quest_letter/exp_bonus");
        pot=me->query("quest_letter/pot_bonus");
        tell_object(me,targ+"喜道：多谢您及时送信给我！\n\n"
	HIW"你被奖励了："+chinese_number(exp)+"点经验值。\n"
           "            "+chinese_number(pot)+"点潜能。\n\n"NOR);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set("quest_letter",0);
        destruct(present("xin",me));
        return 1;
}

void owner_is_killed() { destruct(this_object()); }
