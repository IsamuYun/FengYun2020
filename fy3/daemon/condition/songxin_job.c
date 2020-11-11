//欢乐英雄
//任务
// by lion@hero

#include <login.h>
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string *poisons=({
    "bowel_grass",
    "blood_poison",
    "crane_red",
    "gold_worm",
    "no_shadow",
    "peafowl_gall",
    "three_poison",
});

int update_condition(object me, int duration)
{
	object killer, letter;
	int reward_lvl, killer_type;
	
    me->apply_condition("songxin_job", duration - 1);
    if( duration < 1 )
    {
    	return 0;
    }
    
	letter = present("secret letter",me);
	if( objectp(letter) && me->query("ing_letter") )
	{
		reward_lvl = (int)letter->query("reward_lvl");
		if(reward_lvl < 1 || reward_lvl > 9)
		{
			reward_lvl = 1;	
		}

		killer_type = 1+random(1+reward_lvl);
		if(killer_type > 9)
		{
			killer_type = 9;	
		}
		killer = new("/d/linjiabao/npc/killer"+sprintf("%d",killer_type));
		if(killer)
		{
			me->start_busy(2);
			killer->set("target_obid",me->query("id"));
			killer->set("combat_exp", me->query("combat_exp") * reward_lvl);
			killer->set("eff_kee", me->query("max_kee") * reward_lvl);
			killer->set("max_kee", me->query("max_kee") * reward_lvl);
			killer->set("kee", me->query("max_kee") * reward_lvl);
			killer->set("eff_gin", me->query("max_gin") * reward_lvl);
			killer->set("max_gin", me->query("max_gin") * reward_lvl);
			killer->set("gin", me->query("max_gin") * reward_lvl);
			killer->set("eff_sen", me->query("max_sen") * reward_lvl);
			killer->set("max_sen", me->query("max_sen") * reward_lvl);
			killer->set("sen", me->query("max_sen") * reward_lvl);
			killer->set("dur", me->query("dur") * reward_lvl);
			killer->set("agi", me->query("agi") * reward_lvl);
			killer->set("con", me->query("con") * reward_lvl);
                      killer->set("str", me->query("str"));
			killer->set("fle", me->query("fle") * reward_lvl);
			killer->set("cor", me->query("cor") * reward_lvl);
			killer->set("cps", me->query("cps") * reward_lvl);
			killer->set_skill("dodge", 100*reward_lvl);
			killer->set_skill("move", 100*reward_lvl);
			killer->set_skill("unarmed", 100*reward_lvl);
			killer->set_skill("force", 100*reward_lvl);
			killer->set_skill("parry", 100*reward_lvl);
			killer->set_skill("sword", 100*reward_lvl);
			killer->set_skill("blade", 100*reward_lvl);
                        if( reward_lvl < 8 )
			{
                                killer->set("force_factor", random(20*reward_lvl));   
                                 killer->set_skill("iron-cloth", 20*(random(reward_lvl)+1));
                                 killer->set_skill("jin-gang", 20*(random(reward_lvl)+1));
				killer->set_temp("apply/damage", random(50*reward_lvl));
                                 killer->set_temp("apply/armor", random(150*reward_lvl));
			}
			else
			{
if(random(2))
{
				me->apply_condition(poisons[random(sizeof(poisons))], reward_lvl);
}
				if(reward_lvl > 8 && !random(3))
				{
					me->apply_condition(poisons[random(sizeof(poisons))], reward_lvl);
				}
                                 killer->set("force_factor", 50+random(50*reward_lvl));
                            killer->set_skill("iron-cloth", 50*(random(reward_lvl)+1));
                        killer->set_skill("jin-gang", 50*(random(reward_lvl)+1));
                                killer->set_temp("apply/damage", random(100*reward_lvl));
			}
			
			killer->move(environment(me));
			message_vision(HIR"\n$N突然从阴暗处闪了出来！！！\n"NOR,killer);
			message_vision(HIC"$N对着$n大喝一声：小子，乖乖把密函交出来吧。\n\n"NOR,killer,me);
			killer->set_leader(me);
			killer->kill_ob(me);
			me->kill_ob(killer);            
        }
    }
    return CND_CONTINUE;
}
