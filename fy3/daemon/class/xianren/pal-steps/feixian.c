// yiru@hero
// feixian.c

#include <ansi.h>

inherit SSERVER;
void flyto(object me);


int conjure(object me, object target)
{
    object ob;

    if( me->query_temp("nofly") || me->query("job/sxy") )
        return notify_fail("你有重要的任务在身，不能乱跑！\n");

    if(me->query("class")!="xianren")
    {
        if( (me->query("score") < 3000) && (me->query("score") > -3000) )
            return notify_fail("你的综合评价不够，无法驾御[飞仙术]\n");
        if( me->query("PKS") > 300 )
            return notify_fail("你的罪孽太深了，已经无法领悟[飞仙术]\n");
        if( me->query("bellicosity") > 3000 )
            return notify_fail("你的杀气太重了，无法驾御[飞仙术]\n");

    }

    if( !(ob = me->query_temp("weapon"))
      ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("不用剑，怎么能够御剑飞行？\n");

    if( me->is_fighting() )
    {
         return notify_fail("战斗中无法使用御剑飞行！\n");
    } 

    if(stringp(me->query_temp("fly_dest")))
        return notify_fail("你已经准备御剑飞行了！\n");

    if( me->query_spi() < 24 )
        return notify_fail("你的灵性太低，无法使出飞仙术！\n");
    if( me->query("gin") < 90 )
        return notify_fail("你的精力无法有效的集中！\n");
    if( me->is_ghost())
        return notify_fail("鬼魂无法使用飞仙术！\n");

    if((int) me->query_skill("incarnation") < 190)
        return notify_fail("你的仙术不够高深！\n");
    if((int) me->query_skill("windcloud-move",1) < 100)
        return notify_fail("你的仙风云体术不够纯熟！\n");
    if((int) me->query_skill("imperialsword",1) < 100)
        return notify_fail("你的御剑术未免也太差了吧！\n");

    write(HIY"你想飞向什么地方呢？"NOR);
    input_to( (: call_other, __FILE__, "select_target", me :));
    return 1;
}

/* yiru removed, this is a bug.
int perform(object me, object target)
{
    return notify_fail("[飞仙术]是一门法术。\n");
}
*/

void select_target(object me, string name)
{
    object ob, wp;
    int cost;

    cost=120-me->query_spi();
    if(cost<10) cost=10;

    if( !(wp = me->query_temp("weapon")) ){
        write("没有剑，怎么能够御剑飞行？\n");
        return;
    }

    if( !name || name=="" ) {
        write("唉，还是算了吧。\n");
        return;
    }

    ob = find_player(name);
    if( !ob || !me->visible(ob) || wizardp(ob) )
        ob = find_living(name);

    if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)) {
        write(HIC"你无法感受到这个人的灵性 ....\n"NOR);
        write(HIY"你想飞向什么地方呢？"NOR);
        input_to( (: call_other, __FILE__, "select_target", me :));
        return;
    }
    
    if( random(ob->query("spi")) < 3 || ob->query_temp("spi_protect") )
    {
        write(HIG"你感受到这个人的灵性，但不够强烈 ....\n\n"NOR);
        return;
    }

    if( me->query("atman") < cost ) {
        write("你的灵力不够！\n");
        return;
    }

    if(environment(ob)->query("no_magic"))
    {
        write("唉！那个地方好象什么都感受不到。\n");
        return;
    }
    me->add("atman", -cost);

    if( random(240) > ( me->query_skill("incarnation") ) 
        || random(me->query_skill("windcloud-move",1)+me->query_skill("imperialsword",1)) < 10 )
    {
        message_vision(HIB"$N高高兴兴地往$n"HIB"上一跳，\n"
          HIY"结果一个不稳，连人带剑跌了下来，“啪嗤”一声摔了个嘴啃泥。\n"NOR, me, wp);
        if(!(wp->query("owner")) && !(wp->query("no_drop")) )
            wp->move(environment(me));
        else
            message_vision( HIW "还好$N动作迅速，轻轻一抄就把$n"HIW"稳稳的握在手中。\n" NOR, me, wp);
        me->start_busy(1);
        return;
    }

    printf(HIW "你开始感应"+ob->query("name")+HIW"的所在……\n" NOR);

    me->set_temp("fly_dest",environment(ob));
    me->set("no_see",1);

    message( "vision", HIB "\n一道蓝光掠过，"
      + me->name() + "御剑飞行，只一会就消失得无影无踪！\n" NOR,
      environment(me), ({ me }) );

    flyto(me);
    return;
}

void flyto(object me)
{
    object ob=me->query_temp("fly_dest"), wp;

    me->delete("no_see");
    if( !(wp = me->query_temp("weapon")) ){
        write("没有剑，怎么能够御剑飞行？\n");
        return;
    }

    if(ob){
        printf(HIB "你凝神静气，往%s"HIB"上一跳，稳稳地飞向%s。\n"NOR,
          wp->name(),ob->query("short"));
        me->move(ob);
    } else {
        printf("不知道为什么，御剑飞行不幸失败了。\n");
        return;
    }

    message( "vision", HIW "\n一道白光掠过，你眼前突然出现一人御剑飞行而至！\n" NOR,
      ob, ({ me }) );

    me->delete_temp("fly_dest");
    return;
}

