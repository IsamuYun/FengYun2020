
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object soldier;
        int strategy,leadership, exp, MAX_GUARD, i;
        
        if ((string)me->query("class") != "dali")
        return notify_fail("你不是大理国官员，没有调集护卫的权利！\n");
//        if ( me->is_busy() )
//        return notify_fail("你现在正忙，无法调集军队。\n");
        if( !me->is_fighting() )
        return notify_fail("好象没有人要杀你！\n");

        strategy = (int)me->query_skill("strategy");
        leadership = (int)me->query_skill("leadership");
        exp = (int)me->query("combat_exp");
        if(strategy < 20 || leadership < 20)
        return notify_fail("你兵法和用人之技太差了，没人愿意理你！\n"); 
        
        MAX_GUARD = (strategy+leadership)/60 + 1;
		if(MAX_GUARD > 8)
		{
			MAX_GUARD = 8;	
		}
		
        if( me->query_temp("max_guard") > 0 )
                return notify_fail("你现在已经受到足够的保护了！\n");

        if((int)me->query("sen")< 100*MAX_GUARD)
        	return notify_fail("你的神太差了！\n");

        seteuid(getuid());
        me->receive_damage("sen",100*MAX_GUARD);
        soldier= new("/obj/npc/bingtou");
        message_vision(HIC "\n$N从怀中拿出一令旗，调集大理护卫前来助阵！\n" NOR, me);   
        soldier->move(environment(me));
        message_vision(HIC "\n$N带领一小队护卫应声而来！\n" NOR, soldier);
        soldier->invocation(me, (leadership+strategy));
        soldier->set("possessed", me);
        
        for(i=0;i<MAX_GUARD;i++)
        {
	        soldier= new("/obj/npc/bing");
	        soldier->move(environment(me));
	        soldier->invocation(me, (leadership+strategy));
	        soldier->set("possessed", me);
	    }

        me->set_temp("max_guard",MAX_GUARD+1);
//        me->remove_all_killer();
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：diaoji
 
这个指令让大理官员调集一小队护卫来保护自己。
护卫的素质就要看玩家官职的大小了。
 
HELP

    );
    return 1;
}

