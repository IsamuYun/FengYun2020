c
// blade.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("令牌", ({"ling pai","ling" }));
       set_max_encumbrance(10);
       set("unit", "块");
       set("long", "这是一块朱红的令牌,精钢打造。\n");
       set("value", 11110);
    //   set("no_drop", "这样东西不能离开你。\n");
       set("no_burn",1);
       set("no_get", "这是朝廷的东西，平常人拿了会惹麻烦的。\n");
       set_weight(200);
       set("place","on");

       setup();
}
void owner_is_killed(object killer,object victim)
{
        victim->delete_temp("last_damage_from");
        killer->delete_temp("last_damage_from");
        victim->remove_all_killer();
        killer->remove_all_killer();

        victim->set("eff_kee", victim->query("max_kee"));
        victim->set("kee", victim->query("max_kee"));
        victim->set("gin", victim->query("max_gin"));
        victim->set("eff_gin", victim->query("max_gin"));
        victim->set("sen", victim->query("max_sen"));
        victim->set("eff_sen", victim->query("max_sen"));
        victim->set("force", victim->query("max_force"));
        victim->move("/d/fy/biwutai");
  victim->reincarnate();

        killer->set("eff_kee", killer->query("max_kee"));
        killer->set("kee", killer->query("max_kee"));
        killer->set("gin", killer->query("max_gin"));
        killer->set("eff_gin", killer->query("max_gin"));
        killer->set("sen", killer->query("max_sen"));
        killer->set("eff_sen", killer->query("max_sen"));
        killer->set("force", killer->query("max_force"));


        message("channel:chat",HIW"【比武场】"+
                killer->query("family/family_name")+"的"+killer->query("name")+"在比武台击败"+
                victim->query("family/family_name")+"的"+victim->query("name")+"！\n\n"NOR,users());

        message_vision (CYN"$N重重地摔在地上！\n"NOR,victim);
        message_vision (CYN"\n$N慢慢从地上爬将起来，被壮汉扶着走下比武台。\n"NOR,victim);
        victim->move(__DIR__"biwukantai");
        message_vision (CYN"$N被壮汉扶着慢慢走了过来。\n"NOR,victim);
        message_vision (CYN"几名壮汉欢呼着簇拥着$N走下比武台。\n"NOR,killer);
        killer->move(__DIR__"biwukantai");
        message_vision (CYN"$N被几名壮汉簇拥着走了过来。\n"NOR,killer);

        victim->delete("biwu_fighter");
        killer->delete("biwu_fighter");

}

