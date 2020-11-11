// yiru@hero
// feixian.c

#include <ansi.h>
#include <combat.h>

int conjure(object me, object target)
{
    object ob, wp;

    if( !(ob = me->query_temp("weapon"))
     || (string)ob->query("skill_type") != "sword" )
        return notify_fail("���ý�����ô�ܹ�ʹ���ɽ�����\n");

    // search for another sword.
    wp = present("sword", me);
    if(!wp) wp = ob;

    if( wp->query("owner")!=geteuid(me) && wp->query("no_drop") )
        return notify_fail("�á�"+wp->name()+"����ѽ�����̫�˷��ˣ����ǻ�һ�Ѱɡ�\n");

    if( me->query_spi() < 24 )
        return notify_fail("�������̫�ͣ��޷�ʹ���ɽ�����\n");
    if( me->query("gin") < 300 )
        return notify_fail("��ľ����޷���Ч�ļ��У�\n");
    if( me->query("atman") < 300 )
        return notify_fail("������������ˣ�\n");
    if( me->is_ghost())
        return notify_fail("����޷�ʹ�÷�������\n");

    if( (string)me->query_skill_mapped("sword")!="imperialsword")
        return notify_fail("�ɽ����������������ʹ�ã�\n");
    if((int) me->query_skill("incarnation") < 190)
        return notify_fail("��������������\n");
    if((int) me->query_skill("imperialsword",1) < 100)
        return notify_fail("����������������죡\n");
    if((int) me->query_skill("windcloud-move",1) < 130)
        return notify_fail("����ɷ�������δ��Ҳ̫���˰ɣ�\n");

    write("����ɽ�ȡ˭���׼���");
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
        write("û�н�����ô��ʹ����������\n");
        return;
    }

    if( !name || name=="" ) {
        write("�����������˰ɡ�\n");
        return;
    }

//        ob = find_player(name);
//        if( !ob || !me->visible(ob) || wizardp(ob) )
    ob = find_living(name);

    if( !objectp(ob) || !ob ) {
        write("���޷����ܵ�Ҫɱ���ˡ�\n");
        return;
    }
    if( !environment(ob) ) {
        write("���޷����ܵ�Ҫɱ���ˡ�\n");
        return;
    }
    if( environment(ob)==environment(me) ) {
        write("Ҫɱ����������ߣ��޷�ʹ�÷ɽ�����\n");
        return;
    }
    if( ob->query("no_arrest") ){
        write("���޷����ܵ�Ҫɱ���ˡ�\n");
        return;
    }
    if( me->query_spi()<ob->query_spi() ){
        write("�Է����Ա���ߣ��ɽ��޷����С�\n");
        return;
    }

    if( (int)environment(ob)->query("no_death_penalty") == 1 ){
        write("�����Ǹ��ط�����ʲô���ɲ���ȥ��\n");
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

    tell_object(me, "�㿪ʼ��Ӧ"+ob->name()+"�����ڡ���\n");
    message_vision(HIW"\n$NǱ������������$n"HIW"���ֶ����������ˡ�\n\n"NOR,me,wp);

    if( cost > 0 ){
        extra = ap2*2 + ap3;
        ob->kill_ob(me); me->kill_ob(ob);
        me->add_temp("apply/attack", -ap1/6 );
        me->add_temp("apply/damage", extra );

message( "vision", HIW "\n����ͻȻ����һ��������Ӷ�����\n" NOR, environment(ob), ({ me }) );
message( "vision", HIW "\n"+wp->name()+"˲��ɵ�"+ob->name()+"���Ͽգ�\n" NOR, environment(me), ({ me }) );
        for(;cost>0;cost--){
message( "vision", HIC "\n������������Զ���ת�طɣ�ֱ��"+ob->name()+"��Ҫ��\n" NOR, environment(ob), ({ me }) );
message( "vision", HIC "\n"+wp->name()+"��������Զ���ת�طɣ�ֱ��"+ob->name()+"��Ҫ��\n" NOR, environment(me), ({ ob }) );
COMBAT_D->do_attack(me, ob, wp, TYPE_REGULAR,"","����");
        }

        me->add_temp("apply/attack", ap1/6 );
        me->add_temp("apply/damage", -extra );
        wp->move(ob);
        if( wp->query("owner")==geteuid(me) ) {
            message_vision(HIB "\n$n"HIB"���˻���������$N����Ľ��ʡ�\n\n"NOR,me,wp);
            wp->move(me);
        }
    } else {
        tell_object(me,"���ʲôҲû�з�������ʧ���ˡ�\n");

        if( wp->query("owner")!=geteuid(me) ) {
            destruct(wp);
        } else {
            wp->move(ob);
            message_vision(HIB "\n$n"HIB"���˻���������$N����Ľ��ʡ�\n\n"NOR,me,wp);
            wp->move(me);
        }
    }

    if( wizardp(me) )
        tell_object(me, GRN"AP��"+ap+"��DP��"+dp+"\n"NOR);

me->remove_all_killer();
    me->start_busy(3);

    return;
}
