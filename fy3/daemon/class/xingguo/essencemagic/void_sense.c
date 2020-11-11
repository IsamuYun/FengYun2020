 // void_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        int skill;
        int lv,msize,i;
		object *mem;
        
        if((int) me->query_skill("essencemagic",1) < 250)
                return notify_fail("你的八识神通不够高深！");
		mem = me->query_team();
		msize = sizeof(mem);
		if (msize < 2)
			return notify_fail("空识只能在组队中使用。\n");
		if( me->query("atman") < 100*msize )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 50*msize )
                return notify_fail("你的精不够！\n");
		skill= (int) me->query_skill("essencemagic",1);
        me->add("atman", -100*msize);
        me->receive_damage("gin", 50*msize);
        message_vision(HIY "$N双手合十，垂眉俯首，低声吟诵 ...色即是空，空既是色，空识无形，唯我神通！\n" NOR, me);
     
		for(i=0;i<msize;i++)
		{
		if( environment(me) == environment(mem[i])&& mem[i]->query_temp("invoid")== 0)
			{
			 
			mem[i]->add_temp("apply/defense",skill*5);
			mem[i]->set_temp("invoid",1);
			seteuid(ROOT_UID);
			mem[i]->start_call_out( (: call_other, __FILE__, "remove_effect", me,mem[i], skill*5 :), skill/10);
			seteuid(getuid());
			message_vision(HIY"\n$N身上被异样的光圈笼罩着，$N的防御力得到了加强。\n" NOR,mem[i]);
			}
		}       
        me->start_busy(2);
        return 1;
} 
void remove_effect(object me,object target, int amount)
{
        target->add_temp("apply/defense", -amount);
        target->delete_temp("invoid");

        message_vision( HIR"$N浑身一凛，身上附加的神力消失了。\n" NOR, target);
}
int help(object me)
{
        write(YEL"\n八识神通之空识："NOR"\n");
	write(@HELP

      兴国禅寺的妙法之二，临时提高队友玩家的防御力

HELP
	);
	return 1;
}


    
       
