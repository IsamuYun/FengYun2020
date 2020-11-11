// lion@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    object *ob,weapon;
    int i,damage;
    string msg;
    int extra,myforce,mymana;
    extra = me->query_skill("staff");
    if ( extra < 200) return notify_fail("你的伏魔杖法还不够纯熟！\n");
    if(!me->is_fighting() )
        return notify_fail("［群魔伏首］只能在战斗中使用。\n");
    myforce = me->query("force");
    mymana = me->query("mana");
    weapon = me->query_temp("weapon");
    if(myforce<600) return notify_fail("你的内力不够！\n");
    if(mymana<200) return notify_fail("你的法力不够！\n");
    me->add("force",-300);
    me->add("mana",-100);
    me->receive_damage("kee", 60);
    message_vision(HIC"$N展开伏魔杖法，手中的"+weapon->name()+"在$N周身化做一个光圈。\n"NOR,me);
    damage = extra + me->query("max_force") + me->query("max_mana");
    ob = all_inventory(environment(me));
    i = sizeof(ob);
    if(i>15) i = 15;
    while(i--) 
    {
        if( !ob[i]->is_character() || ob[i]==me ) continue;

        if( ob[i]->is_ghost() && (int)ob[i]->query("combat_exp") < 1000000 )
        {
            message_vision(RED "$N惨叫了一声，化为了灰烬！\n" NOR, ob[i]);
            ob[i]->die();
            continue;
        }

        if(ob[i]->is_zombie()==1) {
            message_vision(RED "$N惨叫了一声，化为了一滩血水！\n" NOR, ob[i]);
            ob[i]->die();
            continue;
        }

		if( living(ob[i]) && ob[i]->is_fighting(me) && me->is_fighting(ob[i]) )
		{
        	damage = damage - ob[i]->query("max_force") - ob[i]->query("max_mana");
    		if(damage>5500) damage = 5500;
        	if (damage<50) damage = 50;
        	msg = HIR"$n被$N身上的杖气所伤！！\n"NOR;
        	ob[i]->receive_damage("kee", damage, me);
        	COMBAT_D->do_attack(me,ob[i], weapon, TYPE_REGULAR,msg);
		}
    }
    me->start_busy(3);
    return 1;
}
