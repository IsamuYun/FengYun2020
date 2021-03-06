 
#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_send", "she");
}


void create()
{
       set_name(HIR"死亡之箭"NOR, ({"swzj"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
               "这是烟雨创造的神箭，专门对付那些爱不死的巫师\n");
               set("value", 0);
               set("unit", "枚");
               set("no_get", 0);
               set("no_drop", 0);
       }
}

int do_send(string target)
{
       object me, conc;

       me = this_object();

       if (target=="chen")
             target = this_player()->query("id");

       if(!(conc = find_player(target)))
             if(!(conc = find_living(target)))
             {
                   write("没有这个人或生物。\n");
                   return 1;
             }

       message_vision(HIR "死亡之箭带着风雷雨电射向$n。\n" NOR, me, conc);

       me->move(environment(conc));

       message_vision(HIR "$N以雷霆之势离弦。\n" NOR, me);

       conc->set_temp("last_damage_from", "被" + me->name() + "射中");
       CHANNEL_D->do_channel(this_object(), "rumor", sprintf("%s被死亡之箭射死了。", conc->name(1)));

       conc->set("immortal",12);  
       conc->set("env/invisibility",0);
       conc->set("env/immortal",0);
       conc->die();

       find_player(target)->reincarnate();
       find_player(target)->delete_temp("apply/name");
       find_player(target)->delete_temp("apply/id");
       find_player(target)->delete_temp("apply/short");
       find_player(target)->delete_temp("apply/long");
       destruct(this_object());
       return 1;
}
