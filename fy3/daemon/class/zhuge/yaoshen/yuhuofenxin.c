//欲火焚心  writted by tiandi,jjf提供

#include <ansi.h> 
inherit SSERVER; 

string *action = ({
"$n正要再出手时，忽然看见$N化作一团火！\n一个人眼见另一个人忽然化作一团熊熊的青焰，那感觉是奇特的，尤其是那团厉火直向自己卷来之时。\n",
"$N吆喝一声，“呼”、“呼”二团火焰，竟串连在一起，如一火棒般，向$n没头没脑地打到！\n",
"$N眼见得手，又给$n化去，勃然大怒，即行抢攻，$n只要一个不留神，就要丧在$N的火攻之下,这正是“以逸待劳”！\n",
"$N的眼神似烈火碰上了干柴，哗哗啪啪的烧了起来，让人感觉到火星正在飞溅！\n",
"$N杀性大起，一作怒起来，全身如火烧，衣袂亦烧，眼神更在烧！\n",
"$N的另一股火团也引发起来，两股烈火一产爆发，以致$n觉得烈火焚身。\n",
"$N手中的妖神火刃爆出两团烈火，被沾上之人立刻就成了火团，惨嚎之声不绝于耳。\n",
"$n身上的火越烧越旺，不过这刻$n却忙于躲避$N不时发出的火团,无法分心去理这些。\n"
});

void finish(object me);

int cast(object me, object target)
{ 
       object weapon, env; 
       string msg; 
       int extra, damage; 
       if(!me->is_fighting())
		 return notify_fail(HIR"「欲火焚心」"NOR"只能在战斗中使用。\n"); 

      if( !target ) target = offensive_target(me); 

  if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展这个法术？\n");
    
       if( me->query("TASK") < 2300  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("以你目前的状况，还没有资格用这一招。\n");
	if( me->query_temp("yuhuo") ) 
               return notify_fail("你正在使用"HIR"「欲火焚心」"NOR"！\n"); 
       if (time()<(me->query_temp("perform/yuhuo")+20)) 
               return notify_fail(HIG"你刚使用完"HIR"「欲火焚心」"HIG"，多用会伤身的！\n"NOR); 
                
       if( (int)me->query("mana") < 250 ) 
               return notify_fail("你的法力不够！\n"); 

       extra = me->query_skill("yaoshen",1); 

       if( extra < 150 ) 
               return notify_fail("你的妖神等级不够.\n"); 
	if( (int)target->query("kee") < 1000 ) 
               return notify_fail("杀鸡岂用牛刀？\n"); 

       weapon = me->query_temp("weapon"); 

       me->set_temp("yuhuo", 1); 
	me->set_temp("perform/yuhuo",time()); 

       msg = HIY"$N念动九字真诀，人已离开原来的地方。火焰，在一刹那间，喷了出去。\n\n" NOR; 
       message_vision(msg,me); 
        
       damage = extra*5; 
       damage = damage/2 + random(damage); 
	if ( damage > 800 ) damage = 800;
        
       if( random(extra) > target->query_skill("dodge")/5 ) { 
               msg = RED"$n的衣服上至少有四处地方着了火。\n"NOR; 
               target->receive_damage("kee", damage); 
               target->receive_wound("kee", damage/2); 
               message_vision(msg,me,target); 
               COMBAT_D->report_status(target); 
       } 

       msg = HIC"\n$N的瞳孔开始收缩，$N发现$n越来越不似想象中那么好对付。\n" NOR; 
       message_vision(msg,me,target);  
       env = environment(me); 
            if ( weapon&&weapon->query("id")== "yaoshen-blade")
       call_out("auto_perform", 5, me, target , env, weapon, extra/15); 

            if ( !weapon||weapon->query("id")!= "yaoshen-blade")      me->delete_temp("yuhuo");
       me->start_busy(2); 
       return 1; 
} 

void auto_perform(object me, object target, object env, object weapon, int i) 
{ 
       int damage, extra; 
       string msg; 
	if (i>7) i=7;
    	
	if(!target 
        || weapon->query("id")!= "yaoshen-blade"
        || me->query_temp("weapon")!=weapon 
        || me->query_skill_mapped("spells")!="yaoshen" 
        || environment(target)!=env 
        || environment(me)!=env 
        || i<0 
        || !me->is_fighting(target) 
        || (int)me->query("force")<200 
        || !me->query_temp("yuhuo") ){ 
           finish(me);
               return; 
       } 
       msg = HIR"\n"+action[i]+NOR; 
       message_vision(msg,me,target);
	i--; 
       extra = (int)me->query_skill("yaoshen",1); 
       if( random(extra) >  target->query_skill("dodge")/4 ) { 
       msg = CYN"$n"NOR+CYN"退无可退，被$N的"NOR+weapon->name()+NOR+CYN"撩中，登时身上又多出了几处烧伤。\n"NOR; 
       message_vision(msg,me,target);   
       damage = extra*3; 
       damage = damage/2 + random(damage); 
	if ( damage > 800 ) damage = 800;

       target->receive_damage("kee", damage); 
       COMBAT_D->report_status(target); 
       } 
       call_out("auto_perform", 5, me, target , env, weapon, i); 
} 
void finish(object me) 
{ 
       string msg; 
       
       if( !me ) return; 
       msg = "$N终于施完了妖神，深深地吸了口气.....\n"NOR; 
       message_vision(msg,me); 
       me->delete_temp("yuhuo"); 
} 

