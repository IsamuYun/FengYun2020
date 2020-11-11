// saveall.c  by tiandi 普渡众生

#include <ansi.h>

int exert(object me, object target, int amount)
{
	object *mem;
	int msize,lv,i,mm,extra;
	lv = me->query("saveall");
	if (!me->query("saveall"))
		me->set("saveall",1);
	lv = me->query("saveall");
	if( !me->is_fighting() )
		return notify_fail("普渡众生只能在战斗时使用。\n");
	mem = me->query_team();
	msize = sizeof(mem);
	if (msize < 2)
		return notify_fail("普渡众生只能对组队中的伙伴使用。\n");

	if( (int)me->query("force") < 100 * lv )
		return notify_fail("你的真气不够。\n");
	if( (int)me->query("kee") < me->query("eff_kee")/2 )
		return notify_fail("你的气血不够。\n");
	extra = me->query_skill("lotusforce",1);
	if (extra < 300)
		return notify_fail("你的技能还不够熟练。\n");
	message_vision(HIW"$N双手呈观音，暗念真诀，佛光普照大地，照亮在同伴身上。\n却见$N的同伴都血色满堂，唯独$N自己已经脸色煞白。\n" NOR,me);
	me->set("kee",1);
	me->set("force", 100+extra);
	if (lv < msize-1)
		mm = lv;
	else 
		mm = msize;
	for(i=0;i<mm;i++)
		{
		if( mem[i] != me && (environment(me) == environment(mem[i])) && random(extra)>100)
			{
			mem[i]->set("eff_kee",mem[i]->query("max_kee"));
			mem[i]->set("kee",mem[i]->query("max_kee"));
			mem[i]->set("eff_gin",mem[i]->query("max_gin"));
			mem[i]->set("gin",mem[i]->query("max_gin"));
			mem[i]->set("eff_sen",mem[i]->query("max_sen"));
			mem[i]->set("sen",mem[i]->query("max_sen"));
			mem[i]->set("force",mem[i]->query("max_force"));
			mem[i]->set("atmane",mem[i]->query("max_atman"));
			mem[i]->set("mana",mem[i]->query("max_mana"));
			message_vision(HIY"\n佛光照在$N身上，$N恢复到了最佳状态。\n" NOR,mem[i]);
			}
		else 
			if (mem[i] != me)
				message_vision(HIY"\n由于$N不够熟练，佛光照在$n身旁一丈之处，$n并未感觉有任何变化。\n" NOR,me,mem[i]);
		}
	if(me->query("saveall") < (target->query("level")/10) && !userp(target))
	{
	 	 me->add("saveall_exp",1);
	      tell_object(me, "你的【普渡众生】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("saveall_exp") > (me->query("saveall")*me->query("saveall")*100))&&(me->query("saveall")< 10))
		{
		me->add("saveall",1);
		me->set("saveall_exp",0);

	      tell_object(me, HIW"你的【普渡众生】等级上升了。\n"NOR);
		}
	return 1;
}
int help(object me)
{
        write(YEL"\n莲华心法之普渡众生："NOR"\n");
	write(@HELP

      兴国禅寺的妙法之一，牺牲自身，挽救同伴的性命。
	
	  莲华心法每上升一级，减少绝招消耗内力和气血一点。
      普渡众生级每提升一级，增加此招的有效人数一名。
     

HELP
	);
	return 1;
}

