// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int attack,int damage);
int perform(object me, object target)
{
        int skill,lv,extra,orforce,attack,damage;
		lv = (int)me->query("mowuchen");
		if (!lv)   me->set("mowuchen",1);
		lv = (int)me->query("mowuchen");	
        if( target != me ) return 
	notify_fail("你只能将［莫无尘］用在自己的身上。\n");
		lv = (int)me->query("mowuchen");
		if (!lv)   me->set("mowuchen",1);
		lv = (int)me->query("mowuchen");	
		if(me->is_busy())
		return notify_fail("你现在没空！！\n");
            extra = me->query_skill("nodust-steps",1);
		if( !me->is_fighting() )
		return notify_fail("［莫无尘］只能在战斗中使用。\n");

	orforce = (int) me->query("force");
	if (orforce < lv*100)
		return notify_fail("你的内力不足。\n");


        if( (int)me->query_temp("wuchen") ) return 
	notify_fail("你已经在施展［莫无尘］了。\n");
	skill = me->query_skill("nodust-steps",1);
	if(skill < 10) return notify_fail("你的无尘步太差了！\n");
	 me->add("force", -100*lv);
	 attack = skill + random(skill);
	 damage = skill + random(skill/3*2);
	 	if ( random(100)+lv*5 >= 50) 
	{
        message_vision( HIR
"$N轻身一跃，使出无尘步法中的［莫无尘］，身影随风，瞬息把自身的攻击提升到极致！\n" NOR, me);
	//	write("临时命中提高了"+attack+",临时伤害提高了"+damage+"\n");
        me->add_temp("apply/attack", attack);
		me->add_temp("apply/damage", damage);
        me->set_temp("wuchen", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
attack,damage :), 20*lv);
	}
			else 
	{
	write("由于不够熟练，你施展莫无尘失败了。\n");
	}

        me->start_busy(3);
		return 1;
}


void remove_effect(object me, int attack,int damage)
{
        me->add_temp("apply/attack", - attack);
		me->add_temp("apply/damage", - damage);
	//	write("临时命中降低了"+attack+",临时伤害提高了"+damage+"\n");
        me->delete_temp("wuchen");
        tell_object(me, HIG"你的莫无尘失去效果了。\n"NOR);
			if(me->query("mowuchen") < (me->query("level")/10) && userp(me))
	{
	  me->add("mowuchen_exp",1);
	      tell_object(me, "你的【莫无尘】获得了一点技能熟练度。\n"NOR);
	  if(me->query("mowuchen_exp") > (me->query("mowuchen")*me->query("mowuchen")*100)&&(me->query("mowuchen")<10))
		{
		me->add("mowuchen",1);
		me->set("mowuchen_exp",0);
	      tell_object(me, HIW"你的【莫无尘】熟练上升了。\n"NOR);
		}
	}
}
 
int help(object me)
{
	int skill;
	skill = me->query_skill("nodust-steps",1);
 write(YEL"\n无尘步法之莫无尘："NOR"\n");
write(@HELP
蓝大先生的身份到现在依然是个谜，没有人知道他的师傅是谁。有人说他
曾求艺少林，也有人说他曾经是个道人，其武功之杂，之精令武林中人咋舌。
此步法似乎出于少林，但经蓝大先生去糙留华，威力以不可估量。


HELP
);
	  write("\t当前状态：物理命中加成"+skill+"~"+skill*2+"点.物理伤害加成"+skill+"~"+(int)(skill+skill/3*2)+"点。收招延迟"+me->query("mowuchen")*20+"秒。\n");
	write(@HELP

      无尘步等级每上升一级，增加物理命中1~2点,物理伤害1~2点。
      莫无尘等级每上升一级，收招时间增加二十秒,同时提高成功率。

HELP
	);
	return 1;
}
