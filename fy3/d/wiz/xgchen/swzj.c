 
#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_send", "she");
}


void create()
{
       set_name(HIR"����֮��"NOR, ({"swzj"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
               "�������괴��������ר�ŶԸ���Щ����������ʦ\n");
               set("value", 0);
               set("unit", "ö");
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
                   write("û������˻����\n");
                   return 1;
             }

       message_vision(HIR "����֮�����ŷ����������$n��\n" NOR, me, conc);

       me->move(environment(conc));

       message_vision(HIR "$N������֮�����ҡ�\n" NOR, me);

       conc->set_temp("last_damage_from", "��" + me->name() + "����");
       CHANNEL_D->do_channel(this_object(), "rumor", sprintf("%s������֮�������ˡ�", conc->name(1)));

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
