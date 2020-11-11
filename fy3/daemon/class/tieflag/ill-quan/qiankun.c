#include <ansi.h>
#include <combat.h>
inherit SSERVER;
static object *enemy = ({});
int perform(object me, object target1,object target2)
{
      	string msg;                                
        int extra,lv;
	object weapon;
	lv = me->query("qiankun");
	if (!lv)  me->set("qiankun",1);
	lv = me->query("qiankun");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("ill-quan",1);
	if ( extra < 50) return notify_fail("你的病维摩拳还不够纯熟！\n");
	enemy=me->query_enemy();
        if (sizeof(enemy)<2) return notify_fail("你必须同时和两个以上的敌手战斗才能使用乾坤挪移！\n");
        if( !target1 && target2) return notify_fail("你必须同时指定两个对手\n");
        if( !target2 && target1) return notify_fail("你必须同时指定两个对手\n");
	if(!target1 && !target2)
        {
           target1=enemy[0];
           target2=enemy[1];
         }
        if( !target1 || !target2
	||	!target1->is_character() || !target2->is_character()
	||	!me->is_fighting(target1) || !me->is_fighting(target2))
		return notify_fail("［乾坤挪移］只能对战斗中的对手使用。\n");
	if (me->query("force")<=100*lv) return notify_fail("你的内力不足，无法带动敌人攻势！\n");
        me->add("force",-100*lv);
        message_vision(HIY"\n$N使出病维摩拳的不传之秘「乾坤挪移」,企图使对手互相厮杀！\n"NOR,me);
        me->start_busy(2);
        weapon = target1->query_temp("weapon");
        if (random(extra/10)+lv>target1->query("level")/2)
        {
          message_vision(HIY "$N伸手带动$n的攻势，使之攻向"+target2->name()+"！\n" NOR,me,target1);
          COMBAT_D->do_attack(target1,target2, weapon);  
          target1->receive_damage("kee",0,me);
          target1->start_busy(1);
        }
        else
        {
          message_vision("但$n看破$N的意图，趁势发动攻击！\n",me,target1);
          COMBAT_D->do_attack(target1,me,weapon);
        }
        weapon = target2->query_temp("weapon");
        if (random(extra/10)+lv>target2->query("level")/2)
        {
          message_vision(HIY "\n$N伸手带动$n的攻势，使之攻向"+target1->name()+"！\n" NOR,me,target2);
          COMBAT_D->do_attack(target2,target1, weapon);  
          target2->receive_damage("kee",0,me);
          target2->start_busy(1);
        }
        else
        {
          message_vision("\n但$n看破$N的意图，趁势发动攻击！\n",me,target2);
          COMBAT_D->do_attack(target2,me,weapon);
        }

	 	 me->add("qiankun_exp",1);
	      tell_object(me, "你的【乾坤挪移】获得了一点技能熟练度。\n"NOR);
	  if((me->query("qiankun_exp") > (me->query("qiankun")*me->query("qiankun")*100))&&(me->query("qiankun")< MAX_PFMLEVEL))
		{
		me->add("qiankun",1);
		me->set("qiankun_exp",0);

	      tell_object(me, HIW"你的【乾坤挪移】等级上升了。\n"NOR);
		}

     	return 1;
}
int help(object me)
{
        write(YEL"\n病维摩拳之乾坤挪移："NOR"\n");
	write(@HELP
      乾坤挪移可以将你目前的目标一的攻击引向目标二。
      
     病维摩拳的等级每上升一级，增加此招的成功率。
     乾坤挪移每上升一级，增加此招的成功率。

HELP
	);
	return 1;
}

