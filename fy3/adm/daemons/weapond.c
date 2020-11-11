// weapond.c
#pragma optimize all
#include <ansi.h>
#include <combat.h>

mapping weapon_actions = ([
        "slash": ([
                "damage_type":  "����",
                "action":               "$N�Ӷ�$w��ն��$n��$l",
                "parry":                20,
                ]),
        "slice": ([
                "damage_type":  "����",
                "action":               "$N��$w��$n��$l��ȥ",
                "dodge":                20,
                ]),
        "chop": ([
                "damage_type":  "����",
                "action":               "$N��$w����$n��$l������ȥ",
                "parry":                -20,
                ]),
        "hack": ([
                "action":               "$N����$w����׼$n��$lһ���ҿ�",
                "damage_type":  "����",
                "damage":               30,
                "dodge":                30,
                ]),
        "thrust": ([
                "damage_type":  "����",
                "action":               "$N��$w��$n��$l��ȥ",
                "dodge":                15,
                "parry":                -15,
                ]),
        "pierce": ([
                "action":               "$N��$w��$n��$l�ݺݵ�һͱ",
                "damage_type":  "����",
                "dodge":                -30,
                "parry":                -30,
                ]),
        "whip": ([
                "action":               "$N��$wһ���$n��$l��ȥ",
                "damage_type":  "����",
                "dodge":                -20,
                "parry":                30,
                ]),
        "impale": ([
                "action":               "$N��$w��$n��$lֱ����ȥ",
                "damage_type":  "����",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "bash": ([
                "action":               "$N����$w����$n��$l����һ��",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "crush": ([
                "action":               "$N�߸߾���$w����$n��$l��ͷ����",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "slam": ([
                "action":     "$N����$w����¶�׹⣬�͵ض�׼$n��$l���˹�ȥ",          
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "throw": ([
                "action":               "$N��$w��׼$n��$l���˹�ȥ",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
]);

varargs mapping query_action()
{
        string verb, *verbs;

        verbs = previous_object()->query("verbs");

        if( !pointerp(verbs) ) return weapon_actions["hit"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return 
weapon_actions[verb];
                else return weapon_actions["hit"];
        }       
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
        if( objectp(weapon) ) {
                if( (int)weapon->query_amount()==1 ) {
                        weapon->unequip();
                        tell_object(me, "\n���" + weapon->query("name") + 
"�����ˣ�\n\n");
                }
                weapon->add_amount(-1);
        }
}

void bash_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp;

        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query_str() * 10;
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str() * 10;
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "ֻ������ž����һ����$N���е�" +
ob->name()
                                + "�Ѿ���Ϊ���أ�\n" NOR, victim );
                        ob->unequip();
                        ob->set("name", "�ϵ���" + ob->query("name"));
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
			ob->set("no_get",0);
			ob->set("no_drop",0);
			ob->save();
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision(HIW "$Nֻ��������" + ob->name() +
"�ѳֲ��������ַɳ���\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp / 2 ) {
                        message_vision("$Nֻ��������" + ob->name() +
"һ����Щ���֣�\n", victim);
                } else {
                        message_vision("$N��" + weapon->name() + "��$n��" + 
ob->name()
                                + "�����ð�����Ļ��ǡ�\n", me, victim);
                }
        }
}
 

void wear_off(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp,i;
	object *inv;
// weapon is me's weapon if it is not null
// ob is my victiim's weapon if it is not null
// damage could be RESULT_PARRY, RESULT_DODGE, or a positive number (victim got hit!)
// we won't do anything if it is a DODGE, what can we do?
	ob = victim->query_temp("weapon");
	if (damage == RESULT_DODGE) return;
        if( objectp(weapon) && damage==RESULT_PARRY && objectp(ob))
	{
// we also use wap/(wap+wdp) formular
                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query_str() * 10;
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str() * 10;
// I don't think player can afford damage to their things every time two weapons hit each other
	if(!random(10) && random(wap) > random(wap+wdp))
	{
		message_vision(HIW "$N���е�" +ob->name()+ "���ĳ�һ��ȱ�ڣ�\n" NOR, victim );
		ob->add("weapon_prop/damage",-1);
		if((int)ob->query("weapon_prop/damage") <= 1 ) 
		ob->set("weapon_prop/damage",1);
		else victim->add_temp("apply/damage",-1);
		if(ob->query("owner"))
		ob->save();
		
	}
        if(!random(10) && random(wdp) > random(wap+wdp))
        {
                message_vision(HIW "$N���е�" +weapon->name()+ "���ĳ�һ��ȱ�ڣ�\n" NOR, me);
                weapon->add("weapon_prop/damage",-1);
                if((int)weapon->query("weapon_prop/damage") <= 1 ) 
                weapon->set("weapon_prop/damage",1);
                else me->add_temp("apply/damage",-1);
		if(weapon->query("owner"))
                weapon->save();

        }
    }
        if( damage > 10 && !random(10))
	{
		inv = all_inventory(victim);
		for(i=0;i<sizeof(inv);i++)
			if(inv[i]->query("equipped") == "worn" && inv[i]->query("owner")== victim->query("id") && random(2))
		{
		message_vision(HIW "$N���ϵ�" +inv[i]->name()+ "��Ū����һ�����\n" NOR, victim);
                inv[i]->add("armor_prop/armor",-1);
                if((int)inv[i]->query("armor_prop/armor") <= 1 ) 
                inv[i]->set("armor_prop/armor",1);
                else victim->add_temp("apply/armor",-1);
                inv[i]->save();
		}
	
	}
	return;

}
 
