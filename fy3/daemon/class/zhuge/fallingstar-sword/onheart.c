// 心有灵犀  written by tiandi
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

mapping weapon_name = ([
        "sword" : "剑",
        "blade" : "刀",
        "staff" : "杖",
        "whip"  : "鞭",
	 "axe"   : "斧",
	 "dagger": "刃",
	 "spear" : "枪"
]);

void do_remote_fight(object me, object couple, object target, int n);
void do_here_fight(object me, object couple, object target, int n);

int perform(object me, object target)
{
        int same_place;
        string couple_id;
        string couple_name;
        object couple;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail(HIM"[心有灵犀]"NOR"只能对战斗中的对手使用。\n");

        if (! stringp(couple_id = me->query("marry")))
                return notify_fail("你还没有结婚，灵犀个屁啊？\n");

        couple_name = me->query("marryname");

        if (! objectp(couple = find_player(couple_id)))
                return notify_fail(couple_name + "还在睡大觉呢，这样也能心有灵犀？\n");

          if (!couple->query_skill("tianya-blade"))
		    return notify_fail("你的伴侣好象不会天涯名月刀。\n");
	 if (!couple->query_temp("weapon"))
		    return notify_fail("你的伴侣好象没有用兵器。\n");
	  if  (couple->query_temp("weapon") ->query("skill_type")!="blade")
		      return notify_fail("你的伴侣好象没有用刀。\n");
	if (couple->is_ghost())
                return notify_fail(couple_name + "现在是孤魂野鬼，无法穿越灵界给与你力量。\n");

        if (! living(couple))
                return notify_fail("你的心灵现在无法和" + couple_name + "沟通。\n");

        if (target == couple)
                return notify_fail("你有病啊！\n");

        same_place = (environment(couple) == environment(me));

        if (! same_place)
                do_remote_fight(me, couple, target, (int)couple->query("atman"));
        else
                do_here_fight(me, couple, target, (int)couple->query("atman"));
        return 1;
}

