#include <ansi.h> 
inherit SSERVER;  
 int perform(object me) { 	string msg; 	object weapon; 
 int skill, jing_cost;  	
skill = me->query_skill("damo-sword",1);
 	jing_cost = (int)me->query("int") - 52;      
     if (file_name(environment(me)) !="/d/shaolin/damodong")         		return notify_fail("你不在达摩洞，不能演练。\n"); 
if((string) me->query("class") != "shaolin" ) 		return notify_fail("你不是少林的弟子，不能演练。\n");  	
if( me->is_fighting() ) 		return notify_fail("演练不能在战斗中。\n");   	
if (!objectp(weapon = me->query_temp("weapon")) 	|| (string)weapon->query("skill_type") != "sword") 		return notify_fail("你必须先去找一把剑。\n"); 
 	if( !skill || (skill < 1)) 		return notify_fail("你的达摩剑法等级不够, 不能演练！\n"); 	
if( !skill || (skill > 200)) 		return notify_fail("你的达摩剑法等级已经到了极限了, 不能演练！\n");        
  if( me->query("force") < 3000 )
		return notify_fail("你的内力不够，没有力气演练！\n");         
  if( me->query("gin") < 200 )
		return notify_fail("你现在太累了，无法集中精神演练！\n");  	msg = HIG "$N将手中" + weapon->name() + "在洞里细心的演练。\n"; 	message_vision(msg, me);          me->add("force", -150);
        me->add("kee", -250);
        me->add("gin", -150);
 	if ( skill < 60) 		me->improve_skill("damo-sword", 10); 	else if (skill < 90) 		me->improve_skill("damo-sword", 10 + random((int)me->query("int") - 9)); 	else if (skill < 140) 		me->improve_skill("damo-sword", 10 + random((int)me->query("int") * 2 - 9)); 	else if (skill < 500) 		me->improve_skill("damo-sword", 10 + random((int)me->query("int") * 4 - 9)); 	else 		me->improve_skill("damo-sword", 10 + random((int)me->query("int") * 8 - 9));  	msg = MAG"$P的「达摩剑法」进步了！\n"NOR; 	me->start_busy(random(3));  	message_vision(msg, me);  	return 1; } 