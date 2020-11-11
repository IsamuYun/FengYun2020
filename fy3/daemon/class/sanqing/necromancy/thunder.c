// drainerbolt.c

#include <ansi.h>

inherit SSERVER;

int thunderspell(object me, object obj)
{
	int	spi, kar, kee, damage, spells,lv;

	 lv = (int)me->query("thunder");
	if (!lv)   me->set("thunder",1);
	lv = (int)me->query("thunder");

	message_vision(YEL "\nһ��������$N��ͷ�ϴ�����\n" NOR, obj);
	obj->receive_damage("sen", 0, me);
	spells = me->query_skill("spells");
        if(obj->is_ghost()==1 && obj->query("level")< 10*lv) {
		message_vision(RED "$N�ҽ���һ������Ϊ�˻ҽ���\n" NOR, obj);
			if(me->query("thunder") < (me->query("level")/10) && userp(me))
			{
    	    me->add("thunder_exp",1);
	      tell_object(me, "��ġ����ħ�䡿�����һ�㼼�������ȡ�\n"NOR);
	  if(me->query("thunder_exp") > (me->query("thunder")*me->query("thunder")*100)&&(me->query("thunder")<10))
		{
		me->add("thunder",1);
		me->set("thunder_exp",0);
	      tell_object(me, HIW"��ġ����ħ�䡿���������ˡ�\n"NOR);
		}
			}
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(RED "$N�ҽ���һ������Ϊ��һ̲Ѫˮ��\n" NOR, obj);
    	    me->add("thunder_exp",1);
	      tell_object(me, "��ġ����ħ�䡿�����һ�㼼�������ȡ�\n"NOR);
	  if(me->query("thunder_exp") > (me->query("thunder")*me->query("thunder")*100)&&(me->query("thunder")<10))
		{
		me->add("thunder",1);
		me->set("thunder_exp",0);
	      tell_object(me, HIW"��ġ����ħ�䡿���������ˡ�\n"NOR);
		}

		obj->die();
		return 1;
	}
	if(obj->query("race")=="Ұ��") {
		kar = obj->query("kar");
		spi = obj->query("spi");
		damage = (31 - spi)*(spells/4)*(random(31-kar)+1)+100;
		if(damage <= 20) damage = 0;
		if(damage > 35) damage = 35;
		if(damage != 0) {
			message_vision(RED "��������$N��ͷ�ϣ�\n" NOR, obj);
			obj->receive_damage("kee", damage, me);
	 		COMBAT_D->report_status(obj);
			if( !obj->is_fighting(me) ) {
                		if( living(obj) ) {
                        		if( userp(obj) ) 
						obj->fight_ob(me);
					else
						obj->kill_ob(me);
                		}
                		me->kill_ob(obj);
        		}
		} else 
			message_vision(RED "����$N����ˣ�\n" NOR, obj);
		return 1;
	}
	kar = obj->query("kar");
	spi = obj->query("spi");
	damage = (31 - spi)*(spells/10)*(random(30-kar)+1);
	if(damage < 0) damage = 0;
	if(damage > 20) damage = 20;
	if(damage != 0 && random(kar) < 20) {
		message_vision(RED "��������$N��ͷ�ϣ�\n" NOR, obj);
		obj->receive_damage("kee", damage, me);
 		COMBAT_D->report_status(obj);
		if( !obj->is_fighting(me) ) {
               		if( living(obj) ) {
                       		if( userp(obj) ) 
					obj->fight_ob(me);
				else
					obj->kill_ob(me);
               		}
               		me->kill_ob(obj);
       		}
	} else 
			message_vision(RED "����$N����ˣ�\n" NOR, obj);
	return 1;
	
}
int cast(object me)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;

	if((int)me->query_skill("spells") < 200 )
		return notify_fail("��ķ��������ߣ�\n");

	if((int)me->query("mana") < 200 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("�������������\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("mana", -200);
	me->receive_damage("sen", 90);

	msg = YEL "$N�Ų������˫���ճɷ�ħӡ�������૵��������ģ�\n" NOR;
	msg = msg + RED "�͵�˫��һ�ӣ����ϴ����������磡\n\n" NOR;
	message_vision(msg, me);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(5);
	return 1;
}
 int help(object me)
{
        write(YEL"\n�������֮���ħ��"NOR"\n");
	write(@HELP

     �Թ��ͽ�ʬ������ɾ޴��˺��ķ�����

     ���ħ��ÿ����һ������10*�ȼ����µĹ����Ч��

HELP
	);
	return 1;
}