void do_remote_fight(object me, object couple, object target, int n)
{
        object weapon;
        string chinese_type;
        int need, cost;
        int enhance, count;
        string msg;

        if (n > 500) n = 500;
        need = 300 - n / 2;
        cost = 300 - n / 3;

        if (me->query("atman") < need)
        {
                write("你试图施展心有灵犀，但是一时觉得精力不济，难以联系。\n");
                return;
        }

        if (couple->query("atman") < need)
        {
                write("你隐隐约约的感觉到你伴侣的灵力，但是非常微弱，很难捕捉到。\n");
                return;
        }

	if (me->is_busy())
        {
		write("( 你上一个动作还没有完成，不能施展心有灵犀。)\n");
                return;
        }

        if (random(2))
                tell_object(me, HIM "你心中默默的念着" + couple->name(1) +
                            HIM "的名字，隐隐感到那若即若离的"
                            "灵觉，穿透了无尽的虚空，和你心心相连。\n\n" NOR);
        else
                tell_object(me, HIM "穿过了缥缈的虚空，你仿佛看到" + couple->name(1) +
                            HIM "，给予你无上的鼓舞和无尽的力量。\n\n" NOR);

        if (random(2))
                tell_object(couple, HIM "你似乎感觉到" + me->name(1) +
                            HIM "在你心灵深处呼唤你的名字，两人之"
                            "间有如心有灵犀，你默默的为" +
                            gender_pronoun(me->query("gender")) +
                            "祝福：去吧，我的爱人！\n" NOR);
        else
                tell_object(couple, HIM "冥冥你感到了" + me->name(1) +
                            HIM "对你的呼唤，这一刹那，你们在心灵上"
                            "全然相通，你把无形的力量注入给对方，鼓舞着" +
                            gender_pronoun(me->query("gender")) + "。\n" NOR);

        me->add("atman", -cost);
        couple->add("atman", -cost);
        weapon = me->query_temp("weapon");
        if (weapon && (chinese_type = weapon_name[weapon->query("skill_type")]))
        {
                if (me->query("gender") == "女性")
                        msg = HIG"$N弹" + chinese_type +"轻吟，宛若黄莺出谷，飘身而进，手中的" +weapon->name() + HIG "化作流星夜雨，劈向$n。\n" NOR;
                else
                        msg = HIC"$N持" + chinese_type + "而进，竟然视$n有若无物，手中" +weapon->name() + HIC "挥洒自如，荡起层层" +chinese_type + "影，将$p困在当中。\n" NOR;
        } else
        {
                if (me->query("gender") == "女性")
                        msg = HIG"$N轻声浅笑，飘然而进，身法惊艳绝伦，有若九天玄女踏足红尘，举手投足之间没有任何破绽。\n" NOR;
                else
                        msg = HIC "$N纵声长啸，一股杀气凛然而起，天地登时色变，$N挟风雷万钧之势，压向$n。\n" NOR;
        }
        enhance = (int)couple->query_skill("force")+ n/10;
        count =  random(n / 100);
        if (count > 3)
                count = 3;
        me->add_temp("apply/attack", enhance);
 	 COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
		 
	 msg = MAG+"$N隐隐约约浮现在$n眼前，一会儿又消失了，如幽灵般地出现在$n身后，缠着$n。\n\n"NOR;
	message_vision(MAG+"\n"+couple->query("name")+"隐隐约约浮现在$n眼前，一会儿又消失了，如幽灵般地出现在$n身后，缠着$n。\n"NOR,me,target);

 	 COMBAT_D->do_attack(couple,target,couple->query_temp("weapon"),TYPE_REGULAR,msg);
	 if ( count >	0)
        {
	 msg = HIW+"$N心中更是鼓气勇气，遥指$n双腿，只闻哧、哧二声，两道极强劲的风，飞射$n双膝的“跳环穴”！\n"NOR;
 	 COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
	 }
	 if ( count >	1)
        {
	 msg = MAG+"$N的身影虽映射在$n眼中，却令$n捉摸不透，只见$N双手又是一绕，反切向$n！\n\n"NOR;
	message_vision(MAG+"\n"+couple->query("name")+"的身影映射在$n眼前，却令$n捉摸不透，只见"+couple->query("name")+"双手又是一绕，反切向$n！\n"NOR,me,target);
 	 COMBAT_D->do_attack(couple,target,couple->query_temp("weapon"),TYPE_REGULAR,msg);
	 }
	 if ( count >	2)
        {
	 msg = HIW+"$N心意绵绵，大受感动，直落黄河眭九式，手中"+weapon->name()+HIW"毫不停歇，一连九式攻向$n！\n"NOR; 	
	 COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
	 }



	 me->add_temp("apply/attack", -enhance);
        me->start_busy(3);
        return;
}

void do_here_fight(object me, object couple, object target, int n)
{
        int need, cost;
        int enhance1, enhance2, count;
        string msg;

        if (n > 500) n = 500;
        need = 300 - n / 2;
        cost = 300 - n / 3;

	if (me->is_busy())
        {
		write("( 你上一个动作还没有完成，不能施展心有灵犀。)\n");
                return;
        }

        if (couple->is_busy())
        {
                write("你的伴侣现在正忙，无法配合你进行心有灵犀。\n");
                return;
        }

        if (! couple->is_fighting(target))
                couple->fight_ob(target);

        message_vision(HIY "$N" HIY "和$n" HIY "两人眼神一交，心意已"
                        "然相通，不由的会心一笑，只见二人身形一错，霎时\n"
                        "已经向" + target->name() + "攻出数招！\n" NOR,
                        me, couple);

        enhance1 = (int)couple->query_skill("force",1);
        enhance2 = (int)me->query_skill("force",1);
        count = 2 + random(5 + n / 50);
        if (count > 6)
                count = 6;
        me->add_temp("apply/attack", enhance1);
        couple->add_temp("apply/attack", enhance2);
        while (count--)
        {
                if (me->is_fighting(target) && (count % 2) == 0)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                else
                if (couple->is_fighting(target))
                        COMBAT_D->do_attack(couple, target, couple->query_temp("weapon"), 0);
                else
                        break;
        }

        me->start_busy(2);
        couple->start_busy(2);
        me->add_temp("apply/attack", -enhance1);
        couple->add_temp("apply/attack", -enhance2);
        return;
}

