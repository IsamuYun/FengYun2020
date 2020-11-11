// yiru@hero 2000.8.5

// 雷灵符

inherit SHEET;

#include <ansi.h>
#include <condition.h>
#include "fiveelf.h"

int do_damage(object ob, int damage,object me);

void create()
{
    set_name(HIW"雷"NOR YEL"灵符" NOR, ({ "lei elf sheet", "elf", "sheet"}) );
    set_weight(5);
    set("unit", "张");
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
        write( name()+"只能对战斗中的对手使用。\n");
        return 1;
    }

    bonus = me->query("mana_factor");
    if( bonus < 1 ){
        write("请先使用 encurse 命令指定法力加力点数。\n");
        return 1;
    }
    if( me->query("mana")<me->query("mana_factor") ){
        write("你的法力不够了！\n");
        return 1;
    }
    me->add("mana", -me->query("mana_factor") );
    bonus = bonus * bonus / 50 ;

    message_vision(YEL "\n$N祭起一张"+name()+"。\n", me);

    msg = HIW "\n霎时间风云色变，万里乌云铺天盖地而来，只听得雷声轰鸣。\n"
        "雷声越来越大，五道闪电一齐对准直劈而出！\n" NOR;

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
        // 雷系攻击法术
        damage = fivedamage(damage, NA_LEI, 
            me->query_temp("apply/nature_attrib"), 
            ob->query_temp("apply/nature_attrib")
        );
        if(damage>0){
            // 对方五行相生
            ob->receive_damage("kee", damage, me);
            ob->receive_damage("sen", damage, me);
        }if(damage<0){
            // 对方不属于五行
            damage = -damage;
            ob->receive_damage("kee", damage, me);
        }else{
            // 对方五行相克
            me->receive_wound("gin", dp);
        }
        message_vision( COMBAT_D->damage_msg(damage), ob, me );
        if(damage) COMBAT_D->report_status(ob, 0);
    }else{
        message_vision( "但是被$N躲开了。\n", ob, me );
    }

    return 1;
}
