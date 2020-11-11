//欢乐英雄
//任务
// by lion@hero

#include <login.h>
#include <ansi.h>
#include <condition.h>

//inherit NPC;
//inherit F_CLEAN_UP;

string *poisons=({
    "unknown",
    "green_blood",
    "red_blood",
    "rose_poison",
    "zang_poison",
    "snake_poison",
    "red_poison",
    "beast_poison",
    "bowel_grass",
    "blood_poison",
    "crane_red",
    "gold_worm",
    "no_shadow",
    "peafowl_gall",
    "three_poison",
});

string *depoisons=({
    "demon",
    "bat",
    "unknown",
    "green_blood",
    "red_blood",
    "rose_poison",
    "zang_poison",
    "snake_poison",
    "red_poison",
    "beast_poison",
    "bowel_grass",
    "blood_poison",
    "crane_red",
    "gold_worm",
    "no_shadow",
    "peafowl_gall",
    "three_poison",
});

string *d1_npc=({
    "/d/linjiabao/job/npc/d1/bear",
    "/d/linjiabao/job/npc/d1/bianfu",
    "/d/linjiabao/job/npc/d1/bianfu1",
    "/d/linjiabao/job/npc/d1/bigsnake",
    "/d/linjiabao/job/npc/d1/xsnake",
    "/d/linjiabao/job/npc/d1/monster",
    "/d/linjiabao/job/npc/d1/snake",
    "/d/linjiabao/job/npc/d1/tiger",
    "/d/linjiabao/job/npc/d1/wolf",

});

string *d2_npc=({
    "/d/linjiabao/job/npc/d2/qicai_bianfu",
    "/d/linjiabao/job/npc/d2/fire_monster",
    "/d/linjiabao/job/npc/d2/huomonster",
    "/d/linjiabao/job/npc/d2/moshou",
    "/d/linjiabao/job/npc/d2/tumonster",
    "/d/linjiabao/job/npc/d2/poisonmon",
    "/d/linjiabao/job/npc/d2/shuimonster",
    "/d/linjiabao/job/npc/d2/feng_monster",

});

string *d3_npc=({
    "/d/linjiabao/job/npc/d3/dragon",
    "/d/linjiabao/job/npc/d3/fhuang",
    "/d/linjiabao/job/npc/d3/dragon",
    "/d/linjiabao/job/npc/d3/fhuang",
    "/d/linjiabao/job/npc/d3/huo_god",
    "/d/linjiabao/job/npc/d3/huo_god",
    "/d/linjiabao/job/npc/d3/huo_god",
    "/d/linjiabao/job/npc/d3/zhan_hun",

});

int update_condition(object me, int duration)
{
	object killer, ob;
	int reward_lvl, i;

    for(i=0;i<sizeof(depoisons);i++)
    {
    	if(me->query_condition(depoisons[i]) > 0)
    	{
    		me->clear_condition(depoisons[i]);
    	}	
    }
	
    if( duration < 10 )
    {
		me->apply_condition("lin_princess_job", 4000);
    }
    else
    {
    	me->apply_condition("lin_princess_job", duration - 1);
    }
    
    if( duration%3 != 0 )
    {
    	return CND_CONTINUE;
    }
    
    ob = me->query("protected_ob");
	if(!ob || !userp(ob) || !ob->query("ing_princess") 
		|| !ob->query_temp("nofly") || !environment(ob)->query("lin_job_place") 
		|| !environment(me)->query("lin_job_place") )
	{
		return CND_CONTINUE;
	}

	if( environment(me)->query("lin_rest_place") && environment(me)==environment(ob) )
	{
		return CND_CONTINUE;
	}
    
	reward_lvl = (int)me->query("reward_lvl");
	if(reward_lvl < 1 || reward_lvl > 3)
	{
		reward_lvl = 3;
	}

	if( reward_lvl > 1 )
	{
		ob->apply_condition(poisons[random(sizeof(poisons))], 5+random(reward_lvl*5));
	}

	if( reward_lvl > 2 )		
	{
		ob->apply_condition(poisons[random(sizeof(poisons))], 5+random(reward_lvl*5));
	}

	ob->start_busy(1+reward_lvl);
	for(i=0;i<=random(3);i++)
	{
		switch(reward_lvl)
		{
			case 1:
				killer = new(d1_npc[random(sizeof(d1_npc))]);
				break;
			case 2:
				killer = new(d2_npc[random(sizeof(d1_npc))]);
				break;	
			default:
				killer = new(d3_npc[random(sizeof(d1_npc))]);
				break;	
		}
	
		if(killer)
		{
			killer->set("combat_exp", ob->query("combat_exp") * reward_lvl*3);
			killer->set("eff_kee", ob->query("max_kee") * reward_lvl*10);
			killer->set("max_kee", ob->query("max_kee") * reward_lvl*10);
			killer->set("kee", ob->query("max_kee") * reward_lvl*10);
			killer->set("eff_gin", ob->query("max_gin") * reward_lvl*10);
			killer->set("max_gin", ob->query("max_gin") * reward_lvl*10);
			killer->set("gin", ob->query("max_gin") * reward_lvl*10);
			killer->set("eff_sen", ob->query("max_sen") * reward_lvl*10);
			killer->set("max_sen", ob->query("max_sen") * reward_lvl*10);
			killer->set("sen", ob->query("max_sen") * reward_lvl*10);
			killer->set("dur", me->query("dur") * reward_lvl*2);
			killer->set("agi", me->query("agi") * reward_lvl*2);
			killer->set("con", me->query("con") * reward_lvl*2);
			killer->set("str", me->query("str") * 4);
			killer->set("fle", me->query("fle") * reward_lvl*2);
			killer->set("cor", me->query("cor") * reward_lvl*2);
			killer->set("cps", me->query("cps") * reward_lvl*2);
			killer->set_skill("dodge", 150*reward_lvl);
			killer->set_skill("move", 150*reward_lvl);
			killer->set_skill("unarmed", 150*reward_lvl);
			killer->set_skill("force", 150*reward_lvl);
			killer->set_skill("parry", 150*reward_lvl);
			killer->set_skill("iron-cloth", 150*reward_lvl );
			killer->set_skill("sword", 150*reward_lvl);
			killer->set_skill("blade", 150*reward_lvl);
			killer->set("max_force", 1000000*reward_lvl);   
			killer->set("force", 1000000*reward_lvl);
			killer->set("force_factor", 100+random(100*reward_lvl*reward_lvl));   
	
			killer->add_temp("apply/damage", 100+random(100*reward_lvl*reward_lvl));
			killer->add_temp("apply/armor", 100+random(150*reward_lvl*reward_lvl));
			killer->add_temp("apply/attack", 100+random(150*reward_lvl));
			killer->add_temp("apply/defense", 100+random(150*reward_lvl));
			killer->add_temp("apply/iron-cloth", random(50*reward_lvl*reward_lvl));
			if(random(3))
			{
				killer->set("target_obid",ob->query("id"));			
				killer->move(environment(ob));
				tell_object(ob, HIM""+killer->query("name")+"突然扑了出来！！！\n\n"NOR);
				killer->set_leader(ob);
				killer->kill_ob(ob);
				ob->kill_ob(killer);
			}
			else
			{
				killer->set("target_obid",me->query("id"));			
				killer->move(environment(me));
				message_vision(HIM"$N突然扑了出来！！！\n\n"NOR,killer);
				killer->set_leader(me);
				killer->kill_ob(me);
				me->kill_ob(killer);				
			}
	    }
	}
	me->add_temp("lin_kill_num",1);
    return CND_CONTINUE;
}
