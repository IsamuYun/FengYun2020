//朝天一棍 writted by tiandi

#include <ansi.h>
inherit SSERVER;
void remove_effect(object me, int amount);

int perform(object me,object target,int amount)
{
        string msg;
        object weapon;
        int skill, exp,str;
        skill  = me->query_skill("chaotian-stick",1);
 	 str = me->query("str");
	 exp = me->query("combat_exp");
	 
	 if( !target ) target = offensive_target(me);
	 if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                   return notify_fail("「"+HIW"朝天一棍"NOR+"」只能对战斗中的对手使用。\n");
	 if ( str < 40 ) return notify_fail("你的力气不够。\n");
        if ( exp < 500000 ) return notify_fail("你的实战经验不够。\n");

        if( me->query("TASK") < 2300  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("以你目前的状况，看来是不能使用这一招了。\n");
	  if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
            return notify_fail("你使用的武器不对。\n");
	
	 if( (int)me->query_temp("chaotian") ) return notify_fail("你已经在运功中了。\n");

        if( skill < 150)
            return notify_fail("你的朝天棍等级不够, 不能使用「"+HIW"朝天一棍"NOR+"」！\n");

        if( me->query("force") < 3000 )
            return notify_fail("你的内力不够，无法运用「"+HIW"朝天一棍"NOR+"」！\n");
	
	 if( me->query_temp("five")!=4)
	     return notify_fail("你还没有资格运用这招。\n");

        msg = HIW
    "$N朝天舞了九个棍花。舞动的"+weapon->name()+HIW"发出了尖啸,只见$N一掠而起，越过众人头顶，上持一棍砸下，\n众人不禁纳闷，$N要打谁呢。。。？\n\n"HIB"$n感受到一种特殊而从未有过的感觉：那是“凶”的感觉。\n------“凶”得一如“死亡”一般无可抵御、无法匹敌、无以拒抗、无有比拟的。\n"NOR;


        message_vision(msg, me, target);
        me->set_temp("chaotian", 1);
	 me->set_temp("no_eat",1);
	 me->add("combat_exp",exp*4);
	  me->set_temp("no_quit",1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, exp*4 :), skill/4);

        me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)	 
{
              int kee;
	 object env,room;

	 me->add("combat_exp",-amount);
        me->delete_temp("chaotian");
	 me->set("force",0);
	 me->delete_temp("quit");
	 env = environment(me);
        if ( env->query("no_death_penalty")) 
		{
		room = load_object("/d/death/gate");
  		if(room) me->move(room);
 	 	}//防止玩家pfm完回yaren等死。
	 tell_object(me, HIR"\n\n你用完了最后一点力气，再也站不起来了。\n\n夕阳的余光打在你的脸上，你不禁欣慰的笑了，缓缓地。。。缓缓地闭上了双眼。\n"NOR);
	
	me->add("kee",-(me->query("max_kee")+1000));
	me->set_temp("last_damage_from","???");
	me->delete_temp("no_eat");
}
