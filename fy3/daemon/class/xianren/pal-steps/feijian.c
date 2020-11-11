// yiru@hero
// feixian.c

#include <ansi.h>
#include <combat.h>

int conjure(object me, object target)
{
    object ob, wp;

    if( !(ob = me->query_temp("weapon"))
     || (string)ob->query("skill_type") != "sword" )
        return notify_fail("不用剑，怎么能够使出飞剑术？\n");

    // search for another sword.
    wp = present("sword", me);
    if(!wp) wp = ob;

    if( wp->query("owner")!=geteuid(me) && wp->query("no_drop") )
        return notify_fail("用『"+wp->name()+"』这把剑飞人太浪费了，还是换一把吧。\n");

    if( me->query_spi() < 24 )
        return notify_fail("你的灵性太低，无法使出飞剑术！\n");
    if( me->query("gin") < 300 )
        return notify_fail("你的精力无法有效的集中！\n");
    if( me->query("atman") < 300 )
        return notify_fail("你的灵力不够了！\n");
    if( me->is_ghost())
        return notify_fail("鬼魂无法使用飞仙术！\n");

    if( (string)me->query_skill_mapped("sword")!="imperialsword")
        return notify_fail("飞剑必须与御剑术结合使用！\n");
    if((int) me->query_skill("incarnation") < 190)
        return notify_fail("你的仙术不够高深！\n");
    if((int) me->query_skill("imperialsword",1) < 100)
        return notify_fail("你的御剑术不够纯熟！\n");
    if((int) me->query_skill("windcloud-move",1) < 130)
        return notify_fail("你的仙风云体术未免也太差了吧！\n");

    write("你想飞剑取谁的首级？");
    me->set_temp("feijian",wp);
    input_to( (: call_other, __FILE__, "select_target", me :));
    return 1;
}

int perform(object me, object target)
{
    return conjure( me, target );
}

void select_target(object me, string name)
{
    object ob, wp;
    int cost,ap, ap1,ap2,ap3, dp, extra;

    cost = 300-me->query_spi();
    if(cost<60) cost=60;

    if( !(wp = me->query_temp("feijian")) ){
        write("没有剑，怎么能使用御剑术？\n");
        return;
    }

    if( !name || name=="" ) {
        write("唉，还是算了吧。\n");
        return;
    }

//        ob = find_player(name);
//        if( !ob || !me->visible(ob) || wizardp(ob) )
    ob = find_living(name);

    if( !objectp(ob) || !ob ) {
        write("你无法感受到要杀的人。\n");
        return;
    }
    if( !environment(ob) ) {
        write("你无法感受到要杀的人。\n");
        return;
    }
    if( environment(ob)==environment(me) ) {
        write("要杀的人在你身边，无法使用飞剑术。\n");
        return;
    }
    if( ob->query("no_arrest") ){
        write("你无法感受到要杀的人。\n");
        return;
    }
    if( me->query_spi()<ob->query_spi() ){
        write("对方灵性比你高，飞剑无法刺中。\n");
        return;
    }

    if( (int)environment(ob)->query("no_death_penalty") == 1 ){
        write("唉！那个地方好象什么都飞不进去。\n");
        return;
    }

    ap1 = (int)me->query_skill("incarnation");
    ap2 = (int)me->query_skill("imperialsword",1);
    ap3 = (int)me->query_skill("windcloud-move",1);

    me->add("atman", -cost);
    me->receive_damage("gin", (ap2<120)?(120-ap2)*3:3, ob);

    // now caculating ap and dp
    ap = ap1 * ap2 * (random(ap2-30)+30);
dp=ob->query("combat_exp");
if( dp <= 1000000 ) dp = 1000000;
if( userp(ob) ) dp = 1000000000;

    // var cost is no use now, for reuse.
    cost = ap/dp;
    if( cost > ap2/10 ) cost = ap2/10;

    tell_object(me, "你开始感应"+ob->name()+"的所在……\n");
    message_vision(HIW"\n$N潜运真气，手中$n"HIW"脱手而出，飞走了。\n\n"NOR,me,wp);

    if( cost > 0 ){
        extra = ap2*2 + ap3;
        ob->kill_ob(me); me->kill_ob(ob);
        me->add_temp("apply/attack", -ap1/6 );
        me->add_temp("apply/damage", extra );

message( "vision", HIW "\n空中突然出现一道剑光飞掠而来！\n" NOR, environment(ob), ({ me }) );
message( "vision", HIW "\n"+wp->name()+"瞬间飞到"+ob->name()+"的上空！\n" NOR, environment(me), ({ me }) );
        for(;cost>0;cost--){
message( "vision", HIC "\n剑光犹如灵物，自动御转回飞，直刺"+ob->name()+"的要害\n" NOR, environment(ob), ({ me }) );
message( "vision", HIC "\n"+wp->name()+"犹如灵物，自动御转回飞，直刺"+ob->name()+"的要害\n" NOR, environment(me), ({ ob }) );
COMBAT_D->do_attack(me, ob, wp, TYPE_REGULAR,"","刺伤");
        }

        me->add_temp("apply/attack", ap1/6 );
        me->add_temp("apply/damage", -extra );
        wp->move(ob);
        if( wp->query("owner")==geteuid(me) ) {
            message_vision(HIB "\n$n"HIB"飞了回来，插入$N腰间的剑鞘。\n\n"NOR,me,wp);
            wp->move(me);
        }
    } else {
        tell_object(me,"结果什么也没有发生，你失败了。\n");

        if( wp->query("owner")!=geteuid(me) ) {
            destruct(wp);
        } else {
            wp->move(ob);
            message_vision(HIB "\n$n"HIB"飞了回来，插入$N腰间的剑鞘。\n\n"NOR,me,wp);
            wp->move(me);
        }
    }

    if( wizardp(me) )
        tell_object(me, GRN"AP："+ap+"，DP："+dp+"\n"NOR);

me->remove_all_killer();
    me->start_busy(3);

    return;
}
