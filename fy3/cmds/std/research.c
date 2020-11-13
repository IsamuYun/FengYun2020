#include <skill.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        int gin_cost;   
        int my_skill;
        int pot;
        int old_pot;
        string skill;
        int amount;
        if ( me->is_fighting() ) {
                return notify_fail("在战斗中搞研究？\n");
        }
        if ( !arg || sscanf(arg, "%s %d", skill, pot) != 2 )
                return notify_fail("指令格式：research <技能> <点数>\n");
        if ( !(int)my_skill = me->query_skill(skill, 1) )
                return notify_fail("你对此项技能一无所知，如何搞研究？\n");
                                                                                
        if ( !SKILL_D(skill)->valid_learn(me) ) {
                return 0;
        }
//      if( !SKILL_D(skill)->valid_research(me) ) return 0;
        

        old_pot = (int)me->query("potential") - (int) me->query("learned_points");
        if (pot < 0) {
                return notify_fail("至少用1点潜能\n");
        }
        if (pot > old_pot) {
                return notify_fail("你没有足够的潜能\n");
        }
        
        if (( me->query_skill(skill, 1) * 10) > me->query("score") ) {
	        return notify_fail("你没有足够的评价。\n");
        }
        
        if ( me->query_skill(skill, 1) > me->query("level") * 30 )
        {
		return notify_fail("你的等级太低了，研究不了如此高深的技能。\n");
        }
        amount = my_skill * SKILL_D(skill)->black_white_ness() / 100;
        amount += SKILL_D(skill)->learn_bonus() + (int)me->query_int() + me->query("level") * 10;
        amount = pot + (amount + random(amount)) * random(200);
	//amount = pot * (amount + random(amount));
	me->add("learned_points", pot);
        me->research_skill(skill, amount);
        write("你对" + to_chinese(skill) + "作了一番彻底的研究！\n");
        return 1;
}

int help(object me)
{
   write( @HELP
指令格式: research <技能> <点数>

这一指令让你用一定的潜能对某项技能作深入的研究。
研究时有最低评价的限制，研究消耗的评价和技能等级
成正比，研究的上限是普通学习的1.5倍。
HELP
   );
   return 1;
}

