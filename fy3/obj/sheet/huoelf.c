// yiru@hero 2000.8.5

// �����

inherit SHEET;

#include <ansi.h>
#include <condition.h>
#include "fiveelf.h"

int do_damage(object ob, int damage,object me);

void create()
{
    set_name(HIR"��"NOR YEL"���" NOR, ({ "huo elf sheet", "elf", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    set("level", 5);
    setup();
}

int burn_function()
{
    object me = this_player();
    object *obs;
    string msg;
    int ap, bonus, i;

    if( !me->is_fighting() ){
        write( name()+"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        return 1;
    }

    bonus = me->query("mana_factor");
    if( bonus < 1 ){
        write("����ʹ�� encurse ����ָ����������������\n");
        return 1;
    }
    if( me->query("mana")<me->query("mana_factor") ){
        write("��ķ��������ˣ�\n");
        return 1;
    }
    me->add("mana", -me->query("mana_factor") );
    bonus = bonus * bonus / 50 ;

    message_vision(YEL "\n$N����һ��"+name()+"��\n", me);

    msg = HIR "\n$Nʩ��������ͬ�Ļ��ߣ���з���ۣ�����һ����ȼ��������ŨŨ�һ𽫵��˰�Χ��\n\n" NOR;

    message_vision(msg, me);

    ap = me->query("level") + query("level");
    ap += bonus;

    obs = me->query_enemy();

    for(i=0;i<sizeof(obs);i++)
        {       
        if(!obs[i]) continue;
        do_damage(obs[i], ap, me );
        }

    me->start_busy(2);

    destruct(this_object());

    return 1;
}


int do_damage(object ob, int damage, object me )
{
    int dp;

    if(!ob) return 0;

    dp = ob->query("spi")*2;

    if( random(damage+dp) > dp ){
        damage = damage/2 + random(damage);
        // ��ϵ��������
        damage = fivedamage(damage, NA_HUO, 
            me->query_temp("apply/nature_attrib"), 
            ob->query_temp("apply/nature_attrib")
        );
        if(damage>0){
            // �Է���������
            ob->receive_damage("kee", damage, me);
            ob->receive_damage("sen", damage, me);
        }if(damage<0){
            // �Է�����������
            damage = -damage;
            ob->receive_damage("kee", damage, me);
        }else{
            // �Է��������
            me->receive_wound("gin", dp);
        }
        message_vision( COMBAT_D->damage_msg(damage), ob, me );
        if(damage) COMBAT_D->report_status(ob, 0);
    }else{
        message_vision( "���Ǳ�$N�㿪�ˡ�\n", ob, me );
    }

    return 1;
}
