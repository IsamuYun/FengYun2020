#include <ansi.h> 
inherit SSERVER;  
 int perform(object me) { 	string msg; 	object weapon; 
 int skill, jing_cost;  	
skill = me->query_skill("damo-sword",1);
 	jing_cost = (int)me->query("int") - 52;      
     if (file_name(environment(me)) !="/d/shaolin/damodong")         		return notify_fail("�㲻�ڴ�Ħ��������������\n"); 
if((string) me->query("class") != "shaolin" ) 		return notify_fail("�㲻�����ֵĵ��ӣ�����������\n");  	
if( me->is_fighting() ) 		return notify_fail("����������ս���С�\n");   	
if (!objectp(weapon = me->query_temp("weapon")) 	|| (string)weapon->query("skill_type") != "sword") 		return notify_fail("�������ȥ��һ�ѽ���\n"); 
 	if( !skill || (skill < 1)) 		return notify_fail("��Ĵ�Ħ�����ȼ�����, ����������\n"); 	
if( !skill || (skill > 200)) 		return notify_fail("��Ĵ�Ħ�����ȼ��Ѿ����˼�����, ����������\n");        
  if( me->query("force") < 3000 )
		return notify_fail("�������������û������������\n");         
  if( me->query("gin") < 200 )
		return notify_fail("������̫���ˣ��޷����о���������\n");  	msg = HIG "$N������" + weapon->name() + "�ڶ���ϸ�ĵ�������\n"; 	message_vision(msg, me);          me->add("force", -150);
        me->add("kee", -250);
        me->add("gin", -150);
 	if ( skill < 60) 		me->improve_skill("damo-sword", 10); 	else if (skill < 90) 		me->improve_skill("damo-sword", 10 + random((int)me->query("int") - 9)); 	else if (skill < 140) 		me->improve_skill("damo-sword", 10 + random((int)me->query("int") * 2 - 9)); 	else if (skill < 500) 		me->improve_skill("damo-sword", 10 + random((int)me->query("int") * 4 - 9)); 	else 		me->improve_skill("damo-sword", 10 + random((int)me->query("int") * 8 - 9));  	msg = MAG"$P�ġ���Ħ�����������ˣ�\n"NOR; 	me->start_busy(random(3));  	message_vision(msg, me);  	return 1; } 