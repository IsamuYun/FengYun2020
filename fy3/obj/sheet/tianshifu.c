// yiru@hero 2000.8.5

// 天师符

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "天师符" NOR, ({ "tian-shi sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("value", 0);
    set("level", 5);
    setup();
}

int attach_function(object ob)
{
    object me = this_player();
    int damage, bonus;

    if( !me->is_fighting(ob) ){
        write(name()+"只能对战斗中的对手使用。\n");
        return 1;
    }

    bonus = me->query("atman_factor");
    if( bonus < 1 ){
        write("请先使用 enchant 命令指定灵力加力点数。\n");
        return 1;
    }
    if( me->query("atman")<me->query("atman_factor") ){
        write("你的灵力不够了！\n");
        return 1;
    }
    me->add("atman", -me->query("atman_factor") );
    bonus = bonus * bonus / 40 ;

    message_vision(HIC"\n$N往$n身上贴了一道天师符。\n"NOR,me,ob);
    message_vision(HIY"\n\n天师符瞬间在$N的身上爆炸。爆！爆！爆！\n\n"NOR,ob);

    if( me->query_skill("scratching")>150 )
        damage = 150 + query("level");
    else if( me->query_skill("scratching")>30 )
        damage = query("level");
    else
        damage = 0;
    damage += bonus;
    damage -= ob->query_spi();

    if( damage > 0 ){
                if(me->query("family/family_name")!="蜀山剑派")
                {
               damage = damage/10;
                }

        damage = damage/2 + random(damage);
        ob->receive_damage("gin", damage, me);
        ob->receive_damage("kee", damage, me);
        ob->receive_damage("sen", damage, me);
    }

    // 显示结果状态
    if( wizardp(me) ) tell_object(me, GRN "对敌方造成"+damage+"点伤害。\n" NOR);
    if( wizardp(ob) ) tell_object(ob, CYN "对你造成"+damage+"点伤害。\n" NOR);
    COMBAT_D->report_status(ob, 0);

        if(userp(me))
        {
        me->start_busy(2);
    }
    else
    {
        me->start_busy(1);
    }


    destruct(this_object());

    return 1;
}
