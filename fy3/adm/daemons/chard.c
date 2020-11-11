
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// chard.c

#include <race.h>

void create() { seteuid(getuid()); }
void setup_char(object ob)
{
        string race;
        mapping my;
        if( !stringp(race = ob->query("race")) ) {
                race = "人类";
                ob->set("race", "人类");
        }
                
        switch(race) {
                case "赛亚人":
                case "人类":
                        HUMAN_RACE->setup_human(ob);
                        break;
                case "妖魔":
                        MONSTER_RACE->setup_monster(ob);
                        break;
                case "野兽":
                        BEAST_RACE->setup_beast(ob);
                        break;
                default:
                        error("Chard: undefined race " + race + ".\n");
        }

        my = ob->query_entire_dbase();

        if( undefinedp(my["gin"]) ) my["gin"] = my["max_gin"];
        if( undefinedp(my["kee"]) ) my["kee"] = my["max_kee"];
        if( undefinedp(my["sen"]) ) my["sen"] = my["max_sen"];

        if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
        if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
        if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];

        if( !ob->query_max_encumbrance() )
                ob->set_max_encumbrance( my["str"] * 20000 );

        ob->reset_action();
}

varargs object make_corpse(object victim, object killer)
{
        int i;
        object corpse, *inv,owner;

        if( victim->is_ghost() ) {
                inv = all_inventory(victim);
                inv->owner_is_killed(killer);
                inv -= ({ 0 });
                i = sizeof(inv);
                while(i--) inv[i]->move(environment(victim));
                return 0;
        }

        if( victim->is_zombie() ) {
                inv = all_inventory(victim);
                inv->owner_is_killed(killer);
                inv -= ({ 0 });
                i = sizeof(inv);
                while(i--) destruct(inv[i]);
                say( victim->name() + "缓缓地倒了下来，化为一滩血水。\n");
                return 0;
        }

        corpse = new(CORPSE_OB);
        corpse->set_name( victim->name(1) + "的尸体", ({ "corpse" }) );
        corpse->set("long", victim->long()
                + "然而，" + gender_pronoun(victim->query("gender")) 
                + "已经死了，只剩下一具尸体静静地躺在这里。\n");
        corpse->set("age", victim->query("age"));
        corpse->set("gender", victim->query("gender"));
        corpse->set("victim_name", victim->name(1));
        corpse->set_weight( victim->query_weight()  * (userp(victim)? 100: 1));
        corpse->set_max_encumbrance( victim->query_max_encumbrance() );
        corpse->move(environment(victim));
        
        // by Tiandi for no get from corpse if the corpse is not belong to u.20080802

      if(killer) {  
	  		if(owner=killer->query("possessed"))  
				killer = owner;
			corpse->set_temp("killer",killer->query("id"));
	  }

        if(userp(victim)){
                     corpse->set_temp("corpseowner",victim->query("id"));
//    message_vision( victim->query("id")+"设置完毕。\n", corpse );;
        }
         call_out( "deltmp",30,corpse);
        // Don't let wizard left illegal items in their corpses.
        if( !wizardp(victim) ) {
                inv = all_inventory(victim);
                inv->owner_is_killed(killer);
                inv -= ({ 0 });
                i = sizeof(inv);
                while(i--) {
                        if( (string)inv[i]->query("equipped")=="worn" && !inv[i]->query("selfmaking") ) 
								{
									inv[i]->move(corpse);
								}
								else
								{
									if (!inv[i]->query("no_drop")&& !inv[i]->query("selfmaking"))
										inv[i]->move(corpse);
								}
							}
        }

        return corpse;
}

private void deltmp(object me)
{
        if(me) {
                    me->delete_temp("killer");
                    me->delete_temp("corpseowner");
        }
        return ;
}
